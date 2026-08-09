MODEL SMALL
STACK 100H

DATA SEGMENT
    NUM1   DB 7
    NUM2   DB 2
    RESULT DB ?
DATA ENDS

CODE SEGMENT
          ASSUME CS:CODE, DS:DATA
    START:
          MOV    AX, DATA
          MOV    DS, AX

          MOV    AL, NUM1
          SUB    AL, NUM2
          MOV    RESULT, AL

          MOV    AH, 4CH
          INT    21H
CODE ENDS
END START