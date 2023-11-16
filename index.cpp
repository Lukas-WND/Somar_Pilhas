//
// Created by lukas on 15/11/2023.
//

#include <iostream>

using namespace std;

typedef struct Pilha {
    int num;
    Pilha *acima, *abaixo;
} Pilha;

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

void pop(Pilha **topo){
    if(!isEmpty(*topo)){
        Pilha *temp = (*topo);
        (*topo) = (*topo)->abaixo;

        delete(temp);
    } else {
        (*topo) = nullptr;
    }
}

Pilha *topEl(Pilha *pilha){
    if(pilha == nullptr){
        return nullptr;
    } else {
        return pilha;
    }
}

void clear(Pilha **pilha){
    if(!isEmpty(*pilha)){
        Pilha *aux = (*pilha);

        while(aux != nullptr){
            (*pilha) = (*pilha)->abaixo;
            delete(aux);
            aux = (*pilha);
        }
    }
}

void inserirNumero(Pilha **pilha, int num){
    string numStr = to_string(num);

    for(char digito: numStr){
        int digInt = digito - '0';

        push(pilha, digInt);
    }
}

Pilha *somar(Pilha **num1, Pilha **num2) {
    int carry = 0;
    Pilha *resultado = new Pilha();

    while (!isEmpty(*num1) || !isEmpty(*num2)) {
        int soma = carry;

        if (!isEmpty(*num1)) {
            soma += topEl(*num1)->num;
            pop(num1);
        }

        if (!isEmpty(*num2)) {
            soma += topEl(*num2)->num;
            pop(num2);
        }

        int digito = soma % 10;
        carry = soma / 10;

        push(&resultado, digito);
    }

    if(carry != 0){
        push(&resultado, carry);
    }

    return resultado;
}

int main(){
    Pilha *pilha1 = nullptr, *pilha2 = nullptr;
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

    Pilha *resultado = somar(&pilha1, &pilha2);

    cout << "Resultado da soma: ";

    while(!isEmpty(resultado)){
        cout << topEl(resultado)->num;
        pop(&resultado);
    }

    cout << endl;

    return 0;
}
