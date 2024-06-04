#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

#define DODAVANJE 1
#define BRISANJE 2
#define IZMJENA 3
#define UPLATE 4
#define PRETRAZIVANJE 5
#define SORTIRANJE 6
#define EXIT 7

int GLizbornik() {

	int choice;


	while (1) {
		printf("Opcije upravljanja bazom podataka auto skole:\n");
		printf("1. Dodavanje ucenika\n");
		printf("2. Brisanje ucenika\n");
		printf("3. Izmjena podataka\n");
		printf("4. Uplate ucenika\n");
		printf("5. Pretrazivanje ucenika\n");
		printf("6. Sortiranje ucenika\n");
		printf("7. Exit\n");
		printf("Unesite opciju: ");
		scanf("%d", &choice);

		switch (choice) {
		case DODAVANJE:
			unosUcenika();
			break;
		case BRISANJE:
			BrisanjeUcenika();
			break;
		case IZMJENA:
			IzmjenaPodataka();
			break;
		case UPLATE:
			UplateUcenika();
			break;
		case PRETRAZIVANJE:
			PretrazivanjeUcenika();
			break;
		case SORTIRANJE:
			izbornikSortiranja();
			break;
		case EXIT:
			printf("Izlazenje iz programa\n");
			return 0;
		default:
			printf("Pokusaj ponovo!\n");
		}
		printf("\n");
	}


	return 0;
}

