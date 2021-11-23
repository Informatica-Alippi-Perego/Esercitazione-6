#include <stdio.h>
#include <math.h>

#define MAX 10

struct complesso {
    float re;
    float im;
};

void inserisci(struct complesso *c);
float modulo(struct complesso *c);
int compara(struct complesso *c1, struct complesso *c2);
void ordina(struct complesso *c_in, int n, struct complesso *c_out);

int main(int argc, const char * argv[])
{
    struct complesso sorgete[MAX], dest[MAX];
    int len;
    int i;
    
    printf("Quanti elementi vuoi inserire? ");
    scanf("%d",&len);
    for (i=0; i<len; i++)
        inserisci(&sorgete[i]);
    ordina(sorgete, len, dest);
    for (i=0; i<len; i++)
        printf("%.2f+i%.2f modulo: %.2f\n",dest[i].re,dest[i].im, modulo(&dest[i]));
    return 1;
}

void inserisci(struct complesso *c){
    printf("Inserisci parte reale: ");
    scanf("%f",&(c->re));
    printf("Inserisci parte immaginaria: ");
    scanf("%f",&((*c).im));
}

float modulo(struct complesso *c){
    return sqrt((c->re * c->re) + (c->im * c->im));
}

int compara(struct complesso *c1, struct complesso *c2){
    if (modulo(c1) > modulo(c2))
        return 1;
    else if (modulo(c1)<modulo(c2))
        return -1;
    else
        return 0;
}

void ordina(struct complesso *c_in, int n, struct complesso *c_out){
    int i, scambio;
    struct complesso temp;
    
    //copio l'array
    for (i=0; i<n; i++){
        c_out[i] = c_in[i];
        //*(c_out+i) = *(c_in+i);
    }
    
    //ordino l'array di uscita
    do{
        scambio = 0;
        for (i=0; i<n-1; i++){
            //if (compara(&c_out[i],&c_out[i+1])>0){
            if (compara(c_out+i,c_out+i+1)>0){
                scambio = 1;
                temp = c_out[i];
                c_out[i] = c_out[i+1];
                c_out[i+1] = temp;
            }
        }
    }while(scambio);
}
