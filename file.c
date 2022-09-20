#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct Produit
{
    int code;
    char nom[30];
    int quantite;
    float prix;
    // float prixTTC;

} Produit;
typedef struct ProduitsVendu{
    char nomProduitVendu[30];
    int quantiteProduitVendu;
    float prixProduitVendu;

}ProduitsVendu;
int somme ,totalSomme,totalquantite;
int np = 1;
int nbrpv=0;
ProduitsVendu produitvendu[100];
Produit produit[100]={
{1,"DOLIPRAN",12,13},

};
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
    // produit[np].prixTTC = produit[np].prix +produit[np].prix * 15;
    
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
    printf("  -------------------------------------------------------------------------------\n" );
    printf("  |     Code    |    Nom     |    Prix      |   Prix TTC  |  Quantite du produit |\n" );
    printf("  -------------------------------------------------------------------------------\n" );
            // printf("code    nom      prix      quantite \n");
    for (int i = 0; i < np; i++)
    {
       
    printf("        %d           %s       %.2fdh        %.2fdh              %d          \n", produit[i].code, produit[i].nom, produit[i].prix,produit[np].prix +(produit[np].prix * 15), produit[i].quantite);
    printf("  -------------------------------------------------------------------------------\n" );    
           
        // printf("numero %d\n", i + 1);
        // printf("nom de produit %s\n", produit[i].nom);
        // printf("code de produit %d\n", produit[i].code);
        // printf("quantite de produit %d\n", produit[i].quantite);
        // printf("prix de produit %f\n", produit[i].prix);
        // printf("prixttc de produit %f\n", produit[i].prixTTC);
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
void rechercheCode()
{
    int c, i;
    printf("---------------------------------------------\n");
    printf(" ***1 : chercher avec le code de produit :***\n");
    printf("----------------------------------------------\n");
    printf("Donner le code de produit que vous cherchez: ");
    scanf("%d", &c);
    for (i = 0; i < np; i++)
    {
        if (produit[i].code == c)
        {
        printf("  -------------------------------------------------------------------------------\n" );
        printf("  |     Code    |    Nom   |    Prix      |   Prix TTC  |  Quantite du produit |\n" );
        printf("  -------------------------------------------------------------------------------\n" );
            // printf("code    nom      prix      quantite \n");
        printf("       %d             %s        %.2fdh         %.2fdh              %d          \n", produit[i].code, produit[i].nom, produit[i].prix,produit[np].prix +produit[np].prix * 15, produit[i].quantite);
        printf("  -------------------------------------------------------------------------------\n" );    
            break;
        }
    }
}
void rechercheQuantite()
{
    int q, i;
    printf("----------------------------------------------\n");
    printf(" ***2 : chercher avec le nom de produit  :***\n");
    printf("----------------------------------------------\n");
    printf("Donner la quantite de produit que vous cherchez :");
    scanf("%d", &q);
    for (i = 0; i < np; i++)
    {
        if (produit[i].quantite == q)
        {
            printf("code    nom      prix      quantite \n");
            printf("%d      %s      %.2fdh        %d     \n", produit[i].quantite, produit[i].nom, produit[i].prix, produit[i].quantite);
        }
    }
}
void acheterProduit()
{
    time_t now;//structure time_t affiche temps actuelle 
    time(&now);//initialiser
    int i, code, quantite,count=0;
    printf("entrer le code de produit : ");
    scanf("%d", &code);

    printf("entrer la quantite de produit :");
    scanf("%d", &quantite);
    for (i = 0; i < np; i++)
    {
        if (produit[i].code == code)
        {
            if (produit[i].quantite >= quantite)
            {
                produit[i].quantite -= quantite;
                somme =quantite *(produit[i].prix +(produit[i].prix* 15)/100);
                printf(" LE PRIX DE PRODUIT(S) ACHETER EST: %.2f DH\n\n\n",somme);
                totalSomme+=somme;
                totalquantite+=quantite;
                 strcpy(produitvendu[nbrpv].nomProduitVendu,produit[i].nom);
                      produitvendu[nbrpv].prixProduitVendu=produit[i].prix;
                       produitvendu[nbrpv].quantiteProduitVendu=quantite;
                       nbrpv++;

                printf("%s",ctime(&now));//convertir de stuct a string  

            }
            else
            {
                printf("quantite insuffisante\n");
            }
            break;
        }
        else{
            count++;//pour chercher si le code existe et refaire condition jusqua la derniere case du tableau 
        }
    }
    if(count==np){
                printf("produit introuvable\n");
    }
}
void supprimer()
{
    int i, code, position;
    printf("supprimer un produit :\n");
    printf("donner le code de produit que vous supprimer :");
    scanf("%d", &code);

    for (i = 0; i < np; i++)
    {
        if (code == produit[i].code)
        {
            // printf("%d", i);
            position = i; //in position par lemplacement du produit quon veut supprimer
            for (i = position; i < np; i++)
            {
                produit[i] = produit[i + 1];//remplacer i par i+1
            }
        }
    }
    np--;
}
void alimenterStock()
{
    int i, code, quantite;
    printf("entre le code de produit :");
    scanf("%d", &code);
    printf("entre la quantite de produit :");
    scanf("%d", &quantite);
    for (i = 0; i < np; i++)
    {
        if (produit[i].code == code)
        {
            produit[i].quantite += quantite;
        }
        break;
    }
}
// IF T[I+1].prix*T[i+1].quantite<min
void etat_stock()
{
    int i;
    for (i = 0; i < np; i++)
    {
        if (produit[i].quantite < 3)
        {
            printf("code    nom      prix      quantite \n");
            printf("%d      %s      %.2fdh        %d     \n", produit[i].quantite, produit[i].nom, produit[i].prix, produit[i].quantite);
        
            // printf("nom: %s\n", produit[i].nom);
            // printf("code: %d\n", produit[i].code);
            // printf("prix: %f\n", produit[i].prix);
        }
    }
}
void menu()
{

printf("____________________________________Menu Pharmacie____________________________________________\n");   
printf("| **1)pour ajouter un nouveau produit  :                                                      |\n");
printf("| **2)pour ajouter plusieurs produits :                                                       |\n");
printf("| **3)pour afficher un produit :                                                              |\n");
printf("| **4)pour lister tous les produits par ordre alphabetique croissant :                        |\n");
printf("| **5)pour lister tous les produits par ordre decroissant du prix :                           |\n");
printf("| **6)pour rechercher par code :                                                              |\n");
printf("| **7)pour rechercher par quantite :                                                          |\n");
printf("| **8)pour acheter produit :                                                                  |\n");
printf("| **9)pour supprimer produit :                                                                |\n");
printf("| **10)pour alimenter Stock :                                                                 |\n");
printf("| **11)pour etat Stock :                                                                      |\n");
printf("----------------------------------------------------------------------------------------------\n");   

    
}
void statistiques(){
int i;
float min, max;
           for(i=0;i<nbrpv;i++){
                printf("  NAME: %s \n  PRIX: %.3f DH \n  QUANTITY: %d \n",produitvendu[nbrpv].nomProduitVendu,produitvendu[nbrpv].prixProduitVendu,produitvendu[nbrpv].quantiteProduitVendu);
           }
            min = produitvendu[0].prixProduitVendu;
                for(i=0;i<nbrpv;i++){
                    if (produitvendu[i+1].prixProduitVendu<min)
                    min = produitvendu[i].prixProduitVendu;
                }
                max = produitvendu[0].prixProduitVendu;
                for(i=0;i<nbrpv;i++){
                    if (produitvendu[i+1].prixProduitVendu>max)
                    max = produitvendu[i].prixProduitVendu;
                }
            printf("la somme des prix de votre produits vendus est -----> %.3f DH\n",totalSomme);
            printf("le nombres de votre produits vendus est ----->%d PRODUITS\n\n\n",totalquantite);
            printf("le max des prix des produits vendus aujourd'hui  : %f\n",max);
            printf("le min des prix des produits vendus aujourd'hui  : %f\n",min);
   }
int main()
{

    menu();
    int choix;
    debut:
    printf("entrer votre choix :");
    scanf("%d",&choix);
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

    case 3:
        afficherProduit();
        goto debut;

    case 4:
        triProduitAlphabet();
        goto debut;
    case 5:
        triparprix();
        goto debut;

    case 6:
        rechercheCode();
        goto debut;

    case 7:
        rechercheQuantite();
        goto debut;
    case 8:
        afficherProduit();
        acheterProduit();
        afficherProduit();
        goto debut;
    case 9:
        afficherProduit();
        supprimer();
        afficherProduit();
        goto debut;
    case 10:
        alimenterStock();
        goto debut;
    case 11:
        etat_stock();
        goto debut;
    case 12:

        goto debut;
    default:
        printf("s'il vous plait entrer un nombre entre 1 et 12");
        break;
    }
}
