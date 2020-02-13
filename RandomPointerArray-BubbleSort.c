#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void initalize_array(int *pointer, int size);
void print_array(int *pointer, int size);
int check_size(int size);
float mean(int *pointer, int size);
float median (int *pointer, int size);
void sort (int *pointer, int size);
float standard_deviation(int *pointer, int size);

#define MAX 50

int main (void){
	
	srand(time(NULL));
	int a[MAX];//Creates array with size 50
	int *p;
	p=a;
	int size;

	printf("\nEnter the size of the array to be created: ");
	scanf("%d", &size);
	while (check_size(size)==0){
		printf("Invalid input enter the size of the array 1-50: ");
		scanf("%d", &size);
	}
	initalize_array(p, size);
	print_array(p, size);
	sort(p, size);
	float middle = median(p, size);
	printf("\n\nMedian of the array is %.2f\n\n", middle);
	float deviate = standard_deviation(p, size);
	printf("Standard deviation is %.2f\n\n", deviate);
return 0; 
}

void initalize_array(int *pointer, int size){// Initalize array
	int i;
	for(i=0; i<size; i++) {
		*pointer = (rand()%9)+1;
		pointer++;
	}
}// End of initalize array

void print_array(int *pointer, int size){// Print array
	int i;
	for (i=0; i<size; i++){
		printf("%d", *pointer);
		pointer++;
	}

}// End of print array

int check_size(int size){// Check Size
	if (size<=MAX && size>0){
		return 1;
	}
	return 0;
}// End of check size

float mean(int *pointer, int size){// Mean
	int i;
	float average=0;
	for (i=0; i<size; i++){
		average += *pointer; 
		pointer++;
	}
	average = average / size;
	return average;
}// End of mean

float median (int *pointer, int size){// Median
	float mid=0;
	float middle=0;
	if (size%2==0){// Even size
		mid = size/2-.5;
		middle = (*(pointer +(int) mid)+ *(pointer +(int) (mid + 1)))/2;
	}
	else{// Odd size
		mid = size/2;
		middle = *(pointer + (int) mid);
	}
	return middle;
}// End of Median

void sort (int *pointer, int size){// Sort 
	int i, j, temp;
	temp = 0;
	for (i=0; i<size-1; i++){// Bubble sort with pointers
		for (j=0; j<size-i-1; j++){
			if (*(pointer+j) > *(pointer+j+1)){
				temp = *(pointer+j);
				*(pointer+j) = *(pointer+j+1);
				*(pointer+j+1) = temp;
			}
		}
	}// End of bubble sort
	printf("\n\nSorted array\n");// Prints sorted array
	for (i=0; i<size; i++){
		printf("%d", *pointer);
		pointer++;
	}
}// End of Sort

float standard_deviation(int *pointer, int size){// Standard Deviation
	int i; 
	float deviation = 0;
	float average = mean (pointer, size);
	float total = 0;
	for (i=0; i<size; i++){
		total += pow(average - *(pointer+i),2);
	}
	deviation = sqrt(total / (size-1));
	return deviation;
}// End of Standard Deviation
