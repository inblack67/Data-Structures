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

int precedence(char x)
{
  if(x=='+' || x=='-')
  {
    return 1;
  }
  if(x=='*' || x=='/')
  {
    return 2;
  }

  return 0;
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

char * infixToPostfix(char *infix)
{
  int i=0,j=0;
  long len = strlen(infix);
  char *postfix = (char *)malloc((len + 2)*sizeof(char)); // # and null

  while (infix[i] != '\0')
  {
    if(isOperand(infix[i]))
    {
      postfix[j++] = infix[i++];
    }
    else
    {
      if(precedence(infix[i]) > precedence(Top->data))
      {
        push(infix[i++]);
      }
      else
      {
        postfix[j++] = pop();
      }
    }
  }

  // copying the rest of the elements
  while (isEmpty())
  {
    postfix[j++] = pop();
  }


  postfix[j] = '\0';
  return postfix;
}

int main()
{
  struct Node *st;
  char *infix = "a+b*c-d/e";
  push('#');

  char *postfix = infixToPostfix(infix);
  printf(" %s ", postfix);


  return 0;
}