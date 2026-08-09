.model small
.stack 100h
.data
array DB 5, 2, 4, 1
count DB 4
.code
main:
MOV AX, @data
MOV DS, AX
CALL BubbleSort
MOV AH, 4Ch
INT 21h
BubbleSort:
PUSH AX
PUSH BX
PUSH CX
PUSH SI
MOV CL, count
DEC CL
OUTER:
MOV SI, 0
MOV BL, CL
INNER:
MOV AL, array[SI]
CMP AL, array[SI+1]
JBE NOSWAP
; swap
MOV DL, array[SI+1]
MOV array[SI+1], AL
MOV array[SI], DL
NOSWAP:
INC SI
DEC BL
JNZ INNER
DEC CL
JNZ OUTER
POP SI
POP CX
POP BX
POP AX
RET
end main