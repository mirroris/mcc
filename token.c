#include<string.h>
typedef struct Token Token;

/* this enum is defined for Token identification*/
enum {
    INT = 256,
    ID = 257,
    TRU = 258,
    FAL =  259,
    FLOAT = 260,
    FOR = 261,
    WHILE = 262,
    IF = 263,
    DEF = 264
};

struct Token{
    int id;
    int value;      // if float
    float fvalue;    // if int
    char str[256];      // if id  
    Token *next;
};


void tokenize(char *buf){
    char *peek=buf;
    int line=0;
    
    /* skip until not whitespace and count the number of lines*/
    for(;;peek++){
        if((*peek=='\t') || (*peek==' ')) ;
        else if(*peek=='\n') line++;
        else break;
    }

    /* tokenization here */

    /* number to integer*/
    if((*peek>=30) && (*peek<=39)){ //if *peek have number
        int v =0;
        do{
            v=10*v+atoi(*peek);
            peek++;
        } while((*peek>=30) && (*peek<=39))
    }

    return;
}

int main(){
    return 0;
}