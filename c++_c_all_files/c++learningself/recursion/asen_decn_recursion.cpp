#include <iostream>
using namespace std;

void print_descend(int n)
{
   cout<<n<<endl;
   if (n==1)
   {
      exit(0);
   }
   print_descend(n-1);
}
void print_ascend(int n)
{
   if (n>=1)
   {
      print_ascend(n-1);
      cout<<n<<endl;
   }
   else
   {
      return ;
      //exit(0);   //This is not working because function is not returning to their base form
   }
}

int main()
{
   int n;
   cout<<"Enter the numbers you want to print:\n";
   cin>>n;
   cout<<"Asending order\n";
   print_ascend(n);
   cout<<"Desending order\n";
   print_descend(n);
}