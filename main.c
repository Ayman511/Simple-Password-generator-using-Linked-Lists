#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Element Element;
struct Element{
    char nombre;
    Element *next;
};

typedef struct Liste Liste;
struct Liste{
    Element *premier;
};


void gnrNumbers(int pwdLong);
Liste *initialisation();
void insertion(Liste *maListe, int nbr);
void insertionAuMilieu(Liste *maListe, int nbrCherche, int nbr);
void suppression(Liste *liste, int nbrASupp);
void afficherListe(Liste *Liste);

int main()
{
    int pwdLong = 0, i = 0;
    int *numbers = NULL;

    printf("How long ? ");
    scanf("%d", &pwdLong);

    gnrNumbers(pwdLong);
}

void gnrNumbers(int pwdLong)
{
    int i = 0;
    int *numbers = NULL;

    numbers = malloc(pwdLong * sizeof(int));
    /* Testing if numbers equivalent to NULL */
    if(numbers == NULL)
        exit(0);

    srand(time(NULL));
    for(i; i < pwdLong; i++)
    {
        numbers[i] = rand() % 127;
    }

    /* Le début d'utilisation de la liste chainnée */
    Element *maListe = initialisation();
    for(i = 0; i < pwdLong; i++)
        insertion(maListe, numbers[i]);
    suppression(maListe, 0);

    /* Libérer la mémoire */
    free(numbers);
    /* afficher la nouvelle liste des nombres */
    afficherListe(maListe);

    afficherListe(maListe, pwdLong);
}

Liste *initialisation()
{
    Element *element = malloc(sizeof(*element));
    Liste *liste = malloc(sizeof(*liste));

    if(liste == NULL || liste == NULL)
        exit(EXIT_FAILURE);

    element->nombre = 0;
    element->next = NULL;
    liste->premier = element;
}

void insertion(Liste *liste, int nbr)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if(liste == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);

    nouveau->nombre = nbr;
    nouveau->next = liste->premier;
    liste->premier = nouveau;
}

void insertionAuMilieu(Liste *liste, int nbrCherche, int nbr)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    Element *temp = liste->premier;

    if(liste == NULL || temp == NULL)
        exit(EXIT_FAILURE);

    while(temp->next->nombre != nbrCherche && temp->next != NULL)
        temp = temp->next;

    if(temp->next != NULL)
    {
        nouveau->nombre = nbr;
        nouveau->next = temp->next;
        temp->next = nouveau;
    }
}

void suppression(Liste *liste, int nbrASupp)
{
    Element *aSupprimer = NULL;
    if(liste->premier->nombre == nbrASupp)
    {
        aSupprimer = liste->premier;
        liste->premier = liste->premier->next;
        free(aSupprimer);
    }else
    {
        Element *temp = liste->premier;

        while(temp->next->nombre != nbrASupp && temp->next != NULL)
            temp = temp->next;

        if(temp->next != NULL)
        {
            aSupprimer = temp->next;
            temp->next = temp->next->next;
            free(aSupprimer);
        }
    }
}

void afficherListe(Liste *liste)
{
    Element *actuel = liste->premier;
    if(liste == NULL)
        exit(EXIT_FAILURE);

    while(actuel != NULL)
    {
        printf("%c", actuel->nombre);
        actuel = actuel->next;
    }
}











