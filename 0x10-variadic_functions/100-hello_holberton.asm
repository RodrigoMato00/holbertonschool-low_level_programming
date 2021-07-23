global main
main:
	section .text
	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, msglen
	syscall

	mov rax, 60
	mov rdi, 0;
	syscall

section .data
	msg: db "Hello, Holbeton", 10
	msglen:	 equ $ - msg
