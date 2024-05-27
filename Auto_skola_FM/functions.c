#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"


// Dodavanje
int DodavaljeUcenika() {

	printf("Dodavlje ucenika:");
	char* ime = (char*)calloc(50, sizeof(char));
	char* prezime = (char*)calloc(50, sizeof(char));
	char* datum = (char*)calloc(20, sizeof(char));
	float placanje;
	int broj_rata;

	if (ime == NULL || prezime == NULL || datum == NULL) {
		printf("Greska pri alociranju memorije!\n");
		return;
	}

	printf("Unesite ime: ");
	scanf("%49s", ime);

	printf("Unesite prezime: ");
	scanf("%49s", prezime);

	printf("Unesite iznos placanja: ");
	scanf("%f", &placanje);

	printf("Unesite broj rata: ");
	scanf("%d", &broj_rata);

	printf("Unesite datum predavanja (DD.MM.GGGG): ");
	scanf("%19s", datum);

	FILE* datoteka = fopen("podaci.txt", "w+");

	if (datoteka == NULL) {
		printf("Greska pri otvaranju datoteke!");
		free(ime);
		free(prezime);
		free(datum);
		return;
	}

	fprintf(datoteka, "Ime: %s\n", ime);
	fprintf(datoteka, "Prezime: %s\n", prezime);
	fprintf(datoteka, "Placanje: %.2f\n", placanje);
	fprintf(datoteka, "Broj rata: %d\n", broj_rata);
	fprintf(datoteka, "Datum predavanja: %s\n", datum);

	fclose(datoteka);

	free(ime);
	free(prezime);
	free(datum);

	printf("Podaci su uspjesno spremljeni u datoteku podaci.txt\n");
}
// Brisanje 
int BrisanjeUcenika() {
	char* ime = (char*)calloc(50, sizeof(char));
	char* prezime = (char*)calloc(50, sizeof(char));
	char* linija = (char*)calloc(200, sizeof(char));
	int found = 0;

	if (ime == NULL || prezime == NULL || linija == NULL) {
		printf("Greska pri alociranju memorije!\n");
		free(ime); 
		free(prezime);
		free(linija);
		return;
	}

	printf("Unesite ime ucenika za brisanje: ");
	scanf("%49s", ime);
	printf("Unesite prezime ucenika za brisanje: ");
	scanf("%49s", prezime);

	FILE* staraDatoteka = fopen("podaci.txt", "r+");
	if (staraDatoteka == NULL) {
		perror("Greska pri otvaranju datoteke podaci.txt");
		free(ime); 
		free(prezime);
		free(linija);
		return;
	}

	FILE* novaDatoteka = fopen("novi_podaci.txt", "w+");
	if (novaDatoteka == NULL) {
		perror("Greska pri otvaranju datoteke novi_podaci.txt");
		fclose(staraDatoteka);
		free(ime); 
		free(prezime);
		free(linija);
		return;
	}

	while (fgets(linija, 200, staraDatoteka) != NULL) {
		if (strstr(linija, ime) && strstr(linija, prezime)) {
			found = 1;
			for (int i = 0; i < 4; i++) {
				fgets(linija, 200, staraDatoteka);
			}
		}
		else {
			fprintf(novaDatoteka, "%s", linija);
		}
	}

	fclose(staraDatoteka);
	fclose(novaDatoteka);

	if (found) {
		if (remove("podaci.txt") != 0) {
			perror("Greska pri brisanju datoteke podaci.txt");
		}
		else if (rename("novi_podaci.txt", "podaci.txt") != 0) {
			perror("Greska pri preimenovanju datoteke novi_podaci.txt");
		}
		else {
			printf("Ucenik %s %s je obrisan.\n", ime, prezime);
		}
	}
	else {
		remove("novi_podaci.txt");
		printf("Ucenik %s %s nije pronadjen.\n", ime, prezime);
	}

	free(ime);
	free(prezime);
	free(linija);
	ime = NULL;
	prezime = NULL;
	linija = NULL;
}
//izmjena podataka
int IzmjenaPodataka() {
	char* ime = (char*)calloc(50, sizeof(char));
	char* prezime = (char*)calloc(50, sizeof(char));
	char* noviIme = (char*)calloc(50, sizeof(char));
	char* noviPrezime = (char*)calloc(50, sizeof(char));
	char* noviDatum = (char*)calloc(20, sizeof(char));
	char* linija = (char*)calloc(200, sizeof(char));
	float noviPlacanje;
	int noviBrojRata;
	int found = 0;

	if (ime == NULL || prezime == NULL || noviIme == NULL || noviPrezime == NULL || noviDatum == NULL || linija == NULL) {
		printf("Greska pri alociranju memorije!\n");
		free(ime);
		free(prezime);
		free(noviIme);
		free(noviPrezime);
		free(noviDatum);
		free(linija);
		return;
	}

	printf("Unesite ime ucenika za izmjenu: ");
	scanf("%49s", ime);
	printf("Unesite prezime ucenika za izmjenu: ");
	scanf("%49s", prezime);

	printf("Unesite novo ime: ");
	scanf("%49s", noviIme);
	printf("Unesite novo prezime: ");
	scanf("%49s", noviPrezime);
	printf("Unesite novi iznos placanja: ");
	scanf("%f", &noviPlacanje);
	printf("Unesite novi broj rata: ");
	scanf("%d", &noviBrojRata);
	printf("Unesite novi datum predavanja (DD.MM.GGGG): ");
	scanf("%19s", noviDatum);

	FILE* staraDatoteka = fopen("podaci.txt", "r+");
	if (staraDatoteka == NULL) {
		perror("Greska pri otvaranju datoteke podaci.txt");
		free(ime);
		free(prezime);
		free(noviIme);
		free(noviPrezime);
		free(noviDatum);
		free(linija);
		return;
	}

	FILE* novaDatoteka = fopen("novi_podaci.txt", "w+");
	if (novaDatoteka == NULL) {
		perror("Greska pri otvaranju datoteke novi_podaci.txt");
		fclose(staraDatoteka);
		free(ime);
		free(prezime);
		free(noviIme);
		free(noviPrezime);
		free(noviDatum);
		free(linija);
		return;
	}

	while (fgets(linija, 200, staraDatoteka) != NULL) {
		if (strstr(linija, ime) && strstr(linija, prezime)) {
			found = 1;
			fprintf(novaDatoteka, "Ime: %s\n", noviIme);
			fprintf(novaDatoteka, "Prezime: %s\n", noviPrezime);
			fprintf(novaDatoteka, "Placanje: %.2f\n", noviPlacanje);
			fprintf(novaDatoteka, "Broj rata: %d\n", noviBrojRata);
			fprintf(novaDatoteka, "Datum predavanja: %s\n", noviDatum);
			for (int i = 0; i < 4; i++) {
				fgets(linija, 200, staraDatoteka);
			}
		}
		else {
			fprintf(novaDatoteka, "%s", linija);
		}
	}

	fclose(staraDatoteka);
	fclose(novaDatoteka);

	if (found) {
		if (remove("podaci.txt") != 0) {
			perror("Greska pri brisanju datoteke podaci.txt");
		}
		else if (rename("novi_podaci.txt", "podaci.txt") != 0) {
			perror("Greska pri preimenovanju datoteke novi_podaci.txt");
		}
		else {
			printf("Podaci ucenika %s %s su izmijenjeni.\n", ime, prezime);
		}
	}
	else {
		remove("novi_podaci.txt");
		printf("Ucenik %s %s nije pronadjen.\n", ime, prezime);
	}

	free(ime);
	free(prezime);
	free(noviIme);
	free(noviPrezime);
	free(noviDatum);
	free(linija);
	ime = NULL;
	prezime = NULL;
	noviIme = NULL;
	noviPrezime = NULL;
	noviDatum = NULL;
	linija = NULL;
}

int UplateUcenika() {
	return 0;
}
int PretrazivanjeUcenika() {
	return 0;
}