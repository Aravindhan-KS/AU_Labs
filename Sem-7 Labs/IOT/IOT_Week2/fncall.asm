;ii) CALL - mostly regular registers (R0, A, B for passing/returning values), but the CALL/RET mechanism itself uses the SP (Stack Pointer), which is a special purpose register (SFR at 81H) — it's used internally to push/pop the return address.

ORG 0000H

MAIN:
        MOV R0, #04H         ; pass value in R0
        LCALL SQUARE          ; call subroutine, PC pushed onto stack
        MOV R2, A              ; store returned result from A
        SJMP $                  ; halt

SQUARE:
        MOV A, R0               ; A = R0
        MOV B, R0                ; B = R0
        MUL AB                    ; A = A * B (result low byte in A, high in B)
        RET                        ; pop return address back into PC

        END



;Using special purpose registers
ORG 0000H

MAIN:
        MOV ACC, #04H          ; pass value via ACC (SFR E0H) instead of R0
        LCALL SQUARE              ; CALL uses SP (SFR 81H) internally to push return address
        MOV P1, ACC                 ; store result (in ACC) out to Port 1 (SFR 90H)
        SJMP $

SQUARE:
        MOV B, ACC                    ; B (SFR F0H) = ACC
        MUL AB                          ; ACC = ACC * B (SFRs directly used, result in ACC/B)
        RET                                ; RET pops return address from stack via SP (SFR)

        END