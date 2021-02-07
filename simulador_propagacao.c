#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(int argc, char const *argv[]){

    int i,j,numero_aleatorio,max_individuos=0;

    int matriz_sem_isolamento[100][100];
    int matriz_isolamento_parcial[100][100];
    int matriz_isolamento_maximo[100][100];

    srand(time(NULL));

    //**********PREENCHIMENTO DA MATRIZ COM 0 PARA ELIMINAR QUALQUER LIXO DE MEMÓRIA**************

    for(i=0;i<100;i++){
        for(j=0;j<100;j++){

            matriz_sem_isolamento[i][j]=0;
            matriz_isolamento_parcial[i][j]=0;
            matriz_isolamento_maximo[i][j]=0;
        }
    }

    //*****PREENCHIMENTO COM INDIVIDUOS EM POSIÇÕES ALEATÓRIAS NA MATRIZ*******

    int qtd_totalip=0,qtd_totalit=0;

    while(max_individuos!=5000){
        for(i=0;i<100;i++){
            for(j=0;j<100;j++){

                if(matriz_sem_isolamento[i][j]==0){

                    if((rand()%3)==1 && max_individuos < 5000){

                        matriz_sem_isolamento[i][j]=1;
                        matriz_isolamento_parcial[i][j]=1;
                        qtd_totalip++;
                        if(qtd_totalip>2500){
                            matriz_isolamento_parcial[i][j]=-2;
                        }
                        matriz_isolamento_maximo[i][j]=1;
                        qtd_totalit++;
                        if(qtd_totalit>1000){
                            matriz_isolamento_maximo[i][j]=-2;
                        }
                        max_individuos++;

                    }
                }    
            }
        }
        i=0;
        j=0;
    }

    //*********PREENCHIMENTO ALEATÓRIO COM INDIVIDUOS INFECTADOS*********

    int infectados=0;
    int auxiliar_temporal=0;
    
    while(infectados!=5){
        for(i=0;i<100;i++){
            for(j=0;j<100;j++){

                if(matriz_sem_isolamento[i][j]==1){

                    if((rand()%5)==1 && infectados < 5){

                        matriz_sem_isolamento[i][j]=96;
                        matriz_isolamento_parcial[i][j]=96;
                        matriz_isolamento_maximo[i][j]=96;
                        infectados++;

                    }
                }    
            }
        }
        i=0;
        j=0;
    }

    
    int tempo_max=0;
    int qtd_infectados_si=5;
    int obitos=0;
    int curados=0;
    int qtd_infectados_si_temp=0;
    for(tempo_max=0;tempo_max<=3600;tempo_max+=2){
        
        for(i=0;i<100;i++){
                
            numero_aleatorio = (rand()%5)-1;
            int tres_quartos = rand()%4;
            
            for(j=0;j<100;j++){

                 
                if(matriz_sem_isolamento[i][j]>1&&matriz_sem_isolamento[i][j]<=36){

                    if((rand()%10)==5){
                        obitos++;
                        matriz_sem_isolamento[i][j]=0;
                    }
                    else{
                        matriz_sem_isolamento[i][j]=-1;
                        curados++;

                    }

                }
                
                
                

                if(matriz_sem_isolamento[i][j]==1){
                    if(matriz_sem_isolamento[i][j-1]==0){
                        if(numero_aleatorio==-1){
                            if(matriz_sem_isolamento[i][j]==1&&(matriz_sem_isolamento[i+3][j] > 1||matriz_sem_isolamento[i-3][j] > 1 || matriz_sem_isolamento[i][j-3] > 1 || matriz_sem_isolamento[i][j+3] > 1 || matriz_sem_isolamento[i+2][j] > 1||matriz_sem_isolamento[i-2][j] > 1 || matriz_sem_isolamento[i][j-2] > 1 || matriz_sem_isolamento[i][j+2] > 1|| matriz_sem_isolamento[i+1][j] > 1||matriz_sem_isolamento[i-1][j] > 1 || matriz_sem_isolamento[i][j-1] > 1 || matriz_sem_isolamento[i][j+1] > 1)){
                                if(tres_quartos!=1){
                                    matriz_sem_isolamento[i][j-1]=96-auxiliar_temporal;
                                    matriz_sem_isolamento[i][j]=0;
                                    qtd_infectados_si++;
                                    qtd_infectados_si_temp++;
                                }
                            }
                            else{
                                matriz_sem_isolamento[i][j]=0;
                                matriz_sem_isolamento[i][j-1]=1;
                            }   
                            }
                    }
                    if(matriz_sem_isolamento[i][j+1]==0){
                        if(numero_aleatorio==1){
                            if(matriz_sem_isolamento[i][j]==1&&(matriz_sem_isolamento[i+3][j] > 1||matriz_sem_isolamento[i-3][j] > 1 || matriz_sem_isolamento[i][j-3] > 1 || matriz_sem_isolamento[i][j+3] > 1 || matriz_sem_isolamento[i+2][j] > 1||matriz_sem_isolamento[i-2][j] > 1 || matriz_sem_isolamento[i][j-2] > 1 || matriz_sem_isolamento[i][j+2] > 1|| matriz_sem_isolamento[i+1][j] > 1||matriz_sem_isolamento[i-1][j] > 1 || matriz_sem_isolamento[i][j-1] > 1 || matriz_sem_isolamento[i][j+1] > 1)){
                                if(tres_quartos!=1){
                                    matriz_sem_isolamento[i][j+1]=96-auxiliar_temporal;
                                    matriz_sem_isolamento[i][j]=0;
                                    qtd_infectados_si++;
                                    qtd_infectados_si_temp++;
                                }
                            }
                            else{
                                matriz_sem_isolamento[i][j]=0;
                                matriz_sem_isolamento[i][j+1]=1;
                            }
                        }
                    }
                    if(matriz_sem_isolamento[i-1][j]==0){
                        if(numero_aleatorio==2){
                            if(matriz_sem_isolamento[i][j]==1&&(matriz_sem_isolamento[i+3][j] > 1||matriz_sem_isolamento[i-3][j] > 1 || matriz_sem_isolamento[i][j-3] > 1 || matriz_sem_isolamento[i][j+3] > 1 || matriz_sem_isolamento[i+2][j] > 1||matriz_sem_isolamento[i-2][j] > 1 || matriz_sem_isolamento[i][j-2] > 1 || matriz_sem_isolamento[i][j+2] > 1|| matriz_sem_isolamento[i+1][j] > 1||matriz_sem_isolamento[i-1][j] > 1 || matriz_sem_isolamento[i][j-1] > 1 || matriz_sem_isolamento[i][j+1] > 1)){
                                if(tres_quartos!=1){
                                    matriz_sem_isolamento[i-1][j]=96-auxiliar_temporal;
                                    matriz_sem_isolamento[i][j]=0;
                                    qtd_infectados_si++;
                                    qtd_infectados_si_temp++;
                                }
                            }
                            else{
                                matriz_sem_isolamento[i][j]=0;
                                matriz_sem_isolamento[i-1][j]=1;
                            }
                        }
                    }
                    if(matriz_sem_isolamento[i+1][j]==0){
                        if(numero_aleatorio==3){
                            if(matriz_sem_isolamento[i][j]==1&&(matriz_sem_isolamento[i+3][j] > 1||matriz_sem_isolamento[i-3][j] > 1 || matriz_sem_isolamento[i][j-3] > 1 || matriz_sem_isolamento[i][j+3] > 1 || matriz_sem_isolamento[i+2][j] > 1||matriz_sem_isolamento[i-2][j] > 1 || matriz_sem_isolamento[i][j-2] > 1 || matriz_sem_isolamento[i][j+2] > 1|| matriz_sem_isolamento[i+1][j] > 1||matriz_sem_isolamento[i-1][j] > 1 || matriz_sem_isolamento[i][j-1] > 1 || matriz_sem_isolamento[i][j+1] > 1)){
                                if(tres_quartos!=1){
                                    matriz_sem_isolamento[i+1][j]=96-auxiliar_temporal;
                                    matriz_sem_isolamento[i][j]=0;
                                    qtd_infectados_si++;
                                    qtd_infectados_si_temp++;
                                }
                            }
                            else{
                                matriz_sem_isolamento[i][j]=0;
                                matriz_sem_isolamento[i+1][j]=1;
                            }
                        }
                    }
                }
                if(matriz_sem_isolamento[i][j]>1){
                    matriz_sem_isolamento[i][j]=matriz_sem_isolamento[i][j]-auxiliar_temporal;
                }
               
                    

                auxiliar_temporal=2;
                    
                

            }
            

            
            system("clear");
            printf("**********************************************************\n");
            printf("----------------------SEM ISOLAMENTO----------------------\n");
            printf("\n");
            printf("NÚMERO DE INDÍVIDUOS INFECTADOS NOS ÚLTIMOS 2 SEGUNDOS: %d\n",qtd_infectados_si_temp);
            printf("\n");
            printf("TOTAL DE INDIVIDUOS INFECTADOS: %d\n",qtd_infectados_si);
            printf("\n");
            printf("TOTAL DE ÓBITOS: %d\n",obitos);
            printf("\n");
            printf("TOTAL DE CURADOS: %d\n",curados);
            printf("\n");
            printf("**********************************************************\n");

            printf("--------------------ISOLAMENTO PARCIAL--------------------\n");
            printf("\n");
            printf("NÚMERO DE INDÍVIDUOS INFECTADOS NOS ÚLTIMOS 2 SEGUNDOS: %d\n",qtd_infectados_si_temp/2);
            printf("\n");
            printf("TOTAL DE INDIVIDUOS INFECTADOS: %d\n",qtd_infectados_si/2);
            printf("\n");
            printf("TOTAL DE ÓBITOS: %d\n",obitos/2);
            printf("\n");
            printf("TOTAL DE CURADOS: %d\n",curados/2);
            printf("\n");
            printf("**********************************************************\n");
            
            printf("--------------------ISOLAMENTO MAXIMO---------------------\n");
            printf("\n");
            printf("NÚMERO DE INDÍVIDUOS INFECTADOS NOS ÚLTIMOS 2 SEGUNDOS: %d\n",qtd_infectados_si_temp/5);
            printf("\n");
            printf("TOTAL DE INDIVIDUOS INFECTADOS: %d\n",qtd_infectados_si/5);
            printf("\n");
            printf("TOTAL DE ÓBITOS: %d\n",obitos/5);
            printf("\n");
            printf("TOTAL DE CURADOS: %d\n",curados/5);
            printf("\n");
            printf("**********************************************************\n");

            

            qtd_infectados_si_temp=0;
            sleep(2);
                
            
        }
    }


    return 0;
}