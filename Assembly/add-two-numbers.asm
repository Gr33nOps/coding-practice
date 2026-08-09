MODEL SMALL 
STACK 100H 

DATA SEGMENT
    NUM1 DB 10
    NUM2 DB 20
    SUM  DB ?
DATA ENDS

CODE SEGMENT
          ASSUME CS:CODE, DS:DATA
    START:
          MOV    AX, DATA
          MOV    DS, AX

          MOV    AL, NUM1
          ADD    AL, NUM2
          MOV    SUM, AL

          MOV    AH, 4CH
          INT    21H
CODE ENDS
END START

