#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void abertura (){
    cout << "**********************"<< endl;
    cout << "* Jogo da Advinhacao *"<< endl;
    cout << "**********************"<< endl;
}

int main () {

    abertura();

    cout << "Escolha o seu nivel de dificuldade: " << endl;
    cout << "Facil (1), Medio (2) ou Dificil (3)" << endl;

    int nivel;
    cin >> nivel;
    
    int numeroDeTentativas;

    if(nivel == 1){
        numeroDeTentativas = 15;
    } else if (nivel == 2){
        numeroDeTentativas = 10;
    } else {
        numeroDeTentativas = 5;
    }

    //defineNumeroSecreto
    srand(time(NULL));
    const int NUMEROSECRETO = rand() % 100;

    int tentativa = 0;
    bool naoAcertou = true;

    double pontos = 1000.0;

    for (tentativa = 1; tentativa <= numeroDeTentativas; tentativa++) {
        //recebePalpite
        int palpite;
        cout << "Tentativa " << tentativa << endl;
        cout << "Digite seu palpite: ";
        cin >> palpite;

        double pontosPerdidos = abs(palpite - NUMEROSECRETO) / 2.0;
        pontos = pontos - pontosPerdidos;

        //verificaPalpite
        bool acertou = palpite == NUMEROSECRETO;
        bool maior = palpite > NUMEROSECRETO;

        if (acertou) {
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            naoAcertou = false;
            break;
        } else if (maior) {
            cout << "Seu palpite foi maior que o numero secreto!" << endl;
        } else {
            cout << "Seu palpite foi menor que o numero secreto!" << endl;
        }
    }

    cout << "Fim de jogo!" << endl;

    if (naoAcertou) {
        cout << "Voce perdeu! Tente novamente!" << endl;
    } else {
        cout << "Voce acertou o numero secreto em " << tentativa << " tentativas!" << endl;
    }
    cout.precision(2);
    cout << fixed;
    cout << "Total de pontos: " << pontos << endl;

}