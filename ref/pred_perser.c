/* This is the reference from a book named "Compiler" A.Eiho */

/*
stmt    ->  expr ;
        |   if ( expr ) stmt;
        |   for( optexpr ; optexpr ; optexpr ) stmt;
        |   other

optexpr ->  epsilon
        |   expr

*/

void match(terminal t){
    if(lookahead == t) lookahead = next;
    else error();
}

void stmt(){
    switch(lookahead){
        case expr:
        match(expr);match(';');break;
        
        case if:
        match(if);match('(');match(expr);match(')');
        stmt();break;

        case for:
        match(for);match('(');optexpr();match(';');
        optexpr();match(';');optexpr();match(')');
        stmt();

        csase other:
        match(other);       
    }
}

void optexpr(){
    if(lookahead == expr) match(expr);
    /*This is just if ,not case because of only two rules */
}

