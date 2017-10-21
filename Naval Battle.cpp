#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define N 5
#define M 10

//FUNÇÕES MODO FACIL E MEDIO
void iniciatabuleirofacil(int tabuleirofacil[][N],int g_tiro[200]);
void mostrartabuleirofacil(int tabuleirofacil[][N]);
void sorteionaviofacil(int naviofacil[][2]);
void alteratabuleirofacil(int tiro[2], int naviofacil[][2], int tabuleirofacil[][N]);
int acertoufacil(int tiro[2], int naviofacil[][2]);
void dica (int tiro[2], int naviofacil[][2], int tentativa);

//FUNÇÕES MODO DIFICIL
void iniciatabuleirodificil(int tabuleirodificil[][M],int g_tiro[200]);
void mostrartabuleirodificil(int tabuleirodificil[][M]);
void sorteionaviodificil(int naviodificil[][2]);
void alteratabuleirodificil(int tiro[2], int naviodificil[][2], int tabuleirodificil[][M]);
int acertoudificil(int tiro[2], int naviodificil[][2]);

//FUNÇÕES DOIS JOGADORES
void iniciatabuleiros(int tabuleiro1[][N], int tabuleiro2[][N]);
void mostrartabuleiro1(int tabuleiro1[][N],int tentativa2);
void mostrartabuleiro2(int tabuleiro2[][N], int tentativa1);
void sorteionavio1(int navio1[][2],int g_tiro1[50]);
void sorteionavio2(int navio2[][2],int g_tiro2[50]);
int acertou1(int tiro[2], int navio1[][2]);
int acertou2(int tiro[2], int navio2[][2]);
void alteratabuleiro1(int tiro[2], int navio1[][2], int tabuleiro1[][N]);
void alteratabuleiro2(int tiro[2], int navio2[][2], int tabuleiro2[][N]);
void dartiro1(int tiro[2], int g_tiro1[50], int *i);
void dartiro2(int tiro[2], int g_tiro2[50], int *j);
void iniciagtiro(int g_tiro1[50],int g_tiro2[50]);

//FUNÇÕES TODOS OS MODOS
void dartiro(int tiro[2],int g_tiro[200],int* i);

//RANKING
struct Ranking{
	char Nome[4];
	int Pontos;
}Medio[10],Dificl[10];

