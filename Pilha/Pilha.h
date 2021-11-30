#ifndef PILHA_H
#define PILHA_H


class Pilha
{
    public:
        Pilha();

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

        nodeptr topo;
        int nElementos;
        int maximo;
};

Pilha::Pilha()
{
    topo = nullptr;
    nElementos = 0;
    maximo = 8;
}

bool Pilha::cheia()
{
    /*
	A capacidade maxima eh definida por 'maximo'
	Pilha cheia -> true
	Pilha não cheia -> false
	*/
	bool estaCheia;

	if(nElementos == maximo)
		estaCheia = true;
	else
        estaCheia = false;

	return estaCheia;
}

bool Pilha::vazia()
{
    /*
    Pilha vazia -> true
    Pilha com elementos -> false
    */
	bool estaVazia;

	if(nElementos == 0)
		estaVazia = true;
	else
        estaVazia = false;

	return estaVazia;
}

void Pilha::insere(int x, bool *ok)
{
    /*
    Cria um nó auxiliar que recebe o elemento
    a ser inserido e coloca ele no topo da pilha.
    A variável ok retornará true caso o elemento
    tenha sido inserido, ou false caso a pilha
    esteja cheia.
    */
    if(cheia())
		*ok = false;
	else{
		nodeptr nodeAux = new node;
		nodeAux->info = x;
		nodeAux->next = topo;
		topo = nodeAux;
		nElementos++;
		*ok = true;
	}
}

void Pilha::retira(int *x, bool *ok)
{
    /*
    Retorna o elemento do topo da pilha
    pela variável x, torna o próximo nó
    o topo da pilha e deleta o topo anterior
    */
    if(vazia())
		*ok = false;
	else{
		nodeptr nodeAux = new node;
		*x = topo->info;
		nodeAux = topo;
		topo = topo->next;
		nElementos--;
		nodeAux = nullptr;
		*ok = true;
	}
}

#endif // PILHA_H
