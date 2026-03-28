import random
import time

class TicTacToe:
    def __init__(self):
        self.board = [0] * 9  # 0: empty, 1: X (Agent), -1: O (Opponent)
        self.winning_combos = [
            (0, 1, 2), (3, 4, 5), (6, 7, 8), # Rows
            (0, 3, 6), (1, 4, 7), (2, 5, 8), # Cols
            (0, 4, 8), (2, 4, 6)             # Diagonals
        ]

    def reset(self):
        self.board = [0] * 9
        return tuple(self.board)

    def get_available_moves(self):
        return [i for i, spot in enumerate(self.board) if spot == 0]

    def make_move(self, position, player):
        self.board[position] = player
        return tuple(self.board)

    def check_winner(self):
        for a, b, c in self.winning_combos:
            if self.board[a] == self.board[b] == self.board[c] and self.board[a] != 0:
                return self.board[a] # Returns 1 (X) or -1 (O)
        if 0 not in self.board:
            return 0 # Draw
        return None # Game is still ongoing

    def render(self):
        symbols = {1: 'X', -1: 'O', 0: ' '}
        print("\n")
        for i in range(3):
            row = f" {symbols[self.board[i*3]]} | {symbols[self.board[i*3+1]]} | {symbols[self.board[i*3+2]]} "
            print(row)
            if i < 2:
                print("---+---+---")
        print("\n")

class QLearningAgent:
    def __init__(self, alpha=0.7, gamma=0.9, epsilon=1.0):
        self.q_table = {}  # Dictionary to hold State -> {Action: Q-Value}
        self.alpha = alpha
        self.gamma = gamma
        self.epsilon = epsilon
        self.min_epsilon = 0.01
        self.decay_rate = 0.0005

    def get_q_value(self, state, action):
        if state not in self.q_table:
            self.q_table[state] = {a: 0.0 for a in range(9) if state[a] == 0}
        return self.q_table[state].get(action, 0.0)

    def choose_action(self, state, available_moves, explore=True):
        # Initialize state in Q-table if not present
        if state not in self.q_table:
            self.q_table[state] = {a: 0.0 for a in available_moves}

        # Epsilon-Greedy Strategy
        if explore and random.uniform(0, 1) < self.epsilon:
            return random.choice(available_moves) # EXPLORE
        else:
            # EXPLOIT: Get the action with the max Q-value
            max_q = max(self.q_table[state].values())
            best_actions = [a for a, q in self.q_table[state].items() if q == max_q]
            return random.choice(best_actions) # Break ties randomly

    def update_q_value(self, state, action, reward, next_state, next_available_moves):
        current_q = self.get_q_value(state, action)
        
        # Find max Q for the next state
        if not next_available_moves: # Terminal state
            max_next_q = 0.0
        else:
            if next_state not in self.q_table:
                self.q_table[next_state] = {a: 0.0 for a in next_available_moves}
            max_next_q = max(self.q_table[next_state].values())

        # Bellman Equation
        new_q = current_q + self.alpha * (reward + self.gamma * max_next_q - current_q)
        self.q_table[state][action] = new_q

# --- 1. TRAINING LOOP ---
env = TicTacToe()
agent = QLearningAgent()
episodes = 20000

print(f"Training Agent over {episodes} episodes")

for episode in range(episodes):
    state = env.reset()
    done = False
    
    while not done:
        # 1. Agent (X) chooses an action
        available_moves = env.get_available_moves()
        action = agent.choose_action(state, available_moves)
        
        # Agent makes the move
        next_state = env.make_move(action, player=1)
        winner = env.check_winner()
        
        if winner is not None:
            # Game ended after Agent's move
            reward = 1 if winner == 1 else 0 # 1 for win, 0 for draw
            agent.update_q_value(state, action, reward, next_state, [])
            break
            
        # 2. Opponent (O) makes a random move
        opp_moves = env.get_available_moves()
        opp_action = random.choice(opp_moves)
        next_state = env.make_move(opp_action, player=-1)
        
        winner = env.check_winner()
        if winner is not None:
            # Game ended after Opponent's move
            reward = -1 if winner == -1 else 0 # -1 for loss, 0 for draw
            agent.update_q_value(state, action, reward, next_state, [])
            break
        else:
            # Game continues
            reward = 0
            agent.update_q_value(state, action, reward, next_state, env.get_available_moves())
            
        state = next_state
        
    # Decay Epsilon
    agent.epsilon = max(agent.min_epsilon, agent.epsilon - agent.decay_rate)

print(f"Training Complete! Q-Table has learned {len(agent.q_table)} unique states.")


# --- 2. PLAY AGAINST THE AI ---
print("\n" + "="*40)
print("   HUMAN (O) vs TRAINED AI (X)")
print("   Positions are 0-8 (Top-Left to Bottom-Right)")
print("="*40)

state = env.reset()
env.render()
done = False

while not done:
    # --- AI TURN (X) ---
    print("AI is thinking...")
    time.sleep(1)
    available_moves = env.get_available_moves()
    # Force explore=False so the AI strictly uses what it learned
    action = agent.choose_action(state, available_moves, explore=False) 
    state = env.make_move(action, player=1)
    env.render()
    
    winner = env.check_winner()
    if winner is not None:
        done = True
        if winner == 1: print("AI Wins! You lose.")
        elif winner == 0: print("It's a Draw!")
        break

    # --- HUMAN TURN (O) ---
    available_moves = env.get_available_moves()
    valid_move = False
    while not valid_move:
        try:
            human_action = int(input(f"Your turn (O). Choose a spot {available_moves}: "))
            if human_action in available_moves:
                valid_move = True
            else:
                print("Invalid move. Spot is taken or out of range.")
        except ValueError:
            print("Please enter a valid integer.")
            
    state = env.make_move(human_action, player=-1)
    env.render()
    
    winner = env.check_winner()
    if winner is not None:
        done = True
        if winner == -1: print("You Win! (Wait, how did you beat the AI?)")
        elif winner == 0: print("It's a Draw!")
        break