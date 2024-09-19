#include <iostream>
#include <vector>

using namespace std;


class Solidos {
    public:
    virtual float area() const = 0;
    virtual float volume() const = 0;
    virtual ~Solidos() = default;
};

class Cilindro : public Solidos {
    private:
    float raio;
    float altura;
    float pi = 3.14;

    public:

    Cilindro(float raio, float altura) {
        this->raio = raio;
        this->altura = altura;
    }

    virtual float area() const override {
        return 2 * pi * raio * (raio + altura);
    }

    virtual float volume() const override {
        return pi * raio * raio * altura;
    }

    ~Cilindro(){}
};

class Esfera : public Solidos {
    private:
    float pi = 3.14;
    float raio;

    public:

    Esfera (float raio) {
        this->raio = raio;
    }

    virtual float area() const override {
        return 4 * pi * raio * raio;
    }

    virtual float volume() const override {
        return 4/3 * pi * raio * raio * raio;
    }

    ~Esfera(){}
};


class Conjuntos {
    private:
    vector<Solidos *> vetor;

    public:

    Conjuntos(){}

    void inserir (Solidos *U) {
        vetor.push_back(U);
    }

    float areaTotal() const {
        float aux = 0;
        for (int i = 0; i < vetor.size(); i++) {
            aux += vetor[i]->area();
        }

        return aux;
    }

    float volumeTotal() const {
        float aux = 0;

        for (int i = 0; i < vetor.size(); i++) {
            aux += vetor[i]->volume();
        }

        return aux;
    }


    ~Conjuntos(){}

};

int main() {
    Conjuntos data;
    Esfera e1(5);
    Cilindro c1(5,4);

    data.inserir(&e1); 
    data.inserir(&c1);

    cout << data.areaTotal() << endl;
    cout << data.volumeTotal() << endl;

}
