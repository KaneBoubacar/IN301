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
	
	if( !test_liste_vide(l) ){
	
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
	}
		return 1;
}

Liste ajout_trie(Liste l, int v){
	
	if( test_liste_vide(l) || v<= l->val) return ajout_debut(l,v);
	
	l->suivant = ajout_trie(l->suivant,v);
	
	return l;
}

Liste ajout_elem_alea(Liste l, int n){
	
	int m;
	
	 do{
		 m = rand()%n;		 
		 l = ajout_debut(l, m);
	 }while( m != 0 );
	 
	 return l;
}

int nombre_elem(Liste l){
	
	int n;
	n=0;
	
		
	while( l != NULL ){
		l=l->suivant;
		n++ ;
	}
	
	return n;
}

int recherche_elem(Liste l, int e){
	
	if ( !test_liste_vide(l)){
		
		while( e != l->val && l->suivant != NULL ){
			l = l-> suivant ;
		}
		if (e == l-> val ) return 1;
		else return 0;
	}
	else return 0;
}

Liste supprimer_elem(Liste l, int e){
	
	Liste tmp;
	
	if(test_liste_vide(l)) return l;
	
	l->suivant = supprimer_elem(l->suivant,e);
	
		if (e == l->val) {
			tmp = l->suivant ;
			free(l);
			l = tmp;
		}

	return l;
}

Liste concat_liste(Liste l1, Liste l2){
	
	if(test_liste_vide(l1)) return l2;
	if(test_liste_vide(l2)) return l1;
	
	Liste tmp;
	tmp = l1;
	
	while(l1->suivant != NULL) l1=l1->suivant;
	l1->suivant = l2;
	
	return tmp;
}

Liste concat_trie(Liste l1, Liste l2){
	
	if(test_liste_vide(l1)) return l2;
	if(test_liste_vide(l2)) return l1;
	
	if( l1 -> val < l2->val) {
		l1 -> suivant = concat_trie(l1->suivant,l2);
		return l1;
	}
	l2->suivant = concat_trie(l1, l2->suivant);
	return l2;
}

Liste triBulle(Liste l){
	int cont = 1;
	liste tmp = l;
	while (){
		cont = 0 ; l = tmp;
		while (!test_liste_videl) && !test_liste_vide(l->suivant){
			

int main() {
	
	srand(time(NULL));
	
	Liste l,p,lp;
	
	l = p = creer_liste_vide();
	
	l = ajout_trie(l, 6);
	l = ajout_trie(l, 4);
	l = ajout_trie(l, 1);
	
	p = ajout_trie(p,5);
	p = ajout_trie(p,2);
	p = ajout_trie(p,3);
	
	affiche_liste(l);
	printf("\n");
	
	affiche_liste(p);
	printf("\n");
	
	lp = concat_trie(l,p);
	
	affiche_liste(lp);
	printf("\n");
	return 0;
}
