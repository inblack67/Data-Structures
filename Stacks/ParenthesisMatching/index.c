#include <stdio.h>
#include <stdlib.h>

struct Node
{
  char data;
  struct Node *next;
} *Top = NULL;

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
    printf(" %d ", p->data);
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

int isBalanced(char *exp)
{
  for(int i=0; exp[i]!='\0'; i++)
  {
    if(exp[i] == '(')
    {
      push(exp[i]);
    }
    else if(exp[i] == ')')
    {
      if(Top == NULL)   // empty stack
      {
        return -1;
      }
      pop();
    }
  }
  if(Top == NULL)
  {
    return 1;
  }
  else
  {
    return -1;
  }
  
}

int isBalancedTwo(char *exp)
{
  for(int i=0; exp[i]!='\0'; i++)
  {
    if(exp[i] == '(' || exp[i] == '{'  || exp[i] == '[')
    {
      push(exp[i]);
    }
    else if(exp[i] == ')' || exp[i] == '}'  || exp[i] == ']')
    {
      if(Top == NULL)   // empty stack
      {
        return -1;
      }
      pop();
    }
  }
  if(Top == NULL)
  {
    return 1;
  }
  else
  {
    return -1;
  }
  
}

int main()
{
  struct Node *st;

  char *exp = "{[(a+b)*(a-b)]})";

  // printf("isBalanced? %d\n",isBalanced(exp));
  printf("isBalanced? %d\n",isBalancedTwo(exp));


  return 0;
}