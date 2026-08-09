.model small
.stack 100h
.data
.code
main:
    mov ax,3
    mov bx,4
    call my_sub
    
    mov ah, 4ch
    int 21h
    
my_sub:
    add ax,bx
    ret 
    
end main