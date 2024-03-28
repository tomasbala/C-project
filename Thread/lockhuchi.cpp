#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

volatile int counter(0);
std::mutex mtx;

//阻塞上锁版本
void thrfunc(){
     for(int i=0;i<10000;++i){
        mtx.lock();
        ++counter;
        mtx.unlock();
    }
}
//非阻塞版本
void n_thrfunc(){
    for(int i=0;i<10000;++i){
        if(mtx.try_lock()){
            ++counter;
            mtx.unlock();
        }
        else 
            std::cout<<"try_lock false\n";
    }
}


int main(int argc,char *argv[]){
   std::thread threads[10];
    for(int i=0;i<10;++i)
        threads[i] = std::thread(n_thrfunc);
    for(auto& th:threads) th.join();
    std::cout <<"count to"<< counter <<"successfully\n";
    return 0; 
}   