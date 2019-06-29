#include"Aresta.h"
#include<iostream>
#include<stdio.h>

using namespace std;

Aresta::Aresta(double p, int c){
    this->chegada = c;
    this->peso = p;
    this->prox = NULL;
}

Aresta::~Aresta(){
    //cout << "Destrutor Aresta...\n";
}

Aresta::Aresta(){
    this->peso = -1;
    this->prox = NULL;
}

void Aresta::setPeso(double p){
    this->peso = p;
}

void Aresta::setProx(Aresta* a){
    this->prox = a;
}

double Aresta::getPeso(){
    return this->peso;
}

int Aresta::getChegada(){
    return this->chegada;
}

Aresta* Aresta::getProx(){
    return this->prox;
}

void Aresta::imprime(){
    Aresta *aux = this;
    int c = 1;
    while(aux != NULL){
        if(c%5 == 0){
            printf("\n\t");
        }
        c++;
        printf("-> [%03d|%.15lf]",aux->chegada+1,aux->peso);
        aux = aux->prox;
    }
    cout << "-> NULL";
}