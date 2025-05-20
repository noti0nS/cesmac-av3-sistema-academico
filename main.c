#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define USERNAME "admin"
#define PASSWORD "admin"
#define MAX_ALUNOS 500

struct Aluno
{
  char nome[100];
  int nr_matricula;
};

struct AlunoDisciplinaNota
{
  int aluno_matricula;
  float nota;
};

struct Disciplina
{
  char titulo[50];
  struct AlunoDisciplinaNota aluno_notas[500];
};

void atribuir_nota()
{
  printf("TODO\n");
}

struct Aluno matricular_aluno(int total_alunos)
{
  if (total_alunos >= MAX_ALUNOS)
  {
    printf("Limite de alunos atingido.\n");
    return;
  }
  struct Aluno novo;

  printf("Digite o nome do aluno: ");
  scanf(" %[^\n]", novo.nome);

  printf("Digite o número de matrícula: ");
  scanf("%d", &novo.nr_matricula);

  return novo;
}

void exibir_alunos_matriculados()
{
  printf("TODO\n");
}

struct Disciplina cadastrar_disciplina()
{
  struct Disciplina disciplina;
  printf("Digite o título da disciplina: ");
  scanf("%s", disciplina.titulo);
  return disciplina;
}

void exibir_disciplinas()
{
  printf("TODO\n");
  ;
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
  system("cls || clear");
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

  limpar_tela();
  autenticar_usuario();
  limpar_tela();

  int total_alunos = 0;
  struct Aluno alunos[MAX_ALUNOS];

  int current_disciplina_idx = 0;
  struct Disciplina disciplinas[20];

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

    if (option > 0 && option < 7)
    {
      limpar_tela();
      printf("\n");
    }

    switch (option)
    {
    case 1:
      exibir_disciplinas();
      exibir_banner();
      break;
    case 2:
      struct Disciplina disciplina = cadastrar_disciplina();
      disciplinas[current_disciplina_idx] = disciplina;
      current_disciplina_idx++;
      exibir_banner();
      break;
    case 3:
      exibir_alunos_matriculados();
      exibir_banner();
      break;
    case 4:
      alunos[total_alunos] = matricular_aluno(total_alunos);
      total_alunos++;

      exibir_banner();
      break;
    case 5:
      atribuir_nota();
      exibir_banner();
      break;
    case 6:
      printf("Obrigado por usar o nosso sistema! Até a próxima :-)\n");
      break;
    default:
      printf("Opção inválida! Tente novamente.\n");
      break;
    }
  } while (option != 6);

  return 0;
}
