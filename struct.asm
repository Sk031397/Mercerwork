; NAME:  Bob Allen
; Assignment: Struc Demo
; Date: Fall 2018

; Constant for Size of array of structs
LEN:	EQU	11

; Define Structure for character on screen
STRUC mStruct
		RESB 2  ; space for <esc>[
	.row:	RESB 2  ; two digit number (characters)
		RESB 1  ; space for ;
	.col:	RESB 2  ; two digit number (characters)
		RESB 1  ; space for the H
	.char:	RESB 1  ; space for THE character
	.size:
ENDSTRUC

SECTION .data
; Create an array of structs: formatted like the print interrupt uses.
message:	db 1bh,'[05;69H '
		db 1bh,'[05;70HG'
		db 1bh,'[05;71Ho'
		db 1bh,'[05;72H '
		db 1bh,'[05;73HB'
		db 1bh,'[05;74He'
		db 1bh,'[05;75Ha'
		db 1bh,'[05;76Hr'
		db 1bh,'[05;77Hs'
		db 1bh,'[05;78H!'
		db 1bh,'[05;79H '


SECTION .bss

SECTION .text
global _main
_main:

; Demonstrate function calls which uses an array of structs
	mov	ecx,10

top: 	call	_displayMessage
	call	_pause
	call	_adjustMessage
	loop	top



; Normal termination code
mov eax, 1
mov ebx, 0
int 80h
;;;;;;;;;;;;;;;;;;;;; END OF MAIN ;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;  Function that shifts row/cols through the array of structs 
;;;;;;;;;;;;  and moves first char one to the left.
_adjustMessage:	
	pusha

	mov	ecx,LEN-1
	mov	ebx,message+(LEN-1)*mStruct.size

_amTop: mov	dx,[ebx - mStruct.size + mStruct.row] 	;; get row above
	mov	[ebx + mStruct.row],dx			;; copy to this row

	mov	dx,[ebx - mStruct.size + mStruct.col] 	;; get col above
	mov	[ebx + mStruct.col],dx			;; copy to this col

	sub	ebx,mStruct.size
	loop	_amTop

	dec	BYTE [ebx + mStruct.col + 1]		;; move first char to left

	popa
	ret


;;;;;;;;;;;   Function to print the array of structs of message
_displayMessage:
	pusha
	mov	ebx,message
	mov	ecx,LEN

_dmTop:	push	ecx
	push	ebx
	mov	eax,4  ; system print
	mov	ecx,ebx ; points to string to print
	mov	ebx,1   ; standard out
	mov	edx,9   ; num chars to print
	int	80h

	pop	ebx
	add	ebx,mStruct.size
	pop	ecx
	loop	_dmTop
	popa
	ret


;;;;;;;;;;;;;  Function to sleep 1/2 second ;;;;;;;;;;;;;;;;;;;;;
_pause: 
	pusha
	mov	eax,162
	mov	ebx,seconds
	mov	ecx,0
	int	80h
	popa
	ret

;;;;;;;;;;;;	Tricky use of ram.... put some data here for _pause to use
seconds: dd	0,500000000  ;;;  seconds, nanoseconds


