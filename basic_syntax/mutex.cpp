//
//  mutex.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-20.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <string_view>
#include <future>

using std::cout;
using std::endl;
using std::string_view;

std::mutex mtx {};  // Declaration of a mutex object

class Anima {
    using friend_t= std::list<Anima>;
    string_view s_name{"unkown"};
    friend_t l_friends {};
    
public:
    Anima() = delete;
    Anima(const string_view n): s_name(n) {}
    
    bool operator == (const Anima& o) const {
        return s_name.data()==o.s_name.data();
    }
    
    bool is_friend(const Anima& o) const {
        for(const auto& a : l_friends){
            if(a==o) return true;
        }
        return false;
    }
    
    bool add_friend(Anima& o) noexcept {
        cout<<"add friend "<< s_name << " -> "<<o.s_name<<endl;
        if(*this==o) return  false;
        
        std::lock_guard<std::mutex> l {mtx};
        if(!is_friend(o)) l_friends.emplace_back(o);
        if(!o.is_friend(*this)) o.l_friends.emplace_back(*this);
        
        return true;
    }
    
    bool delete_friend(Anima& o) noexcept {
        cout<<"deleting friend... "<< s_name << " -> "<<o.s_name<<endl;
        if(*this==o) return false;
    
        std::lock_guard<std::mutex> l {mtx};
        if(auto t= find_friend(o); t) l_friends.erase(t.value());
        if(auto t =find_friend(*this); t) o.l_friends.erase(t.value());
                                                            
        return true;
    }
                                                            
    std::optional<friend_t::iterator> find_friend(const Anima& o) noexcept {
            for(auto it = l_friends.begin();it!=l_friends.end();++it){
                if(*it==o) return it;
            }
            return {};
        }
    
    void print_friends() const noexcept {
        std::lock_guard<std::mutex> l{mtx};
        
        auto num = l_friends.size();
        cout<<"total friends: "<<num<<endl;
        
        if(!num) cout<<"no friends"<<endl;
        else{
            for( auto n:l_friends){
                cout<<n.s_name<<endl;
                if(--num) cout<<", "<<endl;
            }
        }
    }
                                                            
};


void sharedResourceAccess() {
    // Lock the mutex before accessing the shared resource
    std::lock_guard<std::mutex> lock(mtx);

    // Access the shared resource
    // ...

    // The mutex is automatically released when lock goes out of scope
}

int main77778() {
    // Create multiple threads that access the shared resource
//    std::thread t1(sharedResourceAccess);
//    std::thread t2(sharedResourceAccess);

    // Wait for the threads to finish their execution
//    t1.join();
//    t2.join();
    
//    create unique pointer using make_unique, can use ptr->method() later
    auto cat1= std::make_unique<Anima>("Fei");
    auto tiger1= std::make_unique<Anima>("Astro");
    auto donkey1= std::make_unique<Anima>("Yu");
    auto dog1= std::make_unique<Anima>("wang");
    
    //access object through the unique pointer
    auto a1= std::async([&]{cat1 -> add_friend(*tiger1);});
    auto a2= std::async([&]{cat1 -> add_friend(*donkey1);});
    auto a3= std::async([&]{cat1 -> add_friend(*dog1);});    //access object through the unique pointer
    
    a1.wait();a2.wait();a3.wait();
    
    auto p1= std::async([&]{cat1 -> print_friends();});
    auto p2= std::async([&]{dog1 -> print_friends();});
    auto p3= std::async([&]{donkey1 -> print_friends();});
    
    p1.wait();p2.wait();p3.wait();
    
    
    

    return 0;
}

