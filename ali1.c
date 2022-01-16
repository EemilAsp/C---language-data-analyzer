/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Eemil Aspholm
 * Opiskelijanumero: 0567753
 * Päivämäärä: 26.2.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: www.programiz.com/c-programming,  
 */
/*******************************************************************/
#include "ali1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>

void tulostaTulokset(TIEDOT *ptr){
    // muuttujien alustus
    FILE *fp = NULL;
    char file[30];
    char *tdst = file;
    char choice;
    char header[] = "Tehtävä;Lkm"; //Tiedostolle / tulostukselle otsikkotiedot
    printf("Tulosta tiedostoon (k/e): ");
    scanf(" %c", &choice);
    if(choice == 'k'){
        kysyTiedosto(tdst);
        if((fp = fopen(tdst, "w")) == NULL){
            perror("Tiedostoon kirjoittaminen epäonnistui.\n");
            exit(0);
        }
        fprintf(fp, "%s\n", header);
        for(int i = 1; i<size; i++){
            fprintf(fp, "%s;%d\n", ptr[i].name, ptr[i].value);
        }
        fclose(fp);
    }
    else if(choice == 'e'){
        printf("%s\n", header);
        for(int i = 1; i<size; i++){
            printf("%s;%d\n", ptr[i].name, ptr[i].value);
        }
    }
    else{
        printf("Et antanut kirjainta 'k' tai 'e'.\n");
        exit(0);
    }
	printf("\n");
    return;
}
LIST *lisaaTaulukkoon(LIST *phead, char *pRow){
    //varataan muisti dynaamisesti aliohjelmassa selkeyttää rakennetta.
    LIST *pNew = NULL, *ptr = NULL;
    int year, month, day, hour, minute;
    char *p1, *p2, *p3, *p4;
    if ((pNew = (LIST*)malloc(sizeof(LIST))) == NULL){
        perror("Muistin varaus epäonnistui.\n");
        exit(0);
    }
    if ((pNew->date = (struct tm*)malloc(sizeof(struct tm))) == NULL){
        perror("Muistin varaus epäonnistui.\n");
        exit(0);
    } //varataan myös date pointterille muisti

    //tietojen irroitus 8/09/20, 10:46;L01T1;1;6607164
    p1 = strtok(pRow, ";"); // aikatiedot 1.sarake
    p2 = strtok(NULL, ";"); // tehtävänimi 2.sarake
    p3 = strtok(NULL, ";"); // tehtäväid 3.sarake
    p4 = strtok(NULL, ";"); // palauttajanid 4.sarake
    sscanf(p1, "%d/%d/%d, %d:%d", &day, &month, &year, &hour, &minute); // time_t:tä varten string integeriksi
    pNew->date->tm_mday = day;
    pNew->date->tm_mon = month-1;
    pNew->date->tm_year = year+100;
    pNew->date->tm_hour = hour;
    pNew->date->tm_min = minute;
    strcpy(pNew->ename, p2);
    pNew->eid = atoi(p3);
    pNew->userid = atoi(p4);
    pNew->next = NULL;
    if (phead == NULL){
        phead = pNew;
        } else {
            ptr = phead;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = pNew;
    }
    return phead;
}

LIST *lueTiedosto(LIST *phead){
    //Alustetaan muuttujat
    int lkm = 0;
    char aloituspvm[20], lopetuspvm[20], file[30];
    LIST *ptr = NULL;
    FILE *fptr = NULL;
    char *tdst = file;
    char rivi[LEN];
    kysyTiedosto(tdst);
    if ((fptr = fopen(tdst, "r")) == NULL){
        printf("Tiedoston avaus epäonnistui.\n");
        exit(0);
    }
    fgets(rivi, sizeof(rivi), fptr); //luetaan otsikkorivi pois
    while(fgets(rivi, sizeof(rivi), fptr) != NULL) {
        lkm++;
        phead = lisaaTaulukkoon(phead, rivi);
    } 
    fclose(fptr);
    ptr = phead;
    while(ptr->next != NULL) //mennään taulukon viimeiseen solmuun jotta saadaan aikaväli
        {
         ptr = ptr->next;
         }
    strftime(aloituspvm, sizeof(aloituspvm), "%d.%m.%Y", phead->date);
    strftime(lopetuspvm, sizeof(lopetuspvm), "%d.%m.%Y", ptr->date);
    printf("Yhteensä %d palautusta %s - %s väliseltä ajalta.\n\n", lkm, aloituspvm, lopetuspvm);
    return phead;
}
