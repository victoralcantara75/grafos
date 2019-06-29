#ifndef ARESTA_H
#define ARESTA_H
class Aresta {
    private:
        int chegada;
        double peso;
        Aresta *prox;
    public:
         Aresta(double, int);
         Aresta();
         virtual ~Aresta();

         void setPeso(double);
         void setProx(Aresta*);

         double getPeso();
         int getChegada();
         Aresta* getProx();

         void imprime();
         
};
#endif