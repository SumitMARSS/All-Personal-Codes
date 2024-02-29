#include <iostream>
using namespace std;

bool is_safe(int **arr, int x, int y, int n)
{
   //checking each row has queen or not
   for (int row = 0; row < x; row++)
   {
      if (arr[row][y]==1)
      {
         return false;
      }
      
   }
   int row=x, col=y;
   //for left diagonals
   while (row>=0 && col>=0)
   {
      if (arr[row][col]==1)
      {
         return false;
      }
      row--;
      col--;
   }
   //for right diagonals
   row=x;
   col=y;// reintialize
   while (row>=0 && col>=0)
   {
      if (arr[row][col]==1)
      {
         return false;
      }
      row--;
      col++;
   }
   return true;
}

bool place_n_queen(int **arr, int x, int n) //no need to pass y as no need to check in the same row
{
   //end case
   if (x>=n)
   {
      return true;
   }
   for (int col = 0; col < n; col++)
   {
      if (is_safe(arr,x,col,n))
      {
         arr[x][col]=1;
         if (place_n_queen(arr, x+1, n))
         {
            return true;
         }
         arr[x][col]=0;  //backtracking
      }
   }
   return false;
}

int main()
{
   int n;
   cout<<"Enter the rows in array:\n";
   cin>>n;
   int **arr= new  int*[n];
   for (int i = 0; i < n; i++)
   {
      arr[i]= new int [n] ;
      for (int j = 0; j < n; j++)
      {
         arr[i][j]=0;
      }
   }
   //no need of making sol array because no need to take input array
   if (place_n_queen(arr,0,n))
   {
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            cout<<arr[i][j]<<" ";
         }
         cout<<endl;
      }  
   }
}