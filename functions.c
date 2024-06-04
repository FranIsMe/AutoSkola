#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


// Dodavanje
void unosUcenika() {
	char ime[50];
	char prezime[50];
	float placanje;
	int brojRata;
	char datum[20];

	printf("Unesite ime: ");
	scanf("%49s", ime);
	printf("Unesite prezime: ");
	scanf("%49s", prezime);
	printf("Unesite iznos placanja: ");
	scanf("%f", &placanje);
	printf("Unesite broj rata: ");
	scanf("%d", &brojRata);
	printf("Unesite datum predavanja (DD.MM.GGGG): ");
	scanf("%19s", datum);

	FILE* datoteka = fopen("podaci.txt", "a");
	if (datoteka == NULL) {
		perror("Greska pri otvaranju datoteke podaci.txt");
		return;
	}

	fprintf(datoteka, "Ime: %s\n", ime);
	fprintf(datoteka, "Prezime: %s\n", prezime);
	fprintf(datoteka, "Placanje: %.2f\n", placanje);
	fprintf(datoteka, "Broj rata: %d\n", brojRata);
	fprintf(datoteka, "Datum predavanja: %s\n", datum);
	fprintf(datoteka, "-----\n");

	fclose(datoteka);

	printf("Podaci su uspjesno spremljeni u datoteku podaci.txt\n");
}
// Brisanje 
void BrisanjeUcenika() {
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

	FILE* staraDatoteka = fopen("podaci.txt", "r");
	FILE* novaDatoteka = fopen("novi_podaci.txt", "w");

	if (staraDatoteka == NULL || novaDatoteka == NULL) {
		perror("Greska pri otvaranju datoteke");
		if (staraDatoteka) fclose(staraDatoteka);
		if (novaDatoteka) fclose(novaDatoteka);
		free(ime);
		free(prezime);
		free(linija);
		return;
	}

	char buffer[50];
	snprintf(buffer, sizeof(buffer), "Ime: %s\n", ime);
	char bufferPrezime[50];
	snprintf(bufferPrezime, sizeof(bufferPrezime), "Prezime: %s\n", prezime);

	// Prolazak kroz staru datoteku i kopiranje podataka u novu, osim onih koje zelimo obrisati
	while (fgets(linija, 200, staraDatoteka) != NULL) {
		if (strcmp(linija, buffer) == 0) {
			fgets(linija, 200, staraDatoteka);
			if (strcmp(linija, bufferPrezime) == 0) {
				found = 1;
				// Preskakanje sljedecih 3 linija
				for (int i = 0; i < 3; i++) {
					fgets(linija, 200, staraDatoteka);
				}
			}
			else {
				fputs(buffer, novaDatoteka);
				fputs(linija, novaDatoteka);
			}
		}
		else {
			fputs(linija, novaDatoteka);
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
			printf("Podaci ucenika %s %s su obrisani.\n", ime, prezime);
		}
	}
	else {
		remove("novi_podaci.txt");
		printf("Ucenik %s %s nije pronadjen.\n", ime, prezime);
	}

	// Oslobadjanje memorije i ponistavanje pokazivaca
	free(ime);
	free(prezime);
	free(linija);
	ime = NULL;
	prezime = NULL;
	linija = NULL;
}
//izmjena podataka
void IzmjenaPodataka() {
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

	printf("Unesite ime ucenika za izmjenu: ");
	scanf("%49s", ime);
	printf("Unesite prezime ucenika za izmjenu: ");
	scanf("%49s", prezime);

	FILE* staraDatoteka = fopen("podaci.txt", "r");
	FILE* novaDatoteka = fopen("novi_podaci.txt", "w");

	if (staraDatoteka == NULL || novaDatoteka == NULL) {
		perror("Greska pri otvaranju datoteke");
		if (staraDatoteka) fclose(staraDatoteka);
		if (novaDatoteka) fclose(novaDatoteka);
		free(ime);
		free(prezime);
		free(linija);
		return;
	}

	char buffer[50];
	snprintf(buffer, sizeof(buffer), "Ime: %s\n", ime);
	char bufferPrezime[50];
	snprintf(bufferPrezime, sizeof(bufferPrezime), "Prezime: %s\n", prezime);

	while (fgets(linija, 200, staraDatoteka) != NULL) {
		if (strcmp(linija, buffer) == 0) {
			fgets(linija, 200, staraDatoteka);
			if (strcmp(linija, bufferPrezime) == 0) {
				found = 1;

				char novoIme[50];
				char novoPrezime[50];
				float novoPlacanje;
				int noviBrojRata;
				char noviDatum[20];

				printf("Unesite nove podatke:\n");
				printf("Novo ime: ");
				scanf("%49s", novoIme);
				printf("Novo prezime: ");
				scanf("%49s", novoPrezime);
				printf("Novi iznos placanja: ");
				scanf("%f", &novoPlacanje);
				printf("Novi broj rata: ");
				scanf("%d", &noviBrojRata);
				printf("Novi datum predavanja (DD.MM.GGGG): ");
				scanf("%19s", noviDatum);

				fprintf(novaDatoteka, "Ime: %s\n", novoIme);
				fprintf(novaDatoteka, "Prezime: %s\n", novoPrezime);
				fprintf(novaDatoteka, "Placanje: %.2f\n", novoPlacanje);
				fprintf(novaDatoteka, "Broj rata: %d\n", noviBrojRata);
				fprintf(novaDatoteka, "Datum predavanja: %s\n", noviDatum);
				fprintf(novaDatoteka, "-----\n");

				// Preskakanje starih podataka
				for (int i = 0; i < 3; i++) {
					fgets(linija, 200, staraDatoteka);
				}
			}
			else {
				fputs(buffer, novaDatoteka);
				fputs(linija, novaDatoteka);
			}
		}
		else {
			fputs(linija, novaDatoteka);
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
	free(linija);
	ime = NULL;
	prezime = NULL;
	linija = NULL;
}

void UplateUcenika() {
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

	printf("Unesite ime ucenika za izmjenu: ");
	scanf("%49s", ime);
	printf("Unesite prezime ucenika za izmjenu: ");
	scanf("%49s", prezime);

	FILE* staraDatoteka = fopen("podaci.txt", "r");
	FILE* novaDatoteka = fopen("novi_podaci.txt", "w");

	if (staraDatoteka == NULL || novaDatoteka == NULL) {
		perror("Greska pri otvaranju datoteke");
		if (staraDatoteka) fclose(staraDatoteka);
		if (novaDatoteka) fclose(novaDatoteka);
		free(ime);
		free(prezime);
		free(linija);
		return;
	}

	char buffer[50];
	snprintf(buffer, sizeof(buffer), "Ime: %s\n", ime);
	char bufferPrezime[50];
	snprintf(bufferPrezime, sizeof(bufferPrezime), "Prezime: %s\n", prezime);

	while (fgets(linija, 200, staraDatoteka) != NULL) {
		if (strcmp(linija, buffer) == 0) {
			fputs(linija, novaDatoteka); // Ime
			fgets(linija, 200, staraDatoteka);
			fputs(linija, novaDatoteka); // Prezime
			if (strcmp(linija, bufferPrezime) == 0) {
				found = 1;

				float novoPlacanje;
				int noviBrojRata;

				printf("Unesite nove podatke:\n");
				printf("Novi iznos placanja: ");
				scanf("%f", &novoPlacanje);
				printf("Novi broj rata: ");
				scanf("%d", &noviBrojRata);

				fgets(linija, 200, staraDatoteka); // Preskoci stari Placanje
				fprintf(novaDatoteka, "Placanje: %.2f\n", novoPlacanje);
				fgets(linija, 200, staraDatoteka); // Preskoci stari Broj rata
				fprintf(novaDatoteka, "Broj rata: %d\n", noviBrojRata);
				fgets(linija, 200, staraDatoteka); // Datum predavanja
				fputs(linija, novaDatoteka);
				fgets(linija, 200, staraDatoteka); // -----
				fputs(linija, novaDatoteka);
			}
			else {
				fputs(bufferPrezime, novaDatoteka);
			}
		}
		else {
			fputs(linija, novaDatoteka);
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
	free(linija);
	ime = NULL;
	prezime = NULL;
	linija = NULL;
}
void PretrazivanjeUcenika() {
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

	printf("Unesite ime ucenika za ispis: ");
	scanf("%49s", ime);
	printf("Unesite prezime ucenika za ispis: ");
	scanf("%49s", prezime);

	FILE* datoteka = fopen("podaci.txt", "r");
	if (datoteka == NULL) {
		perror("Greska pri otvaranju datoteke podaci.txt");
		free(ime);
		free(prezime);
		free(linija);
		return;
	}

	char buffer[50];
	snprintf(buffer, sizeof(buffer), "Ime: %s\n", ime);
	char bufferPrezime[50];
	snprintf(bufferPrezime, sizeof(bufferPrezime), "Prezime: %s\n", prezime);

	while (fgets(linija, 200, datoteka) != NULL) {
		if (strcmp(linija, buffer) == 0) {
			fgets(linija, 200, datoteka); // Prezime
			if (strcmp(linija, bufferPrezime) == 0) {
				found = 1;
				printf("%s", buffer); // Ime
				printf("%s", bufferPrezime); // Prezime

				fgets(linija, 200, datoteka); // Placanje
				printf("%s", linija);
				fgets(linija, 200, datoteka); // Broj rata
				printf("%s", linija);
				fgets(linija, 200, datoteka); // Datum predavanja
				printf("%s", linija);
				fgets(linija, 200, datoteka); // -----
				printf("%s", linija);
				break;
			}
		}
	}

	if (!found) {
		printf("Ucenik %s %s nije pronadjen.\n", ime, prezime);
	}

	fclose(datoteka);
	free(ime);
	free(prezime);
	free(linija);
	ime = NULL;
	prezime = NULL;
	linija = NULL;
}
// sortiranje
