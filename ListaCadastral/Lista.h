#ifndef LISTA_H
#define LISTA_H


class Lista
{
    public:
        Lista();
        void insere(int x, bool *ok);
        void retira(int x, bool *ok);
        bool estaNaLista(int x);
        void pegaOPrimeiro(int *x, bool *ok);
        void pegaOProximo(int *x, bool *ok);
        bool vazia();
        bool cheia();

    private:
        struct node{
            int info;
            struct node *next;
        };
        typedef struct node* nodeptr;


        nodeptr primeiro,
                ultimo,
                atual;
};

Lista::Lista()
{
    primeiro = nullptr;
    ultimo = nullptr;
    atual = nullptr;
}

bool Lista::vazia()
{
    if(primeiro == nullptr)
        return true;
    else
        return false;
}

bool Lista::cheia()
{
    //A lista não possui capacidade máxima implementada
    return true;
}

bool Lista::estaNaLista(int x)
{
  /*
  Cria um node pointer que percorre a lista
  e compara o valor de cada nó com o valor x.
  Caso encontre um nó com o mesmo valor de x
  retorna true, caso contrário false.
  */
    if(!vazia())
    {
        nodeptr nodeAux = new node;
        nodeAux = primeiro;

        if(nodeAux->info == x)
            return true;

        while(nodeAux != ultimo)
        {
            nodeAux = nodeAux->next;
            if(nodeAux->info == x)
                return true;
        }

        return false;
    }
    else
        return false;
}

void Lista::insere(int x, bool *ok)
{
  /*
  Caso o valor de x não esteja inserido na lista,
  é criado um node pointer com o valor de x que é colocado
  em primeiro, caso a lista esteja vazia ou colocado "ao lado"
  do ultimo nó e passa a ser referenciado como o ultimo.
  ok -> retorna true caso o elemento seja inserido ou false quando já há
  um elemento de valor x na lista.
  */
    if(estaNaLista(x))
        *ok = false;
    else
    {
        nodeptr nodeAux = new node;
        nodeAux->info = x;

        if(vazia())
        {
            primeiro = nodeAux;
            ultimo = primeiro;
            primeiro->next = ultimo;
        }
        else
        {
            ultimo->next = nodeAux;
            ultimo = nodeAux;
        }
    }
}

void Lista::retira(int x, bool *ok)
{
  /*
  Caso a lista não esteja vazia e o valor x esteja na lista,
  é criado dois node pointers: nodeAtual que aponta para o nó
  sendo comparado no momento; e nodeAnterior que aponta para
  o nó anterior ao nó atual. Para a retirada de um nó da lista
  são identificados 3 casos:
  Caso 1: valor x encontrado no primeiro nó em uma lista com apenas 1 nó.
  Caso 2: valor x encontrado no primeiro nó em uma lista com vários nós.
  Caso 3: valor x encontrado no meio da lista.
  Caso 4: valor x encontrado no fim da lista.
  */
    if(!vazia() && estaNaLista(x))
    {
        nodeptr nodeAtual, nodeAnterior;
        nodeAtual = new node;
        nodeAtual = primeiro;

        if(nodeAtual->info == x)
        { 
            if(ultimo == primeiro)
            {   //Caso 1
                primeiro = nullptr;
                ultimo = nullptr;
            }
            else
            {   //Caso 2
                primeiro = primeiro->next;
            }
            nodeAtual = nullptr;
            *ok = true;
        }
        else
        {
            while(nodeAtual != ultimo)
            {   //Caso 3 e 4
                nodeAnterior = nodeAtual;
                nodeAtual = nodeAtual->next;
                if(nodeAtual->info == x)
                {
                    if(nodeAtual == ultimo) //Caso 4
                        ultimo = nodeAnterior;
                    else //Caso 3
                        nodeAnterior->next = nodeAtual->next;

                    nodeAtual = nullptr;
                    *ok = true;
                    break;
                }
            }
        }
    }
    else
        *ok = false;
}

void Lista::pegaOPrimeiro(int *x, bool *ok)
{
  /*
  Faz com que o node pointer 'atual' aponte para o
  node pointer 'primeiro'.
  ok -> retorna true caso tenha dado certo ou false
        caso a lista esteja vazia.
  */
    if(!vazia())
    {
        atual = primeiro;
        *x = atual->info;
        *ok = true;
    }
    else
        *ok = false;
}

void Lista::pegaOProximo(int *x, bool *ok)
{
  /*
  Caso o node pointer 'atual' não esteja apontando
  para 'ultimo', faz ele apontar para o nó "ao lado".
  Necessita que pegaOPrimeiro() seja executado ao menos
  uma vez antes.
  ok -> retorna true caso tenha dado certo ou false
        caso 'atual' aponte para 'ultimo'.
  */
    if(atual != ultimo){
		atual = atual->next;
		*x = atual->info;
		*ok = true;
	}
	else *ok = false;
}

#endif // LISTA_H
