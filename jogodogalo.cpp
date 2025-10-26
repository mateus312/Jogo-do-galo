#include <iostream>
using namespace std;

struct galo {
    char a = ' ';
    bool b = false;
};

galo jogo[3][3];

void mostrar() {
    cout << endl << "Jogo do galo" << endl;
    cout << "   1   2   3" << endl;
    cout << "1 [" << jogo[0][0].a << "] [" << jogo[0][1].a << "] [" << jogo[0][2].a << "]" << endl;
    cout << "2 [" << jogo[1][0].a << "] [" << jogo[1][1].a << "] [" << jogo[1][2].a << "]" << endl;
    cout << "3 [" << jogo[2][0].a << "] [" << jogo[2][1].a << "] [" << jogo[2][2].a << "]" << endl;
}

int main() {
    int coluna;
    int linha;
    char jogador;
    string player1;
    string player2;
    string nomeAtual;
    char escolha;

    system("cls");
    cout << "Nome do primeiro jogador: ";
    cin >> player1;
    cout << "Nome do segundo jogador: ";
    cin >> player2;


    while (true) {
    cout << player1 << ", digite se quer ser X ou O: ";
    cin >> escolha;

    if (escolha == 'X' || escolha == 'O') {
        jogador = escolha; // escolha válida, sai do ciclo
        break;
    } else {
        cout << "Escolha invalida. Digite apenas X ou O." << endl;
    }
}

    nomeAtual = player1;

    system("cls");
    mostrar();

    for (int i = 0; i < 9; i++) {
        cout << endl << nomeAtual << " (" << jogador << "), e a sua vez!" << endl;
        cout << "Digite a linha que queira jogar: ";
        cin >> linha;
        cout << "Digite a coluna que queira jogar: ";
        cin >> coluna;

        if (jogo[linha - 1][coluna - 1].b == true) {
            system("cls");
            cout << endl << "Essa posica ja foi usada, escolha outra!" << endl;
            mostrar();
            i--; // repete o turno
            continue;
        } else {
            jogo[linha - 1][coluna - 1].a = jogador;
            jogo[linha - 1][coluna - 1].b = true;
        }

        system("cls");
        mostrar();

        if (jogador == 'X') {
            jogador = 'O';
            nomeAtual = player2;
        } else {
            jogador = 'X';
            nomeAtual = player1;
        }
    }

    cout << endl << "Fim de jogo!" << endl;
}

