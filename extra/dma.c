// Apple Question ( DMA)
// Given an n x n matrix, implement the following functions:
// Allocate Memory:
// Write a function to dynamically allocate memory for an n x n matrix.
// Take Input:
// Write a function to assign values to the allocated n x n matrix by taking input 
// from the user.
// First Diagonal Sum:
// Write a function to find the sum of the elements along the first diagonal (from 
// the top left to the bottom right) of the matrix.
// The function should return this sum as an integer.
// Second Diagonal Sum:
// Write a function to find the sum of the elements along the second diagonal (from 
// the top right to the bottom left) of the matrix.
// The function should return this sum as an integer.
// Example:
// Given the matrix:
// 1 2
// 3 4
// The first diagonal consists of elements 1 and 4. Its sum is 5.
// The second diagonal consists of elements 2 and 3. Its sum is 5.

#include<stdio.h>
// Allocate Memory:
int* allocateMemory(int r, int c) {
    int *arr = (int *)malloc((r*c)*sizeof(int));
    return arr;
}
// Take Input:

// First Diagonal Sum:

// Second Diagonal Sum: