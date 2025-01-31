.section .text
.globl wrt

wrt:
	movq $1, %rax
	syscall
	ret
