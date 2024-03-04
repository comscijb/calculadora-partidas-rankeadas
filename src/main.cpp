#include<iostream>
#include<vector>
using namespace std;

int countVictories(vector <string> playerMatchesResults[]);
string qualifyPlayer(int playerVictoryCount);
void addVictories(vector <string> playerMatchesResults[], int victories);
void addDefeats(vector <string> playerMatchesResults[], int defeats);

int main(){
    string playerName;
    cout << "Seja bem vindo!\nPor favor digite seu nome de jogador: ";
    cin >> playerName;
    vector <string> playerMatchesResults[10000];
    int playerVictoryCount;
    string playerQualification;

    int option = 1;
    while (option != 0){
        cout << "\nDeseja adicionar vitorias ou derrotas?\n1 - Vitorias\n2 - Derrotas\n0 - Sair\n";
        cin >> option;
        if (option == 1){
            int newVictories;
            cout << "Por favor digite o numero de vitorias: ";
            cin >> newVictories;
            addVictories(playerMatchesResults, newVictories);
        } else if (option == 2){
            int newDefeats;
            cout << "Por favor digite o numero de derrotas: ";
            cin >> newDefeats;
            addDefeats(playerMatchesResults, newDefeats);
        } else if (option == 0){
            cout << "Encerrando o programa e contando vitorias e derrotas...\n";
        } else{
            cout << "\nOpcao invalida! Por favor digite novamente: ";
        }
    }
    playerVictoryCount = countVictories(playerMatchesResults);
    playerQualification = qualifyPlayer(playerVictoryCount);
    cout << "O Heroi tem o saldo de " << playerVictoryCount << " vitorias e esta no nivel " << playerQualification;

    return 1;
}

int countVictories(vector <string> playerMatchesResults[]){
    int victoryCount = 0;
    int iterator = 0;
    for (iterator = 0; iterator < playerMatchesResults->size(); iterator++) {
        vector<string> matches = playerMatchesResults[iterator];
        int iterator2 = 0;
        for (iterator2 = 0; iterator2 < matches.size(); iterator2++) {
            if (matches[iterator2] == "V"){
                victoryCount++;
            }else if (matches[iterator2] == "D"){
                victoryCount--;
            }
        }
    }
    return victoryCount;
}

string qualifyPlayer(int playerVictoryCount){
    string playerQualification = "";
    if (playerVictoryCount <= 10) {
        playerQualification = "Ferro";
    } else if(playerVictoryCount > 10 && playerVictoryCount <= 20){
        playerQualification = "Bronze";
    } else if(playerVictoryCount > 20 && playerVictoryCount <= 50){
        playerQualification = "Prata";
    } else if(playerVictoryCount > 50 && playerVictoryCount <= 80){
        playerQualification = "Ouro";
    } else if(playerVictoryCount > 80 && playerVictoryCount <= 90){
        playerQualification = "Diamante";
    } else if(playerVictoryCount > 90 && playerVictoryCount <= 100){
        playerQualification = "Lendario";
    } else if(playerVictoryCount > 100){
        playerQualification = "Imortal";
    }
    return playerQualification;
}

void addVictories(vector <string> playerMatchesResults[], int victories){
    int iterator = 0;
    for (iterator = 0; iterator <= victories; iterator++){
        playerMatchesResults->push_back("V");
    }
    cout << victories <<"\nVitorias adcionadas com sucesso!";
}

void addDefeats(vector <string> playerMatchesResults[], int defeats){
    int iterator = 0;
    for (iterator = 0; iterator <= defeats; iterator++){
        playerMatchesResults->push_back("D");
    }
    cout << defeats <<"\nDerrotas adicionadas com sucesso!";
}

