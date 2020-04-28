#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#define tam_pop 400
#define tam_genes 8
#define prob_mut 1
#define tam_torneio 20
#define prob_cruz 0.8



void inicializaPopulacao(int **populacao)
{
	time_t t;
	srand(time(&t));
	int individuo, genes, i, j;
	for(individuo =0; individuo < tam_pop; individuo++){
		for(genes=0; genes < tam_genes; genes++)
		{
			populacao[individuo][genes] = genes;
		}
	}
	int aux, ponto1, ponto2;
	for(i=0; i<tam_pop; i++)
	{
		
		for(j=0; j<tam_genes-1; j++)
		{
			ponto1 = rand() % tam_genes;
			ponto2 = rand() % tam_genes;
			
			aux = populacao[i][ponto1];
			populacao[i][ponto1] = populacao[i][ponto2];
			populacao[i][ponto2] = aux;
		}
	}
}






int fitness(int *individuo)
{
	int i, j, score = 49;
	
	for(i=0; i<tam_genes-1; i++)
	{
		for(j=0; j<tam_genes; j++)
		{
			if(individuo[i] == individuo[j] && i != j)
			{
				score -= 1;
			}
			
			if((i+individuo[i] == j+individuo[j] && i != j) || (individuo[i] - i == individuo[j] - j && i != j))
			{
				score -= 1;
			}
			
			if(individuo[i] == individuo[i+1]+1)
			{
				score -= 1;
			}
		}
		
		
	}
	return score;
}
void cruzamento(int indice_pai1, int indice_pai2,int **populacao, int *filho)
{
	time_t t;
	srand(time(&t));
	
	int i, j;
	
	int ponto = rand() % tam_genes;

	
	for(i=0; i<=ponto; i++)
	{
		filho[i] = populacao[indice_pai1][i];
	}
	
	for(i=ponto+1; i<tam_genes; i++)
	{
		filho[i] = populacao[indice_pai2][i];
	}
}

void mutacao(int *individuo)
{
	time_t t;
	srand(time(&t));
	
	int ponto = rand() % tam_genes, atual;
	int ponto2, temp;
	do{
		ponto2 = rand() % tam_genes;
	}
	while(ponto == ponto2);
	
	temp = individuo[ponto];
	individuo[ponto] = individuo[ponto2];
	individuo[ponto2] = temp;
	
	
}

int obterMelhor(int **populacao)
{
	int i, j, scoreMelhor = fitness(populacao[0]), indiceMelhor = 0;
	
	for(i=1; i<tam_pop; i++)
	{
		int score = fitness(populacao[i]);
		if(score > scoreMelhor)
		{
			indiceMelhor = i;
			scoreMelhor = score;
			
		}
	}
	return indiceMelhor;
}

void rankPop(int **populacao)
{
	int i, j;

	int **ranked_pop;
	int *aux;
	int **populacao_ordenada;
	populacao_ordenada = (int**) calloc(tam_pop, sizeof(int*));
	
	for(i=0; i<tam_pop;i++)
	{
		populacao_ordenada[i] = (int*) calloc(tam_genes, sizeof(int));
	}
	
	for(i=0; i<tam_pop;i++)
	{
		for(j=0; j<tam_genes;j++)
		{
			populacao_ordenada[i][j] = populacao[i][j];
		}
	}

	for(i=0; i<tam_pop-1; i++)
	{
		for(j=0; j<tam_pop-1-i; j++)
		{
			if(fitness(populacao_ordenada[j]) > fitness(populacao_ordenada[j+1]))
			{
				aux = populacao_ordenada[j+1];
				populacao_ordenada[j+1] = populacao_ordenada[j];
				populacao_ordenada[j] = aux;
			}
		}
	}
	
	for(i=0; i<tam_pop; i++)
	{
		for(j=0; j<tam_genes; j++)
		{
			populacao[i][j] = populacao_ordenada[i][j];
		}
	}
	
}

