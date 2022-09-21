#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Produit
{
    int code;
    char nom[30];
    int quantite;
    float prix;
    float prixTTC;

} Produit;
typedef struct Historique{
    time_t time;
    int quantite;
    // int prix-total;
    struct Produit produit;

};
// typedef struct Stock
// {
//     int revenu;
//     int nombre_produit;
//     

// } Stock;

int np = 0;
Produit produit[100];
// Produit produit[2]={{1,"ART",2,40},{2,"tam",5,50}};
// Stock stock[100];
void ajouterProduit()
{
    printf("entrer le code du produit :");
    scanf("%d", &produit[np].code);
    printf("entrer le nom du produit :");
    scanf("%s", produit[np].nom);
    printf("entrer la quantite du produit :");
    scanf("%d", &produit[np].quantite);
    printf("entrer le prix du produit :");
    scanf("%f", &produit[np].prix);
    produit[np].prixTTC = produit[np].prix + produit[np].prixTTC * 15;
    // printf("entrer le prixTTC du produit :");
    // scanf("%f",&produit[np].prixTTC);
    np++;
}
void ajouterPlusieurProduit()
{
    int i, nbr;
    printf("entrer le nombre de produit :");
    scanf("%d", &nbr);
    for (i = 0; i < nbr; i++)
    {
        ajouterProduit();
    }
}
void afficherProduit()
{
    for (int i = 0; i < np; i++)
    {
        printf("numero %d\n", i + 1);
        printf("nom de produit %s\n", produit[i].nom);
        printf("code de produit %d\n", produit[i].code);
        printf("quantite de produit %d\n", produit[i].quantite);
        printf("prix de produit %f\n", produit[i].prix);
        printf("prixttc de produit %f\n", produit[i].prixTTC);
    }
}
void triProduitAlphabet(void)
{
    Produit p;
    for (int i = 0; i < np; i++)
    { // np-1 parcequon a commence par 0
        for (int j = i + 1; j < np; j++)
        {
            if (strcmp(produit[i].nom, produit[j].nom) > 0)
            {
                p = produit[i];
                produit[i] = produit[j];
                produit[j] = p;
            }
        }
    }
    afficherProduit();
}
void triparprix()
{
    for (int i = 0; i < np - 1; i++)
    {
        for (int j = i + 1; j < np; j++)
        {
            if (produit[i].prix < produit[j].prix)
            {
                Produit p;
                p = produit[i];
                produit[i] = produit[j];
                produit[j] = p;
            }
        }
    }
    afficherProduit();
}
int rechercherProduits(int code){
    int count = 0;
    printf("entrer le code que vous voulez");
    scanf("%d", &code);
    for (int i = 0; i < np - 1; i++)
    {
        if (produit[i].code == code)
        {
            return (i + 1); // afficher son emplacement commence par 1 et pas 0, return case ou il existe
            break;
        }
        else
        {
            count++; // pour executer tous les produits pas slment le premier
        }
    }
    if (count == np)
    {
        return 0; // printf("ce produit n'existe pas");
    }
}
void acheterproduit(int code)
{
    int quantite;
    int i = rechercherProduits(code);
    if (i == 0)
    {
        printf("ce produit n'existe pas");
    }
    else
    {
        printf("entrer la quantite que vous voulez");
        scanf("%d", &quantite);
        if (produit[i - 1].quantite > quantite)
        { // i-1 pour quelle commence par 0 a nouveau
            produit[i - 1].quantite -= quantite;
        }
        if (produit[i - 1].quantite < quantite)
        {
            printf("ce produit n'existe pas");
        }
    }
}

void menu()
{
    int choix;
       debut:
    
        printf("pour ajouter un nouveau produit entrer 1:\n");
        printf("pour ajouter plusieurs produits entrer 2:\n");
        printf("pour afficher un produit entrer 3:\n");
        printf("pour lister tous les produits par ordre alphabetique croissant entrer 4:\n ");
        printf("pour lister tous les produits par ordre decroissant du prix entrer 5:\n ");
        printf("pour acheter produit entrer 6:\n");
        printf("entrer votre choix :");
        scanf("%d", &choix);
        

        switch (choix)
        {
        case 1:
            // ajouter un seul produit
            ajouterProduit();
            goto debut;
        case 2:
            // ajouter plusieur produit
            ajouterPlusieurProduit();
            goto debut;
            // printf("entrer le nombre de produits que vous voulez saisir\n");
            // scanf("%d", &nbr);
            // for (int i = 0; i < nbr; i++)
            // {
            //     ajouterUnProduit(produit);
            // }
            // break;
        case 3:
           
            triProduitAlphabet();
            goto debut;
        case 4:
            triparprix();
            goto debut;
            
        case 5:
            // printf("entrer le code de produit que vous voulez acheter\n");
            // scanf("%d", &nbr);

           
        case 6:
            // printf("entrer le code de produit que vous voulez acheter\n");
            // scanf("%d", &nbr);
            // int i = recherche(nbr, produit);
            // if (i == 0)
            // {
            //     printf("produit n'existe pas");
            // }
            // else
            // {
            //     printf("\t\t\t_______________________\n");
            //     printf("\t\t\t||numero|code   |nom        |prix    |TCC||\n");
            //     printf("\t\t\t|| %d  ", i);
            //     printf("\t\t\t%d     ", produit[i - 1].code);
            //     printf("\t\t\t%s     ", produit[i - 1].nom);
            //     printf("\t\t\t%f     ", produit[i - 1].prix);
            //     printf("\t\t\t%f     ||\n", produit[i - 1].TTC);
            //     printf("\t\t\t________________________\n");
            // }
            // break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        default:
            printf("s'il vous plait entrer un nombre entre 1 et 12");
            break;
        }
    
}

int main()
{

    menu();
}