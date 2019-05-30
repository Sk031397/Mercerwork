; Sahid Kebe
; 9/10/18 
; Addition of two registers 

SECTION .data 

SECTION .text
global _main
_main:
;First problem 
mov ax, 246h 
mov bx, 0cdabh
add ax,bx
done1:

mov ax, 0abcdh
mov bx, 0dcbah 
add ax, bx 
done2:

mov ax, 0fff8h 
mov bx, 0008h
add ax, bx 
done3:

mov ax, 0f0f0h
mov bx, 0ff00h
add ax, bx
done4:

mov ax, 2468h 
mov bx, 0db98h 
add ax, bx 
done5: 



; Normal termination code
mov eax, 1
mov ebx, 0
int 80h
 
