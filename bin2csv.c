#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int chr;
    
    if (argc < 2) {
        goto error;
    }
    
    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        goto error;
    }
    
    while((chr = fgetc(fp)) != EOF) {
        printf("0x%x",chr & 0x0f);
        printf("%x, ",(chr >> 4) & 0x0f);
    }
    
    fclose(fp);
    
    return 0;
    
error:
    printf("file not open!\n");
    return -1;
}
