//choosing the number of threads at runtime
//the bigger the job we want to distribute the work using multithreading

#include<iostream>
#include<vector>
#include<thread>
#include<algorithm>
#include<cassert>
using namespace std;


void worker(int number){
    cout<<"I am Worker Thread No:"<<number<<endl;
}

int main(){
    vector<std::thread>workers;

    //how many threads are supported by the hardware concurrently without overlapping
    unsigned long const hardware_threads=std::thread::hardware_concurrency();

    std::cout<<hardware_threads<<endl;

    for(int i=0;i<hardware_threads;i++){
        workers.emplace_back(std::thread(worker,i));
    }

    std::for_each(workers.begin(),workers.end(),[](std::thread &t){
        assert(t.joinable());
        t.join();
    });
    return 0;
}