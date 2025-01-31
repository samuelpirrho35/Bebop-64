.section .bss
    .lcomm buffer, 1  # Alocação de 1 byte de buffer

.section .text
.globl _start

_start:
    # Loop para limpar o stdin
_clear_stdin:
    movq $0, %rax           # Número da chamada de sistema (sys_read)
    movq $0, %rdi           # fd (0 para stdin)
    lea buffer(%rip), %rsi  # Endereço do buffer
    movq $1, %rdx           # Tamanho do buffer (1 byte)
    syscall                 # Chama sys_read

    testq %rax, %rax        # Verifica se a quantidade de bytes lidos é 0
    jnz _clear_stdin        # Se %rax != 0 (ainda há dados no stdin), repete

    # Quando o stdin estiver vazio, termina o programa
_exit:
    movq $60, %rax          # Número da chamada de sistema (sys_exit)
    xor %rdi, %rdi          # Código de saída 0
    syscall                 # Chama sys_exit
