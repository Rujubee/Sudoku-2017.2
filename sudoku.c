#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <time.h>
#define N 9

int numero, linha, coluna;


void desenha_grade(int grade[N][N]) {
  int i,j;
  printf("  1  2  3   4  5  6   7  8  9  \n");
  printf("+---------+---------+---------+\n");
  for (i = 0; i < N; i++) {
	printf("|");
	for (j = 0; j < N; j++) {
	  if (grade[i][j] != 0)
	printf(" %d ", grade[i][j]);
	  else
	printf("   ");
	  if (j % 3 == 2)
	printf("|");
	}
	if (i % 3 == 2)
	  printf("\n+---------+---------+---------+");
	printf("\n");
  }
}




//------------------
//-------------------

/* void marca_tempo(){   //FUNÇÃO PARA MARCAR O TEMPO JOGADO
	float tempo;
	int i, j;
	time_t t_inicio, t_final;
		t_inicio = time(NULL);
			for(i = 0; i < 50000; i++){
				for(j = 0; j < 50000; j++);
			}
		t_final = time(NULL);
			tempo = difftime(t_final, t_inicio);
				printf("Tempo marcado: %f\n", tempo);

}  */

//--------------------
//--------------------

int verificar_linha(int grade[N][N], int linha, int coluna, int numero){
    int j;
    for (j=0; j<9; j++){
        if (j != coluna){
            if (grade[linha][j] == numero){
                return 0;
	    }
	}else{
		return 1;
    	}
    }
}

//---------------------
//---------------------


int verificar_coluna(int grade[N][N], int linha, int coluna, int numero){
    int i;
    for (i=0; i<9; i++){
        if (i != linha){
            if (grade[i][coluna] == numero){
                return 0;
	    }
	}else {
	        return 1;
	}
    }
}


//------------------
//------------------
int verificar_posicao(int grade[N][N], int linha, int coluna, int numero){
	if (grade[linha][coluna]==0){
		 return 1;
	 
	 }else{
	         return 0;
	 }
}
//-------------------
//------------------
int numeros_possiveis(int numero)
{
  if(numero>0 && numero <=9)
	 return 1;
   else
	  return 0;

}


//---------------------
//-------------------

int testar_jogada(int grade[N][N], int linha, int coluna, int numero){
    if (verificar_posicao(grade, linha, coluna, numero) == 1  && verificar_coluna(grade, linha, coluna, numero) == 1 && verificar_linha(grade, linha, coluna, numero) == 1 && numeros_possiveis(numero) ==1){
      printf("     ✵✵--------------✵✵\n");
      printf("       Jogada Inserida\n");
      printf("          ✵✵----✵✵\n\n");
      return 1;
    }else{
	return 0;
    }
}

//---------------------
//---------------------


void remover_jogada(int grade[N][N],int grade2[N][N], int linha, int coluna){ //FUNÇÃO PARA REMOVER UMA JOGADA FEITA
    printf("Digite uma linha: ");
          scanf("%d", &linha);
	  linha = linha-1;

      printf("Digite uma coluna: ");
          scanf("%d", &coluna);
	  coluna = coluna-1;

      if(grade2[linha][coluna]==0){
      grade[linha][coluna]=0;
      system ("clear");

      printf("     ✵✵--------------✵✵\n");
      printf("       Jogada Removida\n");
      printf("          ✵✵----✵✵\n\n");
      }else{
      system("clear");
      printf("\n     ✵✵----------------------------------✵✵\n");
      printf("        O número não pode ser removido,\n"); 
      printf("       pois já foi predefinido pelo jogo!\n");
      printf("              ✵✵---------------✵✵\n");
				}	
}

