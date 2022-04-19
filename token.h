
typedef struct Token Token;

/* this enum is defined for Token identification*/
enum {
    INT = 256;
    ID = 257;
    TRU = 258;
    FAL =  259;
    FLOAT = 260;
};

Token{
    int id;
    int value;      // if float
    float value;    // if int
    char *str;      // if id  
    Token *next;
};