#include <iostream>
#include <math.h>
#include <string>

using namespace std;
class Complexo {
private:
    double real {0.0};
    double imaginario {0.0};
public:
    Complexo() {}
    Complexo(double valorReal) {
        setReal(valorReal);
    }
    Complexo(double valorReal, double valorImaginario) {
        setReal(valorReal);
        setImaginario(valorImaginario);
    }

    double getReal() {
        return real;
    }
    void setReal(double novoReal) {
        real = novoReal;
    }
    double getImaginario() {
        return imaginario;
    }
    void setImaginario(double novoImaginario) {
        imaginario = novoImaginario;
    }

    Complexo operator+(const Complexo& outroComplexo) {
        Complexo complexo;
        complexo.real = this->real + outroComplexo.real;
        complexo.imaginario = this->imaginario + outroComplexo.imaginario;
        return complexo;
    }

    Complexo operator-(const Complexo& outroComplexo) {
        Complexo complexo;
        complexo.real = this->real - outroComplexo.real;
        complexo.imaginario = this->imaginario - outroComplexo.imaginario;
        return complexo;
    }

    Complexo operator*(const Complexo& outroComplexo) {
        Complexo complexo;
        complexo.real = this->real * outroComplexo.real;
        complexo.imaginario = this->imaginario * outroComplexo.imaginario;
        return complexo;
    }

    Complexo operator/(const Complexo& outroComplexo) {
        Complexo complexo;
        complexo.real = this->real / outroComplexo.real;
        complexo.imaginario = this->imaginario / outroComplexo.imaginario;
        return complexo;
    }

    bool operator==(const Complexo& outroComplexo) {
        return (this->real == outroComplexo.real && this->imaginario == outroComplexo.imaginario);
    }

    double abs() {
        return sqrt(pow(getReal(), 2) + pow(getImaginario(), 2));
    }

    double getAngulo() {
        return atan(getImaginario()/getReal());
    }

    Complexo getInverso() {
        Complexo complexo;
        complexo.real = pow(this->real, -1);
        complexo.imaginario = pow(this->imaginario, -1);
        return complexo;
    }

    void mostra() {
        cout.precision(2);
        cout << "Z = " << fixed << getReal() << " + " << fixed << getImaginario() << "i" << endl;
    }

    string toString() {
        return "("+to_string(getReal())+";"+to_string(getImaginario())+")";
    }
};

int main() {
    Complexo complexo = Complexo(2.0, (542.0/812.0));
    Complexo complexo2 = Complexo(6.0, (72.0/6.2));



    complexo.mostra();
    complexo2.mostra();
    complexo = complexo + complexo2;
    complexo.mostra();

    cout.precision(2);
    cout << "Modulo: " << fixed << complexo.abs() << endl;
    cout << "Angulo: " << fixed << complexo.getAngulo() << endl;
    complexo = complexo.getInverso();
    complexo.mostra();

    complexo = (complexo + complexo2 * complexo) / complexo2 - complexo;
    complexo.mostra();
    bool teste = complexo == complexo;
    cout << "complexo == complexo? " << (teste==1?"sim":"nao") << endl;

    cout << "toString: " + complexo.toString() << endl;
    return 0;
}
