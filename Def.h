// Définition des constantes pour la taille de la surface de jeu
#define WIDTH_MIN 8
#define WIDTH_MAX 10
#define HEIGHT_MIN 6
#define HEIGHT_MAX 8



typedef struct {
	char color[100];
	char nom[100];
  bool winner;
} gamer;

extern int Inform_value(int valmin, int valmax);

extern int init_gamers(gamer tab[3] );

extern void  init_Sizetable(int *a, int *b);

extern  void init_table(int table[HEIGHT_MAX][WIDTH_MAX],int a,int b);
 
extern void print_table(int table[HEIGHT_MAX][WIDTH_MAX],int a,int b, gamer tab[3]);


extern int init_Firstgamer(int nb_gamers);


extern void restore_game (int *nb_gamers, gamer tab[],int *num_gamer,int table[HEIGHT_MAX][WIDTH_MAX],int *width,int *height);


extern  int pawn_placement(int a, int b, int table[HEIGHT_MAX][WIDTH_MAX],int num_gamer,gamer tab[3]);

extern void gravity_table(int table[HEIGHT_MAX][WIDTH_MAX], int a, int b, gamer tab[3],int num_gamer);
     
     
extern int gamer_winner(int table[HEIGHT_MAX][WIDTH_MAX],int a, int b,gamer tab[3]);


extern bool exist_empty_box(int table[HEIGHT_MAX][WIDTH_MAX],int a);


extern void Nextgamer(int *gamer,int nb_gamers );
    
    
extern void save_game(int nb_gamers, gamer tab[],int numgamer,int table[HEIGHT_MAX][WIDTH_MAX],int width,int height);

extern void print_table(int table[HEIGHT_MAX][WIDTH_MAX],int a,int b, gamer tab[3]);

extern int print_Size_area_rotaded(gamer tab[3],int num_gamer);

extern void rotated_Pawn(int area_rotated, int a, int b,int *Ligne_pivot, int *colonne_pivot, int *sens);


extern void pawn_gravity(int table[HEIGHT_MAX][WIDTH_MAX],int a, int b,int pion,int num_gamer,gamer tab[3]);
