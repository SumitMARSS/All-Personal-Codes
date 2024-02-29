//each time when we compile it brings some line of code which must be executed before the code runs
#include <bits/stdc++.h> 
using namespace std;
//can't be chage later, before code start compiler replace PI with the value so that compiler see the exact value
#define PI 3.14 

int main(){
    int n;
    float pi=3.14;
    cin>>n;
    cout<<3.14*n*n<<endl;
    cout<<PI*n*n<<endl;
    pi+=1;//fear of this to happen
    cout<<pi*n*n<<endl; //result me affected
}