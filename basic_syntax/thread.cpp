//
//  thread.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-20.
//

#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

void spleepms(const unsigned ms){
    using  millis = std::chrono::milliseconds;
    std::this_thread::sleep_for(millis(ms));
}

void thread_func (const int n){
    cout<<"this is t: "<<n<<endl;
    auto slp_duration = 100*n;
    
    for(auto i=0;i<5;++i){
        spleepms(slp_duration);
        cout<<n<<" : ( "<<slp_duration<<"ms) : loop "<<i+1<<endl;
    }
    
    cout<<"finishing loop..."<<n<<endl;
}

int main33 (){
    thread th1(thread_func,1);
    thread th2(thread_func,2);
    th1.detach();
    th2.detach();
    
    cout<<"main func is starting to sleep..."<<endl;
    spleepms(2000);
    cout<<"main func finished sleep, back to online..."<<endl;
    return 0;
}


