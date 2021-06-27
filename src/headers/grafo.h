#ifndef GRAFO_H
#define GRAFO_H

class Grafo{
    private:
        int numero_vertices;
        int atratividade_agregada, custo_minimo;
        int* valor_turistico;                       //vetor para armazenar o valor turistico de cada ponto.
        int* quantidade_trechos;                    //vetor para armazenar quantas vezes uma aresta sai/incide em cada ponto apos gerada a MST.
        int** matriz_adjacencia;                    //matriz para armazenar quando existe uma aresta de um ponto i para um ponto j inicialmente, antes de gerar a MST.
        int** matriz_adjacencia_MST;                //matriz para armazenar quando existe uma aresta de um ponto i para um ponto j, depois de gerar a MST.
        
    public:
        Grafo(int );                                //construtor.
        void set_valor_turistico(int , int );       //setter para valor turistico de cada ponto.
        void adiciona_aresta(int, int , int );      //metodo para adicionar uma aresta de um ponto i para um ponto j e atribuir o custo desse caminho.
        void calcula_atratividade_agregada();       //metodo que calcula a atratividade agregada e altera o valor deste atributo, apos gerada a MST.
        void imprime_saida();                       //metodo para impressao da saida conforme a especificacao.
        void prim();                                //metodo que gera a MST conforme a especificacao.

};

#endif