#include <stdio.h>
#include <stdlib.h>

//regras de aplicação
const int ORDEM = 10; // ORDEM=10
const int JOGADAS = 72;//numero maximo de jogadas.
const int NUMERO_BOMBAS = 10; //numero de bombas

int ehBomba(char tabuleiro[ORDEM][ORDEM], int x, int y){
    if(tabuleiro[x][y] == '*'){
        return 1; //True == BOMBA.
    }
    return 0; //False == Sem bomba.
}
void adicionarCoordenadas(char tabuleiroUsuario[ORDEM][ORDEM]){
    int i, j, varAuxiliar=1;
    //Laço pra percorrer o vetor e adicionar '-'
    for(i=0; i<ORDEM;i++){
        for(j=0; j<ORDEM;j++){
            if(i==0 && j==0){
                tabuleiroUsuario[i][j] = ' '; //Na posição 0,0 o tabuleiro fica vazio.
            }else{
                tabuleiroUsuario[i][j] = '-';
            }
        }
    }
    //Laço pra adicionar as coordenadas
    for(j=1; j<ORDEM;j++){
        tabuleiroUsuario[j][0] = varAuxiliar + '0';//Adicionando coordenadas as linhas, lembrando que há uma conversão de int pra char.
        tabuleiroUsuario[0][j] = varAuxiliar + '0';//Adicionando coordenadas as colunas, lembrando que há uma conversão de int pra char.
        varAuxiliar++;
    }
}
void bomba(char tabuleiro2[ORDEM][ORDEM]){
    int i, j, x, y;//Inicializando variavel do laço
    srand(time(NULL));//Inicializando a função rand().
    for(i=0;i<ORDEM; i++){
        x = (rand() % 8) + 2;//Gerar numero entre 2 e 9
        for(j=0; j<ORDEM; j++){
            y = (rand() % 8) + 2;//Gerar numero entre 2 e 9
        }tabuleiro2[x][y] = '*';
    }
}
void configuraTabuleiro(char tabuleiro1[ORDEM][ORDEM], char tabuleiro2[ORDEM][ORDEM]){
    adicionarCoordenadas(tabuleiro1); adicionarCoordenadas(tabuleiro2);
    //Adicionando 10 bombas ao tabuleiro Identidade.
    int n;
    for(n=0; n<NUMERO_BOMBAS; n++){
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
int verificaAdjacente(char tabuleiro2[ORDEM][ORDEM], int x, int y){
    //Função pra verificar se há bomba nos adjacentes da posição.
//                 a    b    c
//                  \   |   /
//                      \  |  /
//                d---- i ----h
//                     / | \
//                   /   |  \
//                  e    f   g
    
    int a, b, c, d, e, f, g, h;
    a = ehBomba(tabuleiro2, x-1, y-1);
    b = ehBomba(tabuleiro2, x-1, y);
    c = ehBomba(tabuleiro2, x-1, y+1);
    d = ehBomba(tabuleiro2, x, y-1);
    e = ehBomba(tabuleiro2, x+1, y-1);
    f = ehBomba(tabuleiro2, x+1, y);
    g = ehBomba(tabuleiro2, x+1, y+1);
    h = ehBomba(tabuleiro2, x, y+1);
    //Se retornar 1, então a pos tem uma bomba, se não retorna 0.
    return a+b+c+d+e+f+g+h;
}
int jogada(char tabuleiro1[ORDEM][ORDEM], char tabuleiro2[ORDEM][ORDEM], int x, int y){
    int aux1 = ehBomba(tabuleiro2, x, y);
    if(aux1 == 1){
        return 1;//True == O jogador achou uma bomba.
    }else{
        int aux2 = verificaAdjacente(tabuleiro2, x, y);
        tabuleiro1[x][y] = aux2 + '0';//Adicionando ao tabuleiro a jogada.
        tabuleiro2[x][y] = aux2 + '0';//Adicionando também ao tabuleiro Identidade.
        return 0;//False == O jogador não achou uma bomba.
    }
}
int main(){
    //Declaração de Variáveis
    int i, coordX, coordY, fim;
    
    printf("SEJA BEM-VINDO AO MEU CAMPO MINADO EM C!!!!!!!!!\n");
    printf("Atencao as regras do jogo: \n\n");
    printf("Digite as coordenadas: Linha x Coluna. Por favor, atenção nas coordenadas dos pontos;\n\n");
    char tabuleiroUsuario[ORDEM][ORDEM], tabuleiroIdentidade[ORDEM][ORDEM];//Um será mostrado ao usuário e outro não.
    //Chamando procedimentos de preencher tabuleiro
    configuraTabuleiro(tabuleiroUsuario, tabuleiroIdentidade);
    imprimirTabuleiro(tabuleiroUsuario);
    //Laço de Jogadas
    for(i=0; i<JOGADAS; i++){
        printf("Insira as coordenadas do ponto: ");
        scanf("%d%d", &coordX, &coordY);
        int varAux = jogada(tabuleiroUsuario, tabuleiroIdentidade, coordX, coordY);
        if(varAux == 1){
            printf("BBBBBOOOOOOOOMMMM!!!!!\nGame Over pra voce! Voce encontrou uma bomba.\n\n");
            printf("Essa eram as posicoes das bombas: \n\n");
            imprimirTabuleiro(tabuleiroIdentidade);
            break;
        }else{
            imprimirTabuleiro(tabuleiroUsuario);
            //Resetando variaveis
            coordX = 0, coordY = 0;
        }
    } 
    if(i == JOGADAS-1){
    	printf("Voce venceu o jogo!!!!! Parabens, pequeno gafanhoto.\n");
	}
    return 0;
}
