#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_array - Helper function to print the current subarray being searched
 * @array: A pointer to the first element of the subarray
 * @left: The starting index of the subarray
 * @right: The ending index of the subarray
 */
void print_array(int *array, size_t left, size_t right) {
    printf("Searching in array: ");
    for (size_t i = left; i <= right; i++) {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");
}

/**
 * binary_search - Helper function to perform binary search on the subarray
 * @array: A pointer to the first element of the array to search in
 * @left: The left index of the subarray
 * @right: The right index of the subarray
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int binary_search(int *array, size_t left, size_t right, int value) {
    size_t mid;

    while (left <= right) {
        print_array(array, left, right);
        mid = left + (right - left) / 2;

        if (array[mid] == value)
            return (int)mid;
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

/**
 * exponential_search - Searches for a value in a sorted array of integers using the Exponential search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where value is located, or -1 if not found or array is NULL
 */
int exponential_search(int *array, size_t size, int value) {
    size_t bound = 1;

    if (!array)
        return (-1);

    // Exponential phase to find range
    while (bound < size && array[bound] < value) {
        printf("Value checked array[%zu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    // Apply binary search on the found range
    size_t left = bound / 2;
    size_t right = (bound < size) ? bound : size - 1;
    printf("Value found between indexes [%zu] and [%zu]\n", left, right);
    return binary_search(array, left, right, value);
}