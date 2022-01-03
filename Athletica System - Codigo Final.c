/*
        SISTEMA DE ACADEMIA: Athletica System
	AUTORES: Francisca Kelen Ferreira dos Santos, Mateus Eugênio de Andrade, Thiago Natalys Ribeiro da Silva, Lucas Antônio Ferreira Almeida e Olavo Cartaxo.
*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//prototipo das funções
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
	Função menu está num laço de repetição, escolhe uma das opções mostradas e é feito a chamada de função.
	Usamos o "switch" como estrutura condicional. A funçãõ é encerrado quando o usuario digitar 0.
*/
void menu(){

    setlocale(LC_ALL, "Portuguese"); //acentuação
    int op;
    do{
        system("color E"); //função - cor amarelo
        system("cls"); //limpa tela
        printf("===============================================================");
        printf("\n|                                                             |");
        printf("\n");
        printf("|            .....Menu Athletica System.....                  |");
        printf("\n|                                                             |");
        printf("\n");
        printf("|          Digite a opção que deseja realizar:                |");
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
        printf("OPÇÃO: ");
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
	Função para cadastrar os dados em um arquivo, usando o CPF como chave primária
	para evitar cópias e facilitar a busca, exclusão e atualização dos dados nas demais funções.
	Todas as demais funções dependem do arquivo criado nessa função.
*/
void cadastrar(){

        system("color B");//função para mudar a cor do texto
        setlocale(LC_ALL, "Portuguese");//acentuação
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

        printf("Digite o endereço do(a) aluno(a): ");
        fgets(principal.endereco,300,stdin);

        printf("\n===== MUSCULAÇÃO ====="); //1
        printf("\n===== CROSSFIT   ====="); //2
        printf("\n===== DANÇA      ====="); //3
        printf("\n===== KARATE     ====="); //4
        printf("\n===== JIU JITSU  ====="); //5
        printf("\n===== NATAÇÃO    ====="); //6
        printf("\n===== IOGA       ====="); //7
        printf("\n===== PILATES    ====="); //8
        printf("\n===== JUMP       ====="); //9
        printf("\n===== GINÁSTICA  =====\n\n");

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

        fprintf(arquivo,"ENDEREÇO: ");
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
	Função que busca os dados no arquivo aberto em modo "r".
	Digite a chave-primária(CPF) e o arquivo será buscado, mostrará tudo o que há dentro do arquivo.
	Depois que o arquivo é fechado, a função termina e volta para o menu.
*/
void buscar(){

    system("color F"); //função - cor branco
    setlocale(LC_ALL, "Portuguese"); //acentuação
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
	Função para excluir o aluno matriculado. O usuario digitará o CPF para buscar o arquivo.
	Caso o arquivo não exista, ele mostrará uma mensagem de inexistencia.
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
      scanf("%s", &nome); //pegar arquivo pelo número do CPF

      printf("Tem certeza que deseja prosseguir com a exclusão?\n(1) - SIM\n(2) - NAO\n\nOPÇÃO: ");
      int simounao;
      scanf("%d",&simounao);
      if(simounao == 2){ //if pra confirmar ou não a exclusão
        system("cls");
        return 0;
      }

      arquivo = fopen(nome, "r"); //modo leitura
      fclose(arquivo);

      if(arquivo == NULL){ //if pra se o arquivo não existir, retornar aviso
          printf("\nARQUIVO INEXISTENTE!\n");
      }
      else{ //se existir chama a função remove para excluir o arquivo
         ret = remove(nome);

         if(ret == 0){ //se ret retornar 0 significa que o arquivo foi excluído com sucesso
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
	Função para atualizar os dados em um arquivo atraves de sobrescrita,
	utilizando o CPF como chave primária para localizar o arquivo.
*/
void atualizar(){

        system("color D");//função cor-roxo.
        setlocale(LC_ALL, "Portuguese"); //acentuação
        system("cls"); //limpar tela
        char nome[12]; //CPF é a chave primária para procurar o arquivo.
        dados principal;

        printf("===============================================================\n");
        printf("                          ATUALIZAR                            \n");
        printf("===============================================================\n\n");

        printf("Digite o CPF do aluno que deseja atualizar os dados: ");
        scanf("%s", &nome); //usuario digita o CPF para procurar o arquivo

        printf("Atenção!\nPara atualizar um cadastro é necessario sobrescrever o arquivo original.\n");
        printf("Deseja continuar com a atualização?\n(1) - SIM\n(2) - NAO\n\nOPÇÃO: ");
        int simounao;
        scanf("%d",&simounao);

        if(simounao == 2){ //caso o usuário desista de atualizar ele escolhe a opção 2 e irá retornar para o menu.
            system("cls");
            return 0;
        }
        else{ //caso ele prossiga, ele abre um arquivo em modo "r+" leitura/escrita.
            FILE *arquivo;
            arquivo = fopen(nome, "r+"); //"r+" , O arquivo deve existir e pode ser modificado.

            if(arquivo == NULL){ //condição caso o usuário digite um cpf que não exista, ele mostra a mensagem.

                printf("ARQUIVO INEXISTENTE!\n\n");
                system("pause");
            }
            else{ //se o arquivo existir o dados são todos reescritos novamente como a função cadastrar.

                system("cls"); //limpar tela.
                fflush(stdin); //limpar buffer de memoria.

                printf("Digite o nome do(a) aluno(a): ");
                fgets(principal.nome,100,stdin);

                printf("Digite a idade do(a) aluno(a): ");
                fgets(principal.idade,10,stdin);

                printf("Digite o endereço do(a) aluno(a): ");
                fgets(principal.endereco,300,stdin);

                 printf("\n===== MUSCULAÇÃO ====="); //1
                 printf("\n===== CROSSFIT   ====="); //2
                 printf("\n===== DANÇA      ====="); //3
                 printf("\n===== KARATE     ====="); //4
                 printf("\n===== JIU JITSU  ====="); //5
                 printf("\n===== NATAÇÃO    ====="); //6
                 printf("\n===== IOGA       ====="); //7
                 printf("\n===== PILATES    ====="); //8
                 printf("\n===== JUMP       ====="); //9
                 printf("\n===== GINÁSTICA  =====\n\n"); //10

                printf("Digite a modalidade que deseja se matricular: ");
                fgets(principal.modalidade,50,stdin);

                printf("Digite o numero/telefone do(a) aluno(a): ");
                fgets(principal.telefone_celular,20,stdin);

                fclose(arquivo); //fechar arquivo para não dar problema ao excluir após atualizar.

                //se o arquivo não existir, ele será criado. Se já existir, o conteúdo anterior será destruído.
                arquivo = fopen(nome, "w"); //modo "w" Abrir um arquivo texto para gravação/escrita.

                fprintf(arquivo,"===============================================================");
                fprintf(arquivo,"\n");
                fprintf(arquivo,"NOME: ");
                fputs(principal.nome,arquivo);

                fprintf(arquivo,"IDADE: ");
                fputs(principal.idade,arquivo);

                fprintf(arquivo,"ENDEREÇO: ");
                fputs(principal.endereco,arquivo);

                fprintf(arquivo,"MODALIDADE: ");
                fputs(principal.modalidade,arquivo);

                fprintf(arquivo,"TELEFONE: ");
                fputs(principal.telefone_celular,arquivo);
                fprintf(arquivo,"===============================================================");

                fclose(arquivo); //o arquivo é fechado.
                fflush(stdin); // o buffer de memória é limpo.

                system("cls"); //limpa tela.
                printf("===============================================================\n");
                printf("                       DADOS ATUALIZADOS!                      \n");
                printf("===============================================================\n\n");

                system("pause");
            }
        }
}

/*
	Função principal que só chama a função "menu" e a partir dela todo o sistema será executado.
*/
int main(){

    menu(); //chama a função menu.

    return 0;
}
