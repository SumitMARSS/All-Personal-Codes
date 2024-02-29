#include <bits/stdc++.h>
#include <thread>
#include <unistd.h>
using namespace std;
//using locking system just to safe our increment state and complete that state
//std::mutex mtx;

//after doing atomic a complete change in variable occur then only save the state and again increment
// atomic <int> sum=0;
int sum = 0;
// doubt - why for less value it is showing correct value as 1000 in place of 10000000
void task1()
{
	//mtx.lock();
	
	for (int i = 0; i < 10000000; i++)
	{
		sum++;
	}
	//mtx.unlock();
} // updating inconsistenting as racing problem which one is updating first

int main()
{
	thread t1(task1);
	thread t2(task1);
	t1.join();
	t2.join();
	cout << sum;
}