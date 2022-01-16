/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: 
 * Tekijä: Eemil Aspholm
 * Opiskelijanumero: 0567753
 * Päivämäärä: 26.2.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: www.programiz.com/c-programming,  
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "paaohjelma.h"

int main(){
    //muuttujien alustus
    LIST *pHead = NULL;
    TIEDOT Lista[size];
    int virhe = 0;
    alustaLista(Lista);
    int valinta;
    do
    {
        printf("1) Lue tiedosto\n");
        printf("2) Analysoi tiedot\n");
        printf("3) Tulosta tulokset\n");
        printf("0) Lopeta\n");
        printf("Valintasi: ");
        scanf("%d", &valinta);
        switch(valinta){
            case 1:
            if (pHead == NULL){
            virhe++;
            pHead = lueTiedosto(pHead);
            }
            else{
                pHead = vapautaMuistiTaulukko(pHead);
                pHead = lueTiedosto(pHead);
                virhe ++;
            }
            break;
            case 2:
            if (pHead == NULL){
                printf("Ei analysoitavaa, lue ensin palautustiedosto.\n\n");
                }
            else{
                virhe++;
                alustaLista(Lista);
                analysoiTiedot(pHead, Lista);
            }
            break;
            case 3:
            if(virhe < 2){
                printf("Ei tulostettavaa, analysoi ensin palautustiedosto.\n\n");
            }
            else{
                tulostaTulokset(Lista);
                }
            break;
            case 0:
            printf("Kiitos ohjelman käytöstä.\n\n");
            pHead = vapautaMuistiTaulukko(pHead);
            break;
            default:
            printf("Tuntematon valinta, yritä uudestaan.\n\n");
        }
    } while (valinta != 0);
    return 0;
}