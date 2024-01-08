#include <stdio.h>
#include <stdlib.h>

//regras de aplicação
const int ORDEM = 10; // ORDEM=10
const int JOGADAS = 72;//numero maximo de jogadas.
const int NUMERO_BOMBAS = 10; //numero de bombas

void adicionarCoordenadas(char tabuleiroUsuario[ORDEM][ORDEM]){
    int i, j, varAuxiliar=1;
    //Laço pra percorrer o vetor e adicionar '-'
    for(i=0; i<ORDEM;i++){
        for(j=0; j<ORDEM;j++){
            if(i==0 && j==0){
                tabuleiroUsuario[i][j] = " "; //Na posição 0,0 o tabuleiro fica vazio.
            }else{
                tabuleiroUsuario[i][j] = '-';
            }
        }
    }
    //Laço pra adicionar as coordenadas
    for(j=1; j<=ORDEM;j++){
        printf("%c \n", varAuxiliar + '0');
        tabuleiroUsuario[j][0] = varAuxiliar + '0';//Adicionando coordenadas as linhas, lembrando que há uma conversão de int pra char.
        tabuleiroUsuario[0][j] = varAuxiliar + '0';//Adicionando coordenadas as colunas, lembrando que há uma conversão de int pra char.
        varAuxiliar++;
    }
}
void bomba(char tabuleiro2[ORDEM][ORDEM]){
    int i, j, x, y;//Inicializando variavel do laço
    srand(time(NULL));//Inicializando a função rand().
    for(i=0;i<ORDEM; i++){
        x = rand() % 5;
        for(j=0; j<ORDEM; j++){
            y = rand() % 5;
        }tabuleiro2[x][y] = '*';
    }
}
void configuraTabuleiro(char tabuleiro1[ORDEM][ORDEM], char tabuleiro2[ORDEM][ORDEM]){
    adicionarCoordenadas(tabuleiro1);
    //Adicionando 10 bombas ao tabuleiro Identidade.
    int n=NUMERO_BOMBAS;
    while(n--){
        bomba(tabuleiro2);//Apenas o tabuleiro identidade vai para o procedimento.
    }
   
}
void imprimirTabuleiro(char tabuleiro1[ORDEM][ORDEM]){
    int i, j;
    for(i=0; i<ORDEM;i++){
        for(j=0;j<ORDEM;j++){
            printf("%c ", tabuleiro1[i][j]);
        }printf("\n");
    }
}
int main(){
    int i, numeroDaBomba;
    
    printf("SEJA BEM-VINDO AO MEU CAMPO MINADO EM C!!!!!!!!!\n");
    printf("Atencao as regras do jogo: \n\n");
    char tabuleiroUsuario[ORDEM][ORDEM], tabuleiroIdentidade[ORDEM][ORDEM];//Um será mostrado ao usuário e outro não.
    //Chamando procedimentos de preencher tabuleiro
    configuraTabuleiro(tabuleiroUsuario, tabuleiroIdentidade);
    imprimirTabuleiro(tabuleiroUsuario);
    
    

    
    return 0;
}
