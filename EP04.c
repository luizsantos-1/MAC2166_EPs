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

*/
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXM  100
#define MAXK  5
#define MAXP  32000
#define MAXD  100
#define MAXF  100
#define FALSE 0
#define TRUE  1

/*
A função BuscaMarcador tem o formato do protótipo fornecido no que se refer aos argumentos e à saída.
Seu funcionamento consiste em iterar sobre os índices do politech a partir do índice ini, e somar quantos 
iguais entre o marcador e os n valores do politech a partir de ini (sendo n o tamanho do marcador). Se o 
número de acertos for igual a n, então foi achada a primeira ocorrência do marcador.
*/

int BuscaMarcador( int ini, char politech[MAXP], char marcador[MAXM] );
int BuscaMarcador( int ini, char politech[MAXP], char marcador[MAXM] ){
  int tamanho_marcador, tamanho_politech,i, acertos, gama;

  tamanho_marcador = strlen(marcador);
  tamanho_politech = strlen(politech);

  gama = ini;

  for (gama = ini;gama <= tamanho_politech - tamanho_marcador; gama++){
    acertos = 0;
    for (i = 0; i <= tamanho_marcador - 1; i++){
      if (marcador[i] == politech[i+gama]){
        acertos ++;
      }
    }
    if (acertos == tamanho_marcador){
      return gama;
    }
  }

  return MAXP; 
} 
/*
A função BuscaMarcadores chama a função para cada um dos k marcadores da matriz e guarda o índice em que 
esse mrcador foi enconrado. O próximo passo é comparar esse índice com o menor índice de marcador até o momento
*/
int BuscaMarcadores( int ini, char politech[MAXP],int k, char marcadores[MAXK][MAXM], int *compr);
int BuscaMarcadores( int ini, char politech[MAXP],int k, char marcadores[MAXK][MAXM], int *compr){
  int u, menor_indice = MAXP, indice_marcador, marcador_achado;

  for (u = 0; u <= k - 1; u++){
    indice_marcador = BuscaMarcador(ini, politech, marcadores[u]);
    if (indice_marcador < menor_indice){
      menor_indice = indice_marcador;
      marcador_achado = u;
    }
  }
  if (menor_indice == MAXP){
    *compr = 0;
    return MAXP;
  }
  else{
    *compr = strlen(marcadores[marcador_achado]);
    return menor_indice;
  }
  
}

int Delta( char q[MAXP], char p[MAXP], int delta[MAXD], int desloc, int ini, int fim );
int Delta( char q[MAXP], char p[MAXP], int delta[MAXD], int desloc, int ini, int fim ){
  int i,n_diferencas = 0 ;
  
  for (i = ini; i <= fim; i++){
    if (p[i] != q[i+desloc]){
      delta[n_diferencas] = i;
      n_diferencas ++;
    }
  }
  delta[n_diferencas] = MAXP;

  return n_diferencas;// não entendi se ele quer q retorna fim - ini ou o número de casas de delta
}
/*
A função pertence recebe um vetor de inteiros e um inteiro. 
Retorna 1 se algum valor do vetor é igual ao elemento e retorna 0, caso contrário
*/
int Pertence (int conjunto[MAXP], int elemento );
int Pertence (int conjunto[MAXP], int elemento ){
  int i=0;

  while(conjunto[i] != MAXP && conjunto[i] != elemento){
    i = i +1;
  }
  if (conjunto[i] == MAXP){
    return 0;
  }
  else{
    return 1;
  }

}
/*
A diferença de conjuntos se baseia na definição de conjunto diferença. d pertence a A - B sse d pertence a A e 
não pertence a B.
*/
int DiferencaDeConjuntos( int delta_q[MAXD], int delta_s[MAXD], int q_menos_s[MAXD] );  
int DiferencaDeConjuntos( int delta_q[MAXD], int delta_s[MAXD], int q_menos_s[MAXD] ){
  int j=0,k = 0;

  while(delta_q[j] != MAXP){
    if (Pertence(delta_s,delta_q[j])==0){
      q_menos_s[k] = delta_q[j];
      k = k + 1;
    }
    j = j +1;
  }
  q_menos_s[k] = MAXP;
  return k;
}

