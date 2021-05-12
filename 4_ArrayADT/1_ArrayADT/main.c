#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size; //Stores the max size of array
    int length; //Stores the current length of the array
};

void Display(struct Array arr)
{
    int i;
    printf("Elements are: \n");

    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

void Append(struct Array *arr,int x)
{
    if(arr->length < arr->size)//Check if the current length of the array is less than max length. Only if it is append
    {
        arr->A[arr->length] = x; //Append x
        arr->length++;   //Increment the length by 1
    }



}

void Insert(struct Array *arr,int index,int x)
{
    if(index>=0 && index <= arr->length) //Check if the given index is valid or not i.e
    {
        for(int i=arr->length;i>index;i--) //Shift ith element to i+1 position. So as to make space for 'x' and 'index' position
        {
            arr->A[i]= arr->A[i-1];
        }
        arr->A[index] = x; //Insert x at 'index' position
        arr->length++; //Increment the length of array
    }
}

int Delete(struct Array *arr,int index)
{
    int x=0; //To hold deleted value

    if(index>=0 && index< arr->length) //Check if the index is valid
    {
        x = arr->A[index]; //obtain the current value at the given index

        for(int i=index;i<arr->length-1;i++) //Loop from given index position to (Length - 1) position
        {
            arr->A[i] = arr->A[i+1]; //Place i+1th element in ith position in the array
        }

        arr->length--; //Decrement the length

        return x; //Return the delete value
    }

    return 0; //Return 0 if the given index is invalid
}

int LinearSearch(struct Array arr, int key)
{
    int i;

    for(i=0;i<arr.length;i++)
    {
        if(key == arr.A[i])
        {
            return i; //If key is found return index
        }
    }

    return -1;  //REturn -1 if key is not found
}

int BinarySearch(struct Array arr, int key)
{
    int l,mid,h;
    l=0; //Set lower limit value
    h=arr.length - 1; //Set higher limit value

    while(l<=h)
    {
        mid = (l+h)/2;

        if(arr.A[mid] == key)
            return mid; //Key found. Return the index
        else if(key < arr.A[mid])
            h = mid-1; //Change higher limit value
        else
            l = mid +1; //Change lower limit value
    }
    return -1; //Key not found.
}

int Get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length) //Check if index is valid
        return arr.A[index];

    return -1; //Invalid Index
}

void Set(struct Array *arr, int index, int x)
{
    if(index>=0 && index < arr->length)
        arr->A[index] = x; //Set x in index i of array
}

int Max(struct Array arr)
{
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }

    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    int i;

    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min = arr.A[i];
    }

    return min;
}

int Sum(struct Array arr)
{
    int s=0;
    int i;

    for(i=0;i<arr.length;i++)
    {
        s+=arr.A[i];
    }
    return s;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i,j;

    B = (int *) malloc(arr->length * sizeof(int));

    for(i=arr->length-1,j=0;i>=0;i--,j++)
    {
        B[j] = arr->A[i];
    }
    for(i=0;i<arr->length;i++)
        arr->A[i] = B[i];

    free(B);
}

void InsertSort(struct Array *arr,int x)
{
    int i=arr->length-1; //Start the index from last

    if(arr->length == arr->size) //If length is equal to max size, it means there is not space to insert the element
    {
        return;
    }

    while(i>=0 && arr->A[i]>x)  //Keep iterating till A[i] is greater than the received 'x' or till end of array
    {
        arr->A[i+1] = arr->A[i]; //If true, place ith element in i+1 position
        i--;
    }

    arr->A[i+1] = x; //Insert x in (i+1)th position

    arr->length++; //Increment the length of array
}

int isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i] >> arr.A[i+1]) //Not sorted
        {
            return 0;
        }
    }
    return 1;
}

void Rearrange(struct Array *arr) //These function is used to rearrange all negative numbers
{
    int i,j,temp;
    i=0;
    j=arr->length - 1;

    //The logic is to start two indices. i at 0 and j at len-1. Increment i till positive number has been found and j till negative number has been found
    //Then swap their positions

    while(i<j)
    {
        while(arr->A[i]<0)
        {
            i++;
        }
        while(arr->A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            temp = arr->A[i];
            arr->A[i]=arr->A[j];
            arr->A[j]=temp;
        }
    }
}

struct Array * Merge(struct Array *arr1,struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }

    }

    for(;i<arr1->length;i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    for(;j<arr2->length;j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return(arr3);
}

struct Array * Union(struct Array *arr1,struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else //indicates both are equal
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }

    }

    for(;i<arr1->length;i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    for(;j<arr2->length;j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = k;
    arr3->size = 10;

    return(arr3);
}

struct Array * Intersection(struct Array *arr1,struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else //indicates both are equal
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }

    }


    arr3->length = k;
    arr3->size = 10;

    return(arr3);
}

struct Array * Difference(struct Array *arr1,struct Array *arr2)
{
    int i=0,j=0,k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else //indicates both are equal
        {
            i++;
            j++;
        }

    }

    for(;i<arr1->length;i++)
    {
        arr3->A[k++] = arr1->A[i];
    }


    arr3->length = k;
    arr3->size = 10;

    return(arr3);
}

int main()
{

    struct Array arr={{2,3,4,5,6},10,5}; //Structure initialization
    struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,6,7,15,20},10,5};
    struct Array *arr3;

    arr3 = Difference(&arr1,&arr2);

    Display(*arr3);


    free(arr3);
    return 0;
}
