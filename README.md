Trabalho prático 2 da disciplina de Algoritmos I

O trabalho proposto consistia em desenvolver um sistema computacional capaz de resolver o
problema de escolher o menor número de caminhos para ligar todos os pontos turísticos de
uma dada cidade, de modo que o custo de construção desses caminhos propostos fosse o
menor possível, e ao mesmo tempo optando por aquela configuração cuja atratividade
acumulada fosse a maior possível, ou seja, sempre que dois caminhos tivessem custos iguais
e um deles devesse ser escolhido, deveria-se optar por aquele cuja soma dos valores turísticos
de cada ponto sendo ligado fosse maior.
Desse modo, a modelagem mais simples e adequada para a resolução foi por meio de um
grafo para representação da cidade, no qual os vértices representavam os pontos turísticos e
as arestas os caminhos entre um ponto e outro. Como cada caminho possuía um custo, ou
seja, um peso para aresta e cada ponto turístico um valor turístico, essas informações foram
também armazenadas. Após estabelecidas as devidas ligações entre os pontos com os
possíveis caminhos e seus pesos, bastou transformar esse grafo em uma árvore geradora
mínima, ou Minimum Spanning Tree(MST), por meio do algoritmo de Prim realizando as
modificações necessárias. A principal diz respeito a considerar a maior atratividade dentre
caminhos como um fator de desempate na escolha da aresta quando duas ou mais arestas
possuem o menor peso.