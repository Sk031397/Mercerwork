; Console Output
; Materials - NASM (32-bit)
; Copyright (c) 2017 Hall & Slonka

; Uses system call information from Chapter 10

SECTION .data
s1: DB "Happy",10," Halloween",10," CSC322",10," Class!!", 10, 0
lenS1: EQU ($ - s1)

SECTION .text
global _main
_main:

	mov ebx,s1 ;;; ebx points to the next char to print
	mov ecx,150 ;;; print 5 characters from the string
top:
	push ebx
	push ecx
print:  mov eax, 4     ; syswrite
	mov ecx, ebx    ; starting address of string
	mov ebx, 1     ; stdout
	mov edx, 1     ; len of string
	int 80h
	pop ecx
	pop ebx 
	inc ebx       ;; point to the next char
	loop top

done:	
mov eax, 1
mov ebx, 0
int 80h
