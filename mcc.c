/*
 *  Copyright (c) 2022 Fuma Suenaga(mirroris on Github)
 *  This software is released under the MIT License, see LICENSE.txt
 */

#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* to indicate which charactor mcc is reading */
char *mark;

//function to report an error
//get the same arguments as printf
void error(char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
    exit(1);
}

Token *headToken, *curToken;

void tokenize(const char str[]){
    char *p= str;
    int line;

    // ignore whitespace and count number of lines 
    while (1){
        if(p=='\t' || p==' ')
        else if(p=='\n') line = line + 1;
        else if()
        else break;
        p++;
    }

    //ここに字句解析

}

 int main(int argc, char** argv){
    if(argc!=2){
        fprintf(stderr,"Incorrect number of arguments");
        exit(1);
    }

    //tokenize
    headToken = tokenize(argv[1]);
    
    //start for assembly 
    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");
    
    //expr starts with a number, so check that number and output it
    printf("    mov rax, %d\n", expect_number());

    // consuming the string like '+ <number> 'or'- <number>'
    // output to assembly
    while(!at_eof()){
        if(consume('+')){
            printf("    add rax, %d\n", expect_number());
            continue;
        }

        expect('-');
        printf("    sub rax, %d\n", expect_number());    
    }

    printf("    ret\n");
    return 0;
 }