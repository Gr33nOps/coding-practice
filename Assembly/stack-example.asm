.model small
.stack 100h
.data
.code
main:      
    mov ax, 5
    push ax
    
    mov ax, 2
    pop bx
    
    mov ah, 4ch
    int 21h
       
end main