.MODEL SMALL
.DATA
    multiplicand DB 13      ; First number (4-bit: 0-15)
    multiplier DB 5         ; Second number (4-bit: 0-15)
    result DB 0             ; Result storage

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    ; Initialize result to 0
    MOV AL, 0               ; AL will hold result
    MOV BL, multiplicand    ; BL = 13
    MOV CL, multiplier      ; CL = 5 (counter)
    
MULTIPLY_LOOP:
    CMP CL, 0               ; Check if multiplier is 0
    JE DONE                 ; If yes, done
    
    TEST CL, 1              ; Check if LSB of multiplier is 1
    JZ SKIP_ADD             ; If 0, skip addition
    
    ADD AL, BL              ; Add multiplicand to result
    
SKIP_ADD:
    SHL BL, 1               ; Shift multiplicand left (multiply by 2)
    SHR CL, 1               ; Shift multiplier right (divide by 2)
    JMP MULTIPLY_LOOP       ; Repeat
    
DONE:
    ; Store result
    MOV result, AL
    
    ; Display result (optional - for debugging)
    ; Result is now in AL register
    ; For 13 × 5 = 65 (decimal) = 41h
    
    ; Exit program
    MOV AH, 4CH
    INT 21H
    
MAIN ENDP
END MAIN