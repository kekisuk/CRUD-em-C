/*
        SISTEMA DE ACADEMIA: Athletica System
*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//prototipo das fun��es
void menu();
void cadastrar();
void buscar();
void excluir();
void atualizar();

//struct dos dados do aluno a ser cadastrado
typedef struct dados{
    char cpf[15];
    char nome[100];
    char idade[5];
    char endereco[300];
    char telefone_celular[20];
    char modalidade[100];
}dados;

/*
	Fun��o menu est� num la�o de repeti��o, escolhe uma das op��es mostradas e � feito a chamada de fun��o.
	Usamos o "switch" como estrutura condicional. A fun��� � encerrado quando o usuario digitar 0.
*/
void menu(){

    setlocale(LC_ALL, "Portuguese"); //acentua��o
    int op;
    do{
        system("color E"); //fun��o - cor amarelo
        system("cls"); //limpa tela
        printf("===============================================================");
        printf("\n|                                                             |");
        printf("\n");
        printf("|            .....Menu Athletica System.....                  |");
        printf("\n|                                                             |");
        printf("\n");
        printf("|          Digite a op��o que deseja realizar:                |");
        printf("\n|                                                             |");
        printf("\n");
        printf("|          (1) - CADASTRAR um novo aluno(a)                   |");
        printf("\n");
        printf("|          (2) - BUSCAR um aluno(a)                           |");
        printf("\n");
        printf("|          (3) - ATUALIZAR os dados de um(a) aluno(a)         |");
        printf("\n");
        printf("|          (4) - EXCLUIR um cadastro de um(a) aluno(a)        |");
        printf("\n");
        printf("|          (0) - ENCERRAR o programa                          |");
        printf("\n|                                                             |");
        printf("\n");
        printf("===============================================================");
        printf("\n");
        printf("\n");
        printf("OP��O: ");
        scanf("%d",&op);
        getchar(); //limpar buffer de memoria
        switch(op){
            case 1:
                cadastrar();
            break;
            case 2:
                buscar();
            break;
            case 3:
                atualizar();
            break;
            case 4:
                excluir();
            break;
        }
    } while(op!=0);

}

/*
	Fun��o para cadastrar os dados em um arquivo, usando o CPF como chave prim�ria
	para evitar c�pias e facilitar a busca, exclus�o e atualiza��o dos dados nas demais fun��es.
	Todas as demais fun��es dependem do arquivo criado nessa fun��o.
*/
void cadastrar(){

        system("color B");//fun��o para mudar a cor do texto
        setlocale(LC_ALL, "Portuguese");//acentua��o
        system("cls");//limpar tela
        char name[11];
        dados principal;
        FILE *arquivo;

        printf("===============================================================\n");
        printf("                          CADASTRAR                            \n");
        printf("===============================================================\n\n");
        printf("Digite o numero do CPF do(a) aluno(a): ");
        scanf("%s", &name);

        fflush(stdin);
        printf("Digite o nome do(a) aluno(a): ");
        fgets(principal.nome,100,stdin);

        printf("Digite a idade do(a) aluno(a): ");
        fgets(principal.idade,10,stdin);

        printf("Digite o endere�o do(a) aluno(a): ");
        fgets(principal.endereco,300,stdin);

        printf("\n===== MUSCULA��O ====="); //1
        printf("\n===== CROSSFIT   ====="); //2
        printf("\n===== DAN�A      ====="); //3
        printf("\n===== KARATE     ====="); //4
        printf("\n===== JIU JITSU  ====="); //5
        printf("\n===== NATA��O    ====="); //6
        printf("\n===== IOGA       ====="); //7
        printf("\n===== PILATES    ====="); //8
        printf("\n===== JUMP       ====="); //9
        printf("\n===== GIN�STICA  =====\n\n");

        printf("Digite a modalidade que deseja se matricular: ");
        fgets(principal.modalidade,100,stdin);

        printf("Digite o numero/telefone do(a) aluno(a): ");
        fgets(principal.telefone_celular,20,stdin);

        arquivo = fopen(name, "w"); //modo escrita

        fprintf(arquivo,"===============================================================");
        fprintf(arquivo,"\n");
        fprintf(arquivo,"NOME: ");
        fputs(principal.nome,arquivo);

        fprintf(arquivo,"IDADE: ");
        fputs(principal.idade,arquivo);

        fprintf(arquivo,"ENDERE�O: ");
        fputs(principal.endereco,arquivo);

        fprintf(arquivo,"MODALIDADE: ");
        fputs(principal.modalidade,arquivo);

        fprintf(arquivo,"TELEFONE: ");
        fputs(principal.telefone_celular,arquivo);
        fprintf(arquivo,"===============================================================");

        fclose(arquivo);
        fflush(stdin);

        system("cls");
        printf("===============================================================\n");
        printf("                      DADOS CADASTRADOS!                       \n");
        printf("===============================================================\n\n");

        system("pause");
}

