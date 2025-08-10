#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define L 6 //declarei 6 pq o meu for começa em 1
#define C 11 //11 pq meu for começa em 1, evitando ''comer'' 1 das 10 colunas

void disponibilidadeAssento(int i2, int j2, int mat[][C]);
void mapaAssento(int MAT[][C]);
int assentosLivres(int mat[][C]);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i, j;
    int M[L][C]= {0}; // MATRIZ DECLARADA AQUI PARA PODER SER USADA EM TODOS CASE
    int fileira, assento;
    int escolha, assentos_disponiveis;
    char resposta;


    printf("=== CONTROLE DE ASSENTOS — CINEMA ===");
    printf("\nNo que podemos te ajudar?\n");
    printf("\n1 - Reservar um assento\n2 - Exibir mapa de assentos \n3 - Consultar quantidade de assentos livres\n4 - Sair\n");
    scanf("%d", &escolha);



    while(1)
    {
        switch(escolha)
        {
        case 1:
            printf("\nDigite o a fileira que deseja (de 1 a %d): ", L-1);//L -1 porque eles foram declarados com +1 do tamanho real
            scanf("%d", &i);

            printf("\nDigite o assento que deseja (de 1 a %d): ", C-1);
            scanf("%d", &j);


            //OBS: A MATRIZ M[i][j] TEVE QUE SER DECLARADA ANTES PARA PODER SER USADA EM TODOS CASE!
            disponibilidadeAssento(i, j, M);
            printf("\nDeseja fazer outra reserva? Digite 's' para SIM ou 'n' para NÃO: ");
            scanf(" %c", &resposta);


            while(resposta == 's' || resposta =='S')
            {
                printf("\nDigite o a fileira que deseja (de 1 a 5): ");
                scanf("%d", &i);

                printf("\nDigite o assento que deseja (de 1 a 10): ");
                scanf("%d", &j);

                disponibilidadeAssento(i, j, M);

                printf("\nDeseja fazer outra reserva? Digite 's' para SIM ou 'n' para NÃO: ");
                scanf(" %c", &resposta);
            }
            if(resposta != 's' || resposta != 'S')
            {
                printf("\nReserva finalizada! \n");
            }
            break;

        case 2:
            mapaAssento(M);
            printf("\n");
            break;

        case 3:
            assentos_disponiveis = assentosLivres(M);
            printf("\nAssentos Livres: %d\n", assentos_disponiveis);

            if(assentos_disponiveis == 0)
            {
                printf("\nNão há mais assentos disponíveis para esta sessão. ");
            }
            break;

        case 4:
            printf("\nAtendimento Finalizado!\n");
            return 0;
            break;

        default:
            printf("\nDigite uma opção válida!\n");

        }
        printf("\n === CONTROLE DE ASSENTOS — CINEMA === \n ");
        printf("\nNo que podemos te ajudar?\n");
        printf("\n1 - Reservar um assento\n2 - Exibir mapa de assentos \n3 - Consultar quantidade de assentos livres\n4 - Sair\n");
        scanf("%d", &escolha);
    }
}
int assentosLivres(int mat[][C])
{
    int i,j, cont_livres=0;

    for(i=1; i<L; i++)
    {
        for(j=1; j<C; j++)
        {
            if(mat[i][j]==0)
                cont_livres++;

        }
    }
    return cont_livres;

}
void disponibilidadeAssento(int i2, int j2, int mat[][C])
{

    if(i2>=L || i2 <1 || j2> C || j2<1)
    {
        printf("Assento inválido!\n");
        return; //BOTAMOS RETURN PARA NÃO ENCERRAR E PERGUNTAR DE NOVO QUAL ASSENTO
    }

    if(mat[i2][j2]==0)
    {
        printf("Lugar reservado com sucesso!");
        mat[i2][j2] = 1; //se for 0 (disponível) passa a ser 1 (ocupado).
    }
    else
    {
        printf("Assento já ocupado. Escolha outro.");
    }
}
void mapaAssento(int MAT[][C])
{
    int i, j;
    printf("\n *** LUGARES - CINEMA *** \n");
    for(i=1; i<L; i++)
    {
        for(j=1; j<C; j++)
        {
            printf("%d\t", MAT[i][j]);
        }
        printf("\n");

    }
}
