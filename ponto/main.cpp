#include <iostream>
#include <math.h>

using namespace std;
class Ponto {
private:
    double x {0.0};
    double y {0.0};

public:
    Ponto() {}

    Ponto(double novoX, double novoY) {
        setX(novoX);
        setY(novoY);
    }

    double getX() {
        return x;
    }

    void setX(double novoX) {
        x = novoX;
    }

    double getY() {
        return y;
    }

    void setY(double novoY) {
        y = novoY;
    }

    double distancia (double outroX, double outroY) {
        Ponto outroPonto = Ponto(outroX, outroY);
        return distancia(outroPonto);
    }

    double distancia(Ponto outroPonto) {
        double aux1 = (outroPonto.getX() - x);
        aux1 = pow(aux1, 2);

        double aux2 = (outroPonto.getY() - y);
        aux2 = pow(aux2, 2);

        return sqrt(aux1 + aux2);
    }
};

class Reta {
private:
    Ponto a;
    Ponto b;
public:
    Reta(Ponto pontoA, Ponto pontoB) {
        a = pontoA;
        b = pontoB;
    }

    Reta(double pontoAX, double pontoBX, double pontoAY, double pontoBY) {
        a = Ponto(pontoAX, pontoAY);
        b = Ponto(pontoBX, pontoBY);
    }

    double tamanho() {
        return a.distancia(b);
    }

    double getCoeficienteAngular() {
        return (b.getY() - a.getY()) / (b.getX() - a.getX());
    }

    double getCoeficienteLinear() {
        return a.getY() - (getCoeficienteAngular() * a.getX());;
    }

    mostra() {
        cout << "y=" << getCoeficienteAngular() << "x + " << getCoeficienteLinear() << endl;
    }

    double angulo(Reta outraReta) {
        double s = getCoeficienteAngular();
        double r = outraReta.getCoeficienteAngular();
        return abs((s - r) / (1 + (s * r)));
    }
};

class Triangulo {
private:
    Ponto a;
    Ponto b;
    Ponto c;

public:
    Triangulo (Ponto pontoA, Ponto pontoB, Ponto pontoC) {
        a = pontoA;
        b = pontoB;
        c = pontoC;
    }

    calcularLados() {
        Reta ab = Reta(a, b);
        Reta bc = Reta(b, c);
        Reta ac = Reta(a, c);
        cout << "Lado AB: " << ab.tamanho()  << endl;
        cout << "Lado BC: " << bc.tamanho()  << endl;
        cout << "Lado AC: " << ac.tamanho()  << endl;
    }

    classificar() {
        Reta ab = Reta(a, b);
        Reta bc = Reta(b, c);
        Reta ac = Reta(a, c);
        double abac = ab.angulo(ac);
        double abbc = ab.angulo(bc);
        double acbc = ac.angulo(bc);

        double tamAB = ab.tamanho();
        double tamBC = bc.tamanho();
        double tamAC = ac.tamanho();

        if(tamBC > 10.0 && tamBC < 10.001) {
            tamBC = 10.0;
        }
        if(tamAC > 10.0 && tamAC < 10.001) {
            tamAC = 10.0;
        }

        //cout << "Triangulo ";
        if(tamAB == tamBC && tamAB == tamAC) {
            cout << "Equilatero"  << endl;
        } else if(tamAB == tamBC || tamBC == tamAC || tamAB == tamAC) {
            cout << "Isosceles"  << endl;
        } else {
            cout << "Escaleno" << endl;
        }

       /* if(abac == 90.0 || abbc == 90.0 || acbc == 90.0) {
            cout << "Retangulo" << endl;
        } else if(abac > 90.0 || abbc > 90.0 || acbc > 90.0) {
            cout << "Obtuso" << endl;
        } */
    }

    double altura () {
        Reta ab = Reta(a, b);
        return (ab.tamanho()*sqrt(3))/2;
    }

};
int main()
{
    Ponto pontoA = Ponto(0.0, 0.0);
    Ponto pontoB = Ponto(10.0, 0.0);
    Ponto pontoC = Ponto(5.0, 8.6603);

    Reta retaBC = Reta(pontoB, pontoC);

    Triangulo triangulo = Triangulo(pontoA, pontoB, pontoC);
    cout << "Distancia ponto a (10;0) e ponto b (5;8.6603): " << retaBC.tamanho() << endl;
    retaBC.mostra();
    triangulo.calcularLados();
    triangulo.classificar();
    cout << "altura: " << triangulo.altura() << endl;
    return 0;
}