/*
A função HaIncompatibilidade se baseia na equivalência lógica entre a definição de incompatibilidade do enunciado e a 
seguinte sentença: existem c,d números ineteiros e q,s,r conjuntos tal que c pertença a delta(q)-delta(s) e d pertença
a delta(s)-delta(q) e d,c pertença delta(r)
*/
int HaIncompatibilidade( int n, char F[MAXF][MAXP], int j_p,int G[MAXF], int D[MAXF][MAXD] );
int HaIncompatibilidade( int n, char F[MAXF][MAXP], int j_p,int G[MAXF], int D[MAXF][MAXD] ){
  int achou_in = 0,i,j,k,n_politechs = 0, tamanho_dif_1 = 0, tamanho_dif_2 = 0,m,p;
  int Diferenca1[MAXP], Diferenca2[MAXP];

  for (i=0; i <= n - 1; i++){
    for (j=1; j <= n; j++){

      tamanho_dif_1 = DiferencaDeConjuntos(D[i], D[j%n], Diferenca1);
      tamanho_dif_2 = DiferencaDeConjuntos(D[j%n], D[i], Diferenca2);

        for (m = 0; m <= tamanho_dif_1 - 1; m++ ){
          for (p = 0; p <= tamanho_dif_2 - 1; p++){

            for (k=2; k <= n + 1; k++){
              if (Pertence(D[k%n], Diferenca1[m])*Pertence(D[k%n], Diferenca2[p]) == 1){
                achou_in = 1;
                printf("\ncontraexemplo: q = %d     s = %d     c = %d     d = %d     r = %d", i%n, j%n, Diferenca1[m], Diferenca2[p],k%n);
                // Para evitar índices inválidos para os vetores, foi usada a MOD(x). Dessa forma englobamos os casos quando 
                // q é o último ou o penúltimo politech de F
              }
            }
          }
        }
      
    }
  }
    
  if (achou_in == 0){
    return FALSE;
  }
  else{
    return TRUE;
  }

  return 0;
  
}
/*
Essa implemntação da função fatorial foi copiada da monitoria, como sugerido pelos monitores
*/
double fatorial(int n);
double fatorial(int n){
  if (n==1){
    return 1;
  }
  else{
    return n*fatorial(n-1);
  }
}

double T(int n, int k2, int d);
double T(int n, int k2, int d){

  if(n==1 && k2 ==1 && d ==1){
    return n;
  }
  else{
    return (n-d+1)*k2*(k2-1)*fatorial(d-2)/(fatorial(d-k2));
  }
}

/*
Essa função é equivalente ao método que foi exposto no enunciado de como
calcular o número total de conjuntos dados n e k. Porém foi feito uma simples
simplificação algébrica em n!/(n-k)! para evitar o cálculo de n!, que é um 
número gigantesco
*/
double TotalDeConjuntos(int n, int k);
double TotalDeConjuntos(int n, int k){
  int i; 
  double produto = 1;

  for (i = 0; i < k; i++){
    produto = produto * (n - i);
  }
  return produto;
}


void DiametroEProbabilidades( int delta[MAXD], int ini, int fim, int *apt_diametro, double *prob_d_igual, double *prob_d_nsuperior);
void DiametroEProbabilidades( int delta[MAXD], int ini, int fim, int *apt_diametro, double *prob_d_igual, double *prob_d_nsuperior){
  int k = 0,n;
  int d=0;
  double n_conj_dmenor=0;
  double probabilidade = 0;
  
  n = fim - ini + 1;
  
  while (delta[k] != MAXP){
    k ++;
  } 
  
  *apt_diametro = delta[k-1] - delta[0] + 1;

  *prob_d_igual = T(n,k,*apt_diametro)/TotalDeConjuntos(n,k);

  /*
  Para calcular a probabilidade de termos um conjunto de  diametro menor ou igual *apt_diametro, foi utilizado um
  fato matemático pouco intuitivo (pelo menos para mim). O somatório de T(n,k,d) quando d varia de k até D é igual a 
  -(D-1)!*(D-K+1)*(D*(k-1)-kn)/(D-k+1)!
  Essa conta foi feita pelo WolframAlpha (https://www.wolframalpha.com/input/?i=sum+%28%28n-d%2B1%29*k*%28k-1%29*factorial%28d-2%29%2Ffactorial%28d-k%29%29%2C+d%3Dk+to+D)
  */
  *prob_d_nsuperior = -fatorial(*apt_diametro-1)*(*apt_diametro-k+1)*(*apt_diametro*(k-1)-k*n)/fatorial(*apt_diametro-k+1);
  
  *prob_d_nsuperior = *prob_d_nsuperior/TotalDeConjuntos(n,k);
  
}





