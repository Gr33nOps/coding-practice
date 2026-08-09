.model small
.stack 100h

.data
msg db 'HELLO$'

.code
main proc
    mov ax, @data
    mov ds, ax
    
    lea si, msg
    
print_loop:
    mov al, [si]
    cmp  al, '$'
    js done
    
    mov dl, al
    mov ah, 02h
    int 21h
    
    inc si 
    jmp print_loop
    
done:
    mov ah, 4Ch
    int 21h
    
main endp
end main