//-----------------------
//----------------------

   int menu_2 (int solucao[9][9], int grade[N][N], int grade2[N][N]){
   int menu2;
   int linha, coluna, numero;
   int teste;
   int i, j;
    system("clear");

	do{
	desenha_grade(grade);
   	printf("Selecione uma opção: \n  (1) ✵ Inserir Jogada\n  (2) ✵ Remover Jogada\n  (3) ✵ Verificar se está correto\n  (4) ✵ Mostrar Solução\n  (0) ✵ Retornar ao menu principal\n\n");
  	scanf("%d", &menu2);
  	 switch(menu2){
  		 case 1:

  		 printf("Digite uma linha: ");
   		 scanf("%d", &linha);
		 linha = linha-1;

   		 printf("Digite uma coluna: ");
                 scanf("%d", &coluna);
		 coluna = coluna-1;
   	         printf("Digite o numero: ");
   		 scanf("%d", &numero);
   		 printf("\n \n");

   		 system ("clear\n\n");

   	 	 teste = testar_jogada(grade, linha, coluna, numero);
   		 if(teste == 1){
  		 	grade[linha][coluna]=numero;
                 }else{
			printf("✵✵--------------✵✵--------------✵✵\n");
       			printf(" ERRO! Já existe na linha ou coluna\n");
			printf("   ou a posição já está ocupada.\n");
			printf("        Tente Novamente:\n");
		        printf("        ✵✵----✵✵----✵✵ \n\n");
		 }
  		 break;
  		 case 2:
          	  remover_jogada(grade, grade2, linha, coluna);
 		 break;
		 case 3:
        	 if(grade[N][N]==solucao[N][N]){
                 printf("     ✵✵--------------✵✵\n");
                 printf("       SOLUÇÃO CORRETA!\n");
		 printf("          PARABÉNS!\n");
                 printf("          ✵✵----✵✵\n\n");
                 }else{
                 printf("     ✵✵------------------✵✵\n");
      		 printf("       SOLUÇÃO INCORRETA! :(\n");
      		 printf("          ✵✵------✵✵\n\n");
		 }
                 break;
		 case 4:
       		 system ("clear");
      		 printf("     ✵✵--------------✵✵\n");
      		 printf("       SOLUÇÃO CORRETA:\n");
      		 printf("          ✵✵----✵✵\n\n");
       		 desenha_grade(solucao);
       		 printf("\nVOCÊ RETORNOU AO MENU PRINCIPAL.\n"); 
       		 printf("     O QUE DESEJA FAZER?\n\n");
       		 return 0;
       		 break;
		 case 5:
	         break;
		 case 0: system ("clear");
		 return 0;
   		 default:
		 system("clear"); 
		 printf("✵✵------------------------------✵✵\n");
                 printf("  OPÇÃO INVÁLIDA. TENTE NOVAMENTE: \n");
                 printf("      ✵✵----------------✵✵\n\n");
   	}
   } while(menu2);
   }

// --------------------
// --------------------

void chamar_grade_aleat(){ 
	char str[40];
	int i, j, x, grade[N][N], grade2[N][N], solucao[N][N];
	srand(time(NULL));
	int ram;
	ram = 1 + rand () % 3;
	sprintf(str,"mat/mat%d.txt", ram);
	
	FILE *p=fopen(str, "r");
	for (i=0; i<9; i++){
	for (j=0; j<9; j++){
	fscanf(p,"%d", &solucao[i][j]);
	}
	}	
	for (i=0; i<9; i++){
	for (j=0; j<9; j++){
	grade[i][j]=solucao[i][j];
	}
	}
	for(i=0; i<9; i++){
	x= 6 + rand() %7;
	for(x; x>0; x--){
	j=rand() %9;
	grade[i][j]=0;
	}
	}	

	for (i=0; i<9; i++){
	for (j=0; j<9; j++){
	grade2[i][j]=grade[i][j];
	}
	}

	menu_2 (solucao, grade, grade2);
}




// ----------------------
//----------------------

int main() {
	int menu;
	int x;
               system("clear");
	       setlocale(LC_ALL, "Portuguese");
	       printf("\n     ✵✵-----------✵✵-----------✵✵\n");
               printf("  BEM-VINDX AO SUDOKU  - THE  PUZZLE!\n");
               printf("  ✵✵----✵✵--------✵✵------✵✵----✵✵\n\n");
		do{
		printf(" -> SELECIONE UMA DAS OPÇÕES ABAIXO:\n\n (1) Ver as instruções do jogo\n (2) Iniciar um novo jogo aleatório\n (0) Sair\n");
		scanf("%d", &menu);
		printf("\n\n");

		switch (menu){
			case 1: printf("\t   ----✵✵----\n\t   INSTRUÇÕES:\n\t   ----✵✵----\n\n O objetivo do jogo é completar todos\n os 9 quadrados utilizando números de 1 a 9.\n Para completá-los, é necessário que:\n\n ✵ Não haja numeros repetidos nas linhas horizontais e verticais.\n ✵ Não se repita números no mesmo quadrado.\n");
			printf("\n  -> Digite 0 para retornar ao menu.\n  -> Digite 1 para iniciar um jogo\n");
			scanf("%d", &x);
			if(x==0){
			system ("clear");
			return main();
			}else{
			chamar_grade_aleat();
			}
			break;
			case 2: chamar_grade_aleat();			
			break;
			case 3:
			break;
			case 0: system("clear"); 
			return 0;
			break;
			default: printf("Opção inválida! Digite novamente: \n\n");
		}
	} while(menu);

}
