#include <bits/stdc++.h>
using namespace std;

// // Merge function to merge two sorted subarrays into one sorted array
// void merge(vector<int>& arr, int left, int mid, int right) {
//     int leftSize = mid - left + 1;
//     int rightSize = right - mid;

//     // Create temporary arrays to hold the subarrays
//     vector<int> leftArr(leftSize);
//     vector<int> rightArr(rightSize);

//     // Copy data to temporary arrays
//     for (int i = 0; i < leftSize; ++i)
//         leftArr[i] = arr[left + i];
//     for (int j = 0; j < rightSize; ++j)
//         rightArr[j] = arr[mid + 1 + j];

//     // Merge the two subarrays back into the original array
//     int i = 0, j = 0, k = left;
//     while (i < leftSize && j < rightSize) {
//         if (leftArr[i] <= rightArr[j]) {
//             arr[k] = leftArr[i];
//             ++i;
//         } else {
//             arr[k] = rightArr[j];
//             ++j;
//         }
//         ++k;
//     }

//     // Copy the remaining elements of leftArr, if any
//     while (i < leftSize) {
//         arr[k] = leftArr[i];
//         ++i;
//         ++k;
//     }

//     // Copy the remaining elements of rightArr, if any
//     while (j < rightSize) {
//         arr[k] = rightArr[j];
//         ++j;
//         ++k;
//     }
// }

// // Merge Sort function
// void mergeSort(vector<int>& arr, int left, int right) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;

//         // Recursively sort the two halves
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);

//         // Merge the sorted halves
//         merge(arr, left, mid, right);
//     }
// }

// int main() {
//     vector<int> arr = {12, 11, 13, 5, 6,16,9,11, 7};

//     cout << "Original array: ";
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;

//     mergeSort(arr, 0, arr.size() - 1);

//     cout << "Sorted array: ";
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;
//     return 0;
// }



// void merge(int *arr,int start,int end){
//     int mid = start + (end - start)/2;
//     int len1 =  mid - start+1;
//     int len2 = end - mid ;
//     int *first = new int [len1];
//     int *second = new int [len2];

//     int main_index = start;
//     for (int i = 0; i < len1; i++)
//     {
//         first[i] = arr[main_index];
//         main_index++;
//     }
//     main_index = mid+1;
//     for (int i = 0; i < len2; i++)
//     {
//         second[i] = arr[main_index];
//         main_index++;
//     }

//     int j = 0;
//     int k = 0;
//     int start1 = start;
//     while (j < len1 && k < len2)
//     {
//         if (first[j] <= second[k])
//         {
//             arr[start1++] = first[j++];
//         }
//         else
//         {
//             arr[start1++] = second[k++];
//         }
//     }
//     while (j < len1)
//     {
//         arr[start1++] = first[j++];
//     }
//     while (k < len2)
//     {
//         arr[start1++] = second[k++];
//     }
//     delete []first;
//     delete []second;
// }

// void merge_sort_divide(int *arr,int start,int end){
//     if (start >= end)
//     {
//         return;
//     }
//     int mid = start + (end - start)/2;
//     //merge_sort left part divide 
//     merge_sort_divide(arr,start,mid);
//     //merge_sort right part divide 
//     merge_sort_divide(arr,mid+1,end);
//     //merge the array
//     merge(arr,start,end);
// }

// int main(){
//     int arr[] = {2,7,4,6,34,23,12,9};
//     merge_sort_divide(arr,0,7);
//     for (int i = 0; i < 8; i++)
//     {
//         cout<<*(arr+i)<<" ";
//     }cout<<endl;
// }


// //you can take mid inside also
// void merge(int *arr,int start,int mid,int end){

//     //length of 2 sorted list which we have to merge
//     int length1 = mid - start +1;
//     int length2 = end - mid ;
//     //2 dynamic array
//     int *first = new int [length1];
//     int *second = new int [length2];

//     //copy the array which is sorted
//     for (int i = 0; i < length1; i++)
//     {
//         first[i] = arr[start+i];
//     }
//     for (int j = 0; j < length2; j++)
//     {
//         second[j] = arr[mid+1+j];
//     }
//     //merging the sorted array
//     int a=0, b=0, k=start;
//     while (a<length1 && b<length2)
//     {
//         if (first[a] > second[b])
//         {
//             arr[k++] = second[b++];  //same as 181,182 line
//         }
//         else
//         {
//             arr[k++] = first[a++];
//         }
//     }
//     //if one side array is larger
//     while (a<length1)
//     {
//         arr[k++] = first[a++];
//     }
//     while (b<length2)
//     {
//         arr[k++] = second[b++];
//     }
//     delete[] first;
//     delete[] second;
// }

// void merge_sort(int *arr,int start,int end){
//     if (start >= end)
//     {
//         return;
//     }
//     int mid = start+ (end- start)/2;
//     merge_sort(arr,start,mid);
//     merge_sort(arr,mid+1,end);
//     merge(arr,start,mid,end);
// }

// int main(){

//     int arr[] = {2,6,5,43,34,12,8,56,4,11};

//     merge_sort(arr,0,9);

//     for (int i = 0; i < 10; i++)
//     {
//         cout<<arr[i]<<" ";
//     }cout<<endl;
// }

//inversion count
