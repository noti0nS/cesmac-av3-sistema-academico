#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define USERNAME "admin"
#define PASSWORD "admin"

#define MAX_ALUNOS 500
#define MAX_NOTAS 500
#define MAX_DISCIPLINAS 20

struct Aluno
{
  char nome[100];
  int nr_matricula;
  int ok;
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
  int ok;
};

void atribuir_nota()
{
  printf("TODO\n");
}

struct Aluno matricular_aluno(int total_alunos)
{
  struct Aluno aluno;
  if (total_alunos >= MAX_ALUNOS)
  {
    printf("Limite de alunos atingido.\n");
    return aluno;
  }

  printf("Digite o nome do aluno: ");
  scanf(" %[^\n]", aluno.nome);

  printf("Digite o número de matrícula: ");
  scanf("%d", &aluno.nr_matricula);

  aluno.ok = 1;
  return aluno;
}

void exibir_alunos_matriculados(struct Aluno alunos[], int total_alunos)
{
  if (total_alunos == 0)
  {
    printf("Nenhum aluno matriculado.\n");
    return;
  }

  printf("Lista de alunos matriculados:\n");
  for (int i = 0; i < total_alunos; i++)
  {
    if (alunos[i].ok == 1)
    {
      printf("Nome: %s | Matrícula: %d\n", alunos[i].nome, alunos[i].nr_matricula);
    }
  }
}


struct Disciplina cadastrar_disciplina(int total_disciplinas)
{
  struct Disciplina disciplina;
  if (total_disciplinas >= 20)
  {
    printf("Limite de disciplinas atingido.\n");
    return disciplina;
  }
  printf("Digite o título da disciplina: ");
  scanf("%s", disciplina.titulo);
  disciplina.ok = 1;
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
  // exibir_banner();
  
  int total_alunos = 0;
  struct Aluno alunos[MAX_ALUNOS];
  
  int total_disciplinas = 0;
  struct Disciplina disciplinas[MAX_DISCIPLINAS];
  
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
      struct Disciplina disciplina = cadastrar_disciplina(total_disciplinas);
      if (disciplina.ok > 0)
      {
        disciplinas[total_disciplinas] = disciplina;
        total_disciplinas++;
        printf("Disciplina cadastrada com sucesso!\n");
      }
      exibir_banner();
      break;
    case 3:
      exibir_alunos_matriculados(alunos, total_alunos);
      exibir_banner();
      break;
    case 4:
      struct Aluno aluno = matricular_aluno(total_alunos);
      if (aluno.ok > 0)
      {
        alunos[total_alunos] = aluno;
        total_alunos++;
        printf("Aluno matriculado com sucesso!\n");
      }
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
