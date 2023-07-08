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
bool verificaCaracteresDuplicados(const std::string& fraseEntrada) {
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


// questao 3
std::string encontrarSubstringPalindromicaMaisLonga(const std::string& stringEntrada) {
    int n = stringEntrada.length();
    int ini = 0; // Índice inicial da substring palindrômica mais longa encontrada
    int tamanho = 1; // Tamanho da substring palindrômica mais longa encontrada
    
    // Inicializa e preenche a matriz de palíndromo
    bool palindromo[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            palindromo[i][j] = false;
        }
    }
    
    // Caso base: todos os caracteres individuais são palíndromos
    for (int i = 0; i < n; i++) {
        palindromo[i][i] = true;
    }
    
    // Caso base: verifica substrings de tamanho 2
    for (int i = 0; i < n - 1; i++) {
        if (stringEntrada[i] == stringEntrada[i + 1]) {
            palindromo[i][i + 1] = true;
            ini = i;
            tamanho = 2;
        }
    }
    
    // Verifica substrings de tamanho maior que 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (stringEntrada[i] == stringEntrada[j] && palindromo[i + 1][j - 1]) {
                palindromo[i][j] = true;
                ini = i;
                tamanho = len;
            }
        }
    }
    
    // Retorna a substring palindrômica mais longa encontrada
    return stringEntrada.substr(ini, tamanho);
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

    if (verificaCaracteresDuplicados(dadosEntrada2)) {
        std::string entradaSemDuplicados = removerCaracteresDuplicados(dadosEntrada2);
        printf("Frase sem caracteres duplicados: %s\n", entradaSemDuplicados.c_str());
    } else {
        printf("A frase digitada nao possui caracteres duplicados.\n");
    }

    printf("\n");
    
    return 0;
}