int main(){
	
	int i,j,opc,tiro[2],g_tiro[200],tentativa,acerto; //Variáveis usadas em todos ou quase todos os modos
	int tabuleirofacil[N][N],naviofacil[3][2]; //Variaveis modo facil
	int tabuleirodificil[M][M],naviodificil[6][2]; //Variáveis modo dificil
	int tabuleiro1[N][N],tabuleiro2[N][N],navio1[3][2],navio2[3][2],g_tiro1[50],g_tiro2[50],tentativa1,tentativa2,acerto1,acerto2; //variáveis modo 2 jogadores
	int rank_facil[M][1],rank_dificil[M][1];
	char sair,nome_facil[M][N],nome_dificil[M][N];
		
	do{
		system("cls");
		printf("\t\t\tBATALHA NAVAL\n\n");
		printf("\t1 - 1 JOGADOR\n");
		printf("\t2 - 2 JOGADORES\n");
		printf("\t3 - INSTRUCOES\n");
		printf("\t4 - RANKING(Em Construcao)\n");
		printf("\t5 - SAIR\n");
		printf("\tOpcao: ");
		fflush(stdin);
		scanf("%d",&opc);
		switch(opc){
			case 1: //1 Jogador
				system("cls");
				printf("\t\t\tBATALHA NAVAL\n\n");
				printf("\t1 - FACIL\n");
				printf("\t2 - MEDIO\n");
				printf("\t3 - DIFICL\n");
				printf("\t4 - VOLTAR\n");
				printf("\tOpcao: ");
				fflush(stdin);
				scanf("%d",&opc);
				switch(opc){
					case 1: //Facil
						i=0;
						tentativa=0;
						acerto=0;
						system("cls");
						iniciatabuleirofacil(tabuleirofacil,g_tiro);
						sorteionaviofacil (naviofacil);
						printf("\n\n\n\n\n\n");
						do{
							mostrartabuleirofacil(tabuleirofacil);
							dartiro(tiro,g_tiro,&i);
							tentativa++;
					
							if(acertoufacil(tiro,naviofacil)){
								system("cls");
								dica(tiro,naviofacil,tentativa);
								acerto++;
							}else{
								system("cls");
								dica(tiro,naviofacil,tentativa);
								printf("\n\t\t\t\tAgua!!!!");
							}
							alteratabuleirofacil(tiro,naviofacil,tabuleirofacil);
							printf("\n\n\n\n\n\n");
						}while(acerto != 3);
						system("cls");
						printf("\n\n\tJogo terminado. Voce acertou os 3 navios em %d tentativas",tentativa);
						printf("\n\n\n\n\n\n");
						mostrartabuleirofacil(tabuleirofacil);
						printf("\n\n");
						system("pause");
						break;
					
					case 2: //Medio
						i=0;
						tentativa=0;
						acerto=0;
						system("cls");
						iniciatabuleirofacil(tabuleirofacil,g_tiro);
						sorteionaviofacil (naviofacil);
						printf("\n\n\n\n\n\n");
						do{
							mostrartabuleirofacil(tabuleirofacil);
							dartiro(tiro,g_tiro,&i);
							tentativa++;
					
							if(acertoufacil(tiro,naviofacil)){
								system("cls");
								printf("Tentativas: %d\n",tentativa);
								acerto++;
							}else{
								system("cls");
								printf("Tentativas: %d\n\t\tAgua!!",tentativa);
							}
							alteratabuleirofacil(tiro,naviofacil,tabuleirofacil);
							printf("\n\n\n\n\n\n");
						}while(acerto != 3);
												system("cls");
						printf("\n\n\tJogo terminado. Voce acertou os 3 navios em %d tentativas",tentativa);
						printf("\n\n\n\n\n\n");
						mostrartabuleirofacil(tabuleirofacil);
						printf("\n\n");
						system("pause");
						break;
					
					case 3: //Difícil
						i=0;
						tentativa=0;
						acerto=0;
						system("cls");
						iniciatabuleirodificil(tabuleirodificil,g_tiro);
						sorteionaviodificil(naviodificil);
						printf("\n\n");
						do{
														
							mostrartabuleirodificil(tabuleirodificil);
							dartiro(tiro,g_tiro,&i);
							tentativa++;
							
							if(acertoudificil(tiro,naviodificil)){
								system("cls");
								printf("Tentativas: %d\n",tentativa);
								acerto++;
							}else{
								system("cls");
								printf("Tentativas: %d\n\t\tAgua!!",tentativa);
							}
								
							alteratabuleirodificil(tiro,naviodificil,tabuleirodificil);
							printf("\n\n");
						}while(acerto != 6);
						system("cls");
						printf("\n\n\tJogo terminado. Voce acertou os 6 navios em %d tentativas",tentativa);
						printf("\n\n");
						mostrartabuleirodificil(tabuleirodificil);
						printf("\n\n");
						system("pause");
						break;
					
					case 4: //Voltar
						break;
						
					default:
						system("cls");
						printf("Opcao Invalida!!!\n\n");
						system("pause");
						break;
				}
				break;
				
			case 2: //2 Jogadores
				i=0;
				tentativa1=0;
				tentativa2=0;
				acerto1=0;
				acerto2=0;
				iniciatabuleiros(tabuleiro1,tabuleiro2);
				iniciagtiro(g_tiro1,g_tiro2);
				system("cls");
				sorteionavio1(navio1,g_tiro1);
				system("cls");
				sorteionavio2(navio2,g_tiro2);
				system("cls");
				printf("\n\n\n\n\t\t\tCOMECANDO!!\n\n");
				system("pause");
				iniciagtiro(g_tiro1,g_tiro2);
				do{
					//Vez do Jogador 1
					if(acerto2 != 3){
					mostrartabuleiro2(tabuleiro2,tentativa1);
					dartiro1(tiro,g_tiro1,&i);
					tentativa1++;
					if(acertou2(tiro,navio2)){
						system("pause");
						acerto1++;
					}
					else{
						system("cls");
						puts("\n\n\n\n\t\t\tAGUA!!\n\n");
						system("pause");
					}
					alteratabuleiro2(tiro,navio2,tabuleiro2);
					}
					else
					break;
					
					//Vez do Jogador 2
					if(acerto1 != 3){
					mostrartabuleiro1(tabuleiro1,tentativa2);
					dartiro2(tiro,g_tiro2,&j);
					tentativa2++;
					if(acertou1(tiro,navio1)){
						system("pause");
						acerto2++;
					}
					else{
						system("cls");
						puts("\n\n\n\n\t\t\tAGUA!!\n\n");
						system("pause");
					}
					alteratabuleiro1(tiro,navio1,tabuleiro1);
					}
					else
					break;
				}while(acerto1!=3 || acerto2!=3);
				system("cls");
				if(acerto1 == 3){
				printf("\n\n\n\n\t\t\tO JOGADOR 1 FOI O VENCEDOR!!\n\t\t\t  Tentativas: %d\n\n",tentativa1);
				system("pause");
				}
				else{
				printf("\n\n\n\n\t\t\tO JOGADOR 2 FOI O VENCEDOR!!\n\t\t\t  Tentativas: %d\n\n",tentativa2);
				system("pause");
				}
				break;
			
			case 3: //Instruções
				system("cls");
				puts("\t\t\tBATALHA NAVAL\n\n\tA cada rodada, entre com dois numeros, o numero da linha e o numero da  coluna onde quer dar o tiro. Depois eh so esperar pra ver se acertou, ou a dica.\n\tO jogo possui modo facil e dificil, no modo facil o campo de batalha    sera menor, serao 3 navios para destruir e havera dicas. Ja no modo dificil sera um campo maior com 6 barcos e sem dicas.\n\n");
				puts("Legenda:\n~: Agua no bloco, ainda nao foi dado o tiro.\n*: Tiro dado, nao ha nada ali.\nX: Tiro dado, havia um navio ali.\n");
				system("pause");
				break;
			
			case 4: //Ranking
				break;
			
			case 5: //Sair
				system("cls");
				do{
					printf("Deseja sair(s/n): ");
					fflush(stdin);
					sair = getchar();
				}while(sair != 's' && sair != 'n');
				if (sair == 's'){
				puts("\n\n\t\tSAINDO!!\n\n");
				exit(0);
				}else{
				continue;}
				break;
			
			default:
				system("cls");
				printf("Opcao Invalida!!!\n\n");
				system("pause");
				break;
		}
	}while(sair != 's');
	
	return 0;
}

				/*============ FUNÇÔES MODO FACIL E MEDIO =================*/
