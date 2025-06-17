#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle_array(int *arr, int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        // swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    int arr[100];
    for (int i = 0; i < 100; i++)
        arr[i] = i ;

    srand(time(NULL));  // 시드 초기화

    shuffle_array(arr, 100);

    for (int i = 0; i < 100; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
