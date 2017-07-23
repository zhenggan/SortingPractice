#include <iostream>
#include "SortingAlgo.h"
#include <cstdlib>

int main(int argc, char* argv[])
{
    if (argc == 1)
    {	
	std::cout<<"Please enter the sort you want plus the array" << std::endl;
        return -1;	
    }
    
    int sortSelect = atoi(argv[1]);
    int sizeofArray = argc - 2; //first argument is program name, 2nd is which sort to use, then the next
                                //arguments are the array elements
    int *array = new int[sizeofArray];
    for (int loop = 0; loop < sizeofArray; loop++)
    { 
        array[loop] = atoi(argv[loop+2]);
    }
    
    std::cout<< "Unsorted: ";
    for (int loop = 0; loop < sizeofArray; loop++)
    {
        std::cout << array[loop] << " ";
    }
    std::cout<< std::endl;

    //Select which sort to use
    //TODO: Update to be switch statement
    if (sortSelect == 1)
    {
        bubbleSort(array, sizeofArray);
    }
    else if (sortSelect == 2)
    {
        selectionSort(array, sizeofArray);
    }
    else if (sortSelect == 3)
    {
        insertionSort(array, sizeofArray);
    }
    else
    {
        std::cout << "Please select a valid sort option" << std::endl;
        return -1;
    }
    std::cout<< "Sorted: ";
    for (int loop = 0; loop < sizeofArray; loop++)
    {
        std::cout << array[loop] << " ";
    }
    std::cout<< std::endl;
    
    
    return 0;

}