//Função para iniciar o tabuleiro com -1 que eh quando nao deu neunhum tiro
void iniciatabuleirofacil(int tabuleirofacil[][N],int g_tiro[200]){ 

	int l,c;
	
	for(l=0; l<N; l++){
		for(c=0; c<N; c++){
			tabuleirofacil[l][c] = -1;
		}
	}
	
	for(c=0; c<=99; c++){
		g_tiro[c] = -1;
	}
}

//Função para mostrar tabuleiro ~ = agua, * = tiro errado, X = acertou navio
void mostrartabuleirofacil(int tabuleirofacil[][N]){ 

	int l,c;
	
	printf("\t\t\t1 \t2 \t3 \t4 \t5\n");
	
	for(l=0; l<N; l++){
		printf("\t\t%d ",l+1);
		for(c=0; c<N; c++){
			if(tabuleirofacil[l][c] == -1)
			printf("\t~");
			if(tabuleirofacil[l][c] == 0)
			printf("\t*");
			if(tabuleirofacil[l][c] == 1)
			printf("\tX");
		}
		printf("\n\n");
	}
}

//Função para sortear os 3 navios no tabuleiro usando a função Rand para sortear e verificar se o número ja foi sorteado
void sorteionaviofacil (int naviofacil[][2]){ 

	int l,anterior;
	
	srand(time(NULL));
	
	for(l=0; l<3; l++){
		naviofacil[l][0] = rand()%5;
		naviofacil[l][1] = rand()%5;
		
		//Checar se sorteio for igual
		for(anterior=0; anterior<l; anterior++){
			if(naviofacil[l][0] == naviofacil[anterior][0] && naviofacil[l][1] == naviofacil[anterior][1]){
				do{
					naviofacil[l][0] = rand()%5;
					naviofacil[l][1] = rand()%5;
				}while(naviofacil[l][0] == naviofacil[anterior][0] && naviofacil[l][1] == naviofacil[anterior][1]);
			}
		}
	}
}


//Função para mostrar o acerto retorna verdadeiro
int acertoufacil(int tiro[2], int naviofacil[][2]){
	int l;
	
	for(l=0; l<3; l++){
		if(tiro[0] == naviofacil[l][0] && tiro[1] == naviofacil[l][1]){
			printf("\n\t\t\tVoce acertou o tiro (%d,%d)",tiro[0]+1,tiro[1]+1);
			return 1;
		}
	}
	return 0;
}

