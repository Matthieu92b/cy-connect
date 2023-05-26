#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<ctype.h>
#include "Def.h"

// fonction qui restaure le jeu qui etait dans le fichier ou nous avons sauvegarder la partie avant 
void restore_game (int *nb_gamers, gamer tab[3],int *num_gamer,int table[HEIGHT_MAX][WIDTH_MAX],int *width,int *height){
  char chaine[100];
  FILE* fichier=NULL;
  fichier= fopen("save.txt", "r");
  fscanf(fichier,"%d",nb_gamers);
  for (int i = 0; i<*nb_gamers; i++){
    fscanf(fichier,"%s",chaine);
    for (int j=0;j<strlen(chaine)+1;j++){
      tab[i].nom[j]=chaine[j];
    }
    fscanf(fichier,"%s",chaine);
    for (int j=0;j<strlen(chaine)+1;j++){
      tab[i].color[j]=chaine[j];
    }
    tab[i].winner = false;
  }
  fscanf(fichier,"%d",num_gamer);
  fscanf(fichier,"%d",width);
  fscanf(fichier,"%d",height);
  for (int i = 0; i<*height; i++){
    for (int j = 0; j<*width; j++){
      fscanf(fichier,"%d",&table[i][j]);
    }
  }
  fclose(fichier);
}


// foonction qui permet de sauvegarder la partie en ouvrant un fichier qui va enregistrer la partie commencer 
void save_game (int nb_gamers, gamer tab[],int num_gamer,int table[HEIGHT_MAX][WIDTH_MAX],int width,int height){


  FILE* fichier=NULL;
  fichier= fopen("save.txt", "wt+");

  fprintf(fichier,"%d\n",nb_gamers);
  for (int i = 0; i<nb_gamers; i++)
    {
       fprintf(fichier,"%s\n",tab[i].nom);  
       fprintf(fichier,"%s\n",tab[i].color);
    }
    fprintf(fichier,"%d\n",num_gamer);
  
    fprintf(fichier,"%d\n%d\n",width, height);
   for (int i = 0; i<height; i++){
      for (int j = 0; j<width; j++){
       fprintf(fichier,"%d\n",table[i][j]);
       }
    }
    fclose(fichier);
}




