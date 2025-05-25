#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define USERNAME "admin"
#define PASSWORD "admin"

#define MAX_ALUNOS 100
#define MAX_DISCIPLINAS 20
#define MAX_NOTAS 10

struct Aluno
{
  char nome[100];
  int nr_matricula;
  float notas[MAX_NOTAS];
  int notas_atribuidas;
};

struct Disciplina
{
  char titulo[50];
  struct Aluno alunos[MAX_ALUNOS];
  int alunos_matriculados;
  int ok;
};

struct Disciplina *escolher_disciplina(struct Disciplina disciplinas[], int total_disciplinas)
{
  int opcao_disciplina;

  for (int i = 0; i < total_disciplinas; i++)
  {
    printf("%d - %s\n", i + 1, disciplinas[i].titulo);
  }

  do
  {
    printf("Selecione uma disciplina (1-%d): ", total_disciplinas);
    scanf("%d", &opcao_disciplina);
    if (opcao_disciplina < 1 || opcao_disciplina > total_disciplinas)
    {
      printf("Opção inválida! Tente novamente.\n");
    }
  } while (opcao_disciplina < 1 || opcao_disciplina > total_disciplinas);
  return &disciplinas[opcao_disciplina - 1];
}

struct Aluno *selecionar_aluno(struct Disciplina *disciplina)
{
  int opcao_aluno;

  for (int i = 0; i < disciplina->alunos_matriculados; i++)
  {
    printf("%d - %s\n", i + 1, disciplina->alunos[i].nome);
  }

  do
  {
    printf("Selecione um aluno (1-%d): ", disciplina->alunos_matriculados);
    scanf("%d", &opcao_aluno);
    if (opcao_aluno < 1 || opcao_aluno > disciplina->alunos_matriculados)
    {
      printf("Opção inválida! Tente novamente.\n");
    }
  } while (opcao_aluno < 1 || opcao_aluno > disciplina->alunos_matriculados);
  return &(disciplina->alunos[opcao_aluno - 1]);
}

void atribuir_nota(struct Disciplina disciplinas[], int total_disciplinas)
{
  if (total_disciplinas == 0)
  {
    printf("Nenhuma disciplina cadastrada.\n");
    return;
  }

  struct Disciplina *disciplina_selecionada = escolher_disciplina(disciplinas, total_disciplinas);
  if (disciplina_selecionada->alunos_matriculados == 0)
  {
    printf("Nenhum aluno matriculado nesta disciplina.\n");
    return;
  }

  struct Aluno *aluno_selecionado = selecionar_aluno(disciplina_selecionada);
  if (aluno_selecionado->notas_atribuidas >= MAX_NOTAS)
  {
    printf("Limite de notas atingido para o aluno '%s'.\n", aluno_selecionado->nome);
    return;
  }

  float nota = 0.0;
  printf("Digite a nota do aluno '%s' (Matrícula: %d): ", aluno_selecionado->nome, aluno_selecionado->nr_matricula);
  do
  {
    scanf("%f", &nota);
    if (nota < 0.0 || nota > 10.0)
    {
      printf("Nota inválida! Digite uma nota entre 0 e 10: ");
    }
  } while (nota < 0.0 || nota > 10.0);

  aluno_selecionado->notas[aluno_selecionado->notas_atribuidas] = nota;
  aluno_selecionado->notas_atribuidas++;
}

void matricular_aluno(struct Disciplina disciplinas[], int total_disciplinas)
{
  if (total_disciplinas == 0)
  {
    printf("Nenhuma disciplina cadastrada.\n");
    return;
  }

  struct Disciplina *disciplina_selecionada = escolher_disciplina(disciplinas, total_disciplinas);
  if (disciplina_selecionada->alunos_matriculados >= MAX_ALUNOS)
  {
    printf("Limite de alunos matriculados atingido para essa disciplina.\n");
    return;
  }

  struct Aluno aluno = {0};

  printf("Digite o nome do aluno: ");
  scanf(" %[^\n]", aluno.nome);

  printf("Digite o número de matrícula: ");
  scanf("%d", &aluno.nr_matricula);

  disciplina_selecionada->alunos[disciplina_selecionada->alunos_matriculados] = aluno;
  disciplina_selecionada->alunos_matriculados++;

  printf("Aluno matriculado com sucesso na disciplina '%s'!\n", disciplina_selecionada->titulo);
}

