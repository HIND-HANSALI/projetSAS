#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

//sructure
typedef struct Produit{
    int code;
    char nom[50];
    int quantite;
    float prix;
    float prixTTC;

}Produit;
Produit produit[100];
int np=0;
void ajouterproduit(){
    printf("\nentrer le code du produit :");
    scanf("%d",&produit[np].code);
    printf("entrer le nom du produit :");
    scanf("%s",&produit[np].nom);
    printf("entrer la quantite du produit :");
    scanf("%d",&produit[np].quantite);
    printf("entrer le prix du produit :");
    scanf("%f",&produit[np].prix);
    produit[np].prixTTC = produit[np].prix + (produit[np].prix * 0.15);
    printf("le prixTTC du produit : %.2f", produit[np].prixTTC);
    
    np++;
}
void ajouterPlusieurProduit(){
    int i ,nbr;
    printf("entrer le nombre de produit :");
    scanf("%d",&nbr);
    for(i=0;i<nbr;i++){
        ajouterproduit();
    }
}
void afficher(){
     int i; //nbr????
    for(i=0;i<np;i++){
        printf("nom de produit %s",produit[i].nom);
        printf("code de produit %d",produit[i].code);
        printf("quantite de produit %d",produit[i].quantite);
        printf("prix de produit %f",produit[i].prix);
        printf("prixttc de produit %f\n",produit[i].prixTTC);
        
    }
}
void alphabetcroissant(){
    int i,j;

    for(i=0;i<np;i++){
         for(j=i+1;j<np;j++){
            if(strcmp(produit[i].nom,produit[j].nom)>0){
                Produit zone;
                zone=produit[i];
                produit[i]=produit[j];
                produit[j]=zone;
            }
         }
    }
    afficher();
}
void prixdecroissant(){
    int i,j;

    for(i=0;i<np;i++){
         for(j=i+1;j<np;j++){
            if(produit[i].prix<produit[j].prix){
                Produit zone;
                zone=produit[i];
                produit[i]=produit[j];
                produit[j]=zone;
            }   
         }
   }
   afficher();
}
//void acheterProduit(){
//    int i,code,quantite;
//    afficher();
//    printf("Entrer le code  :");
//    scanf("%d",&code);
//    printf("Entrer la quantite  :");
//    scanf("%d",&quantite);
//
//    for(i=0;i<np;i++)
//    if(produit[i].code==code)
//    if(produit[i].quantite>quantite)
//    produit[i].quantite=quantite;
//    else  
//    printf("quantite insuffisante");
//    else
//    printf("produit introuvable");
//    }
void rechercherCode(){
	int i,nbr;
	bool isExist = false;
   printf("Entrer le code  :");
   scanf("%d",&nbr); 
   
   for(i=0; i < np; i++){
   		if(produit[i].code==nbr){
   			isExist = true;
   			
		   }
   }
   
   if(isExist)
   printf("ce produit existe");
   else
   printf("introuvable");
}






void menu(){
    printf("\n1-ajouter un nouveau produit\n");
    printf("2-ajouter plusieurs produits\n");
    printf("3-afficher un produit\n");
    printf("4-tri par alphabet\n");
    printf("5-tri par prix\n");
    printf("6-recherche\n");
    printf("7-acheter\n");
}

int main(){
    int choix;
    debut:
    menu();
    printf("entrer votre choix");
    scanf("%d", &choix);
    switch(choix){
        case 1: 
        printf("ajouter un nouveau produit");
        ajouterproduit();
        goto debut;
        case 2: 
        printf("ajouter plusieurs produits");
        ajouterPlusieurProduit();
        goto debut;
        case 3: 
        printf("afficher produit");
        afficher();
        goto debut;
        case 4: 
        printf("tri par alphabet");
        alphabetcroissant();
        goto debut;
        case 5: 
        printf("tri par prix");
        prixdecroissant();
        goto debut;
        case 6: 
        printf("recherche");
        rechercherCode();
        goto debut;
        case 7: 
        // printf("acheter");
        // acheterProduit();
        goto debut;
    }
    // ajouterproduit();
    //ajouterPlusieurProduit();

}