/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief This File Contains the definition of all functions specicified in stats.h
 *
 *
 * @author Dilip Gangwar
 * @date 9 April, 2022
 *
 */



#include <stdio.h>
#include <limits.h>
#include<stddef.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)


//Given an array of data and a length, prints the array to the screen
void print_array(unsigned char a[],int n){
    int i; 
    #if !defined (VERBOSE) && defined (HOST)
    #undef PRINTF
    #define PRINTF(...)  
    #endif 
    for(i=0;i<n;i++)
       printf("a[%d] = %d ",i,a[i]);
    printf("\n"); 
    #if defined (VERBOSE) && defined (HOST)
    #undef PRINTF 
    #define PRINTF(...) printf(__VA_ARGS__)
    #endif 
	
}

// A function that prints swaps 2 unsigned chars
void swap(unsigned char *a,unsigned char *b){
   unsigned char t=*a;
   *a=*b;
   *b=t;
}

/**
Given an array of data and a length, sorts the array from largest to smallest.  (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
*/
void sort_array(unsigned char test[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
      for(j=0;j<n-1-i;j++){
        if(test[j] < test[j+1]){
          swap(&test[j],&test[j+1]);
        }
      }
    }
}

 
// Given an array of data and a length, This function returns the median value
float find_median(unsigned char test[],int n){
   int i;
   unsigned char b[SIZE];
   for(i=0;i<n;i++)  //copy test[] into b[]. THis is done so that we do not modify test[]
       b[i]=test[i];
   sort_array(b,n);   // sort b[] and find median
   int x= (n/2)-1;
   int y= n/2;
   return (b[x]+b[y])/2.0;
}


// Given an array of data and a length, This function returns the mean value
float find_mean(unsigned char test[],int n){
    int i;
    float sum=0;
    for(i=0;i<n;i++)
       sum+=test[i];
    return sum/n;   
} 

//Given an array of data and a length, This function returns the maximum value
unsigned char find_maximum(unsigned char test[],int n){
    int max=INT_MIN,i;
    for(i=0;i<n;i++){
      if(test[i] > max)
         max=test[i];
    }
       
    return max;
}

//Given an array of data and a length, This function returns the minimum value
unsigned char find_minimum(unsigned char test[],int n){
   int min=INT_MAX,i;
    for(i=0;i<n;i++){
      if(test[i] < min)
         min=test[i];
    }
       
    return min;
}

// A function that prints the statistics of an array including minimum, maximum,   mean, and median.
void print_statistics(unsigned char test[],int n){
  printf("Median= %f\n",find_median(test,n));
  printf("Mean=%f\n",find_mean(test,n));
  printf("Maximum of array=%d\n",find_maximum(test,n));
  printf("Minimum of array=%d\n",find_minimum(test,n));
}

/*
int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  // Other Variable Declarations Go Here 
  // Statistics and Printing Functions Go Here 
  print_statistics(test,SIZE);
  printf("\nArray Before Sorting\n");
  print_array(test,SIZE);
  sort_array(test,SIZE);
  printf("\nArray After Sorting in Descending Order\n");
  print_array(test,SIZE);
  return 0; 
}
*/

