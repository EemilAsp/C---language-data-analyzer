#*******************************************************************/
#* CT60A2500 C-ohjelmoinnin perusteet
#* Otsikkotiedot: 
#* Tekijä: Eemil Aspholm
#* Opiskelijanumero: 0567753
#* Päivämäärä: 26.2.2021
#* Yhteistyö ja lähteet, nimi ja yhteistyön muoto: www.programiz.com/c-programming,  
#*/
#*******************************************************************/
paaohjelma.exe: paaohjelma.o ali1.o ali2.o
	gcc ali1.o ali2.o paaohjelma.o -o HT
paaohjelma.o: paaohjelma.c ali1.h ali2.h
	gcc paaohjelma.c -c -Wall -std=c99 -pedantic
ali1.o: ali1.c ali1.h
	gcc ali1.c -c -Wall -std=c99 -pedantic
ali2.o: ali2.c ali2.h
	gcc ali2.c -c -Wall -std=c99 -pedantic