/*
	Fun��o que busca os dados no arquivo aberto em modo "r".
	Digite a chave-prim�ria(CPF) e o arquivo ser� buscado, mostrar� tudo o que h� dentro do arquivo.
	Depois que o arquivo � fechado, a fun��o termina e volta para o menu.
*/
void buscar(){

    system("color F"); //fun��o - cor branco
    setlocale(LC_ALL, "Portuguese"); //acentua��o
    int i = 0; //auxiliar do for
    char nome[15]; //nome do arquivo p/ buscar
    int numPalavras = 0;
    char *palavras[50];
    char line[50];

    system("cls");
    printf("===============================================================\n");
    printf("                           BUSCAR                              \n");
    printf("===============================================================\n");
    printf("\nDigite o numero do CPF que deseja buscar: ");
    scanf("%s", &nome);
    printf("\n");

    FILE *arquivo;
    arquivo = fopen(nome, "r"); //abrindo em modo leitura

    if(arquivo == NULL){
        printf("ARQUIVO INEXISTENTE!\n");
        system("pause");
    }
    else{
        while(fgets(line, sizeof line, arquivo) != NULL){
            palavras[i] = strdup(line);
            i++;
            numPalavras++;
        }

        for(i = 0; i<numPalavras; i++){
            printf("%s", palavras[i]); //exibi as palavras que estao no vetor.
        }

        fclose(arquivo); //fecha arquivo
        printf("\n\n");
        getchar(); //limpar buffer
        system("pause");
        system("cls"); //limpa tela

    }
}

