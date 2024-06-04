#ifndef HEADER_H
#define HEADER_H

typedef struct {
	char ime[50];
	char prezime[50];
	float placanje;
	int brojRata;
	char datumPredavanja[20];
} Ucenik;

typedef struct {
	char* ime;
	char* prezime;
	float placanje;
	int brojRata;
	char* datumPredavanja;
} UCENIK;


int GLizbornik();
void unosUcenika();
void BrisanjeUcenika();
void IzmjenaPodataka();
void UplateUcenika();
void PretrazivanjeUcenika();
int izbornikSortiranja();




#endif

