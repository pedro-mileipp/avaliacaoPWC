 #include <iostream>
#include <string>
#include <algorithm>

std::string encontrarMaiorSubstringPalindromica(const std::string& str) {
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
    char input[100];
    printf("Digite a string: ");
    scanf("%[^\n]s", input);

    std::string str(input);


    if (verificaPalindromo(str)) {
        std::string maiorSubstringPalindromica = encontrarMaiorSubstringPalindromica(str); 
        printf("Maior substring palindrômica: %s\n", maiorSubstringPalindromica.c_str());
    } else {
        printf("A string não é palindrômica.\n");
    }

    return 0;
}
