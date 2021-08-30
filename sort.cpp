#include"sortAlgos.h"
#include<Windows.h>
#include <string>
using namespace std;


void bubbleSort(int* arr, int n)
{
    int comps = 0, swaps = 0;
    string AlgoUsed = "BUBBLE SORT";
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            comps++;
            if (arr[j] > arr[j + 1])
            {
                swaps++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                drawBars(arr, AlgoUsed, comps, swaps);
            }
        }
}

void selectionSort(int* arr, int n)
{
    int comps = 0, swaps = 0;
    string AlgoUsed = "SELECTION SORT";
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            comps++;
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swaps++;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        drawBars(arr, AlgoUsed, comps, swaps);
        Sleep(100);
    }
}

void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insertionSort(int* arr, int n)
{
    int comps = 0, swaps = 0;
    string AlgoUsed = "INSERTION SORT";

    for (int i = 1; i < n; ++i) {
        for (int j = i; j >= 1; j--)
        {
            comps++;
            if (arr[j] < arr[j - 1])
            {
                swaps++;
                swap(arr, j, j - 1);
                drawBars(arr, AlgoUsed, comps, swaps);
            }
            else break;
        }
        drawBars(arr, AlgoUsed, comps, swaps);
    }
}


void merge(int* arr, int const left, int const mid, int const right, int &comps, int &swaps)
{
    string AlgoUsed = "MERGE SORT";
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        comps++;
        swaps++; 
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            drawBars(arr, AlgoUsed, comps, swaps);
            Sleep(10);
        }
        else {
            comps++;
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            drawBars(arr, AlgoUsed, comps, swaps);
            Sleep(10);
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        swaps++; 
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        drawBars(arr, AlgoUsed, comps, swaps);
        Sleep(10);
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        swaps++; 
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        drawBars(arr, AlgoUsed, comps, swaps);
        Sleep(10);
    }

}
void mergeSortHelper(int* arr, int const begin, int const end, int &mcomps, int &mswaps)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSortHelper(arr, begin, mid, mcomps, mswaps);
    mergeSortHelper(arr, mid + 1, end,mcomps, mswaps);
    merge(arr, begin, mid, end, mcomps, mswaps);
}



void mergeSort(int* arr, int const begin, int const end)
{
    int mcomps = 0, mswaps = 0;
    mergeSortHelper(arr, begin, end,mcomps, mswaps); 
    mcomps = 0; 
    mswaps = 0; 
}


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int* arr, int low, int high, int &comps, int &swaps)
{
    char AlgoUsed[] = "QUICK SORT";
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        comps++; 
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            swaps++; 
        }
        drawBars(arr, AlgoUsed, comps, swaps);
        Sleep(10);
    }
    swaps++; 
    swap(&arr[i + 1], &arr[high]);
    drawBars(arr, AlgoUsed, comps, swaps);
    Sleep(10);
    return (i + 1);
}

void quickSortHelper(int* arr, int low, int high, int& qcomps, int& qswaps)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, qcomps, qswaps);
        quickSortHelper(arr, low, pi - 1, qcomps, qswaps);
        quickSortHelper(arr, pi + 1, high, qcomps, qswaps);
    }
}

void quickSort(int* arr, int low, int high)
{
    int qcomps = 0, qswaps = 0; 
    quickSortHelper(arr, low, high, qcomps, qswaps); 
    qcomps = 0; 
    qswaps = 0; 
}




void shellSort(int* arr, int n)
{
    int comps = 0, swaps = 0;
    char AlgoUsed[] = "SHELL SORT";
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                comps++;
                swaps++;
                arr[j] = arr[j - gap];
                drawBars(arr, AlgoUsed, comps, swaps);
                Sleep(10);
            }
            comps++;
            arr[j] = temp;
            if (j != i)
                swaps++;
            drawBars(arr, AlgoUsed, comps, swaps);
            Sleep(10);
        }
    }
}

