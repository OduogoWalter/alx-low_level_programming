#include <stdio.h>
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
 * binary_search - Searches for a value in a sorted array of integers using the Binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if not found or array is NULL
 */
int binary_search(int *array, size_t size, int value) {
    size_t left = 0;
    size_t right = size - 1;
    size_t mid;

    if (array == NULL) {
        return -1;
    }

    while (left <= right) {
        print_array(array, left, right);
        mid = left + (right - left) / 2;

        if (array[mid] == value) {
            return (int)mid;
        } else if (array[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}