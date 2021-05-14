#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
class Grafo {
private:
    int v;
    list<int> *listArestas; // usando ponteiro por que nao da pra usar a lista direto
public:
    Grafo(int valorV) {
        v = valorV;
        listArestas = new list<int>[v];
    }

    void addAresta(int vertice, int novaAresta) {
        listArestas[vertice].push_back(novaAresta);// adiciona o int novaAresta a lista de arestas do vertice mencinado
    }

    bool verificaVizinhos(int vertice1, int vertice2) {
        return (find(listArestas[vertice1].begin(), listArestas[vertice1].end(), vertice2) != listArestas[vertice1].end());
    }

    int getV() {
        return v;
    }

    list<int> listaTodosVizinhos(int vertice) {
        int i = 0;
        list<int> *listVizinhos;
        listVizinhos = new list<int>[v];
        vector<int> myVector(listArestas->begin(), listArestas->end());
        for(int i = 0; i<v;i++){
            if(i != vertice) {
                int vertice2 = myVector[i];
                if(verificaVizinhos(vertice, vertice2)){
                    listVizinhos->push_back(vertice2);
                }
            }
        }
        return *listVizinhos;
    }
};
int main() {
    Grafo grafo = Grafo(5);
    grafo.addAresta(0, 1);
    grafo.addAresta(0, 2);
    grafo.addAresta(0, 3);
    grafo.addAresta(0, 4);
    grafo.addAresta(1, 0);
    grafo.addAresta(2, 0);
    grafo.addAresta(3, 0);
    grafo.addAresta(4, 0);
    if (grafo.verificaVizinhos(1, 0)) {
        cout << "1 eh vizinho de 0" << endl;
    } else {
        cout << "1 nao eh vizinho de 0" << endl;
    }
    list<int> listaVizinhos = grafo.listaTodosVizinhos(0);
    cout << "0 eh vizinho de ";
    while(!listaVizinhos.empty()) {
        cout << listaVizinhos.back() << ", ";
        listaVizinhos.pop_back();
    }
    return 0;
}
