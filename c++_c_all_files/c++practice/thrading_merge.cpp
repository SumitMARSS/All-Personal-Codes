#include <iostream>
#include <pthread.h>
#include <stdlib.h>
using namespace std;
#define max 100
int arr[max];
int sortedArr[max];
struct thread_data
{
    int start;
    int end;
};

void merge(int start, int mid, int end)
{
    int i = start, j = mid + 1 , k = start;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            sortedArr[k] = arr[i];
            i++;
        }
        else
        {
            sortedArr[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        sortedArr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        sortedArr[k] = arr[j];
        j++;
        k++;
    }
    for (int p = start; p <= end; p++)
    {
        arr[p] = sortedArr[p];
    }
}

void *mergeSort(void *arg)
{
    thread_data *data = (thread_data *)arg;
    int start = data->start;
    int end = data->end;

    if (start < end)
    {
        int mid = start + (end - start) / 2;
        pthread_t tid1, tid2;
        thread_data leftData;
        leftData.start = start;
        leftData.end = mid;
        thread_data rightData;
        rightData.start = mid + 1;
        rightData.end = end;
        //create seprate thread for left and right part
        pthread_create(&tid1, NULL, mergeSort, (void *)&leftData);
        pthread_create(&tid2, NULL, mergeSort, (void *)&rightData);
        //waiting for thread to complete
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);
        merge(start, mid, end);
    }
    pthread_exit(NULL);
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        arr[i]=rand()%15;
    }
    cout << "Randomly generated elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<"  ";
    }
    cout<<"\n";
    //passing argument in threads
    thread_data data;
    data.start = 0;
    data.end = n - 1;
    pthread_t tid;
    pthread_create(&tid, NULL, mergeSort, (void *)&data);
    pthread_join(tid, NULL);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}