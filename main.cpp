#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

string palavraSecreta = "MELANCIA";
map<char, bool> jaChutou;
vector<char> chutesErrados;

void abertura () {
    cout << "**********************"<< endl;
    cout << "*   Jogo da Forca    *"<< endl;
    cout << "**********************"<< endl;
    cout << endl;
}

void imprimePalavra () {
    for (char letra : palavraSecreta) {
        if (jaChutou[letra]) {
            cout << letra << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

void imprimeErros () {
        cout << "Chutes errados: ";
    for (char letra : chutesErrados) {
        cout << letra << " ";
    }
    cout << endl;
}

bool letraExiste (char palpite) {
    for(char letra : palavraSecreta) {
        if (palpite == letra) {
            return true;
        }
    }
    return false;
}

bool naoAcertou () {
    for (char letra : palavraSecreta) {
        if (!jaChutou[letra]) {
            return true;
        }
    }
    return false;
}

bool naoEnforcou () {
    return chutesErrados.size() < 5;
}

void chuta () {
    char palpite;
    cout << "\nQual seu palpite? \n";
    cin >> palpite;

    jaChutou[palpite] = true;

    if (letraExiste(palpite)) {
        cout << "Parabens! Voce acertou!" << endl;
    }
    else {
        cout << "Que pena, voce errou!" << endl;
        chutesErrados.push_back(palpite);
    }
}





int main () {

    abertura();

    while (naoAcertou() && naoEnforcou()) {

        imprimeErros();

        imprimePalavra();

        chuta();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavraSecreta << endl;
    cout << endl;
    if (naoAcertou()) {
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else {
        cout << "Voce ganhou! Parabens!" << endl;
    }
}