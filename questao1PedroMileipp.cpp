#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <algorithm>

// Questao 1
std::string reverseOrdemPalavras(std::string entrada) {
    std::stack<std::string> pilha;
    std::stringstream ssAux(entrada);
    std::string palavras;
    
    // extrai o fluxo de ssAux para palavras
    while (ssAux >> palavras) {
        pilha.push(palavras); // ao colocar na pilha as palavras, a ordem dos elementos já será invertida
    }
    
    std::string fraseInversa; //string que receberá o resultado final
    
    // Construindo a frase revertida desempilhando as palavras
    while (!pilha.empty()) {
        fraseInversa += pilha.top(); // colocar o topo da pilha na fraseInversa
        pilha.pop(); // exclui o topo da pilha
        
        if (!pilha.empty()) {
            fraseInversa += " "; // se a pilha não estiver vazia, imprime um espaço em branco
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
