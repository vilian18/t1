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
   FILE *f = fopen("alunos.txt", "R");
   while(feof(f)!=0){
      if(fscanf(F, "%d, &mat")==0)
         break;
      c=fgetc(F);
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
