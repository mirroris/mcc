/*
 *  Copyright (c) 2022 Fuma Suenaga(mirroris on Github)
 *  This software is released under the MIT License, see LICENSE.txt
 */

 #include <stdio.h>
 #include <stdlib.h>

 int main(int argc, char** argv){
    if(argc!=2){
        fprintf(stderr,"Incorrect number of arguments");
        exit(1);
    }

    char *p = argv[1];
    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");
    printf("    mov rax, %ld\n", strtol(p,&p,10));

    while(*p){
        if(*p == '+'){
            p++;
            printf("    add rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        if(*p == '-'){
            p++;
            printf("    sub rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        fprintf(stderr,"unexpected number: '%c'\n",*p);
        
    }

    printf("    ret\n");
    return 0;
 }