//Função que dara dica quando tiver navio perto
void dica (int tiro[2], int naviofacil[][2], int tentativa){
	
	int l=0,c=0,fila;
	
	//Contar quantos navios há na linha de tiro
	for(fila=0; fila<3; fila++){
		if (naviofacil[fila][0] == tiro[0])
		l++;
		if (naviofacil[fila][1] == tiro[1])
		c++;
	}
	
	printf("Dica %d: \nLinha: %d = %d navios\nColuna: %d = %d navios",tentativa,tiro[0]+1,l,tiro[1]+1,c);
}

//Função que ira mudar o tabuleiro em * ou X
void alteratabuleirofacil(int tiro[2], int naviofacil[][2], int tabuleirofacil[][N]){
	
	if (acertoufacil(tiro,naviofacil))
	tabuleirofacil[tiro[0]][tiro[1]] = 1;
	else
	tabuleirofacil[tiro[0]][tiro[1]] = 0;
	
}    


		/*============ FUNÇÔES MODO DIFICIL ================*/
//FUNÇÂO QUE RECEBE -1
void iniciatabuleirodificil(int tabuleirodificil[][M],int g_tiro[200]){
	
	int l,c;
	
	for(l=0; l<M; l++){
		for(c=0; c<M; c++){
			tabuleirodificil[l][c] = -1;
		}
	}
	
	for(c=0; c<200; c++){
		g_tiro[c] = -1;
	}

}   

//FUNÇÂO PARA MOSTRAR O TABULEIRO
void mostrartabuleirodificil(int tabuleirodificil[][M]){
	
	int l,c;
	
	printf("\t    1  2  3  4  5  6  7  8  9  10 ");
	printf("\n");
	for(l=0; l<M; l++){
		printf("\t%2d ",l+1);
		for(c=0; c<M; c++){
			if(tabuleirodificil[l][c] == -1)
			printf(" ~ ");
			if(tabuleirodificil[l][c] == 0)
			printf(" * ");
			if(tabuleirodificil[l][c] == 1)
			printf(" X ");
		}
		printf("\n\n");
	}
}

//FUNÇÂO PARA SORTEAR OS NAVIOS
void sorteionaviodificil(int naviodificil[][2]){
	
	int l,anterior;
	
	srand(time(NULL));
	
	for(l=0; l<6; l++){
		naviodificil[l][0] = rand()%10;
		naviodificil[l][1] = rand()%10;
		
		for(anterior=0; anterior<l; anterior++){
			if(naviodificil[l][0] == naviodificil[anterior][0] && naviodificil[l][1] == naviodificil[anterior][1]){
				do{
					naviodificil[l][0] = rand()%10;
					naviodificil[l][1] = rand()%10;
				}while(naviodificil[l][0] == naviodificil[anterior][0] && naviodificil[l][1] == naviodificil[anterior][1]);
			}
		}
	}
	
}

//FUNÇÃO PARA ALTERAR O TABULEIRO
void alteratabuleirodificil(int tiro[2], int naviodificil[][2], int tabuleirodificil[][M]){
	
	if(acertoudificil(tiro,naviodificil))
	tabuleirodificil[tiro[0]][tiro[1]] = 1;
	else
	tabuleirodificil[tiro[0]][tiro[1]] = 0;
}

//FUNÇÃO PARA MOSTRAR QUE O TIRO ACERTOU O ALVO
int acertoudificil(int tiro[2], int naviodificil[][2]){
	
	int l;	
		
	for(l=0; l<6; l++){
		if(tiro[0] == naviodificil[l][0] && tiro[1] == naviodificil[l][1]){
			printf("\t\t\tVoce acertou o tiro (%d,%d)",tiro[0]+1,tiro[1]+1);
			return 1;
		}
	}
	return 0;
}

