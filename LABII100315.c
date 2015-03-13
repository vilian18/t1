/* testar se foi passado argumento para o programa:
if( argc>1){
   nome= argv[1];
}
printf("%s\n", nome);
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_alunos(int* matriculas, char** nomes, int* n){
   int mat, i=0, linha=0;
   char nome[50]={0};
   char c;
   FILE *f;
   f = fopen("aluno.txt", "r");
   if(f==NULL){
      printf("Erro ao abrir arquivo.\n");
      exit(1);
      }
   while(feof(f)!=0){
      if(fscanf(f, "%d, &mat")==0)
         break;
      c=fgetc(f);
      while(c != '\n'){
         nome[i]=c;
         c=fgetc(f);
         i++;
      }
      nome[i]='\0';
      matriculas[linha]=mat;
      strcpy(nomes[linha], nome);
   }
   *n=linha;
   fclose(f);
}

int main (int argc, char **argv){
   char nomes[50][50]={0};
   int matricula[50];
   char* nome_argumento= NULL;
   if(argc>1){
      nome_argumento= argv[1];
      printf("%s\n", nome_argumento);
   }
   else{
      printf("Ha argumento faltando para o programa!\n");
      exit(0);
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
