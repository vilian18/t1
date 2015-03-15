
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_notas(int matriculas[], float notas[]){
   int i=0, mat;
   float nota1=0.0, nota2=0.0;
   FILE *f= fopen("notas.txt", "r");
   if(f==NULL){
      printf("Erro ao abrir arquivo!\n");
      exit(1);
   }
   while(feof(f)==0){
      if (fscanf(f,"%d %f %f\n", &mat, &nota1, &nota2)<0)
         break;
      matriculas[i]= mat;
      notas[i]= (nota1+nota2)/2;
      i++;
   }
   fclose(f);
}

void le_alunos(int* matriculas, char nomes[][50], int* n){
   int mat, i, linha=0;
   char nome[50];
   char c;
   FILE *f;
   f = fopen("alunos.txt", "r");
   if(f==NULL){
      printf("Erro ao abrir arquivo.\n");
      exit(1);
      }
   while(feof(f)==0){
      if(fscanf(f, "%d", &mat)<0)
         break;
      i=0;
      c=fgetc(f);
      while(c != '\n'){
         nome[i]=c;
         i++;
         c=fgetc(f);
      }
      nome[i]='\0';
      matriculas[linha]=mat;
      strcpy(nomes[linha], nome);
      linha++;
   }
   *n=linha;
   fclose(f);
}

void search(char nomes[][50], int matricula_alunos[], int matricula_notas[], float notas[], int *n, char *busca){
   int i=0, cont;
   for(i=0; i<*n; i++){
      if(strcasestr(nomes[i], busca)!=NULL)
         printf("Matricula: %d  Aluno: %s  Media: %g\n\n", matricula_notas[i], nomes[i], notas[i]);
   }
}

int main (int argc, char **argv){
   char nomes[50][50];
   int matricula_alunos[50], matricula_notas[50];
   float notas[50];
   int n=0;
   char nome[50];
   char *busca= nome;
   busca= argv[1];
   if(argc>1){
      le_alunos(matricula_alunos, nomes, &n);
      le_notas(matricula_notas, notas);
      search(nomes, matricula_alunos, matricula_notas, notas, &n, busca);
   }
   else{
      printf("Ha argumento faltando para o programa!\n");
   }
   return 0;
}
