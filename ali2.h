/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: 
 * Tekijä: Eemil Aspholm
 * Opiskelijanumero: 0567753
 * Päivämäärä: 26.2.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: www.programiz.com/c-programming,  
 */
/*******************************************************************/
#ifndef ali2_h
#define ali2_h
#define len 10

typedef struct list
{
    struct tm *date; // pvm ja kello 1.sarake 
    char ename[len]; // tehtävän nimi 2.sarake
    int userid; //käyttäjän tunnistenumero 4.sarake
    int eid; //tehtävän tunnistenumero 3.sarake
    struct list *next;
}LIST;

typedef struct tiedot
{
    char name[len];
    int value;
}TIEDOT;

void alustaLista(TIEDOT *ptr);
LIST *vapautaMuistiTaulukko(LIST *phead);
void kysyTiedosto(char *ptr);
void analysoiTiedot(LIST *phead, TIEDOT *Lista);
#endif
