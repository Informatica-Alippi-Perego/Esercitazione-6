#include <stdio.h>
/*
 Programma per gestire calciatori di una squadra
 funzione che calcoli:
 - tot goal fatti
 - tot goal subiti
 - tot goal attaccanti
 - tot goal difensori
 - tot goal centrocampisti
 
 funzione che stampa la squadra
 funzione che trova il miglior giocatore per goal fatti
 Array con elementi che contengono:
 - numero di maglia
 - ruolo
 - goal fatti (subiti se portiere)
 */

#define MAX 20

typedef enum {
    portiere = 1,
    difensore,
    centrocampista,
    attaccante
} TipoRuolo;

typedef struct TipoGiocatore{
    int numero;
    int goal;
    TipoRuolo ruolo;
} TipoGiocatore;

int inserisciGiocatore(TipoGiocatore g[], int i);
void inserisciGiocatore2(TipoGiocatore g[], int *i);

void stampaSquadra(TipoGiocatore g[], int i);
void stampaSquadra2(TipoGiocatore g[], int i);

void contaGoal(TipoGiocatore g[], int *gFatti, int *gSubiti, int *gAtt, int *gCentr, int *gDif, int i);

TipoGiocatore trovaMigliorGiocatore(TipoGiocatore g[], int i);

int main(int argc, const char * argv[])
{
    TipoGiocatore squadra[MAX];
    TipoGiocatore migliorGiocatore;
    int totaleGaolFatti = 0;
    int totaleGoalSubiti = 0;
    int goalAttaccanti = 0;
    int goalDifensori = 0;
    int goalCentrocampisti = 0;
    int len = 0;
    
    int r;
    
    do{
        printf("1. Inserisci giocatore\n");
        printf("2. Conta goal\n");
        printf("3. Trova miglior giocatore\n");
        printf("4. Stampa\n");
        printf("5. ESCI\n");
        
        scanf("%d",&r);
        
        //Vado a fare tutte le operazioni
        switch (r) {
            case 1:
                len = inserisciGiocatore(squadra, len);
                //inserisciGiocatore2(squadra, &len);
                break;
            case 2:
                contaGoal(squadra, &totaleGaolFatti, &totaleGoalSubiti, &goalAttaccanti, &goalCentrocampisti, &goalDifensori, len);
                                break;
            case 3:
                migliorGiocatore = trovaMigliorGiocatore(squadra, len);
                break;
            case 4:
                stampaSquadra2(squadra, len);
                break;
            case 5:
                printf("Arrivederci!!!\n");
                break;
            default:
                printf("Operazione non valida\n");
                break;
        }
    }while(r!=5);
    return 0;
}

int inserisciGiocatore(TipoGiocatore g[], int i){
    if (i>=MAX){
        printf("Hai già inserito %d giocatori",MAX);
        return i;
    }
    else{
        printf("Inserisci numero maglia: ");
        scanf("%d",&g[i].numero);
        printf("Inserisci goal: ");
        scanf("%d",&g[i].goal);
        printf("Inserisci ruolo (1 portiere, 4 attacante): ");
        scanf("%d",&g[i].ruolo);
        /*
        char ruolo[20];
        scanf("%s",ruolo);
        if(strcmp(ruolo,"portiere")==0)
            g[i].ruolo = portiere;
         */
        return i+1;
    }
    
}
void inserisciGiocatore2(TipoGiocatore g[], int *i){
    if (*i>=MAX){
        printf("Hai già inserito %d giocatori",MAX);
    }
    else{
        printf("Inserisci numero maglia: ");
        scanf("%d",&g[*i].numero);
        printf("Inserisci goal: ");
        scanf("%d",&g[*i].goal);
        printf("Inserisci ruolo (1 portiere, 4 attacante): ");
        scanf("%d",&g[*i].ruolo);
        *i = *i+1;
    }
}

void stampaSquadra(TipoGiocatore g[], int i){
    for(; i>0; i--)
    {
        printf("Numero: %d\nRuolo: %d\nGoal: %d\n",g[i-1].numero,g[i-1].ruolo,g[i-1].goal);
    }
}

void stampaSquadra2(TipoGiocatore g[], int i){
    for(TipoGiocatore *p=g; p<g+i; p++)
    {
        printf("Numero: %d\nRuolo: %d\nGoal: %d\n",(*p).numero,p->ruolo,p->goal);
    }
}

void contaGoal(TipoGiocatore g[], int *gFatti, int *gSubiti, int *gAtt, int *gCentr, int *gDif, int i){
    
    int k;
    *gFatti = 0;
    *gSubiti = 0;
    *gAtt = 0;
    *gCentr = 0;
    *gDif = 0;
    
    for (k=0; k<i; k++){
        switch (g[k].ruolo) {
            case portiere:
                *gSubiti = *gSubiti + g[k].goal;
                break;
            case difensore:
                *gDif = *gDif + g[k].goal;
                break;
            case centrocampista:
                *gCentr = *gCentr + g[k].goal;
                break;
            case attaccante:
                *gAtt = *gAtt + g[k].goal;
                break;
        }
    }
    *gFatti = *gDif + *gCentr + *gAtt;
}

TipoGiocatore trovaMigliorGiocatore(TipoGiocatore g[], int i){
    TipoGiocatore max;
    int k;
    max = g[0];
    
    for (k=0; k<i; k++){
        if ((g[k].ruolo != portiere) && (g[k].goal>max.goal))
            max = g[k];
    }
    return max;
}
