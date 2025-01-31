.section .text
.globl rd

rd:
	movq $0, %rax
	syscall
	ret