/*============ FUNÇÕES USADAS NO MODO FACIL E DIFICIL =============*/
//Função para esolher linha e coluna para ler o tiro
void dartiro(int tiro[2],int g_tiro[200],int *i){ 
	
	int c,x=0;
	
	printf("Linha: ");
	fflush(stdin);
	scanf("%d",&tiro[0]);
	if(tiro[0] < 1 || tiro[0] > 5){
		do{
			puts("Linha inexistente!!\n");
			printf("Informe a linha novamente: ");
			fflush(stdin);
			scanf("%d",&tiro[0]);
		}while(tiro[0] < 1 || tiro[0] > 5);
	}
	tiro[0]--;
	
	printf("Coluna: ");
	scanf("%d",&tiro[1]);
	if(tiro[1] < 1 || tiro[1] > 5){
		do{
			puts("Coluna inexistente!!\n");
			printf("Informe a coluna novamente: ");
			fflush(stdin);
			scanf("%d",&tiro[1]);
		}while(tiro[1] < 1 || tiro[1] > 5);
	}
	tiro[1]--;
	
	for(c=0; c<=*i; c+=2){
		if(x == 1){
			c=0;
			x=0;
		}
		
		if(tiro[0] == g_tiro[c] && tiro[1] == g_tiro[c+1]){
			
			do{
				printf("(%d,%d) ja selecionado!!\n\n",tiro[0]+1,tiro[1]+1);
				printf("Informe a linha novamente: ");
				fflush(stdin);
				scanf("%d",&tiro[0]);
				if(tiro[0] < 1 || tiro[0] > 5){
					do{
						puts("Linha inexistente!!\n");
						printf("Informe a linha novamente: ");
						fflush(stdin);
						scanf("%d",&tiro[0]);
					}while(tiro[0] < 1 || tiro[0] > 5);
				}
				tiro[0]--;		
				printf("Informe a coluna novamente: ");
				fflush(stdin);
				scanf("%d",&tiro[1]);
				if(tiro[1] < 1 || tiro[1] > 5){
					do{
						puts("Coluna inexistente!!\n");
						printf("Informe a coluna novamente: ");
						fflush(stdin);
						scanf("%d",&tiro[1]);
					}while(tiro[1] < 1 || tiro[1] > 5);
				}
				tiro[1]--;
			}while(tiro[0] == g_tiro[c] && tiro[1] == g_tiro[c+1]);
			x=1;
		}
	}
	g_tiro[*i] = tiro[0];
	g_tiro[*i+1] = tiro[1];
	*i+=2;
}


		/*============ FUNÇÕES PARA DOIS JOGADORES ==================*/
//Função para iniciar o navio do jogador 1 e 2
void iniciatabuleiros(int tabuleiro1[][N], int tabuleiro2[][N]){
	
	int l,c;
	
	for(l=0; l<N; l++){
		for(c=0; c<N; c++){
			tabuleiro1[l][c] = -1;
			tabuleiro2[l][c] = -1;
		}
	}
	
}

//Função para iniciar os vetores que guardam os tiros ou navios escolhidos com -1
void iniciagtiro(int g_tiro1[50],int g_tiro2[50]){

	int c;
	
	for(c=0; c<50; c++){
		g_tiro1[c] = -1;
		g_tiro2[c] = -1;
	}
}

//Função que irá mostrar o tabuleiro do jogador 1
void mostrartabuleiro1(int tabuleiro1[][N], int tentativa2){
	
	int l,c;
	
	system("cls");
	
	puts("\t\t\tVez do jogador 2\n");
	printf("Tentativas: %d",tentativa2);
	printf("\n\n\n\n\t\t\t1 \t2 \t3 \t4 \t5\n");
	
	for(l=0; l<N; l++){
		printf("\t\t%d ",l+1);
		for(c=0; c<N; c++){
			if(tabuleiro1[l][c] == -1)
			printf("\t~ ");
			if(tabuleiro1[l][c] == 0)
			printf("\t* ");
			if(tabuleiro1[l][c] == 1)
			printf("\tX ");
		}
		printf("\n\n");
	}
}

//Função que irá mostrar o tabuleiro do jogador 2
void mostrartabuleiro2(int tabuleiro2[][N], int tentativa1){
	
	int l,c;
	
	system("cls");
	
	puts("\t\tVez do jogador 1\n");
	printf("Tentativas: %d",tentativa1);
	printf("\n\n\n\n\t\t\t1 \t2 \t3 \t4 \t5\n");
	
	for(l=0; l<N; l++){
		printf("\t\t%d ",l+1);
		for(c=0; c<N; c++){
			if(tabuleiro2[l][c] == -1)
			printf("\t~ ");
			if(tabuleiro2[l][c] == 0)
			printf("\t* ");
			if(tabuleiro2[l][c] == 1)
			printf("\tX ");
		}
		printf("\n\n");
	}
}

