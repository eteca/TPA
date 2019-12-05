/*FUNÇÃO: gerencia uma sala de teatro
AUTORES: Matheus Gabriel e Silva  e  Giovana Caires Ramos
DATA DE CRIAÇÃO: 2019/12/04*/

#include<stdio.h>
#include<windows.h>
#include<iostream>
#include<locale>
int main(){
	setlocale(LC_ALL, "");
	char x[20][25];
	int j=0, i=0,r=0,cont=0;
	int contR=0,contV=0,f=0,g=0;
	boolean continua = true;
	float p,v,v1;
	
 	while(continua){
  		printf("\n\nSelecione qual opção você deseja:\n\n1-Informar o valor do ingresso e tamanho da sala\n2-Abrir um espetáculo\n3-Reservar um lugar\n4-Vender um lugar(inteira)\n5-Vender um lugar (meia)\n6-Verificar mapa do teatro\n7-Encerrar o espetáculo\n8-Verificar parciais\n9-Encerrar a execução\n\nR: ");
  		scanf("%i", &r);
  		
// INGRESSO E SALA ---------------------------------------------------------		
  		if(r==1){
  			int m=0,n=0;
  			
  			printf("\nQual será o valor do ingresso?\nR: ");
  			scanf("%f",&p);
  			
 			printf("\nQuantas fileiras(horizontais) haverá na sala?\nR: ");
 			scanf("%i",&i);
			  	
  			printf("\nQuantas colunas(verticais) haverá na sala?\nR: ");
 			scanf("%i",&j);
			 		
  			if(j*i>500){
				printf("\nO número de assentos ultrapassou 500, por favor insira outro número de colunas\nR: ");
  				scanf("%i",&j);	
			}
				
			for(m=0; m>=i; m++){
				for(n=0; n>=j; n++){
					x[m][n]='D';
				}
			}
// ABRIR ESPETACULO ---------------------------------------------------------
		}else if(r==2){
			int m=0,n=0;
			for(m=0; m==i; m++){
				for(n=0; n==j; n++){
					x[m][n]= {'D'};
				}
			}
// RESERVAR OU TIRAR RESERVA ---------------------------------------------------------
		}else if(r==3){
			int resposta=0,m=0,n=0;
			printf("O que deseja fazer?\n\n1- Reservar assento\n2- Cancelar reserva\nR: ");
			scanf("%i",&resposta);
			switch(resposta){
				
				case 1:
				printf("\nQual assento deseja reservar?\n\nLinha: ");
				scanf("%i",&m);
				printf("Coluna: ");
				scanf("%i",&n);
				x[m-1][n-1]='R';
				cont++;
				contR++;
				break;
				
				case 2:
				printf("\nDe qual assento deseja cancelar a reserva?\n\nLinha: ");
				scanf("%i",&m);
				printf("Coluna: ");
				scanf("%i",&n);
				x[m-1][n-1]='D';
				cont--;
				contR--;
				break;
				
				default:
					printf("Erro!");
				break;
			}
//VENDER INGRESSO INTEIRA ---------------------------------------------------------
		}else if(r==4){
			int m=0,n=0;
			printf("Entrada inteira\n\n");
			printf("Qual assento deseja vender\n\nLinha: ");
			scanf("%i",&m);
			printf("Coluna: ");
			scanf("%i",&n);
			printf("O valor a ser cobrado é: %.2f",p);
			x[m-1][n-1]='O';
			cont++;
			contV++;
			f++;
//VENDER INGRESSO MEIA ---------------------------------------------------------
		}else if(r==5){
			int m=0,n=0;
			float p2=0.0;
			printf("Meia entrada\n\n");
			printf("Qual assento deseja vender\n\nLinha: ");
			scanf("%i",&m);
			printf("Coluna: ");
			scanf("%i",&n);
			p2=p/2;
			printf("O valor a ser cobrado é: %.2f",p2);
			x[m-1][n-1]='O';
			cont++;
			contV++;
			g++;
//VERIFICA O MAPA DA SALA ---------------------------------------------------------
		}else if(r==6){
			int m=0,n=0;
			
			printf("Mapa do teatro\n\n");
			
			for(m=0;m==i;m++){
				for(n=0;n==j;n++){
					printf(" %c|",x[m][n]);
				}
				printf("\n");
			}
//ENCERRAR O ESPETÁCULO ---------------------------------------------------------
		}else if(r==7){
			v=i*j;
			v1= (60/100)*v;
			if(cont>=v1){
				printf("Espetáculo encerrado!");
			}else{
				printf("Espetáculo não encerrado\nAs vendas não alcançaram os 60%");
			}
//VERIFICAR PARCIAIS ---------------------------------------------------------
		}else if(r==8){
			int s1=0;
			float preco;
			printf("\n\nNúmero de assentos reservados: %i\n",contR);
			s1= v-(contR+contV);
			printf("Número de assentos livres: %i\n",s1);
			printf("Número de assentos vendidos: %i\n",contV);
			preco= (f*p)+(g*(p/2));
			printf("Total arrecadado: %f",preco);
		}else if(r==9){
			continua=false;
		}else{
			printf("Erro!");
		}
	}
 	system("pause");
 	return 0;
}
