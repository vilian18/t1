/* testar se foi passado argumento para o programa:
if( argc>1){
   nome= argv[1];
}
printf("%s\n", nome);
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void imprime_matriculas(int matricula[],int n){
   int i;
   for(i=0; i<n; i++){
      printf("%d\n", matricula[i]);
   }
}

void imprime_nomes(char nomes[][50], int n){
   int i;
   for(i=0; i<n; i++){
         printf("%s\n", nomes[i]);
      }
}

void search(char nomes[][50], int matricula[], int n, char *busca){
   int i=0;
   for(i=0; i<n; i++){
      if(strcasestr(nomes[i], busca)!=NULL)
         printf("%d  %s\n", matricula[i], nomes[i]);
   }
}

int main (int argc, char **argv){
   char nomes[50][50];
   int matricula[50];
   int n=0;
   char nome[50];
   char *busca= nome;
   busca= argv[1];
   if(argc>1){
      le_alunos(matricula, nomes, &n);
      search(nomes, matricula, n, busca);
   }
   else{
      printf("Ha argumento faltando para o programa!\n");
   }

   return 0;
}



/* funcoes de entrada e saida de arquivos:
strcmp --> comparar duas strings
if(strcmp(s1,s2)==0)
   iguais
fopen --> abrir arquivo
fclose --> fechar arquivo
fgetc --> le 1 caracter
feof --> testar se chegou no final do arquivo
if(feof(F)==0) --> significa o final do arquivo
   fclose(F);
*/
