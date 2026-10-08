#include <8051.h>

#define MAX_TASKS 2
#define STACK_SIZE 24

__data unsigned char task1_stack[STACK_SIZE];
__data unsigned char task2_stack[STACK_SIZE];

volatile unsigned char task_sp[MAX_TASKS];
volatile unsigned char current_task = 0;

void task1_counter_P0(void) {
    unsigned char count0 = 0;
    while (1) {
        P1 = 0xFF;
        P0 = ~count0;
        count0++;
    }
}

void task2_counter_P1(void) {
    unsigned char count1 = 0;
    while (1) {
        P0 = 0xFF;
        P1 = ~count1;
        count1++;
    }
}

void timer0_ISR(void) __interrupt(1) __naked {
    __asm
        PUSH    ACC
        PUSH    B
        PUSH    DPH
        PUSH    DPL
        PUSH    PSW
        PUSH    0
        PUSH    1
        PUSH    2
        PUSH    3
        PUSH    4
        PUSH    5
        PUSH    6
        PUSH    7
    __endasm;

    TH0 = 0xF8;
    TL0 = 0x30;

    task_sp[current_task] = SP;

    current_task = (current_task + 1) % MAX_TASKS;

    SP = task_sp[current_task];

    __asm
        POP     7
        POP     6
        POP     5
        POP     4
        POP     3
        POP     2
        POP     1
        POP     0
        POP     PSW
        POP     DPL
        POP     DPH
        POP     B
        POP     ACC
        RETI
    __endasm;
}

void init_task_stack(unsigned char id, void (*task_func)(void), __data unsigned char *stack_base) {
    unsigned int func_addr = (unsigned int)task_func;
    
    stack_base[0] = (unsigned char)(func_addr & 0x00FF);
    stack_base[1] = (unsigned char)((func_addr >> 8) & 0x00FF);

    task_sp[id] = (unsigned char)(stack_base + 14);
}

void main(void) {
    P0 = 0xFF;
    P1 = 0xFF;

    init_task_stack(0, task1_counter_P0, task1_stack);
    init_task_stack(1, task2_counter_P1, task2_stack);

    TMOD = 0x01;
    TH0  = 0xF8;
    TL0  = 0x30;

    ET0 = 1;
    EA  = 1;
    TR0 = 1;

    current_task = 0;
    SP = task_sp[0];

    __asm
        POP     7
        POP     6
        POP     5
        POP     4
        POP     3
        POP     2
        POP     1
        POP     0
        POP     PSW
        POP     DPL
        POP     DPH
        POP     B
        POP     ACC
        RET
    __endasm;

    while (1);
}