#ifndef FILA_H
#define FILA_H
#include<iostream>
using namespace std;

template <class T>
class Fila {

    private:
        T *fila;
        int inicio, fim, tamanho, tamanhoAtual;
    public:
    	Fila(int);
    	~Fila();
        int inserir(T);
        T remover();
        int ordenar();
        int vazia();
        int cheia();
        void imprimir();
         
};

template <class T>
Fila<T>::Fila(int tamanho){
	this->fila = new T[tamanho];
	this->inicio = 0;
	this->fim = 0;
	this->tamanho = tamanho;
	this->tamanhoAtual = 0;
}

template <class T>
Fila<T>::~Fila(){
	delete [] this->fila;
}

template <class T>
int Fila<T>::vazia(){
	if(this->inicio == this->fim)
		return 1;
	return 0;
}

template <class T>
int Fila<T>::cheia(){
	if((this->fim+1)%(this->tamanho) == this->inicio)
		return 1;
	return 0;
}

template <class T>
int Fila<T>::inserir(T elemento){

	if(this->cheia())
		return 0;
	
	this->fim = (this->fim+1)%(this->tamanho);
	this->fila[this->fim].origem = elemento.origem;
	this->fila[this->fim].destino = elemento.destino;
	this->fila[this->fim].peso = elemento.peso;
	this->tamanhoAtual++;

	return 1;
}

template <class T>
T Fila<T>::remover(){
	
	if(!this->vazia()){	
		
		T aux ;//= this->fila[this->inicio];
		aux.destino = this->fila[this->inicio+1].destino;
		aux.origem = this->fila[this->inicio+1].origem;
		aux.peso = this->fila[this->inicio+1].peso;
		this->inicio = (this->inicio+1)%(this->tamanho);
		this->tamanhoAtual--;

		return aux;
	}
}

template <class T>
void Fila<T>::imprimir(){
	
	if(!this->vazia()){	
		
		int i= (this->inicio+1) % this->tamanho;
		while (i != (this->fim+1)%this->tamanho){
		 cout << this->fila[i].origem << " " << this->fila[i].destino << " " << this->fila[i].peso << endl;
		 i = (i+1)%this->tamanho;
	 }
	}
}


template <class T>
int Fila<T>::ordenar(){
	T x;
	int i, j;
	j = this->fim;
	while(j != (this->inicio+1)%this->tamanho){
		for(int i=(this->inicio+1) % this->tamanho; i!= j; i = (i+1)%this->tamanho){
			if(this->fila[(i+1)%this->tamanho] < this->fila[i]){
				x=this->fila[i];
				this->fila[i]=this->fila[(i+1)%this->tamanho];
				this->fila[(i+1)%this->tamanho]=x;
            }
        }
        if(j == 0)
        	j = this->tamanho-1;
        else
			j = j - 1;
    }
	return 1;
}

#endif