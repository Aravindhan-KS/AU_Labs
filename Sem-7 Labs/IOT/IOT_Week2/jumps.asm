;iii) JUMPS — regular registers (A, R3, R4) for the data/comparisons, but the conditional jump JC reads the Carry flag, which is part of the PSW (Program Status Word) — a special purpose register (SFR at D0H).

ORG 0000H

START:
        MOV A, #0AH
        CJNE A, #14H, NOT_EQUAL   ; compare A with 14H, jump if not equal

EQUAL_CASE:
        MOV R3, #01H
        SJMP END_JMP

NOT_EQUAL:
        MOV R3, #00H
        JC  CARRY_SET             ; jump if carry flag set (A < 14H here)
        SJMP END_JMP

CARRY_SET:
        MOV R4, #0FFH

END_JMP:
        LJMP HALT

HALT:
        SJMP $

        END



;Using special purpose registers
ORG 0000H

START:
        MOV ACC, #0AH
        MOV B, #14H
        CJNE A, B, NOT_EQUAL       ; compare ACC(A) with B, affects PSW (SFR D0H) carry flag

EQUAL_CASE:
        MOV P1, #01H                ; write result to Port1 SFR
        SJMP END_JMP

NOT_EQUAL:
        MOV P1, #00H
        JC  CARRY_SET                 ; JC checks Carry flag inside PSW (SFR D0H)
        SJMP END_JMP

CARRY_SET:
        MOV P2, #0FFH                   ; write to Port 2 SFR (A0H)

END_JMP:
        MOV PSW, #00H                     ; directly clear PSW (SFR D0H)
        LJMP HALT

HALT:
        SJMP $

        END