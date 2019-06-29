#ifndef GRAFO_H
#define GRAFO_H
#include"Vertice.h"
#include"Aresta.h"

typedef struct sPrim{
	int pai;
	double peso;
}prim;

typedef struct aresta{
	int origem, destino;
	double peso;
	const bool operator<(const aresta &obj)const {
		return (peso < obj.peso);
	}
}aresta;



class Grafo {
    private:
        int numeroVertices;
        Vertice *list;
        prim *arvorePrim;
        int existeBranco();
        int linhaVazia(int);
        void setVerticesBrancos();
        void resetArvorePrim();
    public:
        Grafo(int);
        ~Grafo();

        void imprimirGrafo();
        void inserirAresta(int, int, double);

        Vertice* getList();

        void setPrim(int);
        prim* getPrim();

};
#endif