//
//  async_func.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-20.
//

#include <iostream>
#include <list>
#include <chrono>
#include <future>

using std::cout;
using std::endl;
using std::chrono::steady_clock;
using secs=std::chrono::duration<double>;

struct prime_time{
    secs dur{};
    uint64_t count{};
};

prime_time count_primes(const uint64_t& max){
    prime_time ret{};
    constexpr auto is_prime= [](uint64_t   n) {
        for(uint64_t i {2};i<n/2; ++i){
            if(n%i == 0) return false;
        }
        return true;
    };
    
    uint64_t start {2};
    uint64_t end {max};
    
    auto thread_start_time= steady_clock::now();
    for(auto i=start;i<=end;++i){
        if(is_prime(i)) ++ret.count;
    }
    ret.dur = steady_clock::now() - thread_start_time;
    return ret;
    
}

int main66(){
    constexpr uint64_t max_prime {0x1ff};
    constexpr size_t num_threads {10};
    
//    list is double linked, future is asynchronous computuation in different threads
    std::list<std::future<prime_time>> swarm;
    
    cout<<"starting get prime parallel..."<<endl;
    auto start_time= steady_clock::now();
    
    for(auto i = num_threads;i;--i){
        swarm.emplace_back(std::async(count_primes, max_prime));
    }
    
    for(auto& s : swarm){
        static auto i=0;
        auto [dur, count] = s.get(); //structured binding
        cout<<"thread "<<++i<<": found "<<count<<" primes in " << dur.count()<<" secs"<<endl;
    }
    
    secs dur_total {steady_clock::now()-start_time};
    
    cout<<"total time: "<<dur_total.count()<<endl;
    
    return 0;
}
