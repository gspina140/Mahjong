#include "Mahjong.h"

void azzera(Campo *campo)
{
    for(int l=0 ; l < MaxLivelli ; l++)    
        for(int r=0; r < MaxRiga ; r++)
            for(int c=0; c < MaxColonna; c++)
                campo->livello[l].riga[r].colonna[c] = 0;
}

int riempi(Campo *campo)
{   
    float time =clock();
    srand(time);

    //quanti caselle disponibili ho
    int Nelem = MaxColonna*MaxRiga*MaxLivelli;
    
    // Scelgo quante carte avere
    int Nfigure = Nelem * 20 /100;

    // Il numero di carte deve essere pari perchè il gioco sia risolvibile
    if(Nfigure % 2 != 0)
        Nfigure++;

    for(int i = 0 ; i < Nfigure; i=i+2 )
    {   
        //Che figura mettere ?
        int figura = rand()%NumFigure;
        //prima cella
        int l,r,c;
        do
        {
            l = MaxLivelli-1;
            r = rand()%MaxRiga;
            c = rand()%MaxColonna;  
            for(int j=l; j>=0; j--){
                if(campo->livello[j].riga[r].colonna[c] == 0){
                    l=j;
                    break;
                }
            }
        } while( campo->livello[l].riga[r].colonna[c] != 0 );
        
        campo->livello[l].riga[r].colonna[c] = figura;

        //seconda cella
        do
        {
            l = MaxLivelli-1;
            r = rand()%MaxRiga;
            c = rand()%MaxColonna;
            for(int j=l; j>=0; j--){
                if(campo->livello[j].riga[r].colonna[c] == 0){
                    l=j;
                    break;
                }
            }
        } while( campo->livello[l].riga[r].colonna[c] != 0 );   
        campo->livello[l].riga[r].colonna[c] = figura;
    }        
    return Nfigure;
}


int setUp(Campo *c)
{
    int n;
    azzera(c);
    n = riempi(c);
    return n;
}

int getLivello(Campo campo, int r, int c)
{
    // 1: trovare il livello
    for(int l = 0 ; l < MaxLivelli; l++)
    {
        if(campo.livello[l].riga[r].colonna[c] != 0)
            return l;
    }
    return -10;
}

int controllaSxDx(Colonna c, int colonna)
{   
    if(colonna == 0 || colonna == MaxColonna-1)
    return 1;
    //prima controllo Sx                //controllo Dx
    if( (c.colonna[colonna-1] == 0) || (c.colonna[colonna+1] == 0) ) 
        return 1;
    else
        return -10;
}

Elemento selezionare(Campo campo, int r, int c)
{   
    Elemento e;
    
    e.Riga=r;
    e.Colonna=c;
    e.Livello=getLivello(campo, r, c );

    
    if(e.Livello >= 0 && e.Livello < MaxLivelli)
        e.validita = controllaSxDx(campo.livello[e.Livello].riga[e.Riga], c);
    else
        e.validita = -10;
    
    e.selezionato = 10;
    
    return e;
}

int ControllaValidita(Elemento e)
{   
    printf("L'elemento selezionato Livello : %d  Riga : %d  Colonna : %d ",e.Livello,e.Riga,e.Colonna);
    if(e.validita > 0)
    {   
        printf("--> Valido \n");
        return 1;
    }
    else
    {
        printf("--> NON Valido\n");
        return -10;
    }
}

int RimuoviElementi(Campo *campo, Elemento e1, Elemento e2 )
{
    //controllo che siano validi
    if( e1.validita > 0 && e2.validita > 0)
    {   //controllo che la posizione sia diversa
        if( (e1.Livello != e2.Livello) || ( e1.Riga != e2.Riga ) || ( e1.Colonna != e2.Colonna ) )
        {
            //controllo se la carta è uguale
            int v1=campo->livello[e1.Livello].riga[e1.Riga].colonna[e1.Colonna];
            int v2=campo->livello[e2.Livello].riga[e2.Riga].colonna[e2.Colonna];

            if (v1 == v2)
            {
                campo->livello[e1.Livello].riga[e1.Riga].colonna[e1.Colonna] = 0;
                campo->livello[e2.Livello].riga[e2.Riga].colonna[e2.Colonna] = 0;
                printf("\nGli elementi sono stati rimossi\n");
                return 1;
            }
            else
                printf("\nImpossibile rimuovere elementi perchè sono diversi\n");
        }
        else
            printf("\nImpossibile rimuovere elementi perchè hai selezionato 2vt lo stesso elemento\n");
    }
    else
        printf("\nImpossibile rimuovere elementi non sono validi\n");

    return 0;
}

int getMateriale(Campo campo, int c, int r, int l)
{
    //prima controllo se è libero a sx e a dx
    if( controllaSxDx(campo.livello[l].riga[r], c) > 0 )
    {
        //controllo livelli sopra
        for(int i = 0 ; i < l ; i++)
        {
            int v = campo.livello[i].riga[r].colonna[c];
            if(v == 0 )
                continue;
            else
                return -10;
        }
        return 10;
    }
    else
    return -10;  
}