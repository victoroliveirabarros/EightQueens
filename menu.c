#include "8queens.h"







main()
{
setlocale(LC_ALL, "");



	system("mode 800");
	
	int escolha;
	
	while(1)
	{
		system("cls");
		printf("                                          ***The Eight Queens***\n\n\n\n01 - Girar o ALGOR�TMO GEN�TICO\n02 - Como funciona?\n03 - Cr�ditos\n04 - O que � um ALGORITMO GEN�TICO??\n05 - Sair\nEscolha uma op��o: ");
		scanf("%d", &escolha);
		
		if(escolha == 2)
		{
			system("cls");
			printf("\n\nAlgoritmo gen�tico � uma t�cnica de busca ultilizada na ci�ncia da computa��o\npara achar solu��es aproximadas em problemas de otimiza��o e busca.\n\nAlgoritmos gen�ticos s�o uma classe particular de algoritmos evolutivos que usam t�cnicas inspiradas pela \nbiologia evolutiva como heredietaridade, muta��o, sele��o natural e recombina��o");
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
			printf("\n\no problema das 8 rainhas consiste em posicionar as rainhas de um jogo de xadrez de maneira que elas n�o entrem em conflito\n\n");
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
			printf("At� mais !! :)");
			system("pause>>null");
			break;
		}
		
	}
	
		
}
