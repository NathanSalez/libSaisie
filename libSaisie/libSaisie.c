#include "libSaisie.h"

// Déclaration des fonctions locales à la bibliothèque
// On ne peut pas les utiliser en dehors de ce fichier.
static int _verif_alpha_num(char * mot);
static void _read_string(char *ch, size_t nb_caracteres);
static void _vider_buffer();

#ifdef __MODE_DEBUG_LIB_SAISIE__
int main()
{
    
    /*
    printf("\nTest de lire_caractere\n");
    char c=0;
    lire_caractere(&c);
    printf("Caractere saisi : %c\n",c);
    lire_caractere(&c);
    printf("Caractere saisi : %c\n",c);
    */

    /*
    printf("\nTest de lire_entier\n");
    int x=0;
    lire_entier(&x);
    printf("Entier saisi : %d\n",x);
    lire_entier(&x);
    printf("Entier saisi : %d\n",x);
    */

    /*
    printf("\nTest de lire_reel_sp\n");
    float e_s = 0;
    lire_reel_sp(&e_s);
    printf("Reel saisi : %f\n",e_s);
    lire_reel_sp(&e_s);
    printf("Reel saisi : %f\n",e_s);
    */

    /*
    printf("\nTest de lire_reel_dp\n");
    double e_d = 0;
    lire_reel_dp(&e_d);
    printf("Reel saisi : %lf\n",e_d);
    lire_reel_dp(&e_d);
    printf("Reel saisi : %lf\n",e_d);
    */

    /*
    printf("\nTest de lire_mot\n");
    char test_mot[NBCARACTERES_MOTS+1];
    lire_mot(test_mot,NBCARACTERES_MOTS);
    printf("Mot saisi : %s\n",test_mot);
    lire_mot(test_mot,NBCARACTERES_MOTS);
    printf("Mot saisi : %s\n",test_mot);
    */

    
    printf("\nTest de lire_chaine\n");
    char test_chaine[NBCARACTERES_CH+1];
    lire_chaine(test_chaine,NBCARACTERES_CH);
    printf("Chaine de caractères saisie : %s\n",test_chaine);
    char test_car;
    lire_chaine(&test_car,1);
    printf("Chaine de caractères saisie : %c\n",test_car);
    
    
    return 0;   
}
#endif


void lire_caractere(char *c)
{
    if( c == NULL )
        return;

    printf("Veuillez saisir un caractère :\n"); 
    scanf("%c",c);
    _vider_buffer();
}


void lire_entier(int *e)
{
    if( e == NULL)
        return;

    int n = 0;
    do{
        printf("Veuillez saisir un entier :\n");  
        n = scanf("%d",e);        
        _vider_buffer();
    }while( n != 1 );
}


void lire_reel_sp(float *d)
{
    if( d == NULL)
        return;

    int n = 0;
    do{
        printf("Veuillez saisir un nombre décimal :\n");  
        n = scanf("%f",d);        
        _vider_buffer();
    }while( n != 1 );
}


void lire_reel_dp(double *d)
{
    if( d == NULL)
            return;

    int n = 0;
    do{
        printf("Veuillez saisir un nombre décimal :\n");  
        n = scanf("%lf",d);        
        _vider_buffer();
    }while( n != 1 );
}


void lire_mot(char *mot, size_t nb_caracteres)
{
    if( nb_caracteres == 0 || mot == NULL )
	    return;

    do {
        printf("Veuillez saisir un mot de %lu caractères :\n",nb_caracteres);
        //fgets(mot,nb_caracteres+1,stdin);_vider_buffer();
        _read_string(mot,nb_caracteres);
    }while( _verif_alpha_num(mot) != 1 );     

}


void lire_chaine(char *ch, size_t nb_caracteres)
{
    if( nb_caracteres == 0 || ch == NULL )
	    return;

    printf("Veuillez saisir une chaine de %lu caractères :\n",nb_caracteres); 
    //fgets(ch,nb_caracteres+1,stdin);_vider_buffer();
    _read_string(ch,nb_caracteres);
}



/****-------------------------------------****/
/**** FONCTIONS LOCALES A LA BIBLIOTHEQUE ****/
/****-------------------------------------****/
static void _vider_buffer()
{
    char c;
    while( ( c = getchar() ) != '\n' && c != EOF)
    {
#ifdef __MODE_DEBUG_LIB_SAISIE__
        printf("Caractère supprimé : %c\n",c);
#endif
    }
}


static int _verif_alpha_num(char * mot)
{
    for(int i =0; i < strlen(mot); i++)
    {
        if( ! isalpha(mot[i]) )
            return 0;
    }
    
    return 1;
}


static void _read_string(char *ch, size_t nb_caracteres)
{
    size_t nb_caracteres_tapes = 0;
    char c;
	while( (c = getchar()) != '\n' && c != EOF && nb_caracteres_tapes < nb_caracteres )
    {
        ch[nb_caracteres_tapes++] = c;
#ifdef __MODE_DEBUG_LIB_SAISIE__
        printf("DEBUG(lire_chaine) - ch = %s\n",ch);
#endif 
    }
    ch[nb_caracteres_tapes] = '\0';
    if( c != '\n' && c != EOF)
        _vider_buffer();
}


