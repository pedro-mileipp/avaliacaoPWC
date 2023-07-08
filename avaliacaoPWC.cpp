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

std::string maiorSubstringPalindromoica(const std::string& str) {
    int n = str.length();
    bool palindromo[n][n];
    std::fill_n(*palindromo, n * n, false);

    // Todos os caracteres individuais são palíndromos
    for (int i = 0; i < n; i++) {
        palindromo[i][i] = true;
    }

    int inicio = 0;
    int tamanho = 1;

    // Verifica substrings de tamanho 2
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            palindromo[i][i + 1] = true;
            inicio = i;
            tamanho = 2;
        }
    }

    // Verifica substrings de tamanho maior que 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (str[i] == str[j] && palindromo[i + 1][j - 1]) {
                palindromo[i][j] = true;
                inicio = i;
                tamanho = len;
            }
        }
    }

    return str.substr(inicio, tamanho);
}

bool verificaPalindromo(const std::string& str) {
    std::string strProcessada = str;

    // Remover espaços em branco e caracteres de pontuação
    strProcessada.erase(std::remove_if(strProcessada.begin(), strProcessada.end(), [](unsigned char c) {
        return std::isspace(c) || std::ispunct(c);
    }), strProcessada.end());

    // Converter para letras minúsculas para fazer a comparação sem diferenciação de maiúsculas e minúsculas
    std::transform(strProcessada.begin(), strProcessada.end(), strProcessada.begin(), ::tolower);

    // Verificar se a string processada é igual à sua inversa
    return strProcessada == std::string(strProcessada.rbegin(), strProcessada.rend());
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

    std::string dadosEntrada3;
    printf("Digite a string: ");
    std::getline(std::cin, dadosEntrada3);

    if (verificaPalindromo(dadosEntrada3)) {
        std::string substringPalindromo = maiorSubstringPalindromoica(dadosEntrada3);
        printf("Maior substring palindrômica: %s\n", substringPalindromo.c_str());
    } else {
        printf("A string não é palindrômica.\n");
    }
    
    return 0;
}
