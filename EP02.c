/*
  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP, 
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA. 
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM 
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES
  DESSE EP E QUE PORTANTO NÃO CONSTITUEM DESONESTIDADE ACADÊMICA
  OU PLÁGIO.  
  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS AS CÓPIAS
  DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO E
  DESONESTIDADE ACADÊMICA SERÃO TRATADOS SEGUNDO OS CRITÉRIOS
  DIVULGADOS NA PÁGINA DA DISCIPLINA.
  ENTENDO QUE EPS SEM ASSINATURA NÃO SERÃO CORRIGIDOS E,
  AINDA ASSIM, PODERÃO SER PUNIDOS POR DESONESTIDADE ACADÊMICA.

  Nome :Luiz Eduardo Tojal Ramos Santos
  NUSP :11764386
  Turma:3
  Prof.:Alair

  fonte:monitoria
*/

#include <stdio.h>
#include <stdlib.h>

void PrimeiraParte(int k, int n, int N, int m, int a, int c, int r_0);
void SegundaParte(int n, int d);
void ImprimeSequencia( int i, int j, int k, int s_i, int s_j, int s_k );


int n,k_2,N,m,a,c,r_0;
int n_2,d;
int i, j, k, s_i, s_j, s_k;

/*
a main realiza a impressão de orientações para o usuário e lê as informações inseridas
*/

int main()
{
    int parte_escolhida;
    
    printf("Digite a parte desejada: 1 para primeira; 2 para segunda\n");
    scanf("%d", &parte_escolhida);
    if (parte_escolhida == 1) {
        printf("Digite parametros n, k, N, m, a, c, r_0:\n");
        scanf("%d %d %d %d %d %d %d", &n ,&k_2, &N, &m, &a, &c, &r_0);
        PrimeiraParte(n, k_2, N, m, a, c, r_0);
        }
    else {
        printf("Digite parametros n, d:\n");
        scanf("%d %d", &n_2 ,&d);
        SegundaParte(n_2,d);
        }
        
    return 0;
}

void ImprimeSequencia( int i, int j, int k, int s_i, int s_j, int s_k ){
    if ( i < j ){
        if ( j < k ){
            printf( "%d %d %d\n", s_i, s_j, s_k );
        }
        else {
            if ( i < k ){
                printf( "%d %d %d\n", s_i, s_k, s_j );
            }
            else {
                printf( "%d %d %d\n", s_k, s_i, s_j );
            }
                
        }
    }
    else {
        if ( i < k ){
            printf( "%d %d %d\n", s_j, s_i, s_k );
        }
        else {
            if ( j < k ){
                printf( "%d %d %d\n", s_j, s_k, s_i );
            }
            else {
                printf( "%d %d %d\n", s_k, s_j, s_i );
            }
        }
    }
            
}

void PrimeiraParte(int n, int k_2, int N, int m, int a, int c, int r_0){
        int f, linha, coluna, maior_numero, menor_numero, diametro;
        
        printf ("Recorrencia   r <-- ( r x %d + %d ) mod %d   a partir da semente %d.\n", a, c, m, r_0); 
        printf("As %d sequencias de %d sorteios (com repeticao) em [ 1 .. %d ] e seus diametros:\n", N, k_2, n);

        /*
        são feitas iterações nas linhas e colunas de modo a construir a matriz em que serão exibidos 
        os resultados dos sorteios
        */
        
        for (linha=0; linha < N; linha++){
            menor_numero = n;
            maior_numero = 0; 
            for (coluna=0; coluna < k_2; coluna ++){

                // nas duas linhas abaixo o sorteio é simulado utilizando as equações fornecidas no enunciado
                r_0 = (a*r_0 + c) % m;
                f = r_0*n/m + 1;
                printf(" %5d", f); 

                 /* 
                 a variavel menor_numero foi inicializado com o maior valor que ela pode assumir: n
                 após cada sorteio, ela é atualizada se o numero sorteado for menor que seu valor atual
                 após uma sequencia de sorteios ela retorna para o valor de n 
                 um processo análogo é feito para guardar o maior valor
                 */
                if (menor_numero > f)
                    menor_numero = f;
                if (maior_numero < f)
                    maior_numero =  f;
            
            }
            diametro = maior_numero - menor_numero + 1;
            printf ("     ->%5d\n", diametro); 
        }  
}

void SegundaParte(int n_2, int d){
        int a2,b,contador,s_a,s_b,s_i,i=1,lim_superior,lim_inferior;
        contador = 0;
        printf("Listagem das sequencias de S( %d , 3 , %d ) (com repeticao):\n", n_2, d );
        if (d > 1){
            
            for (a2 = 1; a2 <= 3; a2++){                            // operaçao 1a, indicada no enunciado
                for (b = 1; b <= 3; b++){                           // operacao 1b,
                    for (i = 1; i <= 3; i++){                       //operacao 2c
                        if ((a2 != b && i!= a2 ) && i != b){        // dois srteios nao podem ter o mesmo indice
                            for (m = 1; m <= n_2 - d + 1; m++){     //operaco 2a
                                s_a = m;                            //operacao 2b
                                s_b = m + d -1; 

                                /*
                                os quatro if's abaixo correspondem aos quatro casos descritos no enunciado e 
                                suas respectivas condições sobre fechamento do intervalo estão indicadas na inicializacao 
                                do contador e na condicao de permanencia de cada um dos for.
                                */
                                if (i > a2 && i > b){
                                    for (s_i = s_a; s_i <= s_b; s_i++){
                                        ImprimeSequencia( a2,b,i, s_a, s_b, s_i);
                                        contador ++;                           
                                    }
                                }
                                if (i < a2 && i < b){
                                    for (s_i = s_a + 1; s_i < s_b; s_i++){
                                        ImprimeSequencia( a2,b,i, s_a, s_b, s_i);
                                        contador ++;
                                    }
                                }
                                if (i > a2 && i < b){
                                    for (s_i = s_a; s_i < s_b; s_i++){
                                        ImprimeSequencia( a2,b,i, s_a, s_b, s_i);
                                        contador ++;
                                    }
                                }
                                if (i< a2 && i > b){
                                    for (s_i = s_a + 1; s_i <= s_b; s_i++){
                                        ImprimeSequencia( a2,b,i, s_a, s_b, s_i);
                                        contador ++;
                                    }
                                }
                                
                            }
                        }
                    }
                    
                }
            }
            printf("Total de %d sequencias\n",contador);
            lim_superior = 9*d*n_2; //formulas encontradas substituindo k = 3 na expressão 7 do enunciado
            lim_inferior = 6*(d-2)*(n_2-d+1);
            printf("Limites: %d e %d\n", lim_inferior, lim_superior);
        }
    int h=1;
    if (d == 1){
        for ( h = 1; h <= n_2; h ++){
            printf( "%d %d %d\n", h,h,h);
            contador ++;
        }
    printf("Total de %d sequencias\n",contador);
    }

}
