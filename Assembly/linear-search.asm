.MODEL SMALL
.STACK 100H

DATA SEGMENT
    ARR   DB 1,5,3,6,2
    LEN   DW 5
    ITEM  DB 7
    FOUND DW 0
DATA ENDS

CODE SEGMENT
                ASSUME CS:CODE, DS:DATA

    START:      
                MOV    AX, @DATA
                MOV    DS, AX

                MOV    CX, LEN
                LEA    SI, ARR

    SEARCH_LOOP:
                MOV    AL, [SI]
                CMP    AL, ITEM
                JE     FOUND_IT

                INC    SI
                DEC    CX
                JNZ    SEARCH_LOOP
                JMP    NOT_FOUND

    FOUND_IT:   
                MOV    FOUND, 1
                JMP    END_PROGRAM

    NOT_FOUND:  
                MOV    FOUND, 0

    END_PROGRAM:
                MOV    AX, FOUND
                MOV    AH, 4CH
                INT    21H

CODE ENDS
END START
