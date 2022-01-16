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
#include "ali1.h"

void alustaLista(TIEDOT *ptr){ //Alustetaan lista.
    for (int i = 1; i<size; i++){
        strcpy(ptr[i].name, "Tyhjä");
        ptr[i].value = 0;
    }
    return;
}
LIST *vapautaMuistiTaulukko(LIST *phead){ //Vapautetaan varattu muisti taulukosta.
    LIST *ptr = phead;
    while(ptr != NULL) {
        phead = ptr->next;
        free(ptr->date); //Lisäksi varattu muisti *date pointterille vapautetaan
        free(ptr);
        ptr = phead;
    }
    return phead;
}
void kysyTiedosto(char *ptr){ //Tiedostonimi osoitettuun char pointteriin
    printf("Anna tiedoston nimi: ");
    scanf("%s", ptr);
    return;
}
void analysoiTiedot(LIST *phead, TIEDOT *Lista){
    //muuttujien
    LIST *ptr = NULL;
    double kskm = 0;
	int plkm = 0, thtlkm = 0;
    int i = 0;
    //tehtävänimet listaan
    for(int luku = 1; luku < size; luku++){
        ptr = phead;
        i++;
    while(ptr != NULL){
        if(ptr->eid == i){ //Lisätään alkioon aina +1, mikäli id ja listan alkion järjestysluku täsmää
            Lista[i].value += 1;
            plkm += 1;
            if ((strcmp(Lista[i].name, ptr->ename) != 0)){ //Testaus onko alkion nimen tilalle vaihdettu oikeanimi
                strcpy(Lista[i].name, ptr->ename);//Tehtävänimi paikalleen
                thtlkm += 1;
            }
            ptr = ptr->next;
        }
        else{
            ptr = ptr->next;
        }
    }}
    kskm = plkm / thtlkm;
    printf("Palautuksia oli yhteensä %d, %d eri tehtävässä, keskimäärin %.0lf per tehtävä.\n\n", plkm, thtlkm, kskm);
    return;
}
