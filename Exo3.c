#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct element {
	int val;
	struct element* suivant;
};

typedef struct element Element;
typedef struct element* Liste;

Liste creer_liste_vide(){
	
	return NULL;
}

int test_liste_vide(Liste l){
	
	return l == NULL ; 
}

void affiche_liste(Liste l){
	 
	 if( !test_liste_vide(l) ) {
		 printf("%d \n", l->val);
		 affiche_liste(l->suivant); 
	 }
}

Liste ajout_debut(Liste l, int v){
	
	Liste p = malloc(sizeof(Element));
	
	p->val = v ;
	p->suivant = l ;
	
	return p;
}


Liste ajout_fin(Liste l, int v){
	
	Liste tmp = l;
	
	Liste p = malloc(sizeof(Element));
	while(tmp->suivant != NULL){ tmp = tmp-> suivant; }
	tmp -> suivant = p;
	p -> val = v;
	p -> suivant = NULL;
	
	return l;
}

int test_tri(Liste l){
	
	int a,b;
	
	a = l->val ;
	l = l->suivant ; 
	b = l->val;
	
	l = l->suivant;
	
	while( !test_liste_vide(l) ) {
		if( a<b ) {
			if (l->val < b) {return 0;}
		}
		else{
			if (l->val > b) {return 0;}
		}
		l = l->suivant;
		}
		
		return 1;
}

Liste ajout_trie(Liste l, int v){
	
	if( test_liste_vide(l) || v<= l->val) return ajout_debut(l,v);
	
	l->suivant = ajout_trie(l->suivant,v);
	
	return l;
}

Liste ajout_elem_alea(Liste l, int n){
	
	int m = rand(n);
	
	while( m != 0 ) {
		 l = ajout_debut(l, m);
	 }
	 
	 return l;
}

int main() {
	
	srand(time(NULL));
	Liste l;
	
	l = creer_liste_vide();
	
	l = ajout_debut(l,1);
	l = ajout_fin(l,2);
	l = ajout_fin(l,3);
	l = ajout_fin(l,4);
	
	affiche_liste(l);
	
	printf(" \n \n %d \n", test_tri(l) );
	
	return 0;
}
