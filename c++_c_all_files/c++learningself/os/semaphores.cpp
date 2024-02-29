#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t sem;// declare a semaphore

void task1(int name)
{
	sem_wait(&sem); // wait for semaphore
	for (int i = 0; i < 4; i++)
	{
		cout<<name<<"  is working\n"<<endl;
		sleep(2);//just to see in compiler
	}
	sem_post(&sem); // release the semaphore
}


int main(){
	sem_init(&sem, 0, 3); // initialize the semaphore with a count of 3
	thread t1(task1,1);
	thread t2(task1,2);
	thread t3(task1,3);
	thread t4(task1,4);
	thread t5(task1,5);
	t1.join();//main function don't take exit first
	t2.join();
	t3.join();
	t4.join();
	t5.join();
}