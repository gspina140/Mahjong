#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define MaxLivelli 3
#define MaxRiga 8
#define MaxColonna 12
#define NumFigure 30


typedef struct Colonna
{
    int colonna[MaxColonna];
}Colonna;

typedef struct Riga
{
    Colonna riga[MaxRiga];
}Riga;


typedef struct Campo
{
    Riga livello[MaxLivelli];
    
}Campo;


typedef struct Elemento
{   
    int validita;
    int Livello;
    int Riga;
    int Colonna;
    int selezionato;

}Elemento;


void azzera(Campo *campo);
int riempi(Campo *campo);
int setUp(Campo *c);
void draw(Campo campo);
int getLivello(Campo campo, int r, int c);
int controllaSxDx(Colonna c, int colonna);
Elemento selezionare(Campo campo, int r, int c);
int ControllaValidita(Elemento e);
int RimuoviElementi(Campo *campo, Elemento e1, Elemento e2 );
int getMateriale(Campo campo, int c, int r, int l);