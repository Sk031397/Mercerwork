;Sahid Kebe
;12/11/18
;This code will create a Snake the user can control on the screen

; Define Structure for character on screen
STRUC mStruct
	.esc	RESB 2  ; space for <esc>[
	.row:	RESB 2  ; two digit number (characters)
	.semi	RESB 1  ; space for ;
	.col:	RESB 2  ; two digit number (characters)
	.H	RESB 1  ; space for the H
	.char:	RESB 1  ; space for THE character
	.size:
ENDSTRUC

;;;;;  OpenFile needs permissions   0=readonly   101h = write
%macro OpenFile 1
	pusha
	mov	eax,5
	mov	ebx,fileName
	mov	ecx,%1  
	mov	edx,777h 
	int	80h
	mov	[fileDescriptor],eax
	popa
%endmacro

;;;; ReadFile from file needs 3 parms:  file descriptor (var), input buffer (var), length
%macro ReadFile 3
	pusha
        mov     eax,3 ;sys read
        mov     ebx,[%1]
	mov	ecx,%2
        mov     edx,%3
        int     80h
	popa
%endmacro

;;;; WriteFile needs 3 parms: file descriptor (var), buffer (var), length
%macro WriteFile 3
        pusha
        mov     eax,4
        mov     ebx,[%1]
        mov     ecx,%2
        mov     edx,%3
        int     80h
        popa
%endmacro

;;;; CloseFile needs no arguments
%macro CloseFile 0
	pusha
	mov	eax,6
	mov	ebx,[fileDescriptor]
	int	80h
	popa
%endmacro

;;;; SetCursorPosition needs a row and a col
%macro SetCursorPosition 2
	push 	eax
	mov	ah,%1
	mov	al,%2
	call	_setCursor
	pop	eax
%endmacro

;Macro to end program
%macro Termination 0
	mov eax, 1
	mov ebx, 0
	int 80h
%endmacro

;Clear The Screen
%macro ClearScreen 0
        pusha
        mov eax, 4
        mov ebx, 1
        mov ecx, cls
        mov edx, 4
        int 80h
        popa
%endmacro

%macro PrintScreen 2
	pusha
	mov eax, 4
	mov ebx, 1
	mov ecx, %1
	mov edx, [%2]
	int 80h
	popa
%endmacro

SECTION .text
global _main
_main:
	ClearScreen
	SetCursorPosition 1, 1
	PrintScreen screen, screenSize
	;;;;;;;;; LOAD message from theMessage
	mov	ax,80-(pythonLength-python) ;;;; Column on screen for first char when right justified
	shr	ax, 1
	mov	ebx,message		  ;;;; pointer in message array of structs
	mov	ecx,[pythonLength]		  ;;;; loop count of characters in string
	mov	edx,python		  ;;;; pointer into the original message
loadTop:
	mov	BYTE [ebx],1bh
	mov	BYTE [ebx+1],'['
	mov	WORD [ebx+2],"07"  ;;;; ROW might need to swap these
	mov	BYTE [ebx+4],';'
	push	eax		   ;;;; Save this for next loop
	call	_toAscii	   ;;;  Pass in int in ax, returns two ascii digits in ax
	mov	WORD [ebx+5],ax
	pop	eax		   ;;;; Restore the screen col number
	mov	BYTE [ebx+7],'H'
	push	ecx
	mov	cl,[edx]	   ;;;; Get next char from string
	mov	[ebx+8],cl
	pop	ecx
	add	ebx,mStruct.size
	inc	edx
	inc	ax
	loop loadTop

	;;;;   FORK 2 PROCS
	mov	eax,2
	int	80h
	;;;;;;;;;;;;;;;;;;;;;;  Creates two processes, same code,
	;;;;;;;;;;;;;;;;;;;;;;   but returns zero to new proc, and the procID of child to parent
	cmp	eax,0
	je	childProc
	mov	[childPID],eax

	parent:
	call _displayMessage
	SetCursorPosition 26, 0
	call _getCode
	cmp	al,'q'
	je	theEnd
	cmp	al,'1'
	je 	sec1
	cmp	al,'2'
	je 	sec2
	cmp	al,'3'
	je	sec3
	cmp	al,'4'
	je	sec4

	mov byte [direction], al
	jmp sleep

	sec1:
	mov dword [sec], 1
	mov dword [sec+4], 0
	jmp sleep

	sec2:
	mov dword [sec], 0
	mov dword [sec+4], 500000000
	jmp sleep

	sec3:
	mov dword [sec], 0
	mov dword [sec+4], 333333333
	jmp sleep

	sec4:
	mov dword [sec], 0
	mov dword [sec+4], 250000000
	jmp sleep

	; sleep second
	sleep:
	call _sleep
	call _adjustMessage
	jmp parent

	childProc:
	ReadFile stdin, inputBuffer, LEN
	;; Open a file for communication
	OpenFile 101h  ; for writing
	;;; write  something to  snakeinput.txt
	WriteFile fileDescriptor, inputBuffer, 1
	;;;  close the file
	CloseFile
	jmp childProc

	theEnd:
	ClearScreen
	SetCursorPosition 1, 1
	;;;;;;  Kill the child process
	mov	eax,37
	mov	ebx,[childPID]
	mov	ecx,9  ; kill signal
	int 	80h
	Termination


;;;;;;;;;;;;  Function that shifts row/cols through the array of structs 
;;;;;;;;;;;;  and moves first char one to the left.
_adjustMessage:	
	pusha

	mov	ecx,[pythonLength]
	dec	ecx
	mov	ebx,message+((pythonLength-python)-1)*mStruct.size

_amTop: mov	dx,[ebx - mStruct.size + mStruct.row] 	;; get row above
	mov	[ebx + mStruct.row],dx			;; copy to this row

	mov	dx,[ebx - mStruct.size + mStruct.col] 	;; get col above
	mov	[ebx + mStruct.col],dx			;; copy to this col

	sub	ebx,mStruct.size
	loop	_amTop

	cmp	byte [direction],'w'
	je	North
	cmp	byte [direction],'s'
	je	South
	cmp	byte [direction],'a'
	je	West
	cmp	byte [direction],'d'
	je	East
	
;;;;;;  Adjust first character to move one space up
North:
	cmp	BYTE [ebx + mStruct.row + 1],'0'
	je	carry1
	dec	BYTE [ebx + mStruct.row + 1]		;; move first char to left
	jmp	adjustEnd
;;;;;;  Adjust first character to move one space down
South:
	cmp	BYTE [ebx + mStruct.row + 1],'9'
	je	carry2
	inc	BYTE [ebx + mStruct.row + 1]		;; move first char to left
	jmp	adjustEnd
;;;;;;  Adjust first character to move one space to the right
East:
	cmp	BYTE [ebx + mStruct.col + 1],'9'
	je	carry3
	inc	BYTE [ebx + mStruct.col + 1]		;; move first char to left
	jmp	adjustEnd
;;;;;;  Adjust first character to move one space to the left 
West:
	cmp	BYTE [ebx + mStruct.col + 1],'0'
	je	carry4
	dec	BYTE [ebx + mStruct.col + 1]		;; move first char to left
	jmp	adjustEnd
;Up
carry1:
	dec	BYTE [ebx + mStruct.row]
	mov	BYTE [ebx + mStruct.row + 1],'9'
	jmp	adjustEnd
;Down
carry2:
	inc	BYTE [ebx + mStruct.row]
	mov	BYTE [ebx + mStruct.row + 1],'0'
	jmp	adjustEnd
;Right
carry3:
	inc	BYTE [ebx + mStruct.col]
	mov	BYTE [ebx + mStruct.col + 1],'0'
	jmp	adjustEnd
;Left
carry4:
	dec	BYTE [ebx + mStruct.col]
	mov	BYTE [ebx + mStruct.col + 1],'9'
	jmp	adjustEnd
adjustEnd:
	popa
	ret

;Function to detect for collisions with the * char
;;;;;;;;;;;;  Function to convert int to two digits of ascii
;;;;;;;;;;;;  Pass in int in ax, return two chars in ax
_toAscii:
	push	ebx

        mov     bl,10
        div     bl      ;; puts ax/10 in al, remainder in ah
        add     ah,'0'
        add     al,'0'

	pop	ebx
	ret

;. _setcursor expects AH = row, AL = col
_setCursor:
	pusha
;;; save original to get col later
	push	eax
;;;;;; process row
	shr	ax,8	;; shift row to right
	mov	bl,10
	div	bl	;; puts ax/10 in al, remainder in ah
	add	ah,'0'
	add	al,'0'
	mov	BYTE [row],al
	mov	BYTE [row+1],ah
;;;; process col
	pop	eax	;; restore original parms
	and	ax,0FFh ;; erase row, leave col
	mov	bl,10
	div	bl	;; puts ax/10 in al, remainder in ah
	add	ah,'0'
	add	al,'0'
	mov	BYTE [col],al
	mov	BYTE [col+1],ah

	;;;;; now print the set cursor codes
	mov	eax,4
	mov	ebx,1
	mov 	ecx,pos
	mov	edx,8
	int 	80h

	popa
	ret

;;;;;;;;;;;   Function to print the array of structs of message
_displayMessage:
        pusha
        mov     ebx,message
        mov     ecx,[pythonLength]

_dmTop: push    ecx
        push    ebx
        mov     eax,4  ; system print
        mov     ecx,ebx ; points to string to print
        mov     ebx,1   ; standard out
        mov     edx,9   ; num chars to print
        int     80h

        pop     ebx
        add     ebx,mStruct.size
        pop     ecx
        loop    _dmTop
        popa
        ret

;;;  GetCode - reads file to see what to do - no args passed in, returns char in AL
_getCode:
	OpenFile 0  ; readonly
	ReadFile	fileDescriptor, inputBuffer, 2
	CloseFile
	mov	al, BYTE [inputBuffer]
	ret

;Function to let the program sleep for a second
_sleep:
        pusha
        mov     eax,162
        mov     ebx,sec
        mov     ecx,0
        int     80h
        popa
        ret

SECTION .bss
LEN		equ	1024
inputBuffer	RESB LEN
message:	RESB mStruct.size*(pythonLength-python)
childPID	RESD 1

SECTION .data
; Clear Screen control characters
cls:    db      1bh, '[2J'

stdin:	dd	0
stdout:	dd	1

direction:	db	'a'

fileName:       db      './sahid.txt',0
fileDescriptor: dd      0

sec:	dd 1,0	 ;; struct for sleep on second

offset: db	' '

; Set cursor position control characters
pos:    db      1bh, '['
row:    db      '00'
        db      ';'
col:    db      '00'
        db      'H'

starting:	ISTRUC mStruct
		AT mStruct.esc,  db 1bh,'['
		AT mStruct.row,  db '07'
		AT mStruct.semi, db ';'
		AT mStruct.col,  db '40'
		AT mStruct.H,    db 'H'
		AT mStruct.char, db ' '
		IEND

python:	db	'@********> '
pythonLength:	dd	$-python

;;;;;;; Screen Pattern
screen: db      "********************************************************************************",0ah
        db      "*                          *                           *                       *",0ah
        db      "*      *************       *        *************      *       *********       *",0ah
        db      "*                          *                           *                       *",0ah
        db      "*                          *                           *                       *",0ah
        db      "*                          *                           *                       *",0ah
        db      "*                                                                              *",0ah
        db      "*           **************************        ***********************          *",0ah
        db      "*                                *               *                             *",0ah
        db      "*                                *     ***********                             *",0ah
        db      "*                          *     *               *     *                       *",0ah
        db      "*                          *     **********      *     *                       *",0ah
        db      "*                          *     *               *     *                       *",0ah
        db      "*                          *     *      **********     *                       *",0ah
        db      "*                          *                           *                       *",0ah
        db      "*                                                                              *",0ah
        db      "*           ***   ***   ***   ***   ***   ***   ***   ***   ***   ***          *",0ah
        db      "*                                                                              *",0ah
        db      "*            *     *     *     *     *     *     *     *     *     *           *",0ah
        db      "*               *     *     *     *     *     *     *     *     *              *",0ah
        db      "*            *     *     *     *     *  W  *     *     *     *     *           *",0ah
        db      "*               *     *     *     *     *     *     *     *     *              *",0ah
        db      "*            *     *     *     *     *     *     *     *     *     *           *",0ah
        db      "*               *     *     *     *     *     *     *     *     *              *",0ah
        db      "********************************************************************************",0ah
screenSize:     dd $-screen

win:	db	"********************************************************************************",0ah
	db	"				You Win						 ",0ah
	db	"********************************************************************************",0ah
winSize:	dd $-win

lose:	db	"********************************************************************************",0ah
	db	"				GameOver					 ",0ah
	db	"********************************************************************************",0ah
loseSize:	dd $-lose

