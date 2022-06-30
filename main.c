#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */
#include<string.h>
#include "pile.h"
#include "tree.h"

#define SIZE 100

int main()
{
	char infix[SIZE], postfix[SIZE];
	printf("\nSUPPOSITION: L'expression infixe contient uniquement les caracteres (a,b) et des symboles(\'|\' or \'*\' or \'.\'or \'+\').\n");
	printf("\nentrer votre expression régulière : ");
	gets(infix);

	InfixToPostfix(infix,postfix);                   
	printf("Expression Postfix : ");
	puts(postfix);                 
	
	
	struct node *tree;
	tree = (struct node*)malloc(sizeof(struct node));
	tree->next = (struct node*)malloc(sizeof(struct node));
	tree->left = (struct node*)malloc(sizeof(struct node));
	tree->right = (struct node*)malloc(sizeof(struct node));
	tree = treeFromPostfix(postfix);
	printf("l\'affichage de votre arbre est comme suit:");
	printInorder(tree);
	printf("\nOk");
}
