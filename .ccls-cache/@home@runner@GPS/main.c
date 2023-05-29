#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int is_alphanumeric(char*str){
  int i;
  for (i = 0; i < strlen(str); i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}

const char* dechiffrerCesar(char* texte, int cle) {
  static char *  res ;
  char * msgDechiffrer= (char *) malloc (strlen(texte));

  for (int i = 0; i <= strlen(texte)-1; i++) {
    if ((int) texte[i] >= 97 && (int) texte[i] <= 122) {
      if ((int) texte[i] - cle < 97) {
        if ((char)97+ ((int) texte[i] - cle-97) >= 0){
          // mod negatif
          msgDechiffrer[i] = (char)97+ ((int) texte[i] - cle-97)+26;
        }else{
          // mod pos
          msgDechiffrer[i] = (char)97+ ((int) texte[i] - cle-97);
        }
      } else {
        msgDechiffrer[i] = (char) (int) texte[i] - cle;
      }
    } else if ((int) texte[i] <= 90 && (int) texte[i] >= 65) {

      if ((int) texte[i] - cle < 65) {

        if ((char)65+ ((int) texte[i] - cle-65) >= 0){
          // mod negatif
          msgDechiffrer[i] = (char)65+ ((int) texte[i] - cle-65)+26;
        }else{
          // mod pos
          msgDechiffrer[i] = (char)65+ ((int) texte[i] - cle-65);
        }
        
      } else {
         msgDechiffrer[i]= texte[i];
      }
    }
  }
  printf("%s\n", msgDechiffrer);
  res=msgDechiffrer ;
  return res;
}

const char* chiffrerCesar(char* texte, int cle) {
  static char *  res ;
  char * msgChiffrer= (char *) malloc (strlen(texte));
  for (int i = 0; i <= strlen(texte)-1; i++) {

    if ((int) texte[i] >= 97 && (int) texte[i] <= 122){
      msgChiffrer[i] = (char)97+ (((int) texte[i] + cle)-97)%26;
    }else if ((int) texte[i] <= 90 && (int) texte[i] >= 65){
      msgChiffrer[i] = (char) 65+((((int) texte[i] + cle)-65)%26);
    }else{
      msgChiffrer[i]= texte[i];
    } 
    //printf("%c", msgChiffrer[i]);
    
  }
  res=msgChiffrer ;
  return res;
}

int main() {
  // char str[]="pipicaca09";
  // is_alphanumeric(str);
  // if (is_alphanumeric(str)) {
  //   printf("abc\n");   
  // }
  char* texte;
  //printf("%s\n", chiffrerCesar("testZ", 1));
  texte = chiffrerCesar("teztZ#éù§§§$$$$$    ;;;", 15);
  printf("%s\n", texte);
  dechiffrerCesar(texte, 15);
  printf("%s\n",  dechiffrerCesar(texte, 15));


  
  return 0;
  
}













