#include <iostream>
using namespace std;

void check_occurance(int *a,int n, int k,int i)
{
   if ((*(a+i)==k))
   {
      cout<<i;
      return ;
   }
   else if (i==n)
   {
      cout<<"You didn't found element";
      return ;
   }
   check_occurance((a+1),n-1,k,i+1);
}

int check_last_occurance(int *a,int n, int k,int i)
{
   if (i==n)
   {
      return -1;
   }
   
   int restarray = check_last_occurance((a),n,k,i+1);
   if (restarray!=-1)
   {
      return restarray;
   }
   else if (*(a+i)==k)
   {
      cout<<i<<endl;
      exit(0);
   }
   return -1;
}

int main()
{
   int n,k;
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
      cout<<"Your array has only one element \nSo 1 is first and last occurance"<<endl;
      exit(0);
   }
   cout<<"Enter the elemnts you want to find in array:\n";
   cin>>k;
   int i=0,p=0;
   cout<<"first occurance"<<endl;
   check_occurance(a,n,k,i);
   cout<<"\nlast occurance"<<endl;
   check_last_occurance(a,n,k,p);
}
