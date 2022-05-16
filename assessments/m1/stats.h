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
 * @file stats.h
 * @brief This file contains the various function prototypes used in the project
 *
 * 
 *
 * @author Dilip Gangwar
 * @date 9 April, 2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief A function that prints the statistics of an array including minimum, maximum,   mean, and median.
 *
 * @param A unsigned character array 
 * @param Integer size of the array
 *
 * @return It returns nothing
 */
 
void print_statistics(unsigned char [],int);
/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * @param A unsigned character array 
 * @param Integer size of the array
 *
 * @return It returns nothing
 */
 
void print_array(unsigned char [],int); 
/**
 * @brief Given an array of data and a length, This function returns the median value
 *
 * @param A unsigned character array 
 * @param Integer size of the array
 *
 * @return It returns median of float type  of the array
 */
 
float find_median(unsigned char [],int); 

/**
 * @brief Given an array of data and a length, This function returns the mean value
 *
 * @param A unsigned character array 
 * @param Integer size of the array
 *
 * @return It returns mean value of float type of the array
 */
float find_mean(unsigned char [],int);  

/**
 * @brief Given an array of data and a length, This function returns the maximum value
 *
 * @param A unsigned character array 
 * @param Integer size of the array
 *
 * @return It returns maximum array value of unsigned char
 */

 unsigned char find_maximum(unsigned char [],int); 

/**
 * @brief Given an array of data and a length, This function returns the minimum value
 *
 * @param A unsigned character array 
 * @param Integer size of the array
 *
 * @return It returns minimum array value of unsigned char
 */

unsigned char find_minimum(unsigned char [],int); 

/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest.  (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 * @param A unsigned character array 
 * @param Integer size of the array
 *
 * @return It returns nothing.
 */

void sort_array(unsigned char [],int); 


#endif /* __STATS_H__ */
