#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

void set_raw_mode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ICANON | ECHO);    // Desativa o modo canônico e o echo
    raw.c_cc[VMIN] = 1;                 // Lê um caractere por vez
    raw.c_cc[VTIME] = 0;                // Não espera por tempo
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void reset_terminal_mode() {
    struct termios normal;
    tcgetattr(STDIN_FILENO, &normal);
    normal.c_lflag |= (ICANON | ECHO);  // Restaura o modo canônico e o echo
    tcsetattr(STDIN_FILENO, TCSANOW, &normal);
}

int main() {
    set_raw_mode(); // Ativa o modo raw

    char c;
    while (1) {
        c = getc(stdin);
        printf("Você pressionou: %c\n", c);
        if (c == 'q') break; // Encerra o programa ao pressionar 'q'
    }

    reset_terminal_mode(); // Restaura o terminal para o modo normal
    return 0;
}
