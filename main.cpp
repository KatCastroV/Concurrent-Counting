//Author: Katherine Castro
//Module 7 Portfolio Milestone
//Portfolio Project: Part I
//CSC 450 Programming III
//Colorado State University Global Campus
//Professor Lawrence Meadors

#include<iostream>
#include<thread>                //std::thread
#include<mutex>                 //std::mutx, std::unique_lock

using namespace std;

//Function Prototype Declarations
void countUp();
void countDown();
void shared_print(string, int);

mutex mu;
int counter = 0;

condition_variable m_cv0;

int main()
{
    thread t1(countUp);     //t1 starts running
    thread t2(countDown);   //t2 starts running
    
    t1.join();
    t2.join();
}

//Counts up from 0 to 20
void countUp()
{
    //cout access exclusive to lifetime of lck
    unique_lock<mutex> lck(mu);
    m_cv0.wait(lck, [&](){return counter < 20;});
   
    while(counter < 20)
    {
        counter++;
        shared_print(string("Counting Up: "), counter);
    }
    m_cv0.notify_all();
    
}

//Counts down from 20 to 0
void countDown()
{
    unique_lock<mutex> lck(mu);
    m_cv0.wait(lck, [&]() {
        return counter > 0;
        });
   while(counter > 0)
   {
       shared_print(string("Counting Down: "), counter);
       counter--;
   }
   m_cv0.notify_all();
}

//Prints both of the counts
void shared_print(string description, int number)
{
    //lock_guard<std::mutex> guard(mu);
    //mu.lock();
    cout << description << number << endl;
    //mu.unlock();
}


