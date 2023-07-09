#include <iostream>
#include <string>
#include <cctype>

std::string primeiraLetraMaiuscula(const std::string& stringEntrada ) {
    std::string resultado = stringEntrada;
    bool capitalizar = true;

    for (size_t i = 0; i < resultado.length(); i++) {
        if (capitalizar && std::isalpha(resultado[i])) {  // Verifica se é necessário capitalizar o caractere
            resultado[i] = std::toupper(resultado[i]);  // Converte o caractere para maiúscula
            capitalizar = false;  // Desativa a flag para não capitalizar outros caracteres da mesma palavra
        } else if (std::isspace(resultado[i])) {  // Verifica se é um espaço em branco
            capitalizar = true;  // Ativa a flag para capitalizar o próximo caractere encontrado
        }
    }

    return resultado;  // Retorna a string modificada
}

int main() {
    char input[100];
    printf("Digite a string: ");
    scanf("%[^\n]s", input);

    std::string str(input);

    std::string output = primeiraLetraMaiuscula(str);  
    printf("Output: %s\n", output.c_str());  

    return 0;
}
