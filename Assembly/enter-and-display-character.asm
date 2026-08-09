.model small
.stack 100h

.data
msg1 db 'Enter a character: $'
msg2 db 13,10, 'You entered: $' 

.code
main proc
    mov ax, @data
    mov ds, ax

    mov ah, 09h      
    lea dx, msg1
    int 21h
    
    mov ah, 01h
    int 21h
    mov bl, al
    
    mov ah, 09h
    lea dx, msg2
    int 21h
    
    mov dl, bl
    mov ah, 02h
    int 21h     

    mov ah, 4Ch
    int 21h   
main endp
end main
