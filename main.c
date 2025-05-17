#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define USERNAME "admin"
#define PASSWORD "admin"

struct Aluno
{
  char nome[100];
  int nr_matricula;
};

struct AlunoDisciplinaNota
{
  struct Aluno aluno;
  float nota;
};

struct Disciplina
{
  char titulo[50];
  struct AlunoDisciplinaNota aluno_notas[500];
};

void cadastrar_disciplina(struct Disciplina *disciplina)
{
  printf("Digite o título da disciplina: ");
  scanf("%s", disciplina->titulo);
}

void exibir_banner()
{
printf("   ▄████████  ▄████████    ▄████████ ████████▄  ▀████    ▐████▀ \n");
printf("  ███    ███ ███    ███   ███    ███ ███   ▀███   ███▌   ████▀  \n");
printf("  ███    ███ ███    █▀    ███    ███ ███    ███    ███  ▐███    \n");
printf("  ███    ███ ███          ███    ███ ███    ███    ▀███▄███▀    \n");
printf("▀███████████ ███        ▀███████████ ███    ███    ████▀██▄     \n");
printf("  ███    ███ ███    █▄    ███    ███ ███    ███   ▐███  ▀███    \n");
printf("  ███    ███ ███    ███   ███    ███ ███   ▄███  ▄███     ███▄  \n");
printf("  ███    █▀  ████████▀    ███    █▀  ████████▀  ████       ███▄ \n");
printf("                                                                \n");

}

void limpar_tela()
{
  system("clear || cls");
}

void autenticar_usuario()
{
  printf("Digite suas credenciais para se autenticar no sistema.\n");

  char usuario[20];
  char senha[20];

  while (1)
  {
    printf("Usuário: ");
    scanf("%s", &usuario);
    printf("Senha: ");
    scanf("%s", &senha);

    if (strcmp(usuario, USERNAME) == 0 && strcmp(senha, PASSWORD) == 0)
    {
      break;
    }
    printf("Usuário ou senha inválidos. Tente novamente.\n");
  }
}

int main()
{
  setlocale(LC_ALL, "Portuguese");

  autenticar_usuario();
  limpar_tela();
  exibir_banner();

  int option = 0;
  do
  {
    printf("1 - Exibir Disciplinas\n");
    printf("2 - Cadastrar Disciplinas\n");
    printf("3 - Exibir Alunos Matriculados\n");
    printf("4 - Matricular Aluno\n");
    printf("5 - Atribuir Nota\n");
    printf("6 - Sair\n");
    printf("> ");

    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("TODO\n");
      break;
    case 2:
      printf("TODO\n");
      break;
    case 3:
      printf("TODO\n");
      break;
    case 4:
      printf("TODO\n");
      break;
    case 5:
      printf("TODO\n");
      break;
    case 6:
      limpar_tela();
      printf("Obrigado por usar o nosso sistema! Até a próxima :-)\n");
      break;
    default:
      printf("Opção inválida! Tente novamente.\n");
      break;
    }
  } while (option != 6);

  return 0;
}
