;Sahid Kebe
;October 9 2018
;Matrix manipulation
;take the contents of an array and add the rows together and the colums 

ROWS:   EQU 2
COLS:   EQU 3
DSIZE:  EQU 4

SECTION .data
; define data/variables here.  Think DB, DW, DD, DQ
myMatrix:  dd 1, 2,3
	   dd 4,5,6 
saved dd 0
product dd 0  
SECTION .bss
rowSums: RESD ROWS
colSums: RESD COLS
totals:  RESD 1

SECTION .text
global _main
_main:
; take the contents of COLS into ecx 
mov ecx, COLS
; check to see how far until the next column 
multiply:
	add dword [product],4
loop multiply
mov eax, 0 ; use eax and ebx to hold the contents at index 2 
mov ebx, 0 
mov edx, [myMatrix] ; save the first value into ebx 
mov ecx, ROWS ; use ecx to store the ROWS 
d: ; just to see what contents are current in the array 
outerLoop:
	mov [saved],ecx ; reset the counter loop variable 
	mov ecx, COLS ; set the counter loop to COLS 
	middleLoop:
		add dword [rowSums+eax],edx ; rowSums[0] += (rowSums)myMatrix[0]  
		add dword [totals],edx ; move the newly updated contents of ebx into totals
		d0: 
		add ebx, 4 ; use ebx as a placeholder
		mov edx, [myMatrix+ebx] ; update ebx with the new index 
d1: ; check contents after the first iteration
		loop middleLoop
	add eax, 4 ; reset eax to original index
	mov ecx,[saved]
loop outerLoop				 

; Total Columns 
mov eax, 0
mov ebx, [product]
mov edx, [myMatrix]
mov ecx, COLS
d2:
outer:
	mov [saved],ecx
	mov ebx,[product]
	mov edx,[myMatrix+eax]
	mov ecx, ROWS
	d2b:
	middle:
		add dword [colSums+eax],edx
		mov edx, [myMatrix+ebx+eax]
	d2c:
		add ebx,[product]
d3: ; check what is currently in registers
		loop middle
	add eax, 4
	mov ecx,[saved]
loop outer
done:


mov eax, 1
mov ebx, 0
int 80h
