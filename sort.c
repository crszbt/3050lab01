#include <cs3050.h>

void bubblesort(void *array, 
				size_t nitems, //number of items in the list
				size_t size, //size of each individual item in the memory
				int (*CompareFunc)(const void *, const void*)) //function for determining if items are in correct positions
{
	for (int i=0;i<nitems;i++) //for each item in the list...
	{
		for (int j=0;j<nitems-1;j++) //for each item in the list besides the last one...
		{
			void * item1 = array + j*size; //item1 points to the that item in the array
			void * item2 = array + (j+1)*size; //item2 points to the NEXT item in the array
			if (CompareFunc(item1,item2)>0) //if item1 and item two are in the incorrect positions...
			{
				Swap(item1,item2,size); //swap 'em!
			}
		}
	}
}

void insertionsort(void *array, 
				size_t nitems, //number of items in the list
				size_t size, //size of each individual item in the memory
				int (*CompareFunc)(const void *, const void*))
{
	for (int i=1;i<nitems;i++) //for each item in the list besides the first one...
	{
		void * item2 = array + j*size; //item2 points to the that item in the array
		void * item1 = array + (j-1)*size; //item1 points to the PREVIOUS item in the array
		while(CompareFunc(item1,item2)>0) //if item1 and item2 are in the incorrect positions...
		{
			Swap(item1,item2,size); //swap 'em!
			if(item1 != array) //if the backtracking hasn't reached the VERY start of the list
			{
				item2 = item1; //move the focus of item2 back by 1
				item1 = item2 - size; //move the focus of item1 back by 1
			}
		}
	}
}
