#include <stdio.h>
#include <stdlib.h>

const int ORDEM = 10; // ORDEM=10
const int JOGADAS = 72;//numero maximo de jogadas.
const int NUMERO_BOMBAS = 10; //numero de bombas

void adicionarCoordenadas(char tabuleiroUsuario[ORDEM][ORDEM]){
    int i, j;
    //Laço pra percorrer o vetor e adicionar '-'
    for(i=0; i<ORDEM;i++){
        for(j=0; j<ORDEM;j++){
            tabuleiroUsuario[i][j] = '-';
        }
    }

//ASDJAD CHAR E NUM
    //Laço pra adicionar as coordenadas
    for(j=0; j<ORDEM;j++){
        tabuleiroUsuario[j][0] = j+1;//Adicionando coordenadas as linhas
        tabuleiroUsuario[0][j] = j+1;//Adicionando coordenadas as colunas
    }
}
void bomba(char tabuleiro1[ORDEM][ORDEM], char tabuleiro2[ORDEM][ORDEM]){
    int i, j, x, y;//Inicializando variavel do laço
    srand(time(NULL));//Inicializando a função rand().
    for(i=0;i<ORDEM; i++){
        x = rand() % 5;
        for(j=0; j<ORDEM; j++){
            y = rand() % 5;
        }tabuleiro2[x][y] = '*';
    }
}
int main(){
    int i, numeroDaBomba;
    
    printf("SEJA BEM-VINDO AO MEU CAMPO MINADO EM C!!!!!!!!!\n");
    printf("Atenção as regras do jogo: ");
    char tabuleiroUsuario[ORDEM][ORDEM], tabuleiroIdentidade[ORDEM][ORDEM];//Um será mostrado ao usuário e outro não.
    for(i=0; i<NUMERO_BOMBAS; i++){
        bomba(tabuleiroUsuario, tabuleiroIdentidade);
    }
    
    

    
    return 0;
}