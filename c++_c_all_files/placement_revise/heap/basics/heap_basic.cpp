#include <iostream>
using namespace std;

class heap{
    public:
    int size;
    int arr[100];

    heap(){
        arr[0] = -1;
        size = 0;
    }
    // max heap
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index/2;
            //max heap chase
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    // min heap
    void insert_min_heap(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index/2;
            //max heap chase
            if (arr[index] < arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void delete_from_heap(){
        //base case
        if( size == 0 ){
            cout<<"Nothing to delete "<<endl;
            return;
        }
        //step - 1 write last node valve to root node see copy
        arr[1] = arr[size];
        //step - 2 remove the node
        size--;
        ///step - 3 move root node to its correct position
        int index=1;
        while ( index <= size )
        {
            int leftchild = index*2;
            int rigthchild = index*2 + 1;
            //making max heap
            if (leftchild < size && arr[leftchild] > arr[index])
            {
                swap( arr[leftchild], arr[index] );
                index = leftchild;
            }
            if ( rigthchild < size && arr[rigthchild] > arr[index])
            {
                swap( arr[rigthchild], arr[index] );
                index = rigthchild;
            }
            else
            {
                return;
            }
        }
    }

    void print(){
        cout<<" Your heap is -> ";
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
        
    }
};
//max heap
void heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    //largest means node we are processing 
    if (left <= size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr,size,largest);
        // or we can say
        // i = largest;
        // heapify(arr,size,i);
    }
    return;
}

//min heap 
// 1.   some problem please check with (left <= size) or something wrong but passed test cases in coding ninja
// void heapify(int arr[], int size, int i){
//     int smallest = i;
//     int left = 2*i + 1;
//     int right = 2*i + 2;
//     if(left < size && arr[smallest] > arr[left]){
//         smallest = left;
//     }
//     if(right < size && arr[smallest] > arr[right]){
//         smallest = right;
//     }
//     if(smallest != i){
//         swap(arr[smallest], arr[i]);
//         heapify(arr,size, smallest);
//     }
//     return;
// }

//2.

// void heapify(int arr[], int size, int i){
//     int smallest = i;
//     int left = 2*i;
//     int right = 2*i + 1;
    
//     if (left <= size && arr[smallest] > arr[left])
//     {
//         smallest = left;
//         swap(arr[smallest], arr[i]);
//         heapify(arr,size,smallest);
//     }
//     if (right <= size && arr[smallest] > arr[right])
//     {
//         smallest = right;
//         swap(arr[smallest], arr[i]);
//         heapify(arr,size,smallest);
//     }
//     // if (smallest != i)
//     // {
//     //     swap(arr[smallest], arr[i]);
//     //     heapify(arr,size,smallest);
//     //     // or we can say
//     //     // i = largest;
//     //     // heapify(arr,size,i);
//     // }
//     return;
// }

    //sorting function
void heap_sort(int arr[], int n){
    int size = n;
    while (size > 1)
    {
        //1. swap the first and last eleemnt
        swap(arr[size], arr[1]);
        //decrement the size
        size--;
        //printing
        //2. heapify or make the correct position of first element
        heapify(arr,size,1);
        // again call the sort for remaining part
        //     no need as you already applied loop -> heap_sort(arr,size);
        
    }
    return;
}

int main(){


    // int arr[6] = { -1,54,53,55,52,50 };
    int arr[6] = { -1,5,15,25,18,27 };
    int n = 5;
    //from last to first and for all recurrsive nodes as if we do changes in last nodes and 
    // call for upper part then again it recursively call rest of the non-leaf node and again make changes
    // if we need changes for upper part


    // 0-based indexing -> n/2-1 to 0 for all non-leaf nodes
    //1 based indexing -> n/2 to 1 for all non-leaf nodes
    for (int i = n/2 ; i > 0; i--)
    {
        heapify(arr,n,i);
    }
    //print array
    cout<<" printing the arr "<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    heap_sort(arr,n);
    cout<<" \nprinting the arr after sorting : "<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }


    // heap hp;
    // hp.insert(50);
    // hp.insert(55);
    // hp.insert(53);
    // hp.insert(52);
    // hp.insert(54);
    // cout<<" Before deletion : ";
    // hp.print();
    // cout<<" Ater deletion : ";
    // hp.delete_from_heap();
    // hp.print();
    // cout<<" Ater deletion : ";
    // hp.delete_from_heap();
    // hp.print();
    // cout<<" Ater deletion : ";
    // hp.delete_from_heap();
    // hp.print();

    //min heap //

    // hp.insert_min_heap(50);
    // hp.insert_min_heap(55);
    // hp.insert_min_heap(53);
    // hp.insert_min_heap(52);
    // hp.insert_min_heap(54);
    // hp.print();
    return 0;
}