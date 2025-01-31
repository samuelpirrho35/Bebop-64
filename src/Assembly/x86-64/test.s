.section .bss
.lcomm buffer, 128

.section .text
.globl _start
.globl read
.globl write

read:
    movq $0, %rax
    movq $0, %rdi
    lea buffer(%rip), %rsi
    movq $128, %rdx
    syscall
    ret

write:
    movq %rax, %rcx
    movq $1, %rax
    movq $1, %rdi
    lea buffer(%rip), %rsi
    movq %rcx, %rdx
    syscal
    ret

_start:
    call read
    call write

    movq $60, %rax
    xor %rdi, %rdi
    syscall
