#include <iostream>
using namespace std;
/*
//elements are sorted or not simple method
int main()
{
   int n;
   cout<<"Enter the elemnts in array:\n";
   cin>>n;
   int a[n],flag;
   for (int i = 0; i < n; i++)
   {
      cout<<"Element "<<i<<"\t";
      cin>>*(a+i);
   }
   for (int i = 0; i < n; i++)
   {
      cout<<"Element "<<i<<" is "<<*(a+i)<<endl;
   }
   int j;
   for (int i = 0; i < n-1; i++)
   {
      j=i+1;
      if (*(a+i)<=*(a+j))
      {
         flag=1;
      }
      else
      {
         flag=0;
         break;
      }
   }
   if (flag==1)
   {
      cout<<"Your array is sorted"<<endl;
   }
   else
   {
      cout<<"Your array is not sorted"<<endl;
   }
}*/


int check_sort(int *a,int q,int n) 
{
   int j=q+1;
   if (*(a+q)<=*(a+j))
   {
      if (q+1==n)
      {
         cout<<"Your array is sorted"<<endl;
         exit(0);
      }
      return check_sort(a,q+1,n);//(a+1,n-1)  size decreses by 1 and array starts from a+1
   }
   else
   {
      cout<<"Your array is not sorted"<<endl;
      exit(0);
   }
}

int main()
{
   int n;
   cout<<"Enter the elemnts in array:\n";
   cin>>n;
   int a[n],flag;
   for (int i = 0; i < n; i++)
   {
      cout<<"Element "<<i<<"\t";
      cin>>*(a+i);
   }
   for (int i = 0; i < n; i++)
   {
      cout<<"Element "<<i<<" is "<<*(a+i)<<endl;
   }
   if (n==1)
   {
      cout<<"Your array is sorted"<<endl;
      exit(0);
   }
   
   int q=0;
   //here in place of sending first and last element you can send it like (a+1,n-1)
   check_sort(a,q,n);
}

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int check(int arr[], int n)
{
    if (n==1)
    {
        return true;
    }
    int restarray=check(arr+1,n-1);
    return (arr[1]>=arr[0] && restarray); 
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
}
*/