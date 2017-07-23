#include "SortingAlgo.h"
#include <limits.h>
#include <iostream>

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

//
void mergeSort(int *array, int size)
{

}







