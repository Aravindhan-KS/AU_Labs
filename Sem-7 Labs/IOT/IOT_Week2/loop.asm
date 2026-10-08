;i) LOOP — regular registers (R0–R7, the general-purpose working registers).

ORG 0000H

START:
        MOV R0, #05H        ; R0 = loop counter (regular register)
        MOV A, #00H          ; A = accumulator, holds running sum

LOOP1:
        ADD A, R0            ; A = A + R0
        DJNZ R0, LOOP1        ; decrement R0, jump to LOOP1 if R0 != 0

        MOV R1, A             ; store final result in R1
        SJMP $                ; halt (infinite jump to self)

        END






; Using ACC (E0H) and B (F0H) SFRs instead of R0-R7 for looping

ORG 0000H

START:
        MOV ACC, #05H         ; ACC (SFR E0H) = loop counter
        MOV B, #00H             ; B (SFR F0H) = running sum

LOOP1:
        MOV A, B                 ; move current sum into A
        ADD A, ACC                ; A = A + ACC (counter)
        MOV B, A                    ; store sum back into B (SFR)
        DEC ACC                       ; decrement ACC (SFR) directly
        MOV A, ACC                     ; check if ACC == 0
        JNZ LOOP1                        ; jump if ACC != 0 (uses PSW zero flag - SFR)

        MOV P1, B                          ; output final sum to Port 1 (SFR 90H)
        SJMP $

        END