/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Projet 3 : Chiffrement de messages                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Gouagout Jorian                                              *
*                                                                             *
*  Nom-prénom2 : Lugagne Théo                                                 *
*                                                                             *
*  Nom-prénom3 : Ah-Hong Emmanuel                                             *
*                                                                             *
*  Nom-prénom4 : Blanco Théo                                                  *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : chiffrement.c                                             *
*                                                                             *
******************************************************************************/

#include "chiffrement.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int is_alphanumeric(char*str){
  /* Cette fonction detecte les caratères alphanumérique dans une chaine de caractère str
     renvoie 0 s'il n'y en as pas 
     renvoie 1 s'il y en as */
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}


const char* dechiffrerCesar(char* texte, int cle) {
  /* dechiffreCesar dechiffre le texte chiffré (par Cesar) en paramètre par la clé aussi en paramètre*/
    static char *  res ;
    char * msgDechiffrer= (char *) malloc (strlen(texte));

    for (int i = 0; i <= strlen(texte)-1; i++) {
        if ((int) texte[i] >= 97 && (int) texte[i] <= 122) {
          // si c'est un caractère minuscule :
            if ((int) texte[i] - cle < 97) {
              // si le carctère décaler depasse la borne
                if ((char)97+ ((int) texte[i] - cle-97) >= 0){
                  // si le modulo est positif :
                    msgDechiffrer[i] = (char)97+ ((int) texte[i] - cle-97)+26;
                }else{
                    msgDechiffrer[i] = (char)97+ ((int) texte[i] - cle-97);
                }
            } else {
                msgDechiffrer[i] = (char) (int) texte[i] - cle;
            }
        } else if ((int) texte[i] <= 90 && (int) texte[i] >= 65) {
          // si c'est un caractère majuscule
            if ((int) texte[i] - cle < 65) {
              // si le carctère décaler depasse la borne
                if ((char)65+ ((int) texte[i] - cle-65) >= 0){
                  // si le modulo est positif :
                    msgDechiffrer[i] = (char)65+ ((int) texte[i] - cle-65)+26;
                }else{
                    msgDechiffrer[i] = (char)65+ ((int) texte[i] - cle-65);
                }
            } else {
                msgDechiffrer[i]= texte[i];
            }
        }
    }
    res=msgDechiffrer ;
    return res;
}


const char* chiffrerCesar(char* texte, int cle) {
  /* chiffreCesar chiffre le texte en paramètre avec le chiffrement Cesar par la clé en paramètre*/
    static char *  res ;
    char * msgChiffrer= (char *) malloc (strlen(texte));
    for (int i = 0; i <= strlen(texte)-1; i++) {
        if ((int) texte[i] >= 97 && (int) texte[i] <= 122){
          // si c'est un caractère minuscule
            msgChiffrer[i] = (char)97+ (((int) texte[i] + cle)-97)%26;
        }else if ((int) texte[i] <= 90 && (int) texte[i] >= 65){
          // si c'est un caractère majuscule
            msgChiffrer[i] = (char) 65+((((int) texte[i] + cle)-65)%26);
        }else{
            msgChiffrer[i]= texte[i];
        }
    }
    res=msgChiffrer ;
    return res;
}


int main() {
    char* texte = (char *) malloc (100);
    int* cle = (int*) malloc (sizeof(int));
    printf("---------------------------------------- \n");
    printf("----------Chiffrement César------------- \n");
    printf("---------------------------------------- \n");
  
    printf("Entrer un texte à chiffrer/déchiffrer :");
    scanf("%s", texte);
    printf("Entrer une clé (entre 1 et 26) :");
    scanf("%d", cle);
    while(*cle <= 0 || *cle >26){
      printf("Clé invalide, veuillez reessayer ! \n");
      printf("Entrer une clé (entre 1 et 26) :");
      scanf("%d", cle);
    }
    
    if (is_alphanumeric(texte)) {
        
        texte = (char*) chiffrerCesar(texte, *cle);
        printf("\n\n\nLe texte chiffré est : ");
        printf("%s\n", texte);

        printf("par déchiffrement on obtient donc : ");
        printf("%s\n",  dechiffrerCesar(texte, *cle));
    } else {
      printf("Vous avez entré un caractère non alphanumérique invalide.");
    }
    return 0;
}