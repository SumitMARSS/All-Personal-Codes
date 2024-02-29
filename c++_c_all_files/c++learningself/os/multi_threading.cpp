// #include <bits/stdc++.h>
// #include <thread>
// #include <unistd.h>
// using namespace std;

// void task1()
// {
// 	for (int i = 0; i < 10; i++)
// 	{
// 		cout<<"task1 is"<<i<<endl;
// 		sleep(2);//just to see in compiler
// 	}
// }

// void task2()
// {
// 	for (int i = 0; i < 10; i++)
// 	{
// 		cout<<"task2 is"<<i<<endl;
// 		sleep(1);
// 	}
// }

// int main(){
// 	thread t1(task1);
// 	thread t2(task2);
// 	t1.join();//main function don't take exit first
// 	t2.join();
// }

#include <bits/stdc++.h>
#include <thread>
#include <unistd.h>
using namespace std;

#define n 2
int a[n][n];
int b[n][n];
int c[n][n];
int d[n][n];
int e[n][n];

void* add(void* arg)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    cout<<"\nMatrix after addition of A and B \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<c[i][j]<<"  ";
        }
        cout<<"\n";
    }
    pthread_exit(NULL);
}

void* sub(void* arg)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            d[i][j]=a[i][j]-b[i][j];
        }
    }
    cout<<"\nMatrix after subtraction of A and B \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<d[i][j]<<"  ";
        }
        cout<<"\n";
    }
    pthread_exit(NULL);
}

int main(){
    cout<<"Enter your matrix elements of A\n";
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"a["<<i<<"]["<<j<<"] is:";
            cin>>a[i][j];
        }
    }
    cout<<"Enter your matrix elements of B\n";
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"b["<<i<<"]["<<j<<"] is:";
            cin>>b[i][j];
        }
    }
    cout<<"Your entered matrix A is:\n";
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<"   ";
        }
        cout<<"\n";
    }
    cout<<"Your entered matrix B is:\n";
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<b[i][j]<<"   ";
        }
        cout<<"\n";
    }
    pthread_t threads[2];
    pthread_attr_t atr;
    pthread_attr_setdetachstate(&atr,PTHREAD_CREATE_JOINABLE);
    pthread_attr_init(&atr);
    pthread_create(&threads[1], &atr, add, NULL);
    pthread_create(&threads[2], &atr, sub, NULL);
    pthread_join(threads[1], NULL); 
    pthread_join(threads[2], NULL); 
    
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            e[i][j]=0;
            for(int k=0; k<n; k++){
                e[i][j] += c[i][k] * d[k][j];
            }
        }
    }
    cout<<"Your matrix multiplication after addition and subtraction is \n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<e[i][j] <<"  ";
        }
        cout<<"\n";
    }
    pthread_attr_destroy(&atr);
}