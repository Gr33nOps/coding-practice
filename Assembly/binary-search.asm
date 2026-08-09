; Very Simple Binary Search
; AX = 0 → found
; AX = 1 → not found

.MODEL SMALL
.STACK 100H

.DATA
arr DB 1, 3, 5, 7, 9     ; sorted array
len DB 5
key DB 7                 ; number to find

.CODE
MOV AX, @DATA
MOV DS, AX

; low = 0, high = len - 1
MOV BL, 0
MOV AL, len
DEC AL
MOV BH, AL

; ---- main loop ----
start_search:
    CMP BL, BH           ; if low > high → not found
    JG not_found

    ; mid = (low + high)/2
    MOV AL, BL
    ADD AL, BH
    SHR AL, 1
    MOV CL, AL           ; mid in CL

    ; arr[mid]
    LEA SI, arr
    ADD SI, CX
    MOV DL, [SI]         ; DL = arr[mid]

    ; compare with key
    CMP DL, key
    JE found             ; if equal → found
    JB go_right          ; if arr[mid] < key → go right

    ; go left
    MOV BH, CL
    DEC BH
    JMP start_search

go_right:
    MOV BL, CL
    INC BL
    JMP start_search

; ---- results ----
found:
    MOV AX, 0            ; found → AX = 0
    JMP done

not_found:
    MOV AX, 1            ; not found → AX = 1

done:
    MOV AH, 4CH          ; end program
    INT 21H
END
