ORG 0000H

; ---- SFR addresses (all lie between 80H and FFH) ----
P1_REG      EQU 90H
TMOD_REG    EQU 89H
TCON_REG    EQU 88H
SCON_REG    EQU 98H
PCON_REG    EQU 87H
PSW_REG     EQU 0D0H
ACC_REG     EQU 0E0H
B_REG       EQU 0F0H
SP_REG      EQU 81H

START:
        MOV P1_REG, #0FFH      ; write directly to Port 1 SFR (90H)
        MOV A, P1_REG            ; read back Port 1 into A

        MOV TMOD_REG, #01H      ; set Timer0 mode 1 (SFR 89H)

        MOV TCON_REG, #10H       ; set TR0 bit to start Timer0 (SFR 88H)

        MOV PSW_REG, #00H         ; clear Program Status Word (SFR D0H)
        SETB PSW_REG.3              ; set RS0 bit (register bank select) directly via bit address

        MOV SP_REG, #60H            ; manipulate Stack Pointer SFR (81H)

        MOV B_REG, #02H              ; write to B register SFR (F0H)
        MOV ACC_REG, #05H              ; write to Accumulator SFR (E0H)
        MOV B, ACC                       ; move ACC to B using register names

        MUL AB                             ; multiply A and B, result affects ACC and B SFRs

; ---- attempting invalid/erroneous SFR bit access ----
        MOV C, 91H                          ; ERROR-prone: 91H is not bit-addressable
                                              ; unless it's a valid bit address in an SFR
                                              ; that supports bit addressing (assembler will flag it)

        SJMP $

        END