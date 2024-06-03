#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"


#define ABECEDNO 1
#define PLACANJE 2
#define EXIT 3
int izbornikSortiranja()
{
	int choice;


	while (1) {
		printf("Opcije upravljanja bazom podataka auto skole:\n");
		printf("1. Sortiranje abecedno\n");
		printf("2. Sortiranje po iznosu placanja\n");
		printf("3. Exit\n");
		printf("Unesite opciju: ");
		scanf("%d", &choice);

		switch (choice) {
		case ABECEDNO:
			sortiranjeAbecedno();
			break;
		case PLACANJE:
			sortiranjePlacanja();
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