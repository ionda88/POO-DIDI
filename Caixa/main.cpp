#include <iostream>

using namespace std;

class Caixa {
private:
    int codigo {0};
    double altura {0.0};
    double largura {0.0};
    double profundidade {0.0};
    double peso {0.0};
    int empilhamento {0};

public:
    Caixa() {}

    Caixa(double altura, double largura, double profundidade) {
        setAltura(altura);
        setLargura(largura);
        setProfundidade(profundidade);
    }

    Caixa(double altura, double largura, double profundidade, double peso, int empilhamento) {
        setAltura(altura);
        setLargura(largura);
        setProfundidade(profundidade);
        setPesoQuilos(peso);
        setEmpilhamento(empilhamento);
    }

    ~Caixa() {
        cout << "caixa excluida" << endl;
    }

    int getCodigo() {
        return codigo;
    }

    double getArea(){
        return altura * largura;
    };

    double getVolume(){
        return getArea() * profundidade;
    };

    int numCaixas(double alt, double larg, double prof){
        double tamanho = alt * larg * prof;
        return tamanho / getVolume();
    };

    void mostra() {
        cout << "altura: " << getAltura() << endl;
        cout << "largura: " << getLargura() << endl;
        cout << "profundidade: " << getProfundidade() << endl;
        cout << "peso: " << getPeso() << endl;
        cout << "empilhamento: " << getEmpilhamento() << endl;
    }

    double getAltura() {
        return altura;
    }

    void setAltura(double novaAltura) {
        if(novaAltura > 0) {
            altura = novaAltura;
        } else {
            altura = 0.0;
        }
    }

    double getLargura() {
        return largura;
    }

    void setLargura(double novaLargura) {
        if(novaLargura > 0) {
            largura = novaLargura;
         } else {
            largura = 0.0;
        }
    }

    double getProfundidade() {
        return profundidade;
    }

    void setProfundidade(double novaProfundidade) {
        if(novaProfundidade > 0) {
            profundidade = novaProfundidade;
        } else {
            profundidade = 0.0;
        }
    }

    double getPeso() {
        return peso;
    }

    void setPesoQuilos(double novoPeso) {
        peso = novoPeso;
    }

    void setPesoGramas(double novoPeso) {
        peso = novoPeso / 1000;
    }

    int getEmpilhamento() {
        return empilhamento;
    }

    void setEmpilhamento(int novaEmpilhamento) {
        empilhamento = novaEmpilhamento;
    }
};

int main()
{
    Caixa caixa(2,3,4,5,6);
    caixa.mostra();

    cout << "Area: " << caixa.getArea() << endl;
    cout << "Volume: " << caixa.getVolume() << endl;
    cout << "numCaixas 5/5/5: " << caixa.numCaixas(5,5,5) << endl;
    return 0;
}
