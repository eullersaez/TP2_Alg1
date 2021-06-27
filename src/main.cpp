#include <iostream>
#include "headers/grafo.h"

int main(){
    int numero_pontos, numero_trechos, valor_turistico, ponto_i, ponto_j, custo;
    std::cin>>numero_pontos>>numero_trechos;                                        //leitura inicial do numero de postos(vertices) e de trechos(arestas) da cidade.
    
    Grafo cidade(numero_pontos);                                                    
    
    for(int i = 0; i < numero_pontos; i++){                                         //leitura e atribuicao do valor turistico de cada ponto.
        std::cin>>valor_turistico;
        cidade.set_valor_turistico(i, valor_turistico);
    }
    
    for(int i = 0; i < numero_trechos; i++){                                        //leitura e atribuicao de cada caminho entre dois pontos, com seu custo.
        std::cin>>ponto_i>>ponto_j>>custo;
        cidade.adiciona_aresta(ponto_i,ponto_j,custo);
    }
    
    cidade.prim();                                                                  //chamada do metodo prim para achar a MST de acordo com a especificacao.
    cidade.imprime_saida();                                                         //chamada do metodo para impressao da saida formatada de acordo com a especificacao.
   
    return 0;
}