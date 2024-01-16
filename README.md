# Campo Minado 9x9
Bem-vindo ao jogo clássico do Campo Minado! Neste projeto, implementamos um Campo Minado com uma grade de 9x9 células e 10 bombas espalhadas aleatoriamente. Este README fornecerá informações sobre como jogar, as regras do jogo e como executar o código.

## Como Jogar
O objetivo do Campo Minado é descobrir todas as células sem bombas, evitando tocar em qualquer célula que contenha uma bomba. Cada célula aberta revelará um número que indica quantas bombas estão adjacentes a essa célula. Use essas dicas para determinar a localização das bombas e continue abrindo células até que todas as células seguras sejam descobertas.

## Regras do Jogo
1. Células Numeradas: Cada célula aberta exibirá um número que representa a quantidade de bombas adjacentes.
Bomba Acidental: Se você abrir uma célula com uma bomba, o jogo termina.
2. Vitória: O jogo é vencido quando todas as células seguras são descobertas.
3. Marcação de Bombas: Você pode marcar células suspeitas de conterem bombas com uma bandeira. Use isso estrategicamente!
## Como Executar o Código
Siga estas etapas para executar o código:

### 1. Requisitos:

Certifique-se de ter uma versão compatível de uma linguagem de programação instalada(gcc).
Baixe os arquivos do projeto para o seu computador.
### 2. Execução:

Abra o terminal na pasta do projeto.
Execute o arquivo principal (por exemplo, program.c) usando o gcc.
```C
gcc program.c -o program.exe
..\program.exe
```
### 1. Jogue:
Siga as instruções no console para interagir com o jogo.
Use coordenadas para abrir células (Linha, Coluna).
## Contribuições
Contribuições são bem-vindas! Se encontrar problemas ou tiver sugestões de melhoria, abra uma issue neste repositório.

Divirta-se jogando Campo Minado!
