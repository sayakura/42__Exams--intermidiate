/*
VOLUME_HISTOGRAM
Assignment name  : volume_histogram
Expected files   : volume_histogram.c
Allowed functions: None
--------------------------------------------------------------------------------
Implement a function which computes, for a given histogram (bar graph)
of positive integers, the volume of water it could hold if someone poured
water across the top.
Each histogram bar has width 1.
Your function must be declared as follows:
int    volume_histogram(int *histogram, int size);
Example 1:
With the following input:
int    histogram[] = {1, 0, 2, 0, 2};
int    size = 5;
('#' bars are the histogram. '.' is water)
           # . #
       # . # . #
       ---------
       1 0 2 0 2
The function here returns 3 (because there is 3 emplacement of water).
Example 2:
With the following input:
int    histogram[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
int    size = 16;
('#' bars are the histogram. '.' is water)
                 #
                 # . . . . #
           # . . # . . . . #
           # . . # . . # . #
           # . . # . . # . #
           # . . # . . # . # . #
       -------------------------------
       0 0 4 0 0 6 0 0 3 0 5 0 1 0 0 0
The function returns 26.
*/
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
int    volume_histogram(int *histogram, int size){
	if (size == 0)
		return (0);
	int	left[size], right[size];
	int let = 0;

	left[0] = histogram[0];
	for (int i = 1; i < size; i++){
		left[i] = max(left[i - 1], histogram[i]);
	}
	right[size - 1] = histogram[size - 1];
	for (int i = size - 2; i >= 0; i--)
		right[i] = max(right[i + 1], histogram[i]);
	
	for (int i = 0; i < size; i++)
	{
		let += min(left[i], right[i]) - histogram[i];
	}
	return (let);
}

/*
#include <stdio.h>
int		main(void)
{
	int arr[] = {1, 2};
	int size = 2;

	printf("%d\n", volume_histogram(arr, size));
}*/
