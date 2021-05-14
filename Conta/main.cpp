#include <iostream>
#include <string>

using namespace std;



class Conta {
private:
    static int ID;
    int codigoConta;
    string nomeCliente {""};
    double vlMonetario {0.0};

public:
    Conta() {
        codigoConta = ++ID;
    }
    Conta(string nomeNovoCliente, double vlMonetarioNovoCliente) : codigoConta(ID++){
        codigoConta = ++ID;
        setNomeCliente(nomeNovoCliente);
        setVlMonetario(vlMonetarioNovoCliente);
    }
    void mostraCodigo() {
        cout << "Conta: "<< getCodigoConta() << endl;
    }

    void mostraSaldo() {
        cout << "Saldo atual: "<< getVlMonetario() << endl;
    }

    void realizarDeposito(double valor) {
        cout << "Deposito de : "<< valor << endl;
        setVlMonetario(getVlMonetario() + valor);
    }

    void realizarSaque(double valor) {
        cout << "Saque de : "<< valor << endl;
        setVlMonetario(getVlMonetario() - valor);
    }

    int getCodigoConta() {
        return codigoConta;
    }

    string getNomeCliente() {
        return nomeCliente;
    }

    void setNomeCliente(string novoNome) {
        nomeCliente = novoNome;
    }

    double getVlMonetario() {
        return vlMonetario;
    }

    void setVlMonetario(double novoValor) {
        vlMonetario = novoValor;
    }

};

class ContaCorrente : public Conta {
public:
    void realizarSaque(double valor) {
        if(valor > getVlMonetario()) {
            cout << "Valor de saque maior que o valor em conta" << endl;
        } else if(valor > 2000.0) {
             cout << "Valor de saque nao permitido" << endl;
        } else {
            setVlMonetario(getVlMonetario() - valor);
        }
    }
};

class contaEspecial : public Conta {
private:
    double vlLimiteCredito;
public:
    void cobrarTaxa() {
        /// perguntar para o professor
    }

    double getVlLimiteCredito() {
        return vlLimiteCredito;
    }

    void setVlLimiteCredito(double valor) {
        vlLimiteCredito = valor;
    }
};

class contaPoupanca : public Conta {
private:
    double vlTaxaReajusteMensal;
public:
    void realizarSaque(double valor) {
        if(valor > getVlMonetario()) {
            cout << "Valor de saque maior que o valor em conta" << endl;
        } else {
            setVlMonetario(getVlMonetario() - valor);
        }
    }
};


int Conta::ID = 0;

int main()
{
    ContaCorrente conta1;
    conta1.mostraCodigo();
    ContaCorrente conta2;
    conta2.mostraCodigo();
    conta1.mostraSaldo();
    conta1.realizarDeposito(80000.0);
    conta1.realizarSaque(2001.0);
    conta1.mostraSaldo();

    return 0;
}
