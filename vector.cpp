#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class Vetor {
private:
    vector<T> v;
public:
    void inserir(T data) {
        v.push_back(data);
    }

    void inserirMiddle (T data) {
        int mid = v.size() / 2;

        vector<T> v_copy;

        v_copy = v;

        v.clear();

        for (int i = 0; i < v_copy.size() ; i++) {
            if (i == mid) {
                v.push_back(data);
                v.push_back(v_copy[i]);
            } else {
                v.push_back(v_copy[i]);
            }
        }
    }

    void removerValue (T data) {
        vector<T> v_copy;

        v_copy = v;

        v.clear();

        for (int i = 0; i < v_copy.size(); i++) {
            if (v_copy[i] != data) {
                v.push_back(v_copy[i]);
            }
        }
    }

    T& operator[] (int index) {
        return v[index];
    }

    void bubble () {
        for (int i = 0; i < v.size() - 1; i++) {
            for (int j = 0; j < v.size() - 1 - i; j++) {
                if (v[j] > v[j + 1]) {
                    T temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
        }
    }

    void imprimir () {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << endl;
        }
    }


};


int main() {
    Vetor<int> v1;

    v1.inserir(10);
    v1.inserir(5);
    v1.inserir(20);
    v1.inserir(15);
    v1.inserir(2);
    v1.inserir(40);

    v1.imprimir();
    cout << "---------" << endl;
    v1.bubble();
    v1.imprimir();
    cout << "---------" << endl;
    v1[2] = -6;
    v1.bubble();
    v1.inserirMiddle(10000);
    v1.imprimir();
}
