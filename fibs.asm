; Sahid Kebe 
; Fibonacci Sequence 
; calculate the numbers in the fibonacci sequence 
; 9/30/18

Section .data
 fib dw 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0

Section .text
global _main

_main:
mov ax, [fib]  
add ax, [fib+2] 
mov [fib+4], ax

mov ax, [fib+2] 
add ax, [fib+4] 
mov [fib+6], ax 

mov ax, [fib+4]
add ax, [fib+6]
mov [fib+8], ax

 
mov ax, [fib+6]
add ax, [fib+8]
mov [fib+10], ax

mov ax, [fib+8]
add ax, [fib+10]
mov [fib+12], ax

mov ax, [fib+10]
add ax, [fib+12]
mov [fib+14], ax

mov ax, [fib+12]
add ax, [fib+14]
mov [fib+16], ax

mov ax, [fib+14]
add ax, [fib+16]
mov [fib+18], ax

mov ax, [fib+16]
add ax, [fib+18]
mov [fib+20], ax


mov ax, [fib+18]
add ax, [fib+20]
mov [fib+22], ax

mov ax, [fib+20]
add ax, [fib+22]
mov [fib+24], ax


mov ax, [fib+22]
add ax, [fib+24]
mov [fib+26], ax

mov ax, [fib+24]
add ax, [fib+26]
mov [fib+28], ax

mov ax, [fib+26]
add ax, [fib+28]
mov [fib+30], ax
 

done:


;Termination
mov eax, 1
mov ebx, 0 
int 80h 
