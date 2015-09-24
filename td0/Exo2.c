#include <stdio.h>

int main(){
	
	int n, h, m, s;
	
	s=0;
	scanf("%d", &n);
	
	h = (n/60)/60 ;
	m =  mod(3600);
	s = mod(60);
	printf(" %d secondes correspond à %d heure %d minutes \n", n, h, m);
	
	return 0;
}
