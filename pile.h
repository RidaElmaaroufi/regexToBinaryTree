#ifndef __PILE_H
#define __PILE_H


void push(char item);
char pop();
void InfixToPostfix(char infix_exp[], char postfix_exp[]);
int precedence(char symbole);

#endif
