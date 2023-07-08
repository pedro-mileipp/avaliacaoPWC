#include <iostream>
#include <string>
#include <sstream>
#include <stack>

std::string reverseOrdemPalavras(std::string frase) {
    std::stack<std::string> pilha;
    std::stringstream ssAux(frase);
    std::string palavra;
    
    // Separando as palavras da frase e empilhando na pilha
    while (ssAux >> palavra) {
        pilha.push(palavra);
    }
    
    std::string fraseInversa;
    
    // Construindo a frase revertida desempilhando as palavras
    while (!pilha.empty()) {
        fraseInversa += pilha.top();
        pilha.pop();
        
        if (!pilha.empty()) {
            fraseInversa += " ";
        }
    }
    
    return fraseInversa;
}

int main() {
    std::string dadosEntrada;
    printf("Digite a frase: ");
    std::getline(std::cin, dadosEntrada);
    
    std::string fraseRevertida = reverseOrdemPalavras(dadosEntrada);
    
    printf("Frase revertida: %s\n", fraseRevertida.c_str());

    printf("\n");
    
    return 0;
}
