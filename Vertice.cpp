#include"Vertice.h"
#include"Aresta.h"
#include<iostream>
#include<string>

using namespace std;

Vertice::Vertice(){
    this->cor = 'b';
    this->fim = NULL;
    this->inicio = NULL;
    this->numeroArestas = 0;
}

Vertice::~Vertice(){
    //cout << "Destrutor Vertice...\n";
    Aresta *aux = this->inicio;
    Aresta *ant;
    while(aux != NULL){
        ant = aux;
        aux = aux->getProx();
        delete ant;
    }
}

void Vertice::setCor(char c){
    this->cor = c;
}

void Vertice::setFim(Aresta* a){
    this->fim = a;
}

void Vertice::setInicio(Aresta* a){
    this->inicio = a;
}

char Vertice::getCor(){
    return this->cor;
}

Aresta* Vertice::getFim(){
    return this->fim;
}

Aresta* Vertice::getInicio(){
    return this->inicio;
}

Vertice* Vertice::inserirOrdenado(Aresta* nova, int o){
    this->indice = o;
    Aresta* aux = this->inicio;
    Aresta* anterior;
    while(aux != this->fim){
        if(nova->getPeso() > aux->getPeso()){
            anterior = aux;
            aux = aux->getProx();
        }
        else{
            break;
        }
    }
    nova->setProx(aux);
    if(aux == this->inicio){
        this->inicio = nova;
    }
    else {
        anterior->setProx(nova);
        if(anterior == this->fim)
            this->fim = nova;
    }
    this->numeroArestas++;
    return this;
}
Vertice* Vertice::inserirInicio(Aresta* nova){
    if(this->inicio == NULL){
        this->inicio = nova;
        this->fim = nova;
    }
    else{
        nova->setProx(this->inicio);
        this->inicio = nova;
    }
    this->numeroArestas++;
    return this;
}

Aresta* Vertice::getAresta(int n){
    if(n > this->numeroArestas)
        throw string("Indice inexistente "); 
    int i = 0;
    Aresta* aux = this->inicio;
    while(i < n){
        aux = aux->getProx();
        i++;
    }
    if(aux == NULL)
        throw string("Aresta NULL ");
    return aux;
}

int Vertice::getNumeroArestas(){
	return this->numeroArestas;
}

int Vertice::getIndice(){
	return this->indice;
}

ostream& operator<<(ostream& saida, Vertice& v)  
{  
    v.getInicio()->imprime();
    return saida;  
} 