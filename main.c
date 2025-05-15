#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


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

void exibir_banner() {
  printf("====================================\n");
  printf("         BEM VINDO AO PROJETO       \n");
  printf("====================================\n");
}

int main()
{

  setlocale(LC_ALL,"");
  int option = 0;
  do
  {
    exibir_banner();
    printf("Escolha uma opção:\n");
    printf("1. Opção 1\n");
    printf("2. Opção 2\n");
    printf("3. Sair\n");
    printf("Digite sua opção: ");
    scanf("%d", &option);

    switch (option)
    {
      case 1:
        printf("Você escolheu a Opção 1.\n");
        break;
      case 2:
        printf("Você escolheu a Opção 2.\n");
        break;
      case 3:
        printf("Saindo...\n");
        break;
      default:
        printf("Opção inválida! Tente novamente.\n");
        break;
    }
  } while (option != 3);
  
  return 0;
}
