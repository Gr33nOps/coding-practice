.model small
.stack 100h
.data
.code
main:

    mov ax, 0b800h
    mov es, ax  
    
    mov al, 3
    add al, 30h
    mov ah, 07h
    mov es:[dI], ax
    
    mov ax, 4ch
    int 21h
           
end main