#include <bits/stdc++.h>
using namespace std;
unordered_map<char, string> ans_text;

// structure for min heap
struct priority_queue_min
{
    priority_queue_min *left, *right;
    char data;
    int freq;
    priority_queue_min(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

// for finding the characters used and their respective frequency
void frequency(string str, unordered_map<char, int> &m)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i] != ',')
            m[str[i]]++;
    }
}

// comparator for comparing left n right elements of a node (for min heap)
struct compare
{
    bool operator()(priority_queue_min *left, priority_queue_min *right)
    {
        return (left->freq > right->freq);
    }
};

// recursive function for printing the characters and their respective codes
void charNfreq(struct priority_queue_min *root, string str)
{
    if (!root)
        return;
    // if current root is not the not internal node, i.e, it is leaf node
    if (root->data != '$')
    {
        cout << "\t    " << root->data << "\t\t     " << str << "\n";
        ans_text[root->data] = str; // this will use in printing the coded string
    }
    // recursively calling the function
    charNfreq(root->left, str + "0");
    charNfreq(root->right, str + "1");
}

// main function of huffman code
void HuffmanCode(char data[], int freq[], int size)
{
    // forming left, right and top node
    struct priority_queue_min *left;
    struct priority_queue_min *right;
    struct priority_queue_min *top;
    priority_queue<priority_queue_min *, vector<priority_queue_min *>, compare> min_heap; // forming min heap
    for (int i = 0; i < size; ++i)
        min_heap.push(new priority_queue_min(data[i], freq[i])); // pushing data and frequency in min heap
    while (min_heap.size() != 1)                                 // till heap size == 1
    {
        // taking two node with min frequency
        left = min_heap.top();
        min_heap.pop();
        right = min_heap.top();
        min_heap.pop();
        // adding the two obtained nodes
        top = new priority_queue_min('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        // again pushing the added nodes, named ad top
        min_heap.push(top);
    }
    // calling the function for printing the the characters and their respective codes
    charNfreq(min_heap.top(), "");
}

int main()
{
    string str = "In computer science and information theory, a Huffman code is a particular type of optimal prefix code "; // text given in ques
    cout << "\nTHE GIVEN STRING IS-\n\n"
         << str << "\n";
    unordered_map<char, int> dat_freq;
    frequency(str, dat_freq);
    char chars_in_text[dat_freq.size()];
    int freq_of_chars[dat_freq.size()], j = 0;
    // making array of chars_in_data and respective frequency
    for (auto i : dat_freq)
    {
        chars_in_text[j] = i.first;
        freq_of_chars[j] = i.second;
        j++;
    }
    cout << "\nTHE REQUIRED CODES FOR THE CHARACTERS ARE-\n\n";
    cout << "\tCHARACTER           CODE\n\n";
    // calling the huffman code function which will print the chars and their code
    HuffmanCode(chars_in_text, freq_of_chars, dat_freq.size());
    cout << "\n\nTHE REQUIRED CODED STRING IS-\n\n";
    // printing the coded string
    for (int i = 0; i < str.length(); i++)
    {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if (str[i] != ',')
        {
            if (str[i] == ' ')
                cout << " ";
            else
                cout << ans_text[str[i]];
        }
    }
    cout << "\n\n";
    return 0;
}








/*


#include <bits/stdc++.h>
using namespace std;

struct MinNode
{
    char val;
    unsigned f;
    MinNode *left, *right;
    MinNode(char val, unsigned f)
    {
        left = right = NULL;
        this->val = val;
        this->f = f;
    }
};
struct comp
{
    bool operator()(MinNode *left, MinNode *right)
    {
        return (left->f > right->f);
    }
};
void CodePrinter(struct MinNode *root, string s)
{

    if (!root)
        return;

    if (root->val != '$')
        cout << root->val << ": " << s << "\n";

    CodePrinter(root->left, s + "0");
    CodePrinter(root->right, s + "1");
}
void HuffmanCodes(char val[], int f[], int n)
{
    struct MinNode *left, *right, *top;
    priority_queue<MinNode *, vector<MinNode *>, comp> minHeap;
    for (int i = 0; i < n; ++i)
    {
        minHeap.push(new MinNode(val[i], f[i]));
    }
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinNode('$', left->f + right->f);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    CodePrinter(minHeap.top(), "");
}
void selectionSort(int a[], char b[], int n)
{
    int i, j, min, temp;
    char temp1;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        
        temp1 = b[i];
        b[i] = b[min];
        b[min] = temp1;
    }
}
int main()
{
    //char str[1000];
    int i, j = 0, count = 0;
    int f[256] = {0};
    //cout << "Enter the string:" << endl;
    //gets(str);
    char str[] = "the rupee opened stronger after the dollar index fell to below hundred and ten levels,said anil kumar bhansali, head of treasury, finrex treasury advisors";
    for (i = 0; str[i] != '\0'; i++)
    {
        f[str[i]]++;
    }
    for (i = 0; i < 256; i++)
    {
        if (f[i] != 0)
        {
            count++;
        }
    }
    char arr[count];
    int f1[count];
    for (i = 0; i < 256; i++)
    {
        if (f[i] != 0)
        {
            f1[j] = f[i];
            arr[j] = char(i);
            j++;
        }
    }
    selectionSort(f1, arr, count);
    cout << "Characters | Frequency" << endl;
    cout << "-----------------------" << endl;
    ;
    for (i = 0; i < count; i++)
    {
        cout << arr[i] << "          | " << f1[i] << endl;
    }
    cout << endl;
    HuffmanCodes(arr, f1, count);
    return 0;
}*/