//passing the ownership of a thread to other process
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
    for(int i=0;i<10;i++){
        std::thread t=std::thread(worker,i);
        workers.push_back(std::move(t));
    }

    std::for_each(workers.begin(),workers.end(),[](std::thread &t){
        assert(t.joinable());
        t.join();
    });
    return 0;
}