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

typedef enum {
    TK_RESERVED,    //  nonterminalsynbol
    TK_NUM,         // integer token
    TK_EOF,         // end of a token
}   TokenKind;

typedef enum{
    intType,
    charType,
    boolType
}Type;

typedef struct Token Token;
struct Token {
    TokenKind kind; //type of a token
    Token *next;    //next token
    int val;        //value (if kind == TK_NUM)
    char *str;      //token string
};

typedef struct SymbolTable SymTab;
typedef struct SymbolTable{
    char *name;
    Type type;
    int val; /*if string, it means the length*/
    char *str;
    SymTab *next;
}table;

SymTab* Symhead = NULL; 

SymTab* searchSymbol(char *name){
    SymTab *p = Symhead;
    while(p){
        if(strcmp(p->name,name)==0) break;
        p = p->next;
    }

    /* if any symbol doesn't match the name */
    if(p == NULL) error("Undefined error %s in line()",name);
    else return p;
}

SymTab* valOfSymbol(char *name){
    SymTab *p = searchSymbol(name);
    /*
     *  specify a TYPE of an argument
    */
    switch(p->type){
        case intType: 
        break;
        case charType:
        break;
        case boolType:
        break;
    }
}





SymTab* pushSymbol(){

}

//current token
Token *token;



bool consume(char op){
    if(token->kind != TK_RESERVED || token->str[0] != op)
        return false;
    token = token->next;
    return true;
}

void expect(char op) {
    if(token->kind != TK_RESERVED || token->str[0] != op)
        error("Isnot '%c'",op);
    token = token->next;
}

int expect_number() {
    if(token->kind != TK_NUM)
        error("Isnot number");
    int val = token->val;
    token = token->next;
    return val;
}

bool at_eof() {
    return token->kind == TK_EOF;
}

// creating a new token and connecting cur
Token *new_token(TokenKind kind, Token *cur, char *str) {
    Token *tok = calloc(1,sizeof(Token));
    tok->kind = kind;
    tok->str = str;
    cur->next = tok;
    return tok; 
}

Token *tokenize(char *p) {
    Token head;
    head.next = NULL;
    Token *cur = &head;

    while (*p) {
        if(isspace(*p)){
            p++;
            continue;
        }

        if(*p == '+' || *p == '-') {
            cur = new_token(TK_RESERVED, cur, p++);
            continue;
        }

        if(isdigit(*p)) {
            cur = new_token(TK_NUM, cur, p);
            cur->val = strtol(p, &p, 10);
            continue;
        }

        error("failed to tokenize!");
    }

    new_token(TK_EOF, cur, p);
    return head.next;
}
 int main(int argc, char** argv){
    if(argc!=2){
        fprintf(stderr,"Incorrect number of arguments");
        exit(1);
    }

    //tokenize
    token = tokenize(argv[1]);
    
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