//Função para esolher as posições dos navios do jogador 1
void sorteionavio1(int navio1[][2],int g_tiro1[50]){
	
	int l,guardar,i=0,x=0;
	
	puts("\n\n\n\t\t\tSELECAO DE NAVIOS DO JOGADOR 1\n\n");
	system("pause");
	
	for(l=0; l<3; l++){
		system("cls");
		printf("\t\tSelecione o %do. navio do tabuleiro 1\n\n",l+1);
		printf("Informe a linha do navio %d: ",l+1);
		fflush(stdin);
		scanf("%d",&navio1[l][0]);
		if(navio1[l][0] < 1 || navio1[l][0] > 5){
			do{
				puts("Linha inexistente!!\n");
				printf("Informe a linha do navio %d: ",l+1);
				fflush(stdin);
				scanf("%d",&navio1[l][0]);
			}while(navio1[l][0] < 1 || navio1[l][0] > 5);
		}
		navio1[l][0]--;
		printf("Informe a coluna do navio %d: ",l+1);
		fflush(stdin);
		scanf("%d",&navio1[l][1]);		
		if(navio1[l][1] < 1 || navio1[l][1] > 5){
			do{
				puts("Coluna inexistente!!\n");
				printf("Informe a coluna do navio %d: ",l+1);
				fflush(stdin);
				scanf("%d",&navio1[l][1]);
			}while(navio1[l][1] < 1 || navio1[l][1] > 5);
		}
		navio1[l][1]--;
		for (guardar=0; guardar<=i; guardar+=2){
			if(x == 1){
				guardar=0;
				x=0;
			}
			if(navio1[l][0] == g_tiro1[guardar] && navio1[l][1] == g_tiro1[guardar+1]){
				do{
							printf("(%d,%d) ja selecionado!!\n\n",navio1[l][0]+1,navio1[l][1]+1);
							printf("Informe a linha do navio %d: ",l+1);
							fflush(stdin);
							scanf("%d",&navio1[l][0]);
							if(navio1[l][0] < 1 || navio1[l][0] > 5){
								do{
									puts("Linha inexistente!!\n");
									printf("Informe a linha do navio %d: ",l+1);
									fflush(stdin);
									scanf("%d",&navio1[l][0]);
								}while(navio1[l][0] < 1 || navio1[l][0] > 5);
							}
							navio1[l][0]--;
							printf("Informe a coluna do navio %d: ",l+1);
							fflush(stdin);
							scanf("%d",&navio1[l][1]);
							if(navio1[l][1] < 1 || navio1[l][1] > 5){
								do{
									puts("Coluna inexistente!!\n");
									printf("Informe a coluna do navio %d: ",l+1);
									fflush(stdin);
									scanf("%d",&navio1[l][1]);
								}while(navio1[l][1] < 1 || navio1[l][1] > 5);
							}
							navio1[l][1]--;
				}while(navio1[l][0] == g_tiro1[guardar] && navio1[l][1] == g_tiro1[guardar+1]);
				x=1;
			}
		}
		puts("");
		printf("\t\t\t%do. navio posicionado (%d,%d)\n\n",l+1,navio1[l][0]+1,navio1[l][1]+1);
		system("pause");
		g_tiro1[i] = navio1[l][0];
		g_tiro1[i+1] = navio1[l][1];
		i+=2;
	}
}

