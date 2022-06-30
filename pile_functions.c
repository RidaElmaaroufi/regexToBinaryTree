#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<string.h>
#include "pile.h"


#define SIZE 100


/* declaration du pile (stack) sous forme dun tableau et un entier top
qui va indiquer la sommet de la pile*/
char stack[SIZE];
int top = -1;

/* definition du push */

void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nstack overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

/* definition du pop */
char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack underflow: invalid infix expression");
		getchar();
		/* underflow may occur for invalid expression */
		/* where ( and ) are not matched */
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

int precedence(char symbole)
{
	if(symbole == '*')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbole == '.')
	{
		return(2);
	}
	else if(symbole == '|')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}



void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');                               /* push '(' onto stack */
	strcat(infix_exp,")");                  /* add ')' to infix expression */

	i=0;
	j=0;
	item=infix_exp[i];         /* initialize before loop*/

	while(item != '\0')        /* run loop till end of infix expression */
	{
		if(item == '(')
		{
			push(item);
		}
		else if(item=='a' || item=='b')//if(item=='a' || item=='b'
		{
			postfix_exp[j] = item;              /* add operand symbole to postfix expr */
			j++;
		}
		else if(is_operator(item) == 1)        /* means symbol is operator */
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  /* so pop all higher precendence operator and */
				j++;
				x = pop();                       /* add them to postfix expresion */
			}
			push(x);
			/* because just above while loop will terminate we have
			oppped one extra item
			for which condition fails and loop terminates, so that one*/

			push(item);                 /* push current oprerator symbol onto stack */
		}
		else if(item == ')')         /* if current symbol is ')' then */
		{
			x = pop();                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; /* go to next symbol of infix expression */
	} /* while loop ends here */
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0'; /* add sentinel else puts() fucntion */
	/* will print entire postfix[] array upto SIZE */

}
