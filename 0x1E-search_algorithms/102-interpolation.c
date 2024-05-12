#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array of integers using the Interpolation search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where value is located, or -1 if not found or array is NULL
 */
int interpolation_search(int *array, size_t size, int value) {
    size_t low = 0, high = size - 1, pos;

    if (!array)
        return (-1);

    while (low <= high && value >= array[low] && value <= array[high]) {
        // Calculate the probe position
        pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]));

        // Check if pos is within the bounds of the array
        if (pos >= size) {
            printf("Value checked array[%zu] is out of range\n", pos);
            break;
        }

        printf("Value checked array[%zu] = [%d]\n", pos, array[pos]);

        // If found, return the index
        if (array[pos] == value)
            return (int)pos;

        // Adjust the range based on the probe's result
        if (array[pos] < value)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return (-1);
}
