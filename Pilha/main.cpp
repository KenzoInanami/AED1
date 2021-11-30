#include <iostream>
#include "Pilha.h"

int main()
{
    Pilha pilha;
    bool ok;
    int x = 0;

    while(!pilha.cheia())
    {
        pilha.insere(x,&ok);
        x++;
    }

    while(!pilha.vazia())
    {
        pilha.retira(&x,&ok);
        if(ok)
            std::cout<<x<<"\n";
    }

    return 0;
}
