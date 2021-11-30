#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

struct arvore
{
  int info;
  struct arvore *dir;
  struct arvore *esq;
};
typedef struct arvore* arvoreptr;

bool vazia(arvoreptr *raiz)
{
  /*
  Retorna true caso raiz não tenha sido declarada,
  false caso o contrário
  */
  if( *raiz == nullptr )
    return true;
  else
    return false;
}

bool estaNaArvore(arvoreptr *raiz, int x)
{ 
  /* 
  Verifica se o valor x está na árvore de raiz R, retornando true para o
  caso de x estar na árvore, e false para o caso de não estar.
  */
  if(!vazia(&(*raiz)))
  {
    if(x == (*raiz)->info)
        return true;
    else
    {
      if(x > (*raiz)->info)
        return estaNaArvore(&(*raiz)->dir, x);
      else
        return estaNaArvore(&(*raiz)->esq, x);
    }
  }
  else
    return false;
}

void insere(arvoreptr *raiz, int x, bool *ok)
{ 
  /* 
  Insere o valor x em 'raiz' como um nó terminal, sem filhos. 
  ok -> retorna true para o caso de X ter sido inserido, e false caso contrário. 
  */
  arvoreptr raizAux = nullptr;
  if(vazia(&(*raiz)))
  {
    raizAux = new struct arvore;
    raizAux->info = x;
    raizAux->dir = nullptr;
    raizAux->esq = nullptr;
    *raiz = raizAux;
    raizAux = nullptr;
    *ok = true;
    return;
  }
  else
  {
    if (estaNaArvore(&(*raiz),x))
        *ok = false;
    else
    {
        if ((*raiz)->info > x)
            insere(&(*raiz)->esq, x , ok);
        else
            insere(&(*raiz)->dir, x, ok);
    }
  }
}

void retira(arvoreptr *raiz, int x, bool *ok)
{ 
  /* 
  Remove o nó de valor x de 'raiz'. 
  ok -> retorna true para o caso de X ter sido encontrado e removido,
        false caso o contrário. 
  */
  if(vazia(&(*raiz)))
    *ok = false;
  else
  {
    if((*raiz)->info > x)
        retira(&(*raiz)->esq,x,ok);
    if((*raiz)->info < x)
        retira(&(*raiz)->dir,x,ok);
    if((*raiz)->info == x){
      *ok = true;
      if((*raiz)->dir == nullptr && (*raiz)->esq == nullptr)
        *raiz = nullptr;
      else
      {
        if((*raiz)->dir == nullptr && (*raiz)->esq != nullptr)
            (*raiz) = (*raiz)->esq;
        if((*raiz)->dir != nullptr && (*raiz)->esq == nullptr)
            (*raiz) = (*raiz)->dir;
        if((*raiz)->dir != nullptr && (*raiz)->esq != nullptr)
        {
            arvoreptr raizAux;
            raizAux = new struct arvore;
            raizAux = *raiz;
            raizAux = raizAux->esq;

            while(raizAux->dir != nullptr){
              raizAux = raizAux->dir;
            }

            (*raiz)->info = raizAux->info;
            retira(&(*raiz)->esq,(*raiz)->info,ok);
        }
      }
    }
  }
}

void deleta(arvoreptr *raiz)
{ 
  /* Apaga todos os nós da árvore e deixa vazia. */
  if(!vazia(&(*raiz))){
    deleta(&(*raiz)->esq);
    deleta(&(*raiz)->dir);
    free(*raiz);
    *raiz = nullptr;
  }
}

void imprimirArvore(arvoreptr raiz)
{ 
  /* Imprime todos os elementos da arvore em ordem crescente */
  if( !vazia(&raiz) ){
    imprimirArvore(raiz->esq);
    std::cout<<raiz->info<<"\n";
    imprimirArvore(raiz->dir);
  }
}

int soma(arvoreptr raiz)
{ 
  /* Retorna a soma do valor dos elementos de R */
  if(raiz == nullptr)
    return 0;
  else
    return raiz->info + soma(raiz->esq) + soma(raiz->dir);
}

#endif // ARVOREBINARIA_H
