#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"



int DodavaljeUcenika() {

	printf("Dodavlje ucenika:");
	char ime[50], prezime[50], datum[20];
	float placanje;
	int broj_rata;

	printf("Unesite ime: ");
	scanf("%s", ime);

	printf("Unesite prezime: ");
	scanf("%s", prezime);

	printf("Unesite iznos placanja: ");
	scanf("%f", &placanje);

	printf("Unesite broj rata: ");
	scanf("%d", &broj_rata);

	printf("Unesite datum predavanja (DD.MM.GGGG): ");
	scanf("%s", datum);

	FILE* datoteka = fopen("podaci.txt", "w");

	if (datoteka == NULL) {
		printf("Greška pri otvaranju datoteke!");
		return;
	}

	fprintf(datoteka, "Ime: %s\n", ime);
	fprintf(datoteka, "Prezime: %s\n", prezime);
	fprintf(datoteka, "Placanje: %.2f\n", placanje);
	fprintf(datoteka, "Broj rata: %d\n", broj_rata);
	fprintf(datoteka, "Datum predavanja: %s\n", datum);

	fclose(datoteka);

	printf("Podaci su uspješno spremljeni u datoteku podaci.txt\n");
	
	
	return 0;
}

int BrisanjeUcenika() {
	return 0;
}
int IzmjenaPodataka() {
	return 0;
}
int UplateUcenika() {
	return 0;
}
int PretrazivanjeUcenika() {
	return 0;
}