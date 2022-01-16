/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: 
 * Tekijä: Eemil Aspholm
 * Opiskelijanumero: 0567753
 * Päivämäärä: 26.2.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: www.programiz.com/c-programming,  
 */
/*******************************************************************/
#include "ali2.h"
#ifndef ali1_h
#define ali1_h
#define LEN 200
#define size 61

void tulostaTulokset(TIEDOT *ptr);
LIST *lisaaTaulukkoon(LIST *phead, char *pRow);
LIST *lueTiedosto(LIST *phead);
#endif