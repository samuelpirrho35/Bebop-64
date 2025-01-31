#include <stdio.h>
#include <string.h>

int main(){
    char *vecOfInterruptionMultBytes = "²³£¢¬°´®ŧøþªÆÐŊĦˀĸŁºˇ«»©µ·ç ";
    int len = strlen(vecOfInterruptionMultBytes);

    printf("len: %d\n\n", len);

    

    unsigned short *vec = (unsigned short*) vecOfInterruptionMultBytes;

    for(int i = 0; i < len / 2; i++)
        printf("%4X\n", *(vec + i));

    return 0;
}