#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node<T>* prox;

    Node(T v) {
        data = v;
        prox = nullptr;
    }
};

template <typename T>
class Lista {
    private:
    Node<T>* ptlista;

    public:
    Lista() {
        ptlista = nullptr;
    }

    void inserirInicio (T x) {
        Node<T>* new_node = new Node<T>(x);

        if (ptlista == nullptr) {
            new_node->prox = nullptr;
            ptlista = new_node;
            return;
        }

        new_node->prox = ptlista;
        ptlista = new_node;
    }


    void inserirFinal (T x) {
        Node<T>* new_node = new Node<T>(x);

        if (ptlista == nullptr) {
            new_node->prox = nullptr;
            ptlista = new_node;
            return;
        }

        Node<T>* ptr = ptlista;

        while (ptr->prox != NULL) {
            ptr = ptr->prox;
        }

        ptr->prox = new_node;
        new_node->prox = nullptr;
    }

    void removerInicio() {
        Node<T>* ptr = ptlista;

        if (ptlista == nullptr) {
            cout << "Lista vazia" << endl;
            return;
        }

        if (ptr->prox == nullptr) {
            ptlista = nullptr;
            delete ptr;
            return;
        }

        ptlista = ptlista->prox;
        delete ptr;
    }

    void removerFinal () {
        Node<T>* ptr = ptlista;
        Node<T>* prev = nullptr;

        if (ptlista == nullptr) {
            cout << "Lista vazia" << endl;
            return;
        }

        if (ptr->prox == nullptr) {
            ptlista = nullptr;
            delete ptr;
            return;
        }


        while (ptr->prox != nullptr) {
            prev = ptr;
            ptr = ptr->prox;
        }

        prev->prox = nullptr;
        delete ptr;
    }

    T& operator[] (int index) const {
        Node<T>* ptr = ptlista;
        for (int i = 0; i < index; i++) {
            ptr = ptr->prox;
        }

        return ptr->data;
    }

    operator string() const {
        stringstream conteudo;
        Node<T>* ptr = ptlista;

        while (ptr != nullptr) {
            conteudo << ptr->data;
            if (ptr->prox != nullptr) {
                conteudo << " -> ";
            }
            ptr = ptr->prox;
        }

        return conteudo.str();
    }

};

int main() {
    Lista<int> intLis;

    intLis.inserirInicio(1);
    intLis.inserirInicio(2);
    intLis.inserirInicio(3);
    intLis.inserirInicio(4);
    intLis.inserirFinal(10);
    intLis.inserirFinal(20);
    intLis.removerInicio();
    intLis.removerFinal();

    cout << string(intLis) << endl;
    cout << "Numero na posição 2 da lista: " << intLis[2] << endl;
}
