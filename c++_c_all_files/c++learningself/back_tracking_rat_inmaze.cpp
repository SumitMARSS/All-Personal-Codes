#include <iostream>
using namespace std;
//condition to move further
bool is_safe(int **arr, int x, int y, int n)
{
   if (x<n && y<n && arr[x][y]==1)
   {
      return true;
   }
   return false;
}

bool ratinmaze(int **arr, int x, int y, int n, int **solarr)
{
   if (x==n-1 && y==n-1)
   {
      solarr[x][y]=1;
      return true;
   }//terminating conditions
   
   if (is_safe(arr, x,  y,  n))
   {
      solarr[x][y]=1;
      if (ratinmaze(  arr,   x+1,   y,   n,solarr))
      {
         return true;
      }
      if (ratinmaze(  arr,   x,   y+1,   n,solarr))
      {
         return true;
      }
      solarr[x][y]=0;// backtracking
      return false;
   }
   return false;
}

int main()
{
   int n,k;
   cout<<"Enter the elemnts in array:\n";
   cin>>n;
   int **arr=new int*[n];
   for (int i = 0; i < n; i++)
   {
      arr[i]=new int [n];
   }//dynamic allocating 2 D arrray
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout<<"arr"<<i<<j;
         cin>>arr[i][j];
      }
   }//taking input the 2 D array
   int **solarr=new int*[n];
   for (int i = 0; i < n; i++)
   {
      solarr[i]=new int [n];
      for (int j = 0; j < n; j++)
      {
         solarr[i][j]=0;
      }
   }//initialising the solarr all elemnts 0

   //Giving output the solution
   if (ratinmaze(arr,0,0,n,solarr))
   {
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            cout<<solarr[i][j];
         }
         cout<<"\n";
      }
   }
}
