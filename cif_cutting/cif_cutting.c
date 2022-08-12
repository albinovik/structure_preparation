#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200

int main(argc, argv)
int argc;
char *argv[];
{

   char filename[MAX];

   FILE *fp;
   FILE *nmf;
   char words[MAX];
   int line=1;
   int mark=1; // if mark == 1 we read the text only
   int number = 1; //it is a name of each file
   char simb[MAX];
//   char temp[MAX];


   switch(argc) {
   case 1:
      fprintf(stderr, "Please enter the file name down:\n");
      scanf("%s", filename);
      break;
   case 2:
      strcpy(filename, argv[1]);
      break;
                }
 

   if(( fp = fopen(filename,"r") ) == NULL ){
		fprintf(stderr, "can not open file '%s'\n", filename);
		exit(1);
   }

   char start[]= "data_";
   char finish[]="#End";

   while( fgets(words, MAX, fp) != 0){//while there no the end of the file
          if(strncmp(words, start,5) == 0){ mark = 2; // if mark == 2 we print the text to file 'number'
                                            sprintf(&simb[0],"%d", number);
                                            char *temp = strcat(&simb[0],".cif");
                                            printf("%d file was created\n",number);
                                            nmf = fopen(temp,"w");
                                          }
          if(strncmp(words, finish,4) == 0){
                                             fprintf(nmf,"%s",words);
                                             fclose(nmf);
                                             mark = 1;//include reading the text only
                                             number++;
                                           }
          if(mark == 2) fprintf(nmf,"%s",words);
          printf("%d file | %d line\n",number, line++);
                                     }

    fclose(fp);

return 0;
}
