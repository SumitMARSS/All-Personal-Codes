#include <iostream>
#include <pthread.h>

// Global variables
const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int sortedArr[MAX_SIZE];

// Structure to pass parameters to sorting threads
struct ThreadData
{
  int startIndex;
  int endIndex;
};

// Function to merge two sorted subarrays into a single sorted array
void merge(int startIndex, int midIndex, int endIndex)
{
  int i = startIndex;
  int j = midIndex + 1;
  int k = startIndex;

  while (i <= midIndex && j <= endIndex)
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

  while (i <= midIndex)
  {
    sortedArr[k] = arr[i];
    i++;
    k++;
  }

  while (j <= endIndex)
  {
    sortedArr[k] = arr[j];
    j++;
    k++;
  }

  for (int p = startIndex; p <= endIndex; p++)
  {
    arr[p] = sortedArr[p];
  }
}

// Merge sort function
void *mergeSort(void *arg)
{
  ThreadData *data = (ThreadData *)arg;
  int startIndex = data->startIndex;
  int endIndex = data->endIndex;

  if (startIndex < endIndex)
  {
    int midIndex = startIndex + (endIndex - startIndex) / 2;

    // Create two separate threads for sorting each sublist
    pthread_t tid1, tid2;

    // Parameters for the left sublist
    ThreadData leftData;
    leftData.startIndex = startIndex;
    leftData.endIndex = midIndex;

    // Parameters for the right sublist
    ThreadData rightData;
    rightData.startIndex = midIndex + 1;
    rightData.endIndex = endIndex;

    // Create two threads for sorting the sublists
    pthread_create(&tid1, NULL, mergeSort, (void *)&leftData);
    pthread_create(&tid2, NULL, mergeSort, (void *)&rightData);

    // Wait for both threads to complete
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // Merge the sorted sublists
    merge(startIndex, midIndex, endIndex);
  }

  pthread_exit(NULL);
}

int main()
{
  int size;
  std::cout << "Enter the number of elements in the array: ";
  std::cin >> size;

  std::cout << "Enter the elements of the array: ";
  for (int i = 0; i < size; i++)
  {
    std::cin >> arr[i];
  }

  // Parameters for the initial sorting thread
  ThreadData data;
  data.startIndex = 0;
  data.endIndex = size - 1;

  // Create the initial sorting thread
  pthread_t tid;
  pthread_create(&tid, NULL, mergeSort, (void *)&data);

  // Wait for the sorting thread to complete
  pthread_join(tid, NULL);

  // Output the sorted array
  std::cout << "Sorted array: ";
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

void removeWhitespace(string &str)
{
    string::iterator end_pos = remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());
}
string toLowercase(const string &str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char c)
              { return tolower(c); });
    return result;
}
int main()
{
    string file1, file2;
    cout << "Enter the path of the first file: ";
    getline(cin, file1);

    cout << "Enter the path of the second file: ";
    getline(cin, file2);

    ifstream fileStream1(file1);
    ifstream fileStream2(file2);

    if (!fileStream1 || !fileStream2)
    {
        cerr << "Failed to open one or both files." << endl;
        return -1;
    }
    string line1, line2;
    int c = 0;
    int Total_Lines =0;
    while (getline(fileStream1, line1) && getline(fileStream2, line2))
    {
        removeWhitespace(line1);
        removeWhitespace(line2);
        line1 = toLowercase(line1);
        line2 = toLowercase(line2);
       ++Total_Lines;
        if (line1 == line2)
        {
            c++;
        }
    }
    while (getline(fileStream1, line1))
    {
        if (!line1.empty())
        {
            ++Total_Lines;
        }
    }
    while (getline(fileStream2, line2))
    {
        if (!line2.empty())
        {        
            ++Total_Lines;
        }
    }
    if (c >= 0)
    {
        cout << "Number of  same lines in both files: " << c << endl;
        cout << "Number of different lines in both files: " << Total_Lines - c << endl;
    }
    return 0;
}
*/