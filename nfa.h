#ifndef __TREE_H
#define __TREE_H
#include<stdio.h>
#include<ctype.h>  //pour les fonctions isalpha et isdigit
#define SIZE 100



struct node etat{
	int c;
	etat *sortie1;
	etat *sortie2;
	int dernier;
};

struct Frag
{
	State *start;//pointeur vers l'etat initial du fragment
	Ptrlist *out;//liste de pointeur sur les pointeurs des etats
};


//helpers
Ptrlist *list1(State **outp);//creates a new pointer list containing the single pointer outp
Ptrlist *append(Ptrlist *l1, Ptrlist *l2);//Append concatenates two pointer lists, returning the result

void patch(Ptrlist *l, State *s);//Patch connects the dangling arrows in the pointer list l to the state s: it sets *outp = s for each pointer outp in l



State*
post2nfa(char *postfix)
{
	char *p;
	Frag stack[1000], *stackp, e1, e2, e;
	State *s;

	#define push(s) *stackp++ = s
	#define pop()   *--stackp

	stackp = stack;
	for(p=postfix; *p; p++){
		switch(*p){
			case '.':
				e2 = pop();
				e1 = pop();
				patch(e1.out, e2.start);
				push(frag(e1.start, e2.out));
				break;
			case '|':
				e2 = pop();
				e1 = pop();
				s = state(Split, e1.start, e2.start);
				push(frag(s, append(e1.out, e2.out)));
				break;
			case '*':
				e = pop();
				s = state(Split, e.start, NULL);
				patch(e.out, s);
				push(frag(s, list1(&s->out1)));
				break;
			default:
				s = state(*p, NULL, NULL);
				push(frag(s, list1(&s->out));
				break;
		}
	}
	
	e = pop();
	patch(e.out, matchstate);
	return e.start;
}





#endif
