#include <iostream>
using namespace std;

class Calculadora {
private:
    int a, b, op, total;
public:
    Calculadora() {
        a = 0;
        b = 0;
        op = 0;
        total = 0;
    }

    void setA(int num1) {
        a = num1;
    }

    void setB(int num2) {
        b = num2;
    }

    void setOp(int oper) {
        op = oper;
    }

    int getA() {
        return a;
    }

    int getB() {
        return b;
    }

    int getOp() {
        return op;
    }

    void ops() {
        if (op == 1) {
            total = a + b;
            cout << "Soma: " << total << endl;
        }
        else if (op == 2) {
            total = a - b;
            cout << "Subtração: " << total << endl;
        }
        else if (op == 3) {
            total = a * b;
            cout << "Multiplicação: " << total << endl;
        }
        else if (op == 4) {
            if (b != 0) {
                total = a / b;
                cout << "Divisão: " << total << endl;
            } else {
                cout << "Erro: Divisão por zero!" << endl;
            }
        }
        else {
            cout << "Operação inválida!" << endl;
        }
    }
};

int main() {
    Calculadora cal;
    int a, b, op;
    cout << "Digite o primeiro número: ";
    cin >> a;
    cout << "Digite o segundo número: ";
    cin >> b;
    cout << "Digite a operação (1 para soma, 2 para subtração, 3 para multiplicação, 4 para divisão): ";
    cin >> op;

    cal.setA(a);
    cal.setB(b);
    cal.setOp(op);
    cal.ops();
    return 0;
}
