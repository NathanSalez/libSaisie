#ifndef __LIB_SAISIE_H__
#define __LIB_SAISIE_H__
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifdef __MODE_DEBUG_LIB_SAISIE__
    #define NBCARACTERES_MOTS 5
    #define NBCARACTERES_CH 15
#endif // __MODE_DEBUG_LIB_SAISIE__

/**
 * NOTE : Chacune des fonctions de lecture vide le buffer d'entrée après la saisie.
 * Si un appel à scanf a été effectué avant l'utilisation de ces fonctions, leur bon fonctionnement n'est plus garanti :/
 */

/**
 *  Permet de lire un caractère quelconque sur l'entrée standard.
 *  N'effectue pas la saisie si c == NULL.
 */
void lire_caractere(char *c);


/**
 *  Permet de lire un entier quelconque sur l'entrée standard.
 *  N'effectue pas la saisie si e == NULL.
 */
void lire_entier(int *e);


/**
 *  Permet de lire un réel codé en simple précision (cf ANM1) quelconque, sur l'entrée standard.
 *  N'effectue pas la saisie si d == NULL.
 */
void lire_reel_sp(float *d);


/**
 *  Permet de lire un réel codé en double précision (cf ANM1) quelconque, sur l'entrée standard.
 *  N'effectue pas la saisie si d == NULL.
 */
void lire_reel_dp(double *d);


/**
 *  Permet de lire un mot de nb_caracteres (ne contient que des caractères de l'alphabet)
 *  N'effectue pas la saisie si mot == NULL ou nb_caracteres == 0.
 *  REMARQUE (1) : Si nb_caractères n'est pas strictement inférieure à l'espace mémoire allouée à mot, 
 *  alors l'erreur de segmentation survient !
 *  Le code suivant marche :
 *      char test[9+1];
 *      lire_mot(test,9);       // NE SURTOUT PAS FAIRE lire_mot(test,10)
 */
void lire_mot(char *mot, size_t nb_caracteres); 


/**
 *  Permet de lire une chaine de nb_caracteres quelconques.
 *  N'effectue pas la saisie si ch == NULL ou nb_caracteres == 0.
 *  La remarque 1 s'applique pour cette fonction.
 */
void lire_chaine(char *ch, size_t nb_caracteres);


#ifdef __MODE_DEBUG_LIB_SAISIE__
    int main();     // Test des fonctions.
#endif // __MODE_DEBUG__


#endif // __LIB_SAISIE_H__
