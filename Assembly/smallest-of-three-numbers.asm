MODEL SMALL
.STACK 100H

DATA SEGMENT
    NUM1   DB 5
    NUM2   DB 2
    NUM3   DB 1
    RESULT DB ?
DATA ENDS

CODE SEGMENT
          ASSUME CS:CODE, DS:DATA

    START:
          MOV    AX, DATA
          MOV    DS, AX

          MOV    AL, NUM1            ; Assume NUM1 is smallest

          CMP    AL, NUM2            ; Compare with NUM2
          JBE    SKIP1               ; If AL <= NUM2, skip
          MOV    AL, NUM2            ; Else, AL = NUM2

    SKIP1:
          CMP    AL, NUM3            ; Compare with NUM3
          JBE    SKIP2               ; If AL <= NUM3, skip
          MOV    AL, NUM3            ; Else, AL = NUM3
    
    SKIP2:
          MOV    RESULT, AL          ; Store the smallest value

          MOV    AH, 4CH
          INT    21H

CODE ENDS
END START