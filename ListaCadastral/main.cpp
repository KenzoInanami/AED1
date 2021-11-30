#include <iostream>
#include "Lista.h"

int main()
{
    Lista lista;
    bool ok;
    int x = 0;

    for(int i=0; i<10; i++)
    {
        lista.insere(x,&ok);
        x++;
    }

    lista.pegaOPrimeiro(&x,&ok);
    while(ok)
    {
        std::cout<<x<<"\n";
        lista.pegaOProximo(&x,&ok);
    }

    return 0;
}