int main() {
  char F[MAXF][MAXP];		/* matriz com a família de Politechs, um por linha */
  int np = 0;	                /* número de Politechs armazenados em F */
  int ncp = 0;			/* total de caracteres dos Politechs de F */
  int j_p = 0;			/* indice do patriarca na família */
  int L[MAXF];		        /* length (comprimento) de cada politech */
  int G[MAXF];		        /* gama, primeira ocorrência de marcador de início */
  int continua = TRUE;		/* iteração continua?  */
  char comando;			/* comando selecionado */
  char m[MAXK][MAXM];		/* marcadores de início */
  int nm = 0;	                /* número de marcadores de início */
  char M[MAXK][MAXM];		/* marcadores de fim */
  int nM = 0;	                /* número de marcadores de fim */
  int i, j, k, compr;
  int ini = 0, fim = MAXP-1;	/* extremidades do intervalo de busca de caracteristicas */
  int D[MAXF][MAXD];		/* matriz de caracteristicas com Delta( F[i] ) em cada linha D[i] */
  int diametro;			/* valor devolvido por DiametroEProbabilidade */
  double Prob_eq_diametro, Prob_le_diametro; /* valores devolvidos por DiametroEProbabilidades */
  char comentario[300];			     /* linha de comentario */

  while( continua ) {
    printf( "Digite uma letra para um comando: " );
    comando = 'q';		/* valor default de leitura se houver erro no scanf */
    do {
      scanf( " %c", &comando );
      if ( comando == '#' ) {
	scanf( "%[^\n]",comentario );
	printf("\n#%s",comentario);
      }
    } while (comando=='#');
    switch( comando ) {
    case 'p':
      printf( "\nDigite um Politech: " );
      scanf( " %[!-~]", F[np] );
      L[np] = strlen( F[np] );
      ncp += L[np];
      printf( "\nPolitech %d de comprimento %d inserido na familia, com %d caractere(s).\n",
	      np, L[np], ncp );
      G[np] = D[np][0] = MAXP;	/* calculo posterior */
      np++;
      break;
    case 'P':
      printf( "\nDigite indice do patriarca: " );
      scanf( " %d", &j_p );
      ini = 0, fim = strlen( F[j_p] ) - 1;
      printf( "\nPatriarca da familia [ %d .. %d ] eh o de numero %d e tem comprimento %d .\n",
	      0, np-1, j_p, fim + 1 );
      break;
    case 'e':
      printf( "\nExtremidades atuais do intervalo de posicoes do patriarca a ser comparado: %d %d", ini, fim );
      if ( nm > 0 )
	printf( "\nPrimeira ocorrencia de um marcador de inicio: %d",
		BuscaMarcadores( ini, F[j_p], nm, m, &compr ) );
      printf("\nDigite duas novas extremidades do intervalo de onde serao extraidas as caracteristicas\n(valores invalidos provocam uma busca automatica que use os conjuntos de marcadores): ");
      scanf( "%d %d", &ini, &fim );
      if ( !( 0 <= ini && ini <= fim && fim < L[j_p] ) ) {
	/* valores invalidos provocam uma busca automatica */
	ini = 0; fim = L[j_p];
	printf( "\nAntigo interv. de busca de caracteristicas: [ %d .. %d ].", ini, fim );	
	i = ini; k = -1;
	do {
	  /* busca marcador de início */
	  i = BuscaMarcadores( i, F[j_p], nm, m, &compr );
	  /* printf( "[ marca_ini compr =  %d %d\n", i, compr ); */
	  if ( i <= fim-compr ) {
	    i = i + compr;
	    /* busca marcador de fim */
	    j = BuscaMarcadores( i, F[j_p], nM, M, &compr );
	    /* printf( "marca_fim ] compr =  %d %d\n", j, compr ); */
	    if ( j <= fim-compr ) 
	      k = i = j + compr;
	    else if ( j == MAXP || j + compr > fim ) {
	      i = MAXP;
	      compr = 0;
	    }
	  } /* if i */
	} while ( i <= fim );
	if ( k >= 0) {
	  /* printf( "ini fim len = %d %d %d\n", ini, fim, L[j_p] ); */
	  fim = k;
	  ini = BuscaMarcadores( 0, F[j_p], nm, m, &compr );
	  /* para incluir mutações biológicas em regiões promotoras */
	  ini = ini < 10 ? 0 : ini-10;
	  /* printf( "ini fim len = %d %d %d\n", ini, fim, L[j_p] ); */
	}
      }
      printf( "\nNovo intervalo de busca de caracteristicas: [ %d .. %d ].\n", ini, fim );
      break;
    case 'm':
      assert( nm < MAXM );
      printf( "\nDigite um marcador de inicio: " );
      scanf( " %[!-~]", m[ nm++ ] );
      printf( "\nInserindo marcador de inicio: %s", m[ nm - 1 ] );
      printf( "  Temos %d marcador(es) de inicio.\n", nm );
      break;
    case 'M':
      assert( nM < MAXM );
      printf( "\nDigite um marcador de fim: " );
      scanf( " %[!-~]", M[ nM++ ] );
      printf( "\nInserindo marcador de fim: %s", M[ nM - 1 ] );
      printf( "  Temos %d marcador(es) de fim.\n", nM );
      break;
    case 'g':
      printf( "\nPrimeira ocorrencia de marcador de inicio (gama) de cada politech:\n%s",
	      "  i   gama" );
      for ( i = 0; i < np; i++ ) {
	G[i] = BuscaMarcadores( 0, F[i], nm, m, &compr );
	printf( "\n%3d %5d", i, G[i] );
      }
      printf("\n");
      break;
    case 'd':
      printf( "\nCaracteristicas no intervalo [ %d .. %d ]:", ini, fim );
      for ( i = 0; i < np; i++ )
	if ( i != j_p ) {
	  k = Delta( F[i], F[j_p], D[i], G[i] - G[j_p], ini, fim );
	  printf( "\nD[ %3d ] = ", i );
	  for ( j = 0; D[i][j] < MAXP; j++ )
	    printf( " %5d", D[i][j] );
	}
	else 
	  D[i][0] = MAXP;	/* conjunto vazio de cararacterísticas */
      printf("\n");
      break;
    case 'b':
      printf( "\nDiametros e Probabilidades do conjunto de caracteristicas:" );
      printf( "\npol     n   k     d  P(diam=d) P(diam<=d)" );
      for ( i = 0; i < np; i++ )
	if ( i != j_p ) {
	  k = Delta( F[i], F[j_p], D[i], G[i] - G[j_p], ini, fim );
	  DiametroEProbabilidades( D[i], ini, fim, &diametro,
				       &Prob_eq_diametro, &Prob_le_diametro );
	  printf( "\n%3d %5d %3d %5d   %8.2e  %-8.3g",
		  i, fim - ini + 1, k, diametro, Prob_eq_diametro, Prob_le_diametro );
	}
	else
	  D[i][0] = MAXP;	/* conjunto vazio de cararacterísticas */
      printf( "\n" );
      break;
    case 'i':
      if ( HaIncompatibilidade( np, F, j_p, G, D ) )
	printf( "\nHah caracteristicas incompativeis e nao hah arvore filogenetica perfeita.\n" );
      else
	printf( "\nNao hah caracteristicas incompativeis e hah arvore filogenetica perfeita.\n" );
      break;
    default:
      printf( "\nComando invalido: %c\n", (int) comando );
    case 'q':
      continua = FALSE;
      printf( "\nObrigado, ate mais.\n" );
      break;
    }
  }
  return 0;
}







