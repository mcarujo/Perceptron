#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    printf("\n");

    int n_entradas=2,n_amostras=10;

    float entradas[3][10]= { {-1.0, -1.0, -1.0, -1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0} , {-0.1, -1.6, -4.9, -3.2, -2.1, 7.2, -4.2, -0.6, 8.2, 0.6} , {-5.9, -6.8, -9.7, -6.0, -4.5, 9.6, 6.8, 0.5, -5.9, 3.9} };
    float pesos[n_entradas+1];
    float saida_desejada[10]={-1.0,-1.0,-1.0,-1.0,-1.0,1.0,1.0,1.0,1.0,1.0};
    float paco_de_aprendizado = 0.001;
    float erro=1,erro_MSE,soma,saida;
    // INICIALIZANDO OS PESOS ENTRE 0 E 1.0;
    for(int i=0;i<n_entradas+1.0;i++){
    pesos[i]= (rand() % 11)*0.1;

    }
    /////////////////////////////////////


    int count=0;
    int count2=0;

    while(count<100){
        // SOMATORIO
        soma=0;
        for(int i=0;i<n_entradas+1.0;i++){
        soma=soma+(entradas[i][count2] * pesos[i]);
        }

        // FUNÇÃO DE ATIVAÇÃO LINEAR Y=soma;
        if(saida>0){saida=1.0;}
        else{saida=0;}

        saida=soma;



        erro=saida_desejada[count2]-saida;


        for(int i=0;i<n_entradas+1.0;i++){
        pesos[i]=pesos[i] + paco_de_aprendizado*erro*entradas[i][count2];}

        erro_MSE=pow(erro,2)/n_amostras;
        count=count+1;
        count2=count2+1;
        if(!count<9){
        count2=0;}

    }
        //Print ERRO
    printf("\n");
    printf("Erro Quadratico Medio-> %F",erro_MSE);

        //Print vetor de pesos final

    printf("\n");
    printf("Vetor de Pesos ->");
    for(int i=0;i<n_entradas+1.0;i++){
        printf(" %f ",pesos[i]);
    }

}