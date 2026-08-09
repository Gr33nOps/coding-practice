.model small       ; Memory model = small (1 code + 1 data segment)
.stack 100h        ; Reserve 256 bytes for stack (100h = 256 in hex)

.data              ; Data section (for variables, messages, etc.)
msg db 'Hello, World!$'    ; Define a message (string ends with $ for DOS)

.code              ; Code section (where instructions start)
main proc          ; Start of main procedure
    mov ax, @data  ; Load data segment address into AX
    mov ds, ax     ; Set DS register to data segment (so data is accessible)

    mov ah, 09h    ; DOS function to print a string
    lea dx, msg    ; Load address of 'msg' into DX
    int 21h        ; Call DOS interrupt to print the string

    mov ah, 4Ch    ; DOS function to exit program
    int 21h        ; Return control to DOS
main endp          ; End of main procedure
end main           ; End of program, entry point = main
