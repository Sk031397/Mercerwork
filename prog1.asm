; Sahid Kebe
; CSC 322 Fall 18
; Sum calculator
; Sum of elements in an array 

Section .data
bArray DB -1,-2,-3,-4,-5
wArray DW  0ah,0bh,0ch,0dh,0eh
dArray DD -10,20,-30,40,-50
bArraySum DB 0 
wArraySum DW 0
dArraySum DD 0 
grandTotal DD 0
global _main
Section .text
_main:

mov al, [bArray] 
add al, [bArray+1] 
add al, [bArray+2]
add al, [bArray+3]
add al, [bArray+4]
mov [bArraySum], al
array: 
; add all the values in the bArray and sum them together 
mov ax, [wArray] 
add ax, [wArray+2] 
add ax, [wArray+4]
add ax, [wArray+6]
add ax, [wArray+8]
mov [wArraySum], ax
array1:
; add all the values in the dArray and sum them together 
mov eax, [dArray]
add eax, [dArray+4]
add eax, [dArray+8]
add eax, [dArray+12]
add eax, [dArray+16]
mov [dArraySum], eax 
array2: 
 ;sum the each Array and add it to the grandTotal 
movsx ebx, byte [bArraySum]
movsx ecx, word [wArraySum]
mov eax, dword [dArraySum] 
add ebx, ecx
add ebx, eax 
mov dword [grandTotal], ebx 
grandT: 
; Normal Termination
mov eax, 1
mov ebx, 0
int 80h


