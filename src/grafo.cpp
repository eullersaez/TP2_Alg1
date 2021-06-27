#include "headers/grafo.h"
#include <iostream>

Grafo::Grafo(int _numero_vertices){                                     //construtor.
    this->numero_vertices = _numero_vertices;                           //recebe-se o numero de vertices do grafo e atribui-se 0 para o custo minimo e a atratividade agregada inicialmente.

    atratividade_agregada = 0;
    custo_minimo = 0;
    
    matriz_adjacencia = new int*[_numero_vertices];                     //alocacao de memoria para a matriz de adjacencia e setando todas posicoes = -1 inicialmente.
    for (int i = 0; i < _numero_vertices; ++i){
        matriz_adjacencia[i] = new int[_numero_vertices];
    }
    for(int i = 0; i < _numero_vertices; i++){
        for (int j = 0; j < _numero_vertices; j++){
            matriz_adjacencia[i][j] = -1;
        }  
    }

    matriz_adjacencia_MST = new int*[_numero_vertices];                  //alocacao de memoria para a matriz de adjacencia MST e setando todas posicoes = -1 inicialmente.
    for (int i = 0; i < _numero_vertices; ++i){
        matriz_adjacencia_MST[i] = new int[_numero_vertices];
    }
    for(int i = 0; i < _numero_vertices; i++){
        for (int j = 0; j < _numero_vertices; j++){
            matriz_adjacencia_MST[i][j] = -1;
        }  
    }
    
    valor_turistico = new int[_numero_vertices];                          //alocacao de memoria para o vetor de valores turisticos de cada ponto.
    
    quantidade_trechos = new int[_numero_vertices];                       //alocacao de memoria para o vetor que armazena a quantidade de trechos de cada ponto e setando todas posicoes = 0
    for(int i = 0; i < _numero_vertices; i++){                            //inicialmente.
        quantidade_trechos[i] = 0;
    }
    
}


void Grafo::set_valor_turistico(int vertice, int _valor_turistico){       //metodo setter, recebe um valor turistico e um vertice, armazena seu valor na posicao vertice do vetor de valor
    valor_turistico[vertice] = _valor_turistico;                          //turistico.
}


void Grafo::adiciona_aresta(int ponto_i, int ponto_j, int custo){         //metodo adiciona uma aresta na matriz de adjacencia inicial que representa o grafo ao colocar o custo do caminho na 
    matriz_adjacencia[ponto_i][ponto_j] = custo;                          //posicao [i][j] e [j][i] (toda posicao com valor > 0 indica presenca de uma aresta, no caso com o custo).
    matriz_adjacencia[ponto_j][ponto_i] = custo;
}


void Grafo::prim(){
    int numero_arestas = 0;                                               //numero de arestas inicialmente adicionadas ao cutset

    bool selecionados[numero_vertices];                                    //vetor para manter o controle de vertices que ja foram selecionados.


    for(int i = 0; i < numero_vertices; i++){                             //inicializando o vetor de vertices selecionados em todas posicoes como falsas.
          selecionados[i] = false;
    }

    selecionados[0] = true;                                               //marcando o vertice de posicao 0 como selecionado inicialmente.

    int linha, coluna;
    
    while (numero_arestas < numero_vertices - 1) {                        //enquanto o numero de arestas for menor do que o numero de vertices - 1, a MST nao esta completa.

        int min = 999999999;                                              //atribuindo valor alto (infinito) inicialmente a variavel para achar e manter controle do menor peso(custo) de aresta.
        int atratividade_temp = 0;                                        //variavel que armazena em cada iteracao o valor da atratividade da aresta atual.
        int atrat = 0;                                                    //variavel para manter controle da maior atratividade ate entao, inicialmente inicializada como 0 (oposto da min, so que para atratividade).

        linha = 0;
        coluna = 0;

        for (int i = 0; i < numero_vertices; i++) {                       //percorrendo a matriz para selecionar a aresta ideal para se ligar ao vertice atual.
            if (selecionados[i]) {                                        //vertice atual se encontra dentro do vetor de selecionados, o cutset, e portanto pode-se buscar a aresta ideal para
                for (int j = 0; j < numero_vertices; j++) {               //se ligar a ele na MST.
                        atratividade_temp = valor_turistico[i] + valor_turistico[j];    //calculo da atratividade da aresta (caminho) ao somar os valores turisticos de cada ponto.
                    if (!selecionados[j] && matriz_adjacencia[i][j] >= 0) {             //checando se vertice ainda nao pertence ao cutset e existe aresta ligando o ponto i ao j.
                        if (min > matriz_adjacencia[i][j] || atrat < atratividade_temp && min == matriz_adjacencia[i][j]){  //caso aresta atual tenha peso(custo) menor ou peso igual porem atratividade maior do que
                            min = matriz_adjacencia[i][j];                                                                  //as que se sabem ate agora, ela passa a ser a aresta candidata a entrar para MST.
                            atrat = atratividade_temp;
                            linha = i;
                            coluna = j;
                        }
                     }
                }
            }
        }
        quantidade_trechos[linha]++;                                                //incrementa-se o numero de vezes em que uma aresta incidiu/saiu no ponto.
        quantidade_trechos[coluna]++;
        matriz_adjacencia_MST[linha][coluna] = matriz_adjacencia[linha][coluna];    //matriz de adjacencia da MST recebe a aresta adequada com o peso(custo) advinda do grafo incial.
        custo_minimo = custo_minimo + matriz_adjacencia[linha][coluna];             //custo minimo eh somado ao peso(custo) da aresta que acabou de ser adicionada na MST.
        selecionados[coluna] = true;                                                //marca-se o vertice ligado pela aresta selecionada como selecionado no vetor de selecionados.
        numero_arestas++;                                                           //incrementa-se o numero de arestas pertencentes ao cutset.
    }
    calcula_atratividade_agregada();                                                //chama o metodo para calcular a atratividade agregada apos gerada a MST.
}


void Grafo::calcula_atratividade_agregada(){                               //calcula a atratividade agregada multiplicando o valor turistico de cada ponto pela quantidade de vezes em que um
    for (int i = 0; i < numero_vertices; i++){                             //caminho incide/sai dele na MST.
        atratividade_agregada = atratividade_agregada + valor_turistico[i]*quantidade_trechos[i];
    } 
}


void Grafo::imprime_saida(){                                                //imprime a saida conforme a especificacao.
    std::cout<<custo_minimo<<" "<<atratividade_agregada<<std::endl;         
    for (int i = 0; i < numero_vertices; i++){
        std::cout<<quantidade_trechos[i]<<" ";
    }

    std::cout<<std::endl;

    for(int i = 0; i < numero_vertices; i++){                               //impressao dos caminhos resultantes apos gerada a MST.
        for (int j = 0; j < numero_vertices; j++){
            if (matriz_adjacencia_MST[i][j]>=0){
                std::cout<<i<<" "<<j<<" "<<matriz_adjacencia_MST[i][j]<<std::endl;
                matriz_adjacencia_MST[j][i] = -1;                           //marcando como -1 a posicao [j][i] apos impresso a posicao [i][j] para evitar duplicatas.
            }
        }
    }
}