# cy-connect
projet d'informatique préing 1 puissance 5
#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<ctype.h>




// Définition des constantes pour la taille de la surface de jeu
#define WIDTH_MIN 8
#define WIDTH_MAX 10
#define HEIGHT_MIN 6
#define HEIGHT_MAX 8
typedef struct {
	char color[100];
	char nom[100];
  bool winner;
}gamer;


// renseignement d'une valeur entière par l'opérateur comprise entre valmin et valmax
int Rens_Valeur(int valmin, int valmax){
  char str_nbre[50];
  int nbre;
  
  scanf("%s",&str_nbre);
  nbre = atoi(str_nbre);
       
    while(nbre< valmin || nbre> valmax){
      printf("Erreur,la valeur doit être comprise entre %d et %d : ",valmin,valmax);
      scanf("%s",&str_nbre);
      nbre = atoi(str_nbre);
    }
    return nbre;
  
}

 void  init_Sizetable(int *a, int *b){
    printf("Entrez la largeur de la surface de jeu (entre %d et %d): ", WIDTH_MIN, WIDTH_MAX);
    *a = Rens_Valeur(WIDTH_MIN, WIDTH_MAX);
    printf("Entrez la hauteur de la surface de jeu (entre %d et %d): ", HEIGHT_MIN, HEIGHT_MAX);
    *b= Rens_Valeur(HEIGHT_MIN, HEIGHT_MAX);
 }

  
    
  
  //initialisation des joueurs 
  int init_gamers(gamer tab[3] ){
    char a[50];
    char surname[100];
    char color[100];
    int nb_gamers;

  
    printf("combien il y a t'il de joueurs (entre 2 et 3 joueurs) : ");
    nb_gamers = Rens_Valeur(2, 3);
   
      for(int i=0;i<nb_gamers;i++){
        printf("joueur %d donnez votre prénom : ", i+1);
        scanf("%s", surname);
        if (i == 1) {
            // On verifie que le nom choisi n'est pas celui du premier joueur
          while (strcmp(surname,tab[0].nom)==0){
                    printf("joueur %d donnez un prénom différent du premier joueur 1: ", i+1);
                    scanf("%s", surname);
            }
          }
          if (i == 2) {
            // On verifie que le nom choisi n'est pas celui des deux premiers joueurs
             while (strcmp(surname,tab[0].nom)==0 || strcmp(surname,tab[1].nom)==0){
                printf ("joueur %d donnez un prénom différent des deux premiers joueurs : ", i+1);
                scanf("%s", surname);
             }
            }

       
       for(int j=0;j<strlen(surname)+1;j++){
         tab[i].nom[j]=surname[j];
         
       }
       
       color[0] = 0;
        
        while(strcmp(color,"JAUNE")!=0 && strcmp(color,"BLEU")!=0 && strcmp(color,"ROUGE")!=0 ){
         printf("%s choisissez votre couleur entre rouge jaune et bleu différente de celle des autres joueurs : ",surname);
         scanf("%s",color);


           for(int j=0;j<strlen(color);j++){
            color[j]=toupper(color[j]);
           }
  

          if (i == 1) {
            // On verifie que la couleur choisie n'est pas celle du premier joueur
            if (strcmp(color,tab[0].color)==0){
              color[0] = 0;
            }
          }
          if (i == 2) {
            // On verifie que la couleur choisie n'est pas celle des deux premiers joueurs
            if (strcmp(color,tab[0].color)==0 || strcmp(color,tab[1].color)==0){
              color[0] = 0;
            }

          }
          
         }

        
         for(int j=0;j<strlen(color)+1;j++){
          tab[i].color[j]=color[j];
         }

        tab[i].winner = false;


        
      }
           
        
       return nb_gamers ;
      }
    
    
     
    
  

  // initialisation du tableau
  void init_table(int table[HEIGHT_MAX][WIDTH_MAX],int a,int b){
    for(int i=0; i<b;i++){
      for(int j=0;j<a;j++){
        table[i][j]=0;
      }
    }
    table[0][0]=1;
    table[0][a-1]=1;
   table[b-1][0]=1;
   table[b-1][a-1]=1;
  }


