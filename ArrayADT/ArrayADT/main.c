//
//  main.c
//  ArrayADT
//
//  Created by Aman Bhardwaj on 11/22/19.
//  Copyright © 2019 Projects. All rights reserved.
//

// ArrayADT


#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        printf(" %d ", arr.A[i]);
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    
}

void maxmin(int A[], int n)
{
    int min = A[0];
    int max = A[0];
    for(int i=0; i<n; i++)
    {
        if(A[i]<min)
            min=A[i];
        else if(A[i]>max)
            max = A[i];
    }
    
    printf(" max -> %d, min -> %d ",max,min);
}

void max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max = arr.A[i];
    }
    
    printf(" max is %d ", max);
}

void sum(struct Array arr)
{
    int sum = 0;
    for(int i=0;i<arr.length;i++)
    {
        sum+=arr.A[i];
    }
    printf("sum of elements is %d",sum);
}

int recSum(struct Array arr, int n)
{
    if(n<0)
        return 0;
    return arr.A[n]+recSum(arr,n-1);
}

void append(struct Array *arr, int x)
{
    if(arr->length<arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

void insert(struct Array *arr,int x,int index)
{
    for(int i=arr->length-1;i>index;i--)
    {
        arr->A[i+1] = arr->A[i];
    }
    arr->A[index] = x;
}

void delete(struct Array *arr, int index)
{
    for(int i=index;i<arr->length;i++)
    {
        arr->A[i] = arr->A[i+1];
    }
}

int linearSearch(struct Array *arr, int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==key)
        {
            swap(&arr->A[i], &arr->A[i+1]);
            //swap(&arr->A[i], &arr->A[0]);
            return 1;

        }
    }
    return -1;
}

int binarySearch(struct Array arr,int low, int high, int key)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;
        if(arr.A[mid]==key)
            return mid;
        else if(key<arr.A[mid])
            return binarySearch(arr, low, mid-1, key);
        else
            return binarySearch(arr, mid+1, high, key);
    }
    
    return -1;
}

int get(struct Array arr, int index)
{
    if(index>0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void set(struct Array *arr, int index, int x)
{
    if(index>=0 && index<arr->A[arr->length])
        arr->A[index]=x;
}

void duplicates(int A[], int n)
{
    int lastDeuplicate = 0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==A[i+1] && lastDeuplicate!=A[i])
        {
            printf(" %d ",A[i]);
            lastDeuplicate=A[i];
        }
    }
    
}

void countDuplicates(int A[], int n)
{
    int i,j;

    for(i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1])
        {
            j=i+1;
            while(A[j]==A[i])
                j++;
            printf(" %d, %d times",A[i],j-i);
            i=j-1;
        }
    }

}

void unsortedDuplicates(int A[], int n)
{
    int H[10] = {0};
    
    for(int i=0; i<n; i++)
    {
        H[A[i]]++;
    }
    
    for(int i=0;i<8;i++)
    {
        if(H[i]>1)
            printf(" %d -> %d times ", i, H[i]);
    }
}

void pairSum(int A[], int n, int k)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=1+1;j<n;j++)
        {
            if(A[i]+A[j]==k)
            {
                printf(" %d + %d = %d \n",A[i],A[j],k);
            }
        }
    }
}

void Hpairsum(int A[], int n, int k)
{
    int H[20] = {0};
    for(int i=0;i<n;i++)
    {
        if(H[k-A[i]]!=0)
            printf(" %d + %d = %d \n",A[i],H[k-A[i]],k);
        H[A[i]]++;
    }
}

void reverse(struct Array *arr)
{
    for(int i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void auxrev(struct Array *arr)
{
    int b[arr->length];
    for(int i=arr->length-1,j=0;i>=0;i--,j++)
    {
        b[j] = arr->A[i];
    }
    
    for(int i=0; i<arr->length;i++)
    {
        arr->A[i] = b[i];
    }
}

void sortedInsert(struct Array *arr,int x)
{
    int i=arr->length-1;
    while(arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
}

void negativeLHS(struct Array *arr)
{
    for(int i=0,j=arr->length-1;i<j;i++,j--)
    {
        if(arr->A[i]>arr->A[j])
            swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array * merge(struct Array *arr1, struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for(;j<arr2->length;j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    
    arr3->length = arr1->length+arr2->length;
    arr3->size = arr1->size+arr2->size;

    return arr3;
}


int main()
{
    struct Array arr = {{1,2,3,4,5},10,5};
    struct Array arr2 = {{6,7,8,9,10},10,5};
    struct Array *arr3;
    arr3 = merge(&arr,&arr2);
    display(*arr3);

    //negativeLHS(&arr2);
    //sortedInsert(&arr,18);
    //printf(" %d ", recSum(arr,arr.length));
    //reverse(&arr);
    //auxrev(&arr);
    //sum(arr);
    //append(&arr,6);
    //insert(&arr,67,1);
    //max(arr);
    //delete(&arr,1);
    //printf(" %d ",linearSearch(&arr, 4));
    //int binaryResult = binarySearch(arr, 0, arr.length-1, 4);
    //int getResult = get(arr, 4);
    //set(&arr, 3, 69);
    //display(arr);
    //int A[10] = {3,6,8,8,10,12,15,15,15,20};
    //int B[10] = {6,3,8,10,16,7,5,2,9,14};
    //maxmin(B, 10);
    //duplicates(A, 10);
    //countDuplicates(A, 10);
    //unsortedDuplicates(B, 10);
    //Hpairsum(B, 10, 10);

    return 0;
}
