
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *malloc_ptr;
    int *calloc_ptr;
    int *realloc_ptr;

    /* 1. malloc() demonstration */
    printf("1. malloc() demonstration\n");

    malloc_ptr = (int *)malloc(5 * sizeof(int));

    if (malloc_ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        malloc_ptr[i] = (i + 1) * 10;
    }

    printf("Memory allocated using malloc():\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", malloc_ptr[i]);
    }

    printf("\n\n");

    /* 2. calloc() demonstration */
    printf("2. calloc() demonstration\n");

    calloc_ptr = (int *)calloc(5, sizeof(int));

    if (calloc_ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        free(malloc_ptr);
        return 1;
    }

    printf("Memory allocated using calloc():\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", calloc_ptr[i]);
    }

    printf("\n\n");

    /* 3. realloc() demonstration */
    printf("3. realloc() demonstration\n");

    realloc_ptr = (int *)realloc(malloc_ptr, 10 * sizeof(int));

    if (realloc_ptr == NULL)
    {
        printf("Memory reallocation failed.\n");
        free(malloc_ptr);
        free(calloc_ptr);
        return 1;
    }

    malloc_ptr = realloc_ptr;

    for (int i = 5; i < 10; i++)
    {
        malloc_ptr[i] = (i + 1) * 10;
    }

    printf("Memory after realloc():\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", malloc_ptr[i]);
    }

    printf("\n\n");

    /* 4. free() demonstration */
    printf("4. free() demonstration\n");

    free(malloc_ptr);
    free(calloc_ptr);

    printf("Allocated memory successfully released.\n");

    return 0;
}