void tabuleiro(int *individuo)
{
    int i, j;
    char tab[tam_genes][tam_genes];
    
    for(i=0; i<tam_genes; i++){
        for(j=0; j<tam_genes; j++){
        	tab[i][j] = 'x';
  		}
  	}
  		
    for(i=0; i<tam_genes; i++){
        for(j=0; j<tam_genes; j++)
        {
            if(i == individuo[j]) tab[i][j] =  'R';
        }
    }
        for(i=0; i<tam_genes; i++){
     
            for(j=0; j<tam_genes; j++)
            {
            printf("%c      ", tab[i][j]);  
            }
            printf("\n\n\n\n");
    }
     
}
 





double mediaFitness(int **populacao){
	int i, totalFit = 0;
	
	for(i=0; i<tam_pop;i++){
	    totalFit += fitness(populacao[i]);
	}
	return (double) (totalFit/tam_pop);
	
}

void popTxt(FILE *txt, int **populacao, int geracao)
{
	int i, j;
	char string1[10];
	char string2[10];
	strcpy(string1, "\nGeração %d\n\n");
	strcpy(string2, "\nMelhor: ");
	fprintf(txt, string1, geracao);
	fprintf(txt, string2);
	for(i=0; i<tam_genes; i++)
	{
		fprintf(txt, "%d ", populacao[obterMelhor(populacao)][i]);
	}
	fprintf(txt, "\nFitness: %d\n", fitness(populacao[obterMelhor(populacao)]));
	
}


rodar_GA(){

setlocale(LC_ALL, "");
	
	time_t t;
	srand(time(&t));
	
	int **populacao, *individuo, i, j, k;
	int *filho;
	int *melhor;
	
	FILE *geracoes;
	
	geracoes = fopen("ga-log.txt", "w");
	populacao = (int**)malloc(sizeof(int*) *  tam_pop );
	filho     = (int*) malloc(sizeof(int*) * tam_genes);
	melhor    = (int*) malloc(sizeof(int*) * tam_genes);
	
	for(i=0; i<tam_pop; i++)
		populacao[i] = (int*) malloc(sizeof(int) * tam_pop);
	
	
	
	for(i=0; ; i++)
	{
	
		inicializaPopulacao(populacao);
		mutacao(filho);
		for(k=0; k<tam_genes; k++)
					{
						populacao[0][k] = filho[k];
						populacao[1][k] = melhor[k];
					}
		for(j=0; j< tam_torneio; j++)
		{
			double prob = ((double) rand() /  (double) RAND_MAX +1);
			
			if(prob < prob_cruz)
			{
				int indice_pai1 = rand() % tam_pop;
				int indice_pai2 = rand() % tam_pop;
				while(indice_pai1 == indice_pai2){
					indice_pai2 = rand() % tam_pop;
				}
				
				cruzamento(indice_pai1, indice_pai2, populacao, filho);
				
				prob = ((double) rand() /  (double) RAND_MAX +1);
				
				if(prob< prob_mut)
				{
					mutacao(filho);
				}
				
				int fit_pai = fitness(populacao[indice_pai1]);
				int fit_filho = fitness(filho);
			
				if(fit_filho > fit_pai)
				{
					for(k=0; k<tam_genes; k++)
					{
						populacao[indice_pai1][k] = filho[k];
					}
				}	
			}
			
		}
		popTxt(geracoes, populacao, i+1);
		system("cls");
		printf("Geração %d\n", i+1);
		printf("\nMelhor : ", obterMelhor(populacao));
		int z;
		for(z=0; z<tam_genes; z++)
		{
			melhor[z] = populacao[obterMelhor(populacao)][z];
		}
		for(j = 0; j < tam_genes; j++)
		{
			printf("%d ", populacao[obterMelhor(populacao)][j]);
		}
		printf("\n\nScore : %d\n\n", fitness(populacao[obterMelhor(populacao)]));
		printf("\n\nMédia de fitness : %2.1f\n\n", mediaFitness(populacao));
		
		
		if(fitness(populacao[obterMelhor(populacao)]) == 49) break;
		
	}
	tabuleiro(melhor);
	printf("\nLegenda:\nX - LUGAR VAZIO\nR - Rainha");
	fclose(geracoes);
	free(populacao);
	free(melhor);
	free(filho);
}
	
	
	
	


