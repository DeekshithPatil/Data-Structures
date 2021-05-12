#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

class Array
{
private:

    int A[10];
    int size; //Stores the max size of array
    int length; //Stores the current length of the array

public:
    Array()
    {
        size=10;
        length=0;
    }


void Display()
{
    int i;
    printf("Elements are: \n");

    for(i=0;i<length;i++)
        printf("%d ",A[i]);
}

void Append(int x)
{
    if(length < size)//Check if the current length of the array is less than max length. Only if it is append
    {
        A[length] = x; //Append x
        length++;   //Increment the length by 1
    }

}

void Insert(int index,int x)
{
    if(index>=0 && index <= length) //Check if the given index is valid or not i.e
    {
        for(int i=length;i>index;i--) //Shift ith element to i+1 position. So as to make space for 'x' and 'index' position
        {
            A[i]= A[i-1];
        }
        A[index] = x; //Insert x at 'index' position
        length++; //Increment the length of array
    }
}

int Delete(int index)
{
    int x=0; //To hold deleted value

    if(index>=0 && index< length) //Check if the index is valid
    {
        x = A[index]; //obtain the current value at the given index

        for(int i=index;i<length-1;i++) //Loop from given index position to (Length - 1) position
        {
            A[i] = A[i+1]; //Place i+1th element in ith position in the array
        }

        length--; //Decrement the length

        return x; //Return the delete value
    }

    return 0; //Return 0 if the given index is invalid
}

int LinearSearch(int key)
{
    int i;

    for(i=0;i<length;i++)
    {
        if(key == A[i])
        {
            return i; //If key is found return index
        }
    }

    return -1;  //REturn -1 if key is not found
}

int BinarySearch( int key)
{
    int l,mid,h;
    l=0; //Set lower limit value
    h=length - 1; //Set higher limit value

    while(l<=h)
    {
        mid = (l+h)/2;

        if(A[mid] == key)
            return mid; //Key found. Return the index
        else if(key < A[mid])
            h = mid-1; //Change higher limit value
        else
            l = mid +1; //Change lower limit value
    }
    return -1; //Key not found.
}

int Get(int index)
{
    if(index>=0 && index<length) //Check if index is valid
        return A[index];

    return -1; //Invalid Index
}

void Set(int index, int x)
{
    if(index>=0 && index < length)
        A[index] = x; //Set x in index i of array
}

int Max()
{
    int max=A[0];
    int i;
    for(i=1;i<length;i++)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }

    return max;
}

int Min()
{
    int min = A[0];
    int i;

    for(i=1;i<length;i++)
    {
        if(A[i]<min)
            min = A[i];
    }

    return min;
}

int Sum()
{
    int s=0;
    int i;

    for(i=0;i<length;i++)
    {
        s+=A[i];
    }
    return s;
}

float Avg()
{
    return (float)Sum() / length;
}

void Reverse()
{
    int *B;
    int i,j;

    B = (int *) malloc(length * sizeof(int));

    for(i=length-1,j=0;i>=0;i--,j++)
    {
        B[j] = A[i];
    }
    for(i=0;i<length;i++)
        A[i] = B[i];

    free(B);
}

void InsertSort(int x)
{
    int i=length-1; //Start the index from last

    if(length == size) //If length is equal to max size, it means there is not space to insert the element
    {
        return;
    }

    while(i>=0 && A[i]>x)  //Keep iterating till A[i] is greater than the received 'x' or till end of array
    {
        A[i+1] = A[i]; //If true, place ith element in i+1 position
        i--;
    }

    A[i+1] = x; //Insert x in (i+1)th position

    length++; //Increment the length of array
}

int isSorted()
{
    int i;
    for(i=0;i<length-1;i++)
    {
        if(A[i] >> A[i+1]) //Not sorted
        {
            return 0;
        }
    }
    return 1;
}

void Rearrange() //These function is used to rearrange all negative numbers
{
    int i,j,temp;
    i=0;
    j=length - 1;

    //The logic is to start two indices. i at 0 and j at len-1. Increment i till positive number has been found and j till negative number has been found
    //Then swap their positions

    while(i<j)
    {
        while(A[i]<0)
        {
            i++;
        }
        while(A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            temp = A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
}

struct Array * Merge(struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<length && j<arr2->length)
    {
        if(A[i] < arr2->A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }

    }

    for(;i<length;i++)
    {
        arr3->A[k++] = A[i];
    }

    for(;j<arr2->length;j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = length + arr2->length;
    arr3->size = 10;

    return(arr3);
}

struct Array * Union(struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<length && j<arr2->length)
    {
        if(A[i] < arr2->A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else if(arr2->A[j] < A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else //indicates both are equal
        {
            arr3->A[k++] = A[i++];
            j++;
        }

    }

    for(;i<length;i++)
    {
        arr3->A[k++] = A[i];
    }

    for(;j<arr2->length;j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = k;
    arr3->size = 10;

    return(arr3);
}

struct Array * Intersection(struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<length && j<arr2->length)
    {
        if(A[i] < arr2->A[j])
        {
            i++;
        }
        else if(arr2->A[j] < A[i])
        {
            j++;
        }
        else //indicates both are equal
        {
            arr3->A[k++] = A[i++];
            j++;
        }

    }


    arr3->length = k;
    arr3->size = 10;

    return(arr3);
}

struct Array * Difference(struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<length && j<arr2->length)
    {
        if(A[i] < arr2->A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else if(arr2->A[j] < A[i])
        {
            j++;
        }
        else //indicates both are equal
        {
            i++;
            j++;
        }

    }

    for(;i<length;i++)
    {
        arr3->A[k++] = A[i];
    }


    arr3->length = k;
    arr3->size = 10;

    return(arr3);
}
};

int main()
{
    Array a1;
    a1.Append(3);
    a1.Display();
    return 0;
}