//Função para esolher as posições dos navios do jogador 2
void sorteionavio2(int navio2[][2],int g_tiro2[50]){
	
	int l,guardar,i=0,x=0;
	
	puts("\n\n\n\t\t\tSELECAO DE NAVIOS DO JOGADOR 2\n\n");
	system("pause");
	
	for(l=0; l<3; l++){
		system("cls");
		printf("\t\tSelecione o %do. navio do tabuleiro 2\n\n",l+1);
		printf("Informe a linha do navio %d: ",l+1);
		fflush(stdin);
		scanf("%d",&navio2[l][0]);
		if(navio2[l][0] < 1 || navio2[l][0] > 5){
			do{
				puts("Linha inexistente!!\n");
				printf("Informe a linha do navio %d: ",l+1);
				fflush(stdin);
				scanf("%d",&navio2[l][0]);
			}while(navio2[l][0] < 1 || navio2[l][0] > 5);
		}
		navio2[l][0]--;
		printf("Informe a coluna do navio %d: ",l+1);
		fflush(stdin);
		scanf("%d",&navio2[l][1]);		
		if(navio2[l][1] < 1 || navio2[l][1] > 5){
			do{
				puts("Coluna inexistente!!\n");
				printf("Informe a coluna do navio %d: ",l+1);
				fflush(stdin);
				scanf("%d",&navio2[l][1]);
			}while(navio2[l][1] < 1 || navio2[l][1] > 5);
		}
		navio2[l][1]--;
		for (guardar=0; guardar<=i; guardar++){
			if(x == 1){
				guardar=0;
				x=0;
			}
			if(navio2[l][0] == g_tiro2[guardar] && navio2[l][1] == g_tiro2[guardar+1]){
				do{
							printf("(%d,%d) ja selecionado!!\n\n",navio2[l][0]+1,navio2[l][1]+1);
							printf("Informe a linha do navio %d: ",l+1);
							fflush(stdin);
							scanf("%d",&navio2[l][0]);
							if(navio2[l][0] < 1 || navio2[l][0] > 5){
								do{
									puts("Linha inexistente!!\n");
									printf("Informe a linha do navio %d: ",l+1);
									fflush(stdin);
									scanf("%d",&navio2[l][0]);
								}while(navio2[l][0] < 1 || navio2[l][0] > 5);
							}
							navio2[l][0]--;
							printf("Informe a coluna do navio %d: ",l+1);
							fflush(stdin);
							scanf("%d",&navio2[l][1]);
							if(navio2[l][1] < 1 || navio2[l][1] > 5){
								do{
									puts("Coluna inexistente!!\n");
									printf("Informe a coluna do navio %d: ",l+1);
									fflush(stdin);
									scanf("%d",&navio2[l][1]);
								}while(navio2[l][1] < 1 || navio2[l][1] > 5);
							}
							navio2[l][1]--;
				}while(navio2[l][0] == g_tiro2[guardar] && navio2[l][1] == g_tiro2[guardar+1]);
				x=1;
			}
		}
		puts("");
		printf("\t\t\t%do. navio posicionado (%d,%d)\n\n",l+1,navio2[l][0]+1,navio2[l][1]+1);
		system("pause");
		g_tiro2[i] = navio2[l][0];
		g_tiro2[i+1] = navio2[l][1];
		i+=2;
	}
}

//Função que irá mostrar que o jogador 1 acertou o tiro
int acertou1(int tiro[2], int navio1[][2]){
	
	int l;
	
	for(l=0; l<3; l++){
		if(tiro[0] == navio1[l][0] && tiro[1] == navio1[l][1]){
			system("cls");
			printf("\n\n\n\n\t\t\tJogador 2 acertou o tiro (%d,%d)\n\n",tiro[0]+1,tiro[1]+1);
			return 1;
		}
	}
	return 0;
}

//Função que irá mostrar que o jogador 2 acertou o tiro
int acertou2(int tiro[2], int navio2[][2]){
	
	int l;
	
	for(l=0; l<3; l++){
		if(tiro[0] == navio2[l][0] && tiro[1] == navio2[l][1]){
			system("cls");
			printf("\n\n\n\n\t\t\tJogador 1 acertou o tiro (%d,%d)\n\n",tiro[0]+1,tiro[1]+1);
			return 1;
		}
	}
	return 0;
}


//função para mudar o tabuleiro do jogador 1 para * ou X
void alteratabuleiro1(int tiro[2], int navio1[][2], int tabuleiro1[][N]){
	
	if(acertou1(tiro,navio1))
	tabuleiro1[tiro[0]][tiro[1]] = 1;
	else
	tabuleiro1[tiro[0]][tiro[1]] = 0;
}

//função para mudar o tabuleiro do jogador 2 para * ou X
void alteratabuleiro2(int tiro[2], int navio2[][2], int tabuleiro2[][N]){
	
	if(acertou2(tiro,navio2))
	tabuleiro2[tiro[0]][tiro[1]] = 1;
	else
	tabuleiro2[tiro[0]][tiro[1]] = 0;
}

