#include "SortingAlgo.h"
#include <limits.h>
#include <iostream>
#include <memory.h>
#include <time.h>
#include <stdlib.h>

void swap(int *element1, int *element2)
{
    int temp1 = *element1;
    int temp2 = *element2;
    *element1 = temp2;
    *element2 = temp1;
}

//O(n^2) average time
void bubbleSort(int *array, int size)
{
    for (int loop = 0; loop < size - 1; loop++)
        for (int loop2 = 0; loop2 < size -loop - 1; loop2++)
        {
            if (array[loop2] > array[loop2+1])
            {
                swap(&array[loop2], &array[loop2+1]);
            }
        } 
}

//O(n^2) Average time
void selectionSort(int *array, int size)
{
    for (int loop = 0; loop < size - 1; loop++)
    {
        int minValue = INT_MAX;
        int minValueElement = 0;
        for (int loop2 = loop; loop2 < size; loop2++)
        {
            if (array[loop2] < minValue)
            {
                minValue = array[loop2];
                minValueElement = loop2;
            }
        }
        swap(&array[loop], &array[minValueElement]);
    }
}

//O(n^2) average time
void insertionSort(int *array, int size)
{
    for (int loop = 1; loop < size; loop++)
    {
        int previousElement = loop - 1;
        int currElement = loop;
        while ((array[currElement] < array[previousElement]) && previousElement > 0)
        {
            swap(&array[currElement], &array[previousElement]);
            currElement = previousElement;
            previousElement--;
        }
    }   
}

/*****
 *  @Descrip Merge 2 sorted arrays into 1 sorted array
 *  @param leftarray left subarray
 *  @param rightArray right subarray
 *  @param int array the main array
 *  @param leftArraySize size of left subarray
 *  @param rightArraySize size of right subarray
 *  @param size size of main array
 *
 */
void merge(int *leftArray, int *rightArray, int *array, int leftArraySize, int rightArraySize, int size)
{
    //Current index of left, right, and main arrays
    int leftElement = 0;
    int rightElement = 0;
    int arrayElement = 0;

    //While both left and right arrays still have elements left, merge them
    while (leftElement < leftArraySize && rightElement < rightArraySize)
    {
        if (leftArray[leftElement] < rightArray[rightElement])
        {
            array[arrayElement] = leftArray[leftElement];
            arrayElement++;
            leftElement++;
        }
        else
        {
            array[arrayElement] = rightArray[rightElement];
            arrayElement++;
            rightElement++;
        }
    }  
    
    //When one of the subarrays runs out of elements, dump the other subarray into the main array
    while (leftElement < leftArraySize)
    {
        array[arrayElement] = leftArray[leftElement];
        arrayElement++;
        leftElement++;
    }

    while (rightElement < rightArraySize)
    {
        array[arrayElement] = rightArray[rightElement];
        arrayElement++;
        rightElement++;
    }
} 

//O(nlogn) average time
void mergeSort(int *array, int size)
{
    //exit case
    if (size <= 1)
    {
        return;
    }
    bool sizeOdd = false;

    if (size % 2 != 0)
    {
        sizeOdd = true;
    }

    int leftArraySize = size / 2;
    int *leftArray = new int[leftArraySize];
    int *rightArray = NULL;
    int rightArraySize = 0;

    //If size of array is odd, give right subarray the extra element
    if (sizeOdd == true)
    {
        rightArraySize = leftArraySize + 1;
    }
    else
    {
        rightArraySize = leftArraySize;
    }
    rightArray = new int[rightArraySize];

    memcpy(leftArray, array, leftArraySize*sizeof(int));
    memcpy(rightArray, array+leftArraySize, rightArraySize*sizeof(int));
  
    //Recursively divide the arrays
    mergeSort(leftArray, leftArraySize);
    mergeSort(rightArray, rightArraySize);
    
    //Merge the array
    merge(leftArray, rightArray, array, leftArraySize, rightArraySize, size);
   
    delete [] leftArray;
    delete [] rightArray; 
}

//Pivots the array so that elements valued less than pivot are to the left of it
//and elements valued greater than pivot are to the right
int pivot(int *array, int pivotIndex, int arrayStart, int arrayEnd)
{
    //Swap the selected pivot value with the end value, this makes pivoting easier without
    //sacrificing much computation time
    swap(&array[pivotIndex], &array[arrayEnd]);

    //Start the index 1 less than start of array, this counts how many elements have already been pivoted
    int alreadySortedIndex = arrayStart - 1;
    for (int loop = arrayStart; loop < arrayEnd; loop++)
    {
        if (array[loop] <= array[arrayEnd]) 
        {
            alreadySortedIndex++;
            swap(&array[loop], &array[alreadySortedIndex]);
        }   
    }
    alreadySortedIndex++;
    swap(&array[alreadySortedIndex], &array[arrayEnd]);
    pivotIndex = alreadySortedIndex;

    //return new index of pivot value to the caller
    return pivotIndex;
}

//Random pivot quicksort, O(nlogn) average can be O(n^2) worst case if pivot is badly chosen,
//Choosing pivot randomly minimizes this risk
void quickSort(int *array, int arrayStart, int arrayEnd)
{
    //Exit condition
    if (arrayStart == arrayEnd)
    {
        return;
    }
    srand(time(NULL));
    int pivotIndex =  (rand() % (arrayEnd - arrayStart + 1) + arrayStart);

    pivotIndex = pivot(array, pivotIndex, arrayStart, arrayEnd);

    //If statements to prevent seg faults
    if (pivotIndex != arrayStart)
    {
        quickSort(array, arrayStart, pivotIndex - 1);
    }
  
    if (pivotIndex != arrayEnd)
    {
        quickSort(array, pivotIndex + 1, arrayEnd);
    }  
}





