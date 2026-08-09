.model small
.stack 100h
.data
.code
main:
    mov ax, 5
    push ax
    mov ax, 3
    push ax 
    
    call add_num
           
    mov ah, 4ch
    int 21h
    
add_num:
    push bp
    mov bp, sp
    
    mov ax, [bp+4]
    add ax, [bp+6]
    
    pop bp
    ret 4