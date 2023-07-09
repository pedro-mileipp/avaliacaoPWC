#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <unordered_set>


// questao 2
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


int main()
{
    char dadosEntrada2[100];
    printf("Digite a frase: ");
    scanf("%[^\n]s", dadosEntrada2);

    if (verificaCaracteresDuplicados(dadosEntrada2)) {
        std::string entradaSemDuplicados = removerCaracteresDuplicados(dadosEntrada2);
        printf("Frase sem caracteres duplicados: %s\n", entradaSemDuplicados.c_str());
    } else {
        printf("A frase digitada nao possui caracteres duplicados.\n");
    }
}
