
	
section .data
	Hello TIMES 46 db "1"
	Hi:


section .text
	global _start
	
_start:
	
	
	push Hi
	
	mov r8, 0
	mov r10, 46 ;  46 is the length of the data(Stated in Hello)
	jmp Loop
	
	
Loop:
	sub BYTE [Hello+r8], 2  ; The two is the encryption byte, this needs to be changed in Setup.c
	inc r8
	cmp r8, r10
	jl Loop
	jmp Hello
	

