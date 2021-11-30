#ifndef FILA_H
#define FILA_H


class Fila
{
    public:
        Fila();
        void insere(int x, bool *ok);
        void retira(int *x, bool *ok);
        bool cheia();
        bool vazia();

    private:
        struct node{
            int info;
            struct node *next;
        };
        typedef struct node* nodeptr;

        nodeptr primeiro, ultimo;
        int nElementos;
        int maximo;
};

Fila::Fila()
{
    primeiro = nullptr;
    ultimo = nullptr;
    nElementos = 0;
    maximo = 8;
}

bool Fila::cheia()
{
  /*
  Retorna true caso a fila tenha chego a quantidade
  máxima de nós ou false quando ainda não ter chego.
  */
    if(nElementos == maximo)
        return true;
    else
        return false;
}

bool Fila::vazia()
{
  /*
  Retorna true caso nenhum elemento tenha sido inserido na fila,
  false caso o contrário.
  */
    if(nElementos == 0)
        return true;
    else
        return false;
}

void Fila::insere(int x, bool *ok)
{
  /*
  Caso a fila não esteja cheia, é verificado se
  a fila está vazia. Caso esteja, declara o nó
  primeiro, insere o valor x nele e aponta o nó
  ultimo para o nó primeiro; caso o contrário,
  é declarado um novo nó nodeAux, x é inserido nele
  e o nó é colocado "ao lado" do nó ultimo.
  nElementos -> é acrecido de 1 a cada inserção.
  ok -> retorna true caso o valor tenha sido inserido,
        false caso o contrário.
  */
    if(cheia())
        *ok = false;
    else{
        if(vazia()){
            primeiro = new node;
            primeiro->info = x;
            primeiro->next = ultimo;
            ultimo = primeiro;
            nElementos++;
        }
        else{
            nodeptr nodeAux = new node;

            nodeAux->info = x;
            ultimo->next = nodeAux;
            ultimo = nodeAux;
            nElementos++;
        }
        *ok = true;
    }
}

void Fila::retira(int *x, bool *ok)
{
  /*
  Caso a lista não esteja vazia, retorna o elemento 
  do nó primeiro pelo pointer x.
  Para retirar o elemento é declarado um novo nó
  nodeAux que apontará para o nó primeiro, x irá
  receber o valor de nodeAux, o pointer primeiro
  passará a apontar para o nó "ao lado" e o antigo
  nó primeiro passa a ser apagado.
  nElementos -> decrescido a cada retirada bem sucedida.
  ok -> retorna true caso tenha retirado um elemento ou
        false caso a fila esteja vazia.
  */
    if(vazia())
        *ok = false;
    else
    {
        nodeptr nodeAux = new node;

        nodeAux = primeiro;
        *x = nodeAux->info;
        primeiro = primeiro->next;
        nodeAux = nullptr;
        nElementos--;
        *ok = true;
    }
}


#endif // FILA_H
