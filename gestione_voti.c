#include <stdio.h>

typedef struct voto{
    char nome[20];
    char cognome[20];
    int matricola;
    int valutazione;
} TipoVoto;

int inserisciVoto(TipoVoto voti[], int i);
int cercaStudente(TipoVoto voti[], int i, int matricola);
void stampaIstogramma(TipoVoto voti[], int i);
int riempiBocciati(TipoVoto voti[], int i, TipoVoto bocc[]);
void stampa(TipoVoto voti[], int i);

int main(int argc, const char * argv[])
{
    TipoVoto voti[200];
    TipoVoto bocciati[200];
    int numVoti = 0;
    int numBocciati = 0;
    int matricola;
    
    int r;
    do{
        printf("1. Inserisci voto\n");
        printf("2. Cerca studente\n");
        printf("3. Istogramma\n");
        printf("4. Array bocciati\n");
        printf("5. ESCI\n");
        scanf("%d",&r);
        
        switch (r) {
            case 1:
                numVoti = inserisciVoto(voti, numVoti);
                stampa(voti, numVoti);
                break;
            case 2:
                printf("Inserisci matricola: ");
                scanf("%d",&matricola);
                printf("%d", cercaStudente(voti, numVoti, matricola));
                break;
            case 3:
                stampaIstogramma(voti, numVoti);
                break;
            case 4:
                numBocciati = riempiBocciati(voti, numVoti, bocciati);
                stampa(bocciati, numBocciati);
                break;
        }
    }while(r!=5);
    
    
    return 0;
}

int inserisciVoto(TipoVoto voti[], int i){
    printf("Inserisci nome: ");
    scanf("%s",voti[i].nome);
    printf("Inserisci cognome: ");
    scanf("%s",&voti[i].cognome[0]);
    printf("Inserisci matricola: ");
    scanf("%d",&voti[i].matricola);
    printf("Inserisci voto: ");
    scanf("%d",&(voti+i)->valutazione);
    return i+1;
}

int cercaStudente(TipoVoto voti[], int i, int matricola){
    int k;
    for (k=0; k<i; k++){
       // if ((strcmp(voti[k].nome,nome)==0) && (strcmp(voti[k].cognome,cognome)==0))
        if (voti[k].matricola == matricola)
            return k;
    }
    return -1;
}
void stampaIstogramma(TipoVoto voti[], int i){
    int k,j,max = 0;
    int isto[4] = {0,0,0,0};
    for (k=0; k<i; k++){
        if (voti[k].valutazione<=6)
            isto[0]++;
        else if (voti[k].valutazione<=18)
            isto[1]++;
        else if (voti[k].valutazione<=25)
            isto[2]++;
        else
            isto[3]++;
    }
    
    for (k=0; k<4; k++){
        if (isto[k]>max)
            max = isto[k];
    }
    
    for (k=max; k>0; k--)
    {
        for (j=0; j<4; j++)
        {
            if(isto[j]>=k)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int riempiBocciati(TipoVoto voti[], int i, TipoVoto bocc[]){
    int k;
    int numBocc = 0;
    
    for (k=0; k<i; k++){
        if (voti[k].valutazione<18){
            bocc[numBocc] = voti[k];
            numBocc++;
        }
    }
    return numBocc;
}

void stampa(TipoVoto voti[], int i){
    int k;
    for (k=0; k<i; k++){
        printf("%d %s %s %d",voti[i].matricola,(voti+i)->cognome,(voti+i)->nome,voti[i].valutazione);
    }
}