//Função para escolher a linha e a coluna para o jogador 1 dar o tiro
void dartiro1(int tiro[2], int g_tiro1[50], int *i){
	int c,x=0;
	
	printf("Linha: ");
	fflush(stdin);
	scanf("%d",&tiro[0]);
	if(tiro[0] < 1 || tiro[0] > 5){
		do{
			puts("Linha inexistente!!\n");
			printf("Informe a linha novamente: ");
			fflush(stdin);
			scanf("%d",&tiro[0]);
		}while(tiro[0] < 1 || tiro[0] > 5);
	}
	tiro[0]--;
	
	printf("Coluna: ");
	fflush(stdin);
	scanf("%d",&tiro[1]);
	if(tiro[1] < 1 || tiro[1] > 5){
		do{
			puts("Coluna inexistente!!\n");
			printf("Informe a coluna novamente: ");
			fflush(stdin);
			scanf("%d",&tiro[1]);
		}while(tiro[1] < 1 || tiro[1] > 5);
	}
	tiro[1]--;
	
	for(c=0; c<=*i; c+=2){
		if(x == 1){
			c=0;
			x=0;
		}
		if(tiro[0] == g_tiro1[c] && tiro[1] == g_tiro1[c+1]){
			do{
				printf("(%d,%d) ja selecionado!!\n\n",tiro[0]+1,tiro[1]+1);
				printf("Informe a linha novamente: ");
				fflush(stdin);
				scanf("%d",&tiro[0]);
				if(tiro[0] < 1 || tiro[0] > 5){
					do{
						puts("Linha inexistente!!\n");
						printf("Informe a linha novamente: ");
						fflush(stdin);
						scanf("%d",&tiro[0]);
					}while(tiro[0] < 1 || tiro[0] > 5);
				}
				tiro[0]--;		
				printf("Informe a coluna novamente: ");
				fflush(stdin);
				scanf("%d",&tiro[1]);
				if(tiro[1] < 1 || tiro[1] > 5){
					do{
						puts("Coluna inexistente!!\n");
						printf("Informe a coluna novamente: ");
						fflush(stdin);
						scanf("%d",&tiro[1]);
					}while(tiro[1] < 1 || tiro[1] > 5);
				}
				tiro[1]--;
			}while(tiro[0] == g_tiro1[c] && tiro[1] == g_tiro1[c+1]);
			x=1;
		}
	}
	g_tiro1[*i] = tiro[0];
	g_tiro1[*i+1] = tiro[1];
	*i+=1;
}

//Função para escolher a linha e a coluna para o jogador 2 dar o tiro
void dartiro2(int tiro[2], int g_tiro2[50], int *j){
	int c,x=0;
	
	printf("Linha: ");
	fflush(stdin);
	scanf("%d",&tiro[0]);
	if(tiro[0] < 1 || tiro[0] > 5){
		do{
			puts("Linha inexistente!!\n");
			printf("Informe a linha novamente: ");
			fflush(stdin);
			scanf("%d",&tiro[0]);
		}while(tiro[0] < 1 || tiro[0] > 5);
	}
	tiro[0]--;
	
	printf("Coluna: ");
	fflush(stdin);
	scanf("%d",&tiro[1]);
	if(tiro[1] < 1 || tiro[1] > 5){
		do{
			puts("Coluna inexistente!!\n");
			printf("Informe a coluna novamente: ");
			fflush(stdin);
			scanf("%d",&tiro[1]);
		}while(tiro[1] < 1 || tiro[1] > 5);
	}
	tiro[1]--;
	
	for(c=0; c<=*j; c+=2){
		if(x == 1){
			c=0;
			x=0;
		}
		if(tiro[0] == g_tiro2[c] && tiro[1] == g_tiro2[c+1]){
			do{
				printf("(%d,%d) ja selecionado!!\n\n",tiro[0]+1,tiro[1]+1);
				printf("Informe a linha novamente: ");
				fflush(stdin);
				scanf("%d",&tiro[0]);
				if(tiro[0] < 1 || tiro[0] > 5){
					do{
						puts("Linha inexistente!!\n");
						printf("Informe a linha novamente: ");
						fflush(stdin);
						scanf("%d",&tiro[0]);
				}while(tiro[0] < 1 || tiro[0] > 5);
				}
				tiro[0]--;		
				printf("Informe a coluna novamente: ");
				fflush(stdin);
				scanf("%d",&tiro[1]);
				if(tiro[1] < 1 || tiro[1] > 5){
					do{
						puts("Coluna inexistente!!\n");
						printf("Informe a coluna novamente: ");
						fflush(stdin);
						scanf("%d",&tiro[1]);
					}while(tiro[1] < 1 || tiro[1] > 5);
				}
				tiro[1]--;
			}while(tiro[0] == g_tiro2[c] && tiro[1] == g_tiro2[c+1]);
			x=1;
		}
	}
	g_tiro2[*j] = tiro[0];
	g_tiro2[*j+1] = tiro[1];
	*j+=2;
}					

