#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class Vetor {
    private:

    vector<T> v;

    public:

    void inserirVector (T data) {
        v.push_back(data);
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

    void inserirMiddle (T data) {
        int mid = v.size() / 2;

        vector<T> v_copy;

        v_copy = v;

        v.clear();

        for (int i = 0; i < v_copy.size(); i++) {
            if (i == mid) {
                v.push_back(data);
                v.push_back(v_copy[i]);
            } else {
                v.push_back(v_copy[i]);
            }
        }

    }

    void imprimirVetor() {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << endl;
        }
    }

    void removerVector (T data) {
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


};

int main() {
    Vetor<int> v1;

    v1.inserirVector(20);
    v1.inserirVector(8);
    v1.inserirVector(15);
    v1.removerVector(3);
    v1.inserirVector(40);
    v1.inserirVector(21);
    v1.removerVector(20);  
    v1.inserirMiddle(100);
    v1.imprimirVetor();

    cout << "Valor na posição 2: " << v1[2] << endl;

}
