#include<stdio.h>
#include<stdlib.h>

int binarySearch(int first, int last, int array[], int searchValue);

int main(int argc, char const *argv[])
{
	int myArray[] = {5,7,9,13,32,33,42,54,56,88};
	int first, last, mid, searchValue;

	printf("Enter your search value: ");
	scanf("%d", &searchValue);

	int n = sizeof(myArray)/sizeof(myArray[0]);

	int searchResult = binarySearch(0, n-1, myArray, searchValue);

	if (searchResult != -1)
	{
		/* code */
		printf("Value found at index %d\n", searchResult);
	}
	else{
		printf("Value not found in the array\n");
	}
}


int binarySearch(int first, int last, int array[], int searchValue){
	while(first<=last){
		int mid = (first+last)/2;

		if (searchValue == array[mid]){
			/* code */
			return mid;
		}

		if (searchValue > array[mid]){
			/* code */
			first = mid+1;
		}
		else{
			last = mid-1;
		}
	}

	return -1;
}








