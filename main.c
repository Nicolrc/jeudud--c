#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bienvenu(char nomJoueur[20]);
int hasar(int min, int max);
int choixJoueur(void);
void comparaison(int desJoueur, int desOrdi);
void leJeu (char rejouer[] );

int main(void)
{
    char Joueur[20];
    char rejouer[2] = "o";

    while (strcmp(rejouer, "o") == 0) {
        int desJoueur;
        int desOrdi;

        bienvenu(Joueur);
        desOrdi = hasar(1, 6);
        desJoueur = choixJoueur();
        comparaison(desJoueur, desOrdi);

        leJeu(rejouer);
    }
    return 0;
}

void bienvenu(char nomJoueur[20])
{
    printf("Qu'elle est ton nom ?\n");
    scanf("%s", nomJoueur);
    printf("Bienvenue a toi %s dans ce petit jeu de des\n", nomJoueur);
}

int choixJoueur(void)
{
    int choix;
    do {
        printf("\nQuelle chiffre a fait ton des, entre 1 et 6 evidemment :\n");

        if (scanf("%d", &choix) != 1) {
            while (getchar() != '\n');
            printf("Il ne faut pas que tu entre de lettre, uniquement un chiffre entre 1 et 6");
            continue;
        }

        if(choix < 0 || choix > 6) {
            printf("Ce n'est pas un chiffre entre 1 et 6 voyons");
        }

    } while (choix > 6 || choix < 1);

}

void comparaison(int desJoueur, int desOrdi)
{
    if (desJoueur < desOrdi) {
        printf("Ton des a fait moins que moi, dommage, c'est perdu, j'ai fait : %d\n", desOrdi);
    } else if (desJoueur > desOrdi) {
        printf("Ton des a fait mieux que moi ! Bravo, c'est gagne ! j'ai fait : %d\n", desOrdi);
    } else {
        printf("On dirait bien qu'on a egalite cowboy !");
    }

}

void leJeu (char rejouer[] )
{
    printf("Veux-tu retenter ta chance ? o/n\n");
    scanf("%s", rejouer);

    if (strcmp(rejouer, "o") == 0) {
        printf("C'est reparti pour un tour !\n");
    } else {
        printf("Merci d'avoir joue ! a bientot!\n");
    }

}

int hasar(int min, int max)
{
    static int desOrdi = 0;
    if (!desOrdi) {
        srand(time(NULL));
        desOrdi = 1;
    }
    return (rand() % (max - min + 1)) + min;
}