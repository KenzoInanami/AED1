#include <iostream>
#include "ArvoreBinaria.h"

int main()
{
    arvoreptr arvore = nullptr;
    bool ok;
    int somaFuncao, somaControle;

    //Testando se está vazia
    if(vazia(&arvore))
        printf("Está vazia!\n\n");

    // Inserindo elementos
    insere(&arvore,10,&ok);
    insere(&arvore,5,&ok);
    insere(&arvore,7,&ok);
    insere(&arvore,3,&ok);
    insere(&arvore,1,&ok);
    insere(&arvore,4,&ok);
    insere(&arvore,6,&ok);
    insere(&arvore,9,&ok);
    insere(&arvore,20,&ok);
    insere(&arvore,15,&ok);
    insere(&arvore,17,&ok);
    insere(&arvore,30,&ok);
    insere(&arvore,25,&ok);
    insere(&arvore,40,&ok);

    //Testando se está vazia
    if(vazia(&arvore))
        printf("Está vazia!\n\n");

    // Mostrando elementos da árvore
    imprimirArvore(arvore);

    // Testando função Retira()
    retira(&arvore,5,&ok);
    retira(&arvore,15,&ok);
    retira(&arvore,40,&ok);

    // verificando elementos retirados
    imprimirArvore(arvore);

    // Soma dos elementos da árvore
    somaFuncao = soma(arvore);
    somaControle = 1+3+4+6+7+9+10+17+20+25+30;
    std::cout<<"Soma funcao: "<< somaFuncao<<"\n";
    std::cout<<"Soma manual: "<< somaControle<<"\n";

    // Testando função deletar()
    deleta(&arvore);
    if(vazia(&arvore))
        printf("Esta vazia!\n\n");

    return 0;
}
