#include<iostream>
#include<stdio.h>
#include"Grafo.h"
#include"Aresta.h"
#include<string>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#define TAMANHO 150

using namespace std;

void lerArquivo(Grafo *g,const char *nome_arquivo){
    try {
        int origem, destino;
        double peso;
        FILE *arquivo = fopen(nome_arquivo, "r");
        if(nome_arquivo == NULL)
            throw string("Problemas na LEITURA do arquivo");
        while(!feof(arquivo)) {
            fscanf(arquivo, "%d %d %lf", &origem, &destino, &peso);
            if(peso > 0)
                g->inserirAresta(origem-1,destino-1,peso);
        }
        fclose(arquivo);
         if(!fclose(arquivo))
            throw string("Problemas no FECHAMENTO do arquivo");
    } catch (string s){
        cout << s << endl;
    }
}

int main(){
    Grafo *grafo = new Grafo(TAMANHO);

    prim *arvore;

    int k, vertice_inicial;

     lerArquivo(grafo, "dados.txt");

    grafo->imprimirGrafo();

	cout << "DIGITE O VÉRTICE INICIAL PARA A ÁRVORE DE PRIM: ";
    cin >> vertice_inicial;

    grafo->setPrim(vertice_inicial-1);
    arvore = grafo->getPrim();
    cout << "=====ARVORE DE PRIM NO VÉRTICE " << vertice_inicial << "=====" << endl;
    cout << "[DESTINO - PAI - PESO]" << endl;
    for(int i =0; i<TAMANHO; i++){
        if(arvore[i].pai == -1 && arvore[i].peso == 0){
            cout << i+1 << " - VÉRTICE INICIAL DA ARVORE"  << endl;
        }else{
            cout << setprecision(15) << i+1 << " " << arvore[i].pai+1 << " " << arvore[i].peso << endl;
        }
    }
	
	
    delete grafo;
    
    return 0;
}