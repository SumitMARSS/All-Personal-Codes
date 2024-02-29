#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 50

struct Min_heap_node 
{
    char item;
    int freq;
    struct Min_heap_node *left, *right;
};

struct MinHeap 
{
    unsigned size;
    unsigned capacity;
    struct Min_heap_node **array;
};

// Create nodes
struct Min_heap_node *newNode(char item, unsigned freq) 
{
    struct Min_heap_node *ptr = (struct Min_heap_node *)malloc(sizeof(struct Min_heap_node));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->item = item;
    ptr->freq = freq;
    return ptr;
}

// Create min heap
struct MinHeap *createMinH(unsigned capacity) {
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Min_heap_node **)malloc(minHeap->capacity * sizeof(struct Min_heap_node *));
    return minHeap;
}

struct Min_heap_node *extract_min(struct MinHeap *minHeap) {
    struct Min_heap_node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size;

    return temp;
}

struct Min_heap_node * huffman(char str[],int fre[], int count)
{
    struct Min_heap_node *root ;
    struct Min_heap_node *left, *right, *top;
    for (int i = 0; i < count; i++)
    {
        left = extract_min(MinHeap);
        right = extract_min(MinHeap);
        top = newNode('k', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert(MinHeap, top);
    }
    return extract_min(MinHeap);
}

void printfreq(int fre[])
{
    char str1[26],count=0;
    for (int i = 0; i < 26; i++) 
    {
        if (fre[i] != 0) 
        {
            printf("%c -> %d\n", i + 'a', fre[i]);
            if (*(str1+i)=NULL)
            {
                continue;
            }
            else
            {
                str1[i]= i + 'a';
                count++;
            } 
        }
    }
    printf("\n%d\n",count);
    for (int i = 0; i < 26; i++) 
    {
        printf("%c",str1[i]);
    }
    huffman(str1,fre,count);
}

void printfre(int fre[])
{
    for (int i = 1; i <= 26; i++) 
    {
        if (fre[i] != 0) 
        {
            printf("%d\n", fre[i]);
        }
    }
}

void findfreq(char str[],int fre[])
{
    int i = 0;
    // Traverse over the string
    while (str[i] != '\0') 
    {
        fre[str[i] - 'a']++;
        i++;
    }
}

void sorting(int arr[])
{
    int t,key;
    for (int i = 1; i<= 26; i++)
    {
        if (arr[i]>arr[i+1])
        {
            t=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=t;
            key=i;
            for (int j = i-1; j >=0; j--)
            {
                if (arr[j]>arr[key])
                {
                    t=arr[j];
                    arr[j]=arr[key];
                    arr[key]=t;
                    key--;
                }
            } 
        }
    }
}

int main()
{
    int fre[26] = {0};
    char str[]="the rupee opened stronger after the dollar index fell to below hundred and ten levels,said anil kumar bhansali, head of treasury, finrex treasury advisors";
    printf("The string:\n");
    puts(str);
    findfreq(str,fre);
    printfreq(fre);
    sorting(fre);
    printf("\n");
    printfre(fre);
}