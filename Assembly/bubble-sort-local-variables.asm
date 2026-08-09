.model small
.stack 100h
.data
    array DB 5, 2, 4, 1
    count DB 4
.code
    main:
                MOV  AX, @data
                MOV  DS, AX
                LEA  AX, array
                PUSH AX
                MOV  AL, count
                CBW
                PUSH AX
                CALL BubbleSort
                MOV  AH, 4Ch
                INT  21h
    BubbleSort:
                PUSH BP
                MOV  BP, SP
                SUB  SP, 2
                PUSH AX
                PUSH BX
                PUSH CX
                PUSH SI
                ; local variable (swap flag)
                MOV  CX, [BP+6]            ; array size
                DEC  CX
    OUTER:
                MOV  SI, 0
                MOV  WORD PTR [BP-2], 0
    INNER:
                MOV  AL, [BP+4][SI]
                CMP  AL, [BP+4][SI+1]
                JBE  NOSWAP
                ; swap
                MOV  DL, [BP+4][SI+1]
                MOV  [BP+4][SI+1], AL
                MOV  [BP+4][SI], DL
                MOV  WORD PTR [BP-2], 1
    NOSWAP:
                INC  SI
                LOOP INNER
                CMP  WORD PTR [BP-2], 1
                JE   OUTER
                POP  SI
                POP  CX
                POP  BX
                POP  AX
                MOV  SP, BP
                POP  BP
                RET  4
end main