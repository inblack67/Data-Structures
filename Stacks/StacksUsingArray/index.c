#include <stdio.h>
#include <stdlib.h>

struct Stack
{
  int Top;
  int *S;
  int size;
};

void create(struct Stack *st)
{
  printf("Enter the size of the stack\n");
  scanf("%d", &st->size);
  st->Top = -1;
  st->S = (int *)malloc(st->size * sizeof(int));
}


void display(struct Stack st)
{
  for(int i=st.Top; i>=0; i--)
  {
    printf(" %d ",st.S[i]);   // values are inside the array of objects
    printf("\n");
  }
}

void push(struct Stack *st, int x)
{
  if(st->Top == st->size-1)
  {
    printf("Stack Overflow \n");
  }

  else
  {
    st->Top++;
    st->S[st->Top] = x;
  }
  
}

int pop(struct Stack *st)
{
  int x = -1;
  if(st->Top == -1)
  {
    printf("Stack Underflow \n");
  }
  else
  {
    x = st->S[st->Top];
    // x = st->S[st->Top--];
    st->Top--;
  }

  return x;
}

int peek(struct Stack st, int position)
{
  int x = -1;
  int index = st.Top - position + 1;
  if(index < 0)
  {
    printf("Invalid Position\n");
  }

  else
  {
    x = st.S[index];
  }
  

  return x;
}

int stackTop(struct Stack st)
{
  int x = -1;

  if(st.Top == -1)
  {
    printf("Stack is empty \n");
  }

  else
  {
    x = st.S[st.Top];
  }
  
  return x;
}

int isEmpty(struct Stack st)
{
  if(st.Top == -1)
  {
    return 1;
  }

  else
  {
    return 0;
  }
}

int isFull(struct Stack st)
{
  if(st.Top == st.size-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}


int main()
{
  struct Stack st;

  create(&st);

  push(&st,1);
  push(&st,2);
  push(&st,3);
  push(&st,4);
  push(&st,5);
  push(&st,6);

  display(st);

  // printf("popped %d \n",pop(&st));
  // printf("popped %d \n",pop(&st));
  // printf("popped %d \n",pop(&st));

  // printf("peeked %d \n",peek(st,1));
  // printf("peeked %d \n",peek(st,2));
  // printf("peeked %d \n",peek(st,3));
  // printf("peeked %d \n",peek(st,4));
  // printf("peeked %d \n",peek(st,5));
  // printf("peeked %d \n",peek(st,6));

  // printf("%d is at the top \n", stackTop(st));

  printf("is empty? %d \n", isEmpty(st));
  printf("is full? %d \n", isFull(st));



  return 0;
}