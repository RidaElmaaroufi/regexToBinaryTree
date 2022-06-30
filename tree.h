#ifndef __TREE_H
#define __TREE_H
#include<stdio.h>
#include<ctype.h>  //pour les fonctions isalpha et isdigit
#define SIZE 100
struct node{
	int data;
	struct node *right,*left;
	struct node *next;//ce pointeur pour assurer les operation du pile(push() et pop())
};


 struct node *head=NULL;
//creation de nouveau noeud
struct node* newNode(char data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
     
    return (node);
}

// affichage de l'arbre
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    else{

    printInorder(node->left);
 
    /* afficher donnée du noeud */
    printf("%c ", node->data);
 
    printInorder(node->right);
    }
}

void push2(struct node* x)
{
    if(head==NULL)
    head = x;
    else
    {
        (x)->next = head;
        head  = x;
    }
    // struct node* temp;
    // while(temp!=NULL)
    // {
    //     printf("%c ", temp->data);
    //     temp = temp->next;
    // }
}

struct node* pop2()
{
    struct node* p = head;
    
    head = head->next;
    return p;
}

int is_operator(char symbole)
{
	if( symbole == '*' || symbole == '|' || symbole == '.')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}


struct node *treeFromPostfix(char postfix_exp[]){
	char temp;
	int i=0;
	struct node *newnode;
	temp = postfix_exp[i];
	while(temp != '\0'){
		if(temp=='a' || temp=='b'){
			newnode = newNode(temp);
			push2(newnode);
		}
		else if(is_operator(temp)){
			newnode = newNode(temp);
			newnode->right = pop2();
			newnode->left = pop2();
			push2(newnode);
		}
		else{
			printf("error! Please verify your postfix expression");
			exit(1);
		}
		i++;
		temp = postfix_exp[i];
	}
	return newnode;
	
}





#endif
