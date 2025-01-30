#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Nombre maximum de contacts

// Définition de la structure contact
typedef struct {
    char nom[31];
    char prenom[31];
    long age;
} contact;

// Fonction pour saisir un contact
void saisirContact(contact* c) {
    printf("Saisir le nom: \n");
    scanf("%s", c->nom);

    printf("Saisir le prénom: \n");
    scanf("%s", c->prenom);

    printf("Saisir l'âge: \n");
    scanf("%ld", &c->age);
}

// Fonction pour afficher un contact
void affiContact(contact* c) {
    printf("Nom: %s\n", c->nom);
    printf("Prénom: %s\n", c->prenom);
    printf("Âge: %ld\n", c->age);
}

// Fonction pour ajouter un contact à la liste
void ajtContact(contact* contacts, int* size) {
    if (*size >= MAX) {
        printf("Le carnet d'adresses est plein.\n");
        return;
    }

    // Saisir un nouveau contact et l'ajouter à la liste
    saisirContact(&(contacts)[*size]);
    (*size)++;
}

// Fonction pour afficher tous les contacts
void afficherTousLesContacts(contact* contacts, int size) {
    if (size == 0) {
        printf("Aucun contact enregistré.\n");
    } else {
        printf("\nContacts enregistrés:\n");
        for (int i = 0; i < size; i++) {
            affiContact(&contacts[i]);
        }
    }
}

int main() {
    contact* contacts =(contact*) malloc(MAX * sizeof(contact));  // Allocation dynamique pour 10 contacts
    if (contacts == NULL) {
        printf("Erreur d'allocation de mémoire.\n");
        return 1;  // Quitter le programme si l'allocation échoue
    }

    int size = 0;  // Nombre actuel de contacts dans la liste
    char choix;

    do {
        // Ajouter un contact si la capacité le permet
        ajtContact(contacts, &size);

        // Afficher tous les contacts
        afficherTousLesContacts(contacts, size);

        // Demander à l'utilisateur s'il veut ajouter un autre contact
        if (size < MAX) {
            printf("\nVoulez-vous ajouter un autre contact ? (o/n): ");
            scanf(" %c", &choix);
        } else {
            choix = 'n';  // Si le carnet est plein, on arrête
        }

    } while (choix == 'o' || choix == 'O');

    // Libérer la mémoire allouée
    free(contacts);

    return 0;
}