int ColorOfGamer(int num_gamer,gamer tab[3]){
  int color;

  if (strcmp(tab[num_gamer].color,"JAUNE")==0)
  {
    color = 33;
  }
  else if (strcmp(tab[num_gamer].color,"BLEU")==0){
             color = 34;
  }
  else if (strcmp(tab[num_gamer].color,"ROUGE")==0){
             color = 31;
  }
  
  return color;
  
}

 void print_table(int table[HEIGHT_MAX][WIDTH_MAX],int a,int b, gamer tab[3]){
   int couleur;
   system("clear");
    for(int i=0; i<b;i++){
     for(int j=0;j<a;j++){
       printf("+---");
        }
        printf("+\n");
       for (int j = 0; j < a; j++) {
            printf("|  ");
       switch (table[i][j]) {
         case 0 :
                printf("\033[40;37m");
                printf(" ");
                break;
         case 1 :
                printf("\033[40;37m");
                printf("X");
                break;
         default :
                couleur = ColorOfGamer(table[i][j]-2,tab);
                printf("\033[40;%dm",couleur);
                printf("X");
                break;
       }
     }
      printf("|\n");
    }
    
     for (int j = 0; j < a; j++) {
        printf("+---");
    }
    printf("+\n");

    for (int j = 0; j < a; j++) {
        printf("  %d ", j+1);
    }
    printf("\n");
         
     printf("\n");
    }
   

 
 
  //detemination du 1er joueur 
  int init_Firstgamer(int nb_gamers){
    int first_gamer;
    printf("l'ordinateur va choisir au hasard le premier joueur qui joue\n");
    srand(time(NULL));
    if (nb_gamers==2){
      first_gamer=rand()%(1)+1;
    }
    if (nb_gamers==3){
      first_gamer=rand()%(2)+1;
    }
    return first_gamer;
  }
 
  //gravité d'un pion
     void  pawn_gravity(int table[HEIGHT_MAX][WIDTH_MAX],int a, int b,int pion,int num_gamer,gamer tab[3]){
   
      int p=-1;
       while(p<b-1 && table[p+1][pion]==0){
         p++; 
         
        if (p!=-1){
          table[p][pion]=num_gamer+2;
        }
        print_table(table, a,b,tab);
        usleep(100000);
        if (p!=-1){
          table[p][pion]=0;
        }
        }
       if (p!=-1){
          table[p][pion]=num_gamer+2;
       }
        print_table(table, a,b,tab);
        usleep(100000);
       
     
     }



   //detemination du placement d'un pion par le joueur 
    int pawn_placement(int a, int b, int table[HEIGHT_MAX][WIDTH_MAX],int num_gamer,gamer tab[3]){
      int pion;
      char str_pion[50];


      
      printf("%s choisis la colonne ou tu veux mettre ton pion : ",tab[num_gamer].nom);
      pion = Rens_Valeur(0, a);

      if (pion > 0){
         //gravité d'un pion
         pawn_gravity(table, a, b,pion-1,num_gamer,tab );
      }
      return pion-1;
    }



    // determination et affichage de la taille a pivoter
    int print_Size_area_rotaded(gamer tab[3],int num_gamer){
      int width_pivoter;
      printf("l'ordinateur va choisir la largeur de la zone a pivoter\n");
      srand(time(NULL));
      width_pivoter=rand()%(5-3+1)+3;
      while (width_pivoter==4){
         width_pivoter=rand()%(5-3+1)+3;
      }
      printf("l'ordinateur a choisis. %s votre largeur de zone a pivoter est de %d cases\n", tab[num_gamer].nom,width_pivoter);
      return width_pivoter;
    }



    //determination de la case pivot et sens de rotation 
    void rotated_Pawn(int area_rotated, int a, int b,int *Ligne_pivot, int *colonne_pivot, int *sens){

    int xmin= area_rotated/2+1;
    int xmax=b-(area_rotated/2);
    int ymax=a-(area_rotated/2);
    int ymin=area_rotated/2+1;
    printf("choisissez la ligne de la case pivot, comprise entre %d et %d ",xmin,xmax);
    *Ligne_pivot=Rens_Valeur(xmin,xmax);
    printf("choisissez la colonne de la case pivot, comprise entre %d et %d ",ymin,ymax);
     *colonne_pivot=Rens_Valeur(ymin,ymax);
     printf("dans quel sens veux tu pivoter le tableau,tape 1 pour droite et 2 pour gauche");
    *sens=Rens_Valeur(1,2);
    }


    // gravité du tableau
    void gravity_table(int table[HEIGHT_MAX][WIDTH_MAX], int a, int b, int area_rotated,int Ligne_pivot, int colonne_pivot,int sens, gamer tab[3]){
          int num_col,num_ligne;
          int num_col_rotated,num_ligne_rotated;
      int imaginary_table[HEIGHT_MAX][WIDTH_MAX];
      int delta = area_rotated/2;


     // printf ("%d %d %d %d\n",area_rotated, delta,Ligne_pivot,colonne_pivot);
     // printf ("%d %d %d %d\n",Ligne_pivot-delta,Ligne_pivot+delta,colonne_pivot -delta,colonne_pivot+delta);
      
       if (sens==1){
      num_ligne_rotated = 1;
      for(num_col=colonne_pivot-delta;num_col<colonne_pivot+delta+1;num_col++){ 
          num_col_rotated = area_rotated;
        for(num_ligne=Ligne_pivot-delta;num_ligne<Ligne_pivot+delta+1;num_ligne++){
          imaginary_table[num_ligne_rotated-1][num_col_rotated-1]=table[num_ligne-1][num_col-1];
          //printf("%d %d --> %d %d\n",num_ligne,num_col,num_ligne_rotated,num_col_rotated);
            num_col_rotated--;
          }
          num_ligne_rotated++;
        }
      }
      else if (sens == 2){
        }
      printf("table \n");
        // Affichage de la zone à tourner dans la table    
       for(num_ligne=Ligne_pivot-delta;num_ligne<Ligne_pivot+delta+1;num_ligne++){
        for(num_col=colonne_pivot-delta;num_col<colonne_pivot+delta+1;num_col++){
          printf("%d" ,table[num_ligne-1][num_col-1]);
         }
         printf("\n");
        }
      // Affichage de la zone tournée dans la table imaginaire
      printf("table imaginaire \n");
       for(num_ligne=0;num_ligne<area_rotated;num_ligne++){
        for(num_col=0;num_col<area_rotated;num_col++){
          printf("%d" ,imaginary_table[num_ligne][num_col]);
         }
         printf("\n");
        }
      // Réécriture de la zone tournée dns la tanle
        num_col_rotated = 1;
      for(num_col=colonne_pivot-delta;num_col<colonne_pivot+delta+1;num_col++){ 
          num_ligne_rotated = 1;
        for(num_ligne=Ligne_pivot-delta;num_ligne<Ligne_pivot+delta+1;num_ligne++){
          table[num_ligne-1][num_col-1]=imaginary_table[num_ligne_rotated-1][num_col_rotated-1];
          //printf("%d %d --> %d %d\n",num_ligne,num_col,num_ligne_rotated,num_col_rotated);
            num_ligne_rotated++;
          }
          num_col_rotated++;
        }

         printf("table \n");
        // Affichage de la zone à tounée dans la table    
       for(num_ligne=Ligne_pivot-delta;num_ligne<Ligne_pivot+delta+1;num_ligne++){
        for(num_col=colonne_pivot-delta;num_col<colonne_pivot+delta+1;num_col++){
          printf("%d" ,table[num_ligne-1][num_col-1]);
         }
         printf("\n");
        }
      char toto[50];
     // printf ("continuer ?");
     // scanf("%s",toto);
      
        print_table(table,a,b,tab);
      
    }



    //determination d'un vainqueur 
    int gamer_winner(int table[HEIGHT_MAX][WIDTH_MAX],int a, int b,gamer tab[3]){
    
      int nb_winner;
      int winner;
      
      int imaginary_table[5][5];
      for(int i=0;i<b-4;i++){
        for(int j=0;j<a-4;j++){
          for(int k=0;k<5;k++){
            for(int l=0;l<5;l++){
              imaginary_table[k][l]=table[k+i][l+j];
            }
          }

          for(int k=0;k<5;k++){
            if(imaginary_table[k][0]==imaginary_table[k][1] &&
              imaginary_table[k][0]==imaginary_table[k][2] &&
              imaginary_table[k][0]==imaginary_table[k][3] &&
              imaginary_table[k][0]==imaginary_table[k][4] && 
              imaginary_table[k][0] < 5 && imaginary_table[k][0]>1){
              winner= imaginary_table[k][0] - 2;
              tab[winner].winner = true;
              }
          }
            for(int l=0;l<5;l++){
              if(imaginary_table[0][l]==imaginary_table[1][l] &&
              imaginary_table[0][l]==imaginary_table[2][l] &&
              imaginary_table[0][l]==imaginary_table[3][l] &&
              imaginary_table[0][l]==imaginary_table[4][l]&& 
              imaginary_table[0][l] < 5 && imaginary_table[0][l]>1){
               winner= imaginary_table[0][l] - 2;
              tab[winner].winner = true;
              }
            }
               if(imaginary_table[0][0]==imaginary_table[1][1] &&
              imaginary_table[0][0]==imaginary_table[2][2] &&
              imaginary_table[0][0]==imaginary_table[3][3] &&
              imaginary_table[0][0]==imaginary_table[4][4]&& 
              imaginary_table[0][0] < 5 && imaginary_table[0][0]>1){
                winner= imaginary_table[0][0] - 2;
                tab[winner].winner = true;
               }
               if(imaginary_table[0][4]==imaginary_table[1][3] &&
              imaginary_table[0][4]==imaginary_table[2][2] &&
              imaginary_table[0][4]==imaginary_table[3][1] &&
              imaginary_table[0][4]==imaginary_table[4][0]&& 
              imaginary_table[0][4] < 5 && imaginary_table[0][4]>1){
               winner= imaginary_table[0][4] - 2;
              tab[winner].winner = true;
               }
          
        }
      }
          nb_winner = 0;
          for(int t=0;t<3;t++){
            if (tab[t].winner == true) {
              nb_winner++;
            }
          }
          if (nb_winner == 1){
            for(int t=0;t<3;t++){
                if (tab[t].winner == true) {
                   printf("le gagnant est : %s\n", tab[t].nom);
               }
           }
          }
          else if(nb_winner > 1){
              printf("les gagnants sont : " );
              for(int t=0;t<3;t++){
                if (tab[t].winner == true) {
                   printf("%s", tab[t].nom);
               }
                printf("\n" );
              }  
          }

      
       if (nb_winner >0)
         return true;
      else return false;
    }


    bool exist_empty_box(){
      return true;
    }



    //detemination du joueur suivant 
    void Nextgamer(int *gamer,int nb_gamers ){
      if (nb_gamers==2){
        if(*gamer==0){
          *gamer=1;
        }
        else{
          *gamer=0;
        }
      }
        if (nb_gamers==3){
        if(*gamer==0){
          *gamer=1;
        }
        else if(*gamer==1){
            *gamer=2;
        }
        else{
          *gamer=0;
        }
        }
  
    }
  
 
