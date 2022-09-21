#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct Date 
{
	int day ,month ,year;
}date;
typedef struct Produit
{
    int code;
    char nom[30];
    int quantite;
    float prix;
    float prixTTC;
} Produit;

typedef struct ProduitsVendu{
    int code;
    char nom[30];
    int quantite;
    float prixTTC;
    float prixTotal;
    date d;

}ProduitsVendu;

Produit produit[100];
int np = 0;

ProduitsVendu produitvendu[100];
int nbrpv=0;




void ajouterProduit()
{
    debt:
    printf("entrer le code du produit :");
    scanf("%d", &produit[np].code);
    for(int i=0;i<np;i++){
        if(produit[np].code==produit[i].code){
           printf("ce code existe deja\n") ;
           goto debt;
        }

    }
    
    printf("entrer le nom du produit :");
    scanf("%s", produit[np].nom);
    printf("entrer la quantite du produit :");
    scanf("%d", &produit[np].quantite);
    // while(produit[np].quantite<0){
            
    //         printf("la quantite pas valide\n");
    //         printf("entrer une nouvelle quantite: ");
    //         scanf("%d",&produit[np].quantite);
    //     }
    printf("entrer le prix du produit :");
    scanf("%f", &produit[np].prix);
    produit[np].prixTTC = produit[np].prix +(produit[np].prix * 0.15);
    printf("le prixTTC du produit :%.2f\n",produit[np].prixTTC);
    
    np++;
}

void ajouterPlusieurProduit()
{
    int i, nbr;
    printf("entrer le nombre du produit :");
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

    for (int i = 0; i < np; i++)
    {
       
    printf("        %d           %s       %.2fdh        %.2fdh             %d          \n", produit[i].code, produit[i].nom, produit[i].prix,produit[i].prixTTC , produit[i].quantite);
    printf("  -------------------------------------------------------------------------------\n" );    
           
    }
     
}

void triProduitAlphabet(void)
{
    Produit p;
    for (int i = 0; i < np; i++)
    { 
        for (int j = i + 1; j < np; j++)// i+1 pour minimiser 
        {
            if (strcmp(produit[i].nom, produit[j].nom) == 1)//>0
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
    Produit p;
    for (int i = 0; i < np ; i++)
    {
        for (int j = i + 1; j < np; j++)
        {
            if (produit[i].prix < produit[j].prix)
            {
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
    printf(" *1 : chercher avec le code de produit :*\n");
    printf("----------------------------------------------\n");
    printf("Donner le code du produit que vous cherchez: ");
    scanf("%d", &c);
    for (i = 0; i < np; i++)
    {
        if (produit[i].code == c)
        {
        printf("  -------------------------------------------------------------------------------\n" );
        printf("  |     Code    |    Nom   |    Prix      |   Prix TTC  |  Quantite du produit |\n" );
        printf("  -------------------------------------------------------------------------------\n" );
            // printf("code    nom      prix      quantite \n");
        printf("       %d             %s        %.2fdh         %.2fdh              %d          \n", produit[i].code, produit[i].nom, produit[i].prix,produit[i].prixTTC, produit[i].quantite);
        printf("  -------------------------------------------------------------------------------\n" );    
            break;
        }
        
    }
}

void rechercheQuantite()
{
    int q, i;
    printf("----------------------------------------------\n");
    printf(" *2 : chercher avec la quantite du produit  :*\n");
    printf("----------------------------------------------\n");
    printf("Donner la quantite du produit que vous cherchez :");
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
    // time_t now;//structure time_t affiche temps actuelle 
    // time(&now);//initialiser
    // float prixproduits;
    time_t t = time(NULL);
  	struct tm* datee = localtime(&t);
    int i, code, quantite,count=0;

    printf("entrer le code du produit : ");
    scanf("%d", &code);

    printf("entrer la quantite du produit :");
    scanf("%d", &quantite);
    for (i = 0; i < np; i++)
    {
        if (produit[i].code == code)
        {
            if (produit[i].quantite >= quantite && quantite>0)
            {
                produit[i].quantite -= quantite;

                produitvendu[nbrpv].code = produit[i].code;
                strcpy(produitvendu[nbrpv].nom,produit[i].nom);
                produitvendu[nbrpv].prixTTC = produit[i].prixTTC;
                produitvendu[nbrpv].quantite = quantite;
                produitvendu[nbrpv].prixTotal = quantite * produit[i].prixTTC;

                produitvendu[nbrpv].d.day =datee->tm_mday ;
			    produitvendu[nbrpv].d.month =datee->tm_mon+1 ;
			    produitvendu[nbrpv].d.year =datee->tm_year+1900 ;
                printf(" %.2d/%.2d/%.2d\n",datee->tm_mday,datee->tm_mon+1,datee->tm_year+1900);

                nbrpv++;
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

    for( i = 0 ; i < nbrpv ; i++){
        printf("%d          %f         %d \n",produitvendu[i].code, produitvendu[i].prixTTC , produitvendu[i].quantite);
    }
}

void supprimer()
{
    int i, code, position;
    printf("supprimer un produit :\n");
    printf("donner le code du produit que vous voulez supprimer :");
    scanf("%d", &code);

    for (i = 0; i < np; i++)
    {
        if (code == produit[i].code)
        {
              position = i; //in position par lemplacement du produit quon veut supprimer
              break;
        }
    }
     for (i = position; i < np; i++)
        {
            produit[i] = produit[i + 1];//remplacer i par i+1
        }
    np--;
}

void alimenterStock()
{
    int i, code, quantite;
    printf("entre le code du produit :");
    scanf("%d", &code);
    printf("entre la quantite du produit :");
    scanf("%d", &quantite);
    for (i = 0; i < np; i++)
    {
        if (produit[i].code == code)
        {
            produit[i].quantite += quantite;
            break;
        }
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

void statistiques(){
    time_t t = time(NULL);
  	struct tm* datee = localtime(&t);
  	int jour = datee->tm_mday;
  	int mois = datee->tm_mon + 1;
  	int annee = datee->tm_year + 1900;
	float prixT = 0 , moyenne = 0 ;
    int i , Totalquantite=0;
    float min, max;
    //&&produitvendu[i].d.month==mois&&produitvendu[i].d.year==annee
     min = produitvendu[0].prixTotal;
     max = produitvendu[0].prixTotal;
    
    for(i=0;i<nbrpv ;i++)
    {
        if(produitvendu[i].d.day==jour&&produitvendu[i].d.month==mois&&produitvendu[i].d.year==annee)
        {
            prixT += produitvendu[i].prixTotal ; //somme prix produit vendu
            Totalquantite+=produitvendu[i].quantite;
            
        if(max < produitvendu[i].prixTotal)
        {
            max = produitvendu[i].prixTotal;
        }
         if(min > produitvendu[i].prixTotal)
        {
            min = produitvendu[i].prixTotal;
        }
        }
    }
    moyenne = prixT/(float)Totalquantite ;  //casting
    
    printf("le total des prix des produits vendus est = %.2f\n",prixT);
    printf("la moyenne des prix des produits vendus est = %.2f\n",moyenne);
    printf("le max des prix des produits vendus aujourd'hui  : %f\n",max);
    printf("le min des prix des produits vendus aujourd'hui  : %f\n",min);
   }

void menu()
{

printf("____Menu Pharmacie______\n");   
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
printf("| **12)pour afficher statistique :                                                            |\n");
printf("----------------------------------------------------------------------------------------------\n");   
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
        statistiques();
        goto debut;

        goto debut;
    default:
        printf("s'il vous plait entrer un nombre entre 1 et 12");
        break;
    }
}