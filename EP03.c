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
#define TAM_MAX 200
#include <stdio.h>
#include <stdlib.h>
int modulo(int n);
int modulo(int n){
    int n_modulo;
    if (n<0){
        n_modulo = -n;
    }
    else{
        n_modulo = n;
    }
    return n_modulo;
}

int criaNumerao(int n, int num[]);
int criaNumerao(int n, int num[]){
    int potencia = 1,digitos = 0,i;

     /*este laço de repetição tem a função de contar o numero de digitos de um número
     com base no fato matemático que se M é o número de dígitos  de n entao ele é o
     menor valor que satisfaz 10 ^ (M + 1) > n*/


    while(modulo(n)/potencia > 0){
        potencia = potencia * 10;
        digitos = digitos + 1;
    }

    /* as estruturas condicionais abaixo atribuem o valor 0 para a casa 0 do vetor construído
    para  numeros positivos e atribui o valor 1 para casa 0 do vetor construido para numero 
    negativos*/

    if (n>=0){
        num[0] = 0;
    }
    if (n<0){
        num[0] = 1;
    }
    potencia = potencia /10;
    for (i = digitos; i >=1 ; i--){
        num[i] = (modulo(n)/potencia) % 10;
        potencia =  potencia/10;

    }
    /* esta estrutura condicional é necessário porque 
    a funcao de soma construida nao sabe lidar com 
    numeros de 0 digitos*/
    
    if(digitos ==0){
        digitos = 1;
    }
    return digitos;
}
void imprimeNumerao(int num[], int TamNum);
void imprimeNumerao (int num[], int TamNum){
    int contador;

    if (num[0]==0){
        printf("%d",num[TamNum]);
    }
    else{
        printf("%d",-num[TamNum]);
    }

    for (contador=TamNum - 1; contador >= 1 ; contador --){
        printf("%d", num[contador]);

    }
    printf("\n");
}
int soma (int maior[], int maior_n, int menor[], int menor_n);
int soma (int maior[], int maior_n, int menor[], int menor_n){
    int j = 1;

    /* o bloco abaixo serve para garantir que as casas relevantes, mas que nao fazem parte do numero
     têm valor 0*/
    maior [maior_n + 1] = 0;
    for (j=menor_n + 1; j<= maior_n + 1; j++){
        menor[j]=0;
    }

    /*a soma é feita somando casa a casa, e realizando um "vai um" para a casa seguinte e uma subtracao de 10 na casa atual c
     caso a soma das casas em questao sej maior que 9*/
    
    for (j=1 ; j <= maior_n + 1;j++){
        maior [j] = maior [j] + menor [j];
        if (maior [j] >= 10){
            maior[j] = maior[j] - 10;
            maior [j+1] = maior [j+1] + 1;
        }
            
           
    }
    /* o if abaixo atualiza a variavel que indicava o numero de digitos da parcela de maior modulo e agora vai indicar 
     o numero de casas do resultado
    é possivel demonstrar que o resultado de uma soma de dois numeros tem no maximo um digito a mais que a maior 
    das parcelas*/

    if (maior[maior_n + 1] != 0){
        maior_n = maior_n + 1;
    }
    // não precisa mexer na casa do sinal os numeros somados tem o mesmo sinal
    
    return maior_n;
}

int subtracao(int maior[], int maior_n, int menor[], int menor_n);
int subtracao(int maior[], int maior_n, int menor[], int menor_n){
    int j = 1,k=1,m;
    for (j=menor_n + 1; j<= maior_n; j++){
        menor[j]=0;
    }

    /* para realizar a subtracao, é feita uma subtracao casa  por casa e se uma dessas 
    subtracoes for um um numero negativo, fazemos uma adicao de dez nessa casa em uma s
    ubtracao de 1 na proxima casa*/

    /*
    podemos realizar sempre a operacao subtraindo o de menor modulo do de maior modulo e, conservando o sinal do de maior modulo
    */

    for (j=1 ; j <= maior_n + 1;j++){
        maior [j] = maior [j] - menor [j];
        if (maior [j] < 0){
            maior[j] = maior [j] +10;
            maior[j+1] = maior[j+1] -1;
        }
    }

    // o laço abaixo serve para definir o numero de casas do resultado
    j=maior_n;
    while (maior[j]==0 && maior_n > 1){
        maior_n = maior_n-1;
        j --;
    }
    return maior_n;    
}

