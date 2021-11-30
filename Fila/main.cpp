#include <iostream>
#include "Fila.h"

int main()
{
    Fila fila;
    bool ok;
    int x = 0;

    while(!fila.cheia())
    {
        fila.insere(x,&ok);
        x++;
    }

    while(!fila.vazia())
    {
        fila.retira(&x,&ok);
        if(ok)
            std::cout<<x<<"\n";
    }

    return 0;
}
