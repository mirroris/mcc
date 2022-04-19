
typedef struct Token Token;

/* this enum is defined for Token identification*/
enum {
    INT = 256,
    ID = 257,
    TRU = 258,
    FAL =  259,
    FLOAT = 260
};

struct Token{
    int id;
    int value;      // if float
    float fvalue;    // if int
    char str[256];      // if id  
    Token *next;
};

int main(){
    return 0;
}