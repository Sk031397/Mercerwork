; Sahid Kebe
; csc 322 October 28 2018 
; matrix multiplication 
; multiply two matrices together 
X	EQU	4	;Rows for Mat1 and Mat3
Y	EQU	3	;Cols for Mat1 and Rows for Mat2
Z	EQU	2	;Cols for Mat2 and Mat3
SECTION .data
M1	dd	 1, 2, 2
dd	 3, 2, 1
dd	 1, 2, 3
dd	 2, 2, 2	

M2	dd	 2, 4
dd	 3, 3
dd	 4, 6
 ; My Test Case
;M1      dd  	 5, 7, 20
;	dd       4, 5, 6
;	dd       2, 8,10
;	dd       28, 51, 50

;M2   
;	dd  2, 4
;	dd  3, 3
;	dd 4, 6


;Store current element
index	dd	0
;Stores current row
row	dd	0
;Stores current column
col	dd	0
;Stores number to go to next row
nextRow dd 	0

SECTION .bss
M3	RESD	 X*Z 

SECTION .text
global _main
_main:

mov ecx, Y
Rows:
add dword [nextRow], 4
loop Rows

mov eax, 0
mov ebx, 0
mov edx, 0
mov ecx, X ; loop X times (row of M1)
Xloop:
push ecx
mov ebx, 0
mov edx, 0
mov ecx, Z ; loop Z times (cols of M2)
Zloop:
push ecx
mov ebx, 0
mov edx, 0
mov ecx, Y ; loop Y times (rows of M3) 
Yloop:
push ecx
mov eax, 0
push edx 
mov edx, dword [row]
mov ecx, dword [M1+edx+4*ebx]
pop edx ; pops the value of ecx 
M1Size:
push ecx
push ebx
mov ebx, dword [col]
mov ecx, dword [M2+ebx+4*Z*edx]
pop ebx
M2Size:
inc eax
loop M2Size
pop ecx
loop M1Size
push ebx
mov ebx, dword [index]
add dword [M3+4*ebx], eax
pop ebx
inc ebx
inc edx
pop ecx
dec ecx
jnz Yloop

add dword [col], 4
inc dword [index]
pop ecx
dec ecx
jnz Zloop
push ebx
mov ebx, dword [nextRow]
add dword [row], ebx
pop ebx
mov dword [col], 0
pop ecx
dec ecx
jnz Xloop

done:

; Normal termination code
mov eax, 1
mov ebx, 0
int 80h
