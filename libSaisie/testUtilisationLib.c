#include "libSaisie.h"

#define NBCARACTERES_MOTS 8

int main()
{
	char mot[NBCARACTERES_MOTS+1]="";
	lire_mot(mot,NBCARACTERES_MOTS);
	printf("Mot saisi : %s\n",mot);
	return 0;
}
