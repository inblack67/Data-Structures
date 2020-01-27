#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  char data;
  struct Node *next;
} *Top = NULL;


int isEmpty()
{
  if(Top==NULL)
  {
    return 0;
  }
  else
  {
    return 1;
  }
  
}

void push(char x)
{
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));

  if (t == NULL) // node is not created
  {
    printf("Stack Overflow \n");
  }
  else
  {
    t->data = x;
    t->next = Top;
    Top = t;
  }
}

void display()
{
  struct Node *p;
  p = Top;
  while (p)
  {
    printf(" %c ", p->data);
    p = p->next;
  }
}

int pop()
{
  int x = -1;

  struct Node *p;

  if (Top == NULL)
  {
    printf("Stack Underflow");
  }

  else
  {
    p = Top;
    Top = Top->next;
    x = p->data;
    free(p);
  }

  return x;
}



int isOperand(char x)
{
  if(x=='+' || x=='-' || x=='*' || x=='/')
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

int evluatePostfix(char *postfix)
{
  int i, result, x1, x2;
  for(i=0; postfix[i] != '\0'; i++)
  {
    if(isOperand(postfix[i]))
    {
      push(postfix[i] - '0');
    }
    else
    {
      x2 = pop();
      x1 = pop();

      switch (postfix[i])
      {
        case '+': result = x1+x2;
        break;

        case '-': result = x1-x2;
        break;

        case '*': result = x1*x2;
        break;

        case '/': result = x1/x2;
        break;
      }
      push(result);
    }
  }

  return Top->data;
}

int main()
{

  char *postfixEval = "35*62/+4-";

  int evaluatedPostfix = evluatePostfix(postfixEval);
  printf("Evaluated Postfix = %d \n", evaluatedPostfix);

  return 0;
}