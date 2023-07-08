#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <unordered_set>

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
bool temCaracteresDuplicados(const std::string& fraseEntrada) {
    std::unordered_set<char> caracteres; // Conjunto para armazenar os caracteres únicos encontrados

    // Percorre cada caractere na frase
    for (char c : fraseEntrada) {
        // Verifica se o caractere já está presente no conjunto
        if (caracteres.find(c) != caracteres.end()) {
            return true; // Se o caractere estiver presente, retorna verdadeiro indicando duplicação
        }

        caracteres.insert(c); // Insere o caractere no conjunto
    }

    return false; // Se nenhum caractere duplicado for encontrado, retorna falso
}




// Questao 2
std::string removerCaracteresDuplicados(const std::string& fraseEntrada) {
    std::unordered_set<char> caracteresDaEntrada; // Conjunto para armazenar os caracteres únicos encontrados
    std::string fraseSemDuplicados; // String para armazenar a frase sem caracteres duplicados

    // Percorre cada caractere na frase
    for (char c : fraseEntrada) {
        // Verifica se o caractere já está presente no conjunto
        if (caracteresDaEntrada.find(c) == caracteresDaEntrada.end()) {
            caracteresDaEntrada.insert(c); // Se o caractere não estiver presente, insere no conjunto
            fraseSemDuplicados += c; // Adiciona o caractere à frase sem duplicados
        }
    }

    return fraseSemDuplicados; // Retorna a frase sem caracteres duplicados
}

int main() {
    std::string dadosEntrada;
    printf("Digite a frase: ");
    std::getline(std::cin, dadosEntrada);
    
    std::string fraseRevertida = reverseOrdemPalavras(dadosEntrada);
    
    printf("Frase revertida: %s\n", fraseRevertida.c_str());

    printf("\n");

    char dadosEntrada2[100];
    printf("Digite a frase: ");
    scanf("%[^\n]s", dadosEntrada2);

    if (temCaracteresDuplicados(dadosEntrada2)) {
        std::string entradaSemDuplicados = removerCaracteresDuplicados(dadosEntrada2);
        printf("Frase sem caracteres duplicados: %s\n", entradaSemDuplicados.c_str());
    } else {
        printf("A frase digitada nao possui caracteres duplicados.\n");
    }

    
    return 0;
}
