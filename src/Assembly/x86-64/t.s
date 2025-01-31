.section .bss
.lcomm buffer, 1

.section .text
.globl _start

_start:
	movq $0, %rax
	movq $0, %rdi
	lea  buffer(%rip), %rsi
	movq $1, %rdx
	syscall

	movq %rax, %rcx
	movq $1, %rax
	movq $1, %rdi
	movq %rcx, %rdx
	syscall

	movq $60, %rax
	xor  %rsi, %rsi
	syscall
