#include "8queens.h"







main()
{
setlocale(LC_ALL, "");



	system("mode 800");
	
	int escolha;
	
	while(1)
	{
		system("cls");
		printf("                                          ***The Eight Queens***\n\n\n\n01 - Girar o ALGORÍTMO GENÉTICO\n02 - Como funciona?\n03 - Créditos\n04 - O que é um ALGORITMO GENÉTICO??\n05 - Sair\nEscolha uma opção: ");
		scanf("%d", &escolha);
		
		if(escolha == 2)
		{
			system("cls");
			printf("\n\nAlgoritmo genético é uma técnica de busca ultilizada na ciência da computação\npara achar soluções aproximadas em problemas de otimização e busca.\n\nAlgoritmos genéticos são uma classe particular de algoritmos evolutivos que usam técnicas inspiradas pela \nbiologia evolutiva como heredietaridade, mutação, seleção natural e recombinação");
			system("pause>>null");
		}
		
		if(escolha ==3)
		{
			system("cls");
			printf("\n\nAluno : Victor Oliveira\n\n.\n\n");
			system("pause");
		}
		
		if (escolha == 4)
		{
			system("cls");
			printf("\n\no problema das 8 rainhas consiste em posicionar as rainhas de um jogo de xadrez de maneira que elas não entrem em conflito\n\n");
			system("pause>>null");
		}
		
		if(escolha == 1)
		{
			time_t t;
			srand(time(&t));
			
			rodar_GA();
			printf("\n\n");
			system("pause");
		}
		if (escolha==5) 
		{
			system("cls");
			printf("Até mais !! :)");
			system("pause>>null");
			break;
		}
		
	}
	
		
}
