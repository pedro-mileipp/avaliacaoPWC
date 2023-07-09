#include <iostream>
#include <string>
#include <unordered_map>

bool verificaAnagramaPalindromo(const std::string& str) {
    std::unordered_map<char, int> contagemCaracteres;

    // Conta o número de ocorrências de cada caractere na string
    for (char c : str) {
        contagemCaracteres[c]++;
    }

    int numCaracteresImpares = 0;

    // Verifica a contagem de caracteres
    for (const auto& par : contagemCaracteres) {
        if (`par.second % 2 != 0) {
            numCaracteresImpares++;
        }
    }

    // Retorna true se houver no máximo um caractere com contagem ímpar
    return numCaracteresImpares <= 1;~
}

int main() {
    char input[100];
    printf("Digite a string: ");
    scanf("%s", input);

    std::string str(input);

    if (verificaAnagramaPalindromo(str)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