int somaNatural(int v[], int numero);
int somaNatural(int v[], int numero){

    /*
    a soma natural é feita usando tres vetores: 
    - v, que é um argumento da funcao
    - v_crescente 
    - v_um

    a soma natural é feita "de baixo para cima". em cada etapa o vetor_um ( um numerao do numero 1) 
    é adicionado ao v_crescente que é por sua vez adicionado ao vetor v que conterá o resulatdo ao final 
    */
    int digitos, v_um[TAM_MAX], v_crescente[TAM_MAX],k, digitos_um, digitos_crescente;
    
    digitos = criaNumerao(numero, v);
    digitos_um = criaNumerao(1,v_um);
    digitos_crescente = criaNumerao(1,v_crescente);

    for (k = 1; k <= numero - 1; k++){
        digitos = soma(v,digitos,v_crescente,digitos_crescente);
        digitos_crescente = soma(v_crescente, digitos_crescente, v_um, digitos_um);
    }
    return digitos;
}


int main (){
    int opcao, digitos_a,digitos_b,primeiro,segundo;
    int a[TAM_MAX], b[TAM_MAX];

    printf("Digite 0 (soma) ou 1 (soma naturais):\n");
    scanf("%d", &opcao);

    if (opcao == 0){

        printf("Digite o primeiro numero:\n");
        scanf ("%d", &primeiro);
        printf("Digite o segundo numero:\n");
        scanf ("%d", &segundo);

        /*
        o primeiro if abarca a soma de dois numeros e a subtracao de dois números negativos
        isso pode ser feito pois -a - b = -(a+b), ou seja, a subtracao de um negativo de outro
        negativo é uma soma seguida de uma inversao de sinal
        */
        if (primeiro*segundo>0){
            if (modulo(primeiro) > modulo(segundo)){
                digitos_a = criaNumerao(primeiro, a);
                digitos_b = criaNumerao(segundo, b);

                digitos_a = soma(a,digitos_a,b,digitos_b);

                printf("Soma: ");

                imprimeNumerao(a, digitos_a);
            }
            if (modulo(segundo)>modulo(primeiro)){
                digitos_a = criaNumerao(primeiro, a);
                digitos_b = criaNumerao(segundo, b);

                digitos_b = soma(b,digitos_b,a,digitos_a);

                printf("Soma: ");

                imprimeNumerao(b, digitos_b);
            }
        }
        
        // esse if abarca os casos em que o primeiro e segundo numero tem sinais opostos

        if (primeiro*segundo<0){
            if (modulo(primeiro) > modulo(segundo)){
                digitos_a = criaNumerao(primeiro, a);
                digitos_b = criaNumerao(segundo, b);
                digitos_a = subtracao(a,digitos_a,b,digitos_b);

                printf("Soma: ");
                imprimeNumerao(a, digitos_a);
            }
            if (modulo(segundo)>modulo(primeiro)){
                digitos_a = criaNumerao(primeiro, a);
                digitos_b = criaNumerao(segundo, b);
                digitos_b = subtracao(b,digitos_b,a,digitos_a);

                printf("Soma: ");
                imprimeNumerao(b, digitos_b);
            }
        }

        /*
        nos dois if's abaixo, sao os abarcados os casos quando pelo menos um dos numeros inseridos é nulo
        */

        if(primeiro == 0 && segundo != 0){
            printf("Soma: ");
            digitos_a = criaNumerao(segundo, a);
            imprimeNumerao(a, digitos_a);
        }

        if(segundo == 0){
            printf("Soma: ");
            digitos_a = criaNumerao(primeiro, a);
            imprimeNumerao(a, digitos_a);
        }
    }

    if (opcao == 1){
        printf("Entre com valor de n para soma dos n primeiros naturais:\n");
        scanf ("%d", &primeiro);

        digitos_a = somaNatural(a,primeiro);

        printf("Soma dos %d primeiros naturais = ", primeiro);
        imprimeNumerao(a, digitos_a);
    }

    return 0;
    
}