/*
	Fun��o para excluir o aluno matriculado. O usuario digitar� o CPF para buscar o arquivo.
	Caso o arquivo n�o exista, ele mostrar� uma mensagem de inexistencia.
*/
void excluir(){

      system("color A");
      setlocale(LC_ALL, "Portuguese");
      int ret;
      FILE *arquivo;
      char nome[15];
      system("cls");

      printf("===============================================================\n");
      printf("                            APAGAR                             \n");
      printf("===============================================================\n");

      printf("Digite o numero do CPF que deseja excluir: ");
      scanf("%s", &nome); //pegar arquivo pelo n�mero do CPF

      printf("Tem certeza que deseja prosseguir com a exclus�o?\n(1) - SIM\n(2) - NAO\n\nOP��O: ");
      int simounao;
      scanf("%d",&simounao);
      if(simounao == 2){ //if pra confirmar ou n�o a exclus�o
        system("cls");
        return 0;
      }

      arquivo = fopen(nome, "r"); //modo leitura
      fclose(arquivo);

      if(arquivo == NULL){ //if pra se o arquivo n�o existir, retornar aviso
          printf("\nARQUIVO INEXISTENTE!\n");
      }
      else{ //se existir chama a fun��o remove para excluir o arquivo
         ret = remove(nome);

         if(ret == 0){ //se ret retornar 0 significa que o arquivo foi exclu�do com sucesso
            printf("\nEXCLUIDO COM SUCESSO!\n");
         }
         else{ //tratamento de erro em caso de problema desconhecido
            printf("\nERRO AO EXCLUIR!\n");
         }
      }

      printf("\n");
      getchar(); //limpar buffer de memoria
      system("pause");
      system("cls"); //limpar tela

}

 /*
	Fun��o para atualizar os dados em um arquivo atraves de sobrescrita,
	utilizando o CPF como chave prim�ria para localizar o arquivo.
*/
void atualizar(){

        system("color D");//fun��o cor-roxo.
        setlocale(LC_ALL, "Portuguese"); //acentua��o
        system("cls"); //limpar tela
        char nome[12]; //CPF � a chave prim�ria para procurar o arquivo.
        dados principal;

        printf("===============================================================\n");
        printf("                          ATUALIZAR                            \n");
        printf("===============================================================\n\n");

        printf("Digite o CPF do aluno que deseja atualizar os dados: ");
        scanf("%s", &nome); //usuario digita o CPF para procurar o arquivo

        printf("Aten��o!\nPara atualizar um cadastro � necessario sobrescrever o arquivo original.\n");
        printf("Deseja continuar com a atualiza��o?\n(1) - SIM\n(2) - NAO\n\nOP��O: ");
        int simounao;
        scanf("%d",&simounao);

        if(simounao == 2){ //caso o usu�rio desista de atualizar ele escolhe a op��o 2 e ir� retornar para o menu.
            system("cls");
            return 0;
        }
        else{ //caso ele prossiga, ele abre um arquivo em modo "r+" leitura/escrita.
            FILE *arquivo;
            arquivo = fopen(nome, "r+"); //"r+" , O arquivo deve existir e pode ser modificado.

            if(arquivo == NULL){ //condi��o caso o usu�rio digite um cpf que n�o exista, ele mostra a mensagem.

                printf("ARQUIVO INEXISTENTE!\n\n");
                system("pause");
            }
            else{ //se o arquivo existir o dados s�o todos reescritos novamente como a fun��o cadastrar.

                system("cls"); //limpar tela.
                fflush(stdin); //limpar buffer de memoria.

                printf("Digite o nome do(a) aluno(a): ");
                fgets(principal.nome,100,stdin);

                printf("Digite a idade do(a) aluno(a): ");
                fgets(principal.idade,10,stdin);

                printf("Digite o endere�o do(a) aluno(a): ");
                fgets(principal.endereco,300,stdin);

                 printf("\n===== MUSCULA��O ====="); //1
                 printf("\n===== CROSSFIT   ====="); //2
                 printf("\n===== DAN�A      ====="); //3
                 printf("\n===== KARATE     ====="); //4
                 printf("\n===== JIU JITSU  ====="); //5
                 printf("\n===== NATA��O    ====="); //6
                 printf("\n===== IOGA       ====="); //7
                 printf("\n===== PILATES    ====="); //8
                 printf("\n===== JUMP       ====="); //9
                 printf("\n===== GIN�STICA  =====\n\n"); //10

                printf("Digite a modalidade que deseja se matricular: ");
                fgets(principal.modalidade,50,stdin);

                printf("Digite o numero/telefone do(a) aluno(a): ");
                fgets(principal.telefone_celular,20,stdin);

                fclose(arquivo); //fechar arquivo para n�o dar problema ao excluir ap�s atualizar.

                //se o arquivo n�o existir, ele ser� criado. Se j� existir, o conte�do anterior ser� destru�do.
                arquivo = fopen(nome, "w"); //modo "w" Abrir um arquivo texto para grava��o/escrita.

                fprintf(arquivo,"===============================================================");
                fprintf(arquivo,"\n");
                fprintf(arquivo,"NOME: ");
                fputs(principal.nome,arquivo);

                fprintf(arquivo,"IDADE: ");
                fputs(principal.idade,arquivo);

                fprintf(arquivo,"ENDERE�O: ");
                fputs(principal.endereco,arquivo);

                fprintf(arquivo,"MODALIDADE: ");
                fputs(principal.modalidade,arquivo);

                fprintf(arquivo,"TELEFONE: ");
                fputs(principal.telefone_celular,arquivo);
                fprintf(arquivo,"===============================================================");

                fclose(arquivo); //o arquivo � fechado.
                fflush(stdin); // o buffer de mem�ria � limpo.

                system("cls"); //limpa tela.
                printf("===============================================================\n");
                printf("                       DADOS ATUALIZADOS!                      \n");
                printf("===============================================================\n\n");

                system("pause");
            }
        }
}

/*
	Fun��o principal que s� chama a fun��o "menu" e a partir dela todo o sistema ser� executado.
*/
int main(){

    menu(); //chama a fun��o menu.

    return 0;
}
