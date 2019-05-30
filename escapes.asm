; NAME: Bob Allen
; Assignment: Demo use of escape sequences and interrupt calls
; Date: Fall 2018

SECTION .data
;;;;; Clear Screen - print 4 chars
cls:	db	1bh, '[2J'		

;;;;;; Set Cursor Position - print 8 chars
cursor:	db	1bh, '[' 
row:	db	'00'
	db	';'
col:	db	'00'
	db	'H'

;;;;;; "Structure" for the sleep interrupt(two seconds) 
secs:	dd	2,0

;;;;;;  Just a message to display - print 17 chars
message: db "No shave November"

;;;;;;  Prompts to get row/col number
rowPrompt: db "Please enter a two digit row number: "  ;; print 37 chars
colPrompt: db "Please enter a two digit col number: "  ;; print 37 chars

;;;;;;  Spaces to clear the old input lines - print 85 chars
clearInput:	db "                                          ",0ah,"                                          "

;;;;;;  Place to read/store the <Enter> character
enter:	db	0

SECTION .text
global _main, _incRow, _incCol, _sleep1
_main:

; Clear the screen
	mov	eax,4
	mov	ebx,1
	mov 	ecx,cls
	mov	edx,4
	int 	80h

; Repeat this 3 times
	mov	ecx,3
top:
	push	ecx
	
	; Set row and col to "00"
	mov	ax,"00"
	mov	[row],ax
	mov	[col],ax

	; Set cursor to 0,0
	mov	eax,4
	mov	ebx,1
	mov 	ecx,cursor
	mov	edx,8
	int 	80h

	; prompt for row input
	mov	eax,4
	mov	ebx,1
	mov 	ecx,rowPrompt
	mov	edx,37
	int 	80h

	; read in two digits
	mov	eax,3 ;sys read
	mov	ebx,0	;stdin
	mov	ecx,row
	mov	edx,2
	int	80h

	; read in the <Enter> char
	mov	eax,3 ;sys read
	mov	ebx,0	;stdin
	mov	ecx,enter
	mov	edx,1
	int	80h

	; prompt for col input
	mov	eax,4
	mov	ebx,1
	mov 	ecx,colPrompt
	mov	edx,37
	int 	80h

	; read in two digits
	mov	eax,3 ;sys read
	mov	ebx,0	;stdin
	mov	ecx,col
	mov	edx,2
	int	80h

	; read in the <Enter> char
	mov	eax,3 ;sys read
	mov	ebx,0	;stdin
	mov	ecx,enter
	mov	edx,1
	int	80h

	; Set cursor to requested row/col
	mov	eax,4
	mov	ebx,1
	mov 	ecx,cursor
	mov	edx,8
	int 	80h

	; Print message
	mov	eax,4
	mov	ebx,1
	mov 	ecx,message
	mov	edx,17
	int 	80h

	; Sleep for 2 seconds
	mov	eax,162
	mov	ebx,secs
	mov	ecx,0
	int	80h
	
	; Set row and col to "00"
	mov	ax,"00"
	mov	[row],ax
	mov	[col],ax

	; Set cursor to 0,0
	mov	eax,4
	mov	ebx,1
	mov 	ecx,cursor
	mov	edx,8
	int 	80h

	; Clear the old input
	mov	eax,4
	mov	ebx,1
	mov 	ecx,clearInput
	mov	edx,85
	int 	80h

	; loop top - top is a far jump, so do loop manually
	pop	ecx
	dec	ecx	
	jz	done
	jmp	top

done:

; Normal termination code
mov eax, 1
mov ebx, 0
int 80h