void exibir_alunos_matriculados(struct Disciplina disciplinas[], int total_disciplinas)
{
  if (total_disciplinas == 0)
  {
    printf("Nenhuma disciplina cadastrada.\n");
    return;
  }

  for (int i = 0; i < total_disciplinas; i++)
  { 
    struct Disciplina disciplina = disciplinas[i];
    if (disciplina.alunos_matriculados == 0) 
    {
      printf("Nenhum aluno matriculado na disciplina '%s'.\n\n", disciplina.titulo);
      continue;
    }
    printf("======%s======\n", disciplina.titulo);
    for (int j = 0; j < disciplina.alunos_matriculados; j++)
    {
      struct Aluno aluno = disciplina.alunos[j];
      printf("%s | %d | ", aluno.nome, aluno.nr_matricula);
      if (aluno.notas_atribuidas == 0)
      {
        printf("Sem notas.\n");
        continue;
      }
      for (int z = 0; z < aluno.notas_atribuidas; z++)
      {
        printf("%.2f · ", aluno.notas[z]);
      }
      printf("\n");
    }
    printf("\n");
  }
}

struct Disciplina cadastrar_disciplina(int total_disciplinas)
{
  struct Disciplina disciplina = {0};
  if (total_disciplinas >= MAX_DISCIPLINAS)
  {
    printf("Limite de disciplinas atingido.\n");
    return disciplina;
  }
  printf("Digite o título da disciplina: ");
  scanf(" %[^\n]", disciplina.titulo);
  disciplina.ok = 1;
  return disciplina;
}
void exibir_disciplinas(struct Disciplina disciplinas[], int total_disciplinas)
{
  printf("=== Disciplinas Cadastradas ===\n");

  if (total_disciplinas == 0)
  {
    printf("Nenhuma disciplina cadastrada.\n");
    return;
  }

  for (int i = 0; i < total_disciplinas; i++)
  {
    if (disciplinas[i].ok == 1)
    {
      printf("Título: %s\n", disciplinas[i].titulo);
      printf("-----------------------------\n");
    }
  }
}
void exibir_banner()
{
  // printf("                                                                \n");
  // printf("   ▄████████  ▄████████    ▄████████ ████████▄  ▀████    ▐████▀ \n");
  // printf("  ███    ███ ███    ███   ███    ███ ███   ▀███   ███▌   ████▀  \n");
  // printf("  ███    ███ ███    █▀    ███    ███ ███    ███    ███  ▐███    \n");
  // printf("  ███    ███ ███          ███    ███ ███    ███    ▀███▄███▀    \n");
  // printf("▀███████████ ███        ▀███████████ ███    ███    ████▀██▄     \n");
  // printf("  ███    ███ ███    █▄    ███    ███ ███    ███   ▐███  ▀███    \n");
  // printf("  ███    ███ ███    ███   ███    ███ ███   ▄███  ▄███     ███▄  \n");
  // printf("  ███    █▀  ████████▀    ███    █▀  ████████▀  ████       ███▄ \n");
  // printf("                                                                \n");
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
  setlocale(LC_ALL, "pt_BR.UTF-8");

  limpar_tela();
  autenticar_usuario();
  limpar_tela();
  exibir_banner();

  int total_disciplinas = 0;
  struct Disciplina disciplinas[MAX_DISCIPLINAS];

  int option = 0;
  do
  {
    printf("1 - Exibir Disciplinas\n");
    printf("2 - Cadastrar Disciplinas\n");
    printf("3 - Exibir Alunos Matriculados\n");
    printf("4 - Matricular Aluno em Disciplina\n");
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
      exibir_disciplinas(disciplinas, total_disciplinas);
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
      exibir_alunos_matriculados(disciplinas, total_disciplinas);
      exibir_banner();
      break;
    case 4:
      matricular_aluno(disciplinas, total_disciplinas);
      exibir_banner();
      break;
    case 5:
      atribuir_nota(disciplinas, total_disciplinas);
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
