MODEL SMALL
STACK 100H

DATA SEGMENT
    NUM       DB 5
    FACTORIAL DB ?
DATA ENDS

CODE SEGMENT
                   ASSUME CS:CODE, DS:DATA

    START:         
                   mov    AX, DATA
                   mov    DS, AX

                   MOV    CL, NUM
                   MOV    AL, 1

    FACTORIAL_LOOP:
                   MUL    CL
                   DEC    CL
                   JNZ    FACTORIAL_LOOP
    
                   MOV    FACTORIAL, AL
                   MOV    AH, 4CH
                   INT    21H
CODE ENDS
END START