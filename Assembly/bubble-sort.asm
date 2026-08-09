.MODEL SMALL
.STACK 100H

.DATA
    arr  DB 5, 3, 2, 4, 1    ; unsorted array
    len  DB 5                ; number of elements
.CODE
               ASSUME CS:CODE, DS:DATA

    START:     
               MOV    AX, @DATA
               MOV    DS, AX              ; initialize data segment

               MOV    CL, len             ; CL = number of elements
               DEC    CL                  ; passes = n - 1

    OUTER_LOOP:
               MOV    CH, CL              ; CH = inner loop counter
               LEA    SI, arr             ; SI points to first array element

    INNER_LOOP:
               MOV    AL, [SI]            ; AL = current element
               MOV    BL, [SI+1]          ; BL = next element
               CMP    AL, BL              ; compare two elements
               JBE    NO_SWAP             ; if AL <= BL, skip swap

               MOV    [SI], BL            ; put smaller value first
               MOV    [SI+1], AL          ; put larger value after

    NO_SWAP:   
               INC    SI                  ; move to next element
               DEC    CH                  ; decrease inner loop counter
               JNZ    INNER_LOOP          ; repeat until CH = 0

               DEC    CL                  ; decrease outer loop counter
               JNZ    OUTER_LOOP          ; repeat passes

               MOV    AH, 4CH
               INT    21H
END START