int main() {
  bool winner,tab_box;
  int width,height;
  int table[HEIGHT_MAX][WIDTH_MAX];
  int pion;
   gamer tab[3];
  int nb_gamers;
  int gamer;
  char a[5];
  int area_rotated;
  int Ligne_pivot;
  int colonne_pivot;
  int sens;



  //initialisation des joueurs 
  nb_gamers=init_gamers(tab);
  //determination de la dimension du tableau
  init_Sizetable(&width , &height);
  // initialisation du tableau
  init_table(table, width, height);
  print_table(table, width, height,tab);
  //detemination du 1er joueur 
  gamer=init_Firstgamer(nb_gamers);
  winner=false;
  tab_box= exist_empty_box();
  pion = 0;
  printf("Si tu veux sauvegarder la partie une fois celle-ci commencée rentre 0 comme colonne ou tu veux placer ton pion \n");
  
  while(winner == false && tab_box == true && pion!= -1) {
    //detemination du placement d'un pion par le joueur 
    pion = pawn_placement(width, height,table,gamer,tab);
    
    if (pion != -1){
   
       // determination  et affichage de la taille a pivoter par l'orinateur
       area_rotated=print_Size_area_rotaded(tab,gamer);
      
       // determination de la case pivot et sens de rotation par le joueur
        rotated_Pawn(area_rotated,width,height,&Ligne_pivot,&colonne_pivot,&sens);
      
       // gravité du tableau
       gravity_table(table,width,height, area_rotated,Ligne_pivot,colonne_pivot,sens,tab);
      
       //determination d'un vainqueur 
       winner = gamer_winner(table,width,height,tab);
       // tab_box= exist_empty_box();
       //detemination du joueur suivant 
       Nextgamer(&gamer,nb_gamers);
    }
    else {
      // Sauvegarde de la partie
      printf("Sauvegarde de la partie non codée pour le moment \n");
    }
  }
  
  
}
      
