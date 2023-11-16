//
// Created by lukas on 15/11/2023.
//

#include <iostream>

using namespace std;

typedef struct Pilha {
    int num;
    Pilha *acima, *abaixo;
};

bool isEmpty(Pilha *topo){
    if(topo == nullptr){
        return true;
    } else {
        return false;
    }
}

void push(Pilha **topo, int num){
    if(isEmpty(*topo)){ // Pilha vazia
        Pilha *node = new Pilha();

        node->acima = nullptr;
        node->abaixo = nullptr;
        node->num = num;

        (*topo) = node;

    } else {
        Pilha *node = new Pilha();

        node->num = num;

        node->abaixo = (*topo);
        (*topo)->acima = node;
        (*topo) = node;
    }
}

void inserirNumero(Pilha **pilha, int num){
    string numStr = to_string(num);

    for(char digito: numStr){
        int digInt = digito - '0';

        push(pilha, digInt);
        cout << "Dig: " << digInt << endl;
    }
}

int main(){
    Pilha *pilha1, *pilha2;
    int num1 = 0, num2 = 0;

    cout << "SOMAR DOIS NUMEROS" << endl;

    cout << "Informe o primeiro numero: ";
    cin >> num1;
    cin.ignore();
    inserirNumero(&pilha1, num1);

    cout << "Informe o segundo numero: ";
    cin >> num2;
    cin.ignore();
    inserirNumero(&pilha2, num2);

}