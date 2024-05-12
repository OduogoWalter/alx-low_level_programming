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
 * binary_search_recursive - Helper function to perform binary search recursively
 * @array: A pointer to the first element of the array to search in
 * @left: The left index of the subarray
 * @right: The right index of the subarray
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int binary_search_recursive(int *array, size_t left, size_t right, int value) {
    size_t mid;

    if (left > right)
        return -1;

    print_array(array, left, right);
    mid = left + (right - left) / 2;

    if (array[mid] < value)
        return binary_search_recursive(array, mid + 1, right, value);
    else if (array[mid] > value)
        return binary_search_recursive(array, left, mid - 1, value);
    else {
        // Check if this is the first occurrence
        if (mid == left || array[mid - 1] != value)
            return (int)mid;
        else
            return binary_search_recursive(array, left, mid - 1, value);
    }
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers using an advanced binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where value is located, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value) {
    if (!array || size == 0)
        return -1;

    return binary_search_recursive(array, 0, size - 1, value);
}
