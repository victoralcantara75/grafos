#include"Grafo.h"
#include"Vertice.h"
#include"Aresta.h"
#include<iostream>
#include<string>
#include"Fila.cpp"

using namespace std;

Grafo::Grafo(int v){
    if(v > 0){
        this->numeroVertices = v;
        this->list = new Vertice[v];
        this->arvorePrim = new prim[v];
        this->resetArvorePrim();
    }
    else {
        this->numeroVertices = 0;
        this->list = NULL;
        this->arvorePrim = NULL;
    }
}

Grafo::~Grafo(){
    //cout << "Destrutor Grafo...\n";
    delete [] this->list;
    delete [] this->arvorePrim;
}

int Grafo::linhaVazia(int l){
    return (this->list[l].getInicio() == NULL);
}

void Grafo::inserirAresta(int s, int c, double p){
    if(s != c){
        Aresta *nova = new Aresta(p,c);
        this->list[s].inserirOrdenado(nova,s);
    }
}

Vertice* Grafo::getList(){
    return this->list;
}

void Grafo::imprimirGrafo(){
    cout << "[Origem] -> [Destino|Peso]" << endl;
    for(int i = 0; i < this->numeroVertices; i++){
        cout << "[" << i+1 << "]";
        this->list[i].getInicio()->imprime();
        cout << endl << endl;
    }
}

int Grafo::existeBranco(){
    for(int i = 0; i < this->numeroVertices; i++) {
        if(this->list[i].getCor() == 'b')
            return 1;
    }
    return 0;
}

void Grafo::setVerticesBrancos(){
    for(int i = 0; i < this->numeroVertices; i++) {
        this->list[i].setCor('b');
    }
}

void Grafo::resetArvorePrim(){
	for(int i = 0; i < this->numeroVertices; i++){
		this->arvorePrim[i].pai = -1;
		this->arvorePrim[i].peso = 10;
	}
}

void Grafo::setPrim(int vertice_inicial){
	this->setVerticesBrancos();
	this->resetArvorePrim();
	
	Fila <aresta> Q(2*this->numeroVertices);
	aresta arestas, menorPeso;
	int verticeAtual = vertice_inicial;
	Aresta *aux;
	
	this->arvorePrim[vertice_inicial].peso = 0;
	
	while(this->existeBranco())
	{
		//INSERE FILHOS NA LISTA
		for(int i=0; i<this->list[verticeAtual].getNumeroArestas(); i++){
			aux = this->list[verticeAtual].getAresta(i);
			
			arestas.origem = verticeAtual;
			arestas.destino = aux->getChegada();
			arestas.peso = aux->getPeso();
			
			if(this->list[arestas.destino].getCor() != 'p'){
				Q.inserir(arestas);
			}
		}
		Q.ordenar();

		//REMOVE FILHOS AINDA NAO VISITADOS
		do{
			menorPeso = Q.remover();
		}while((this->list[menorPeso.destino].getCor() == 'p' || menorPeso.destino == verticeAtual));
		
		this->arvorePrim[menorPeso.destino].pai = menorPeso.origem;
		this->arvorePrim[menorPeso.destino].peso = menorPeso.peso;
		this->list[verticeAtual].setCor('p');
		this->list[menorPeso.destino].setCor('c');
				
		verticeAtual = menorPeso.destino;
		
	}
}

prim* Grafo::getPrim(){
    return this->arvorePrim;
}