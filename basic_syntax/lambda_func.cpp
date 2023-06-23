//
//  lambda_func.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-16.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::vector;
using std::map;
using std::string;
using std::cout;
using std::endl;

void disp_v (const auto v){
    if(!v.size()) return;
    for(auto n:v){
        cout<<n<<endl;
    }
}



const auto char_upper=[](char c)->char{
    //        c-('a'-'A'):  ('a'-'A') gets the gap between upper case letter and lower case letter
    if(c>='a'&&c<='z') return c-('a'-'A');
    else return c;
};


const char prompt (const char * p){
    string r {};
    cout<<p;
    getline(std::cin, r, '\n');
    if(r.size()<1) return 0;
    else if(r.size()>1){
        cout<<"input is too long"<<endl;
        return 0;
    }
    else return char_upper(r.at(0));
}

bool jump(const char s){
    using jfunc = std::function<void()>;
    const map<char, jfunc> jmap{
        {'A',[]{cout<<"function A"<<endl;}},
        {'B',[]{cout<<"function B"<<endl;}},
        {'C',[]{cout<<"function C"<<endl;}},
        {'D',[]{cout<<"function D"<<endl;}},
    };
    
    const auto it=jmap.find(s);
    if(it!= jmap.end()) it->second();
    else {
        cout<<"invalid input"<<endl;
        return false;
    }
    return true;
}

int mainw (){
    vector<int> v1 {1,7,4,9,8,12,10,20};
    vector<string> v2 {"one","two",
        "three","four"};
    disp_v(v1);
    disp_v(v2);
    
    //is_div4 predicate
    auto is_div4 = [](int i){return i%4==0;};
    
    auto count=std::count_if(v1.begin(), v1.end(), is_div4);
    
    cout<<count<<endl;
    
    vector<int> v3 {};
    std::copy_if(v1.begin(), v1.end(), std::back_inserter(v3), is_div4);
    disp_v(v3);
    
    cout<<"upper case: "<<char_upper('c')<<endl;
    
    //char upper transform
    string s1 {"you are my sunshine..."};
    string s2 {};
    string s3 {};
    std::transform(s1.begin(), s1.end(), std::back_inserter(s2), char_upper);
    disp_v(s1);
    disp_v(s2);
    cout<<s1<<endl;
    cout<<s2<<endl;
    
    //first letter uppercase
//    auto first_upper= [char_upper](char c){
//        static char prev_c {' '};
//        char new_c {prev_c==' ' ? char_upper(c) : c};
//        prev_c=c;
//        return new_c;
//
//    };
//
//    std::transform(s1.begin(), s1.end(), std::back_inserter(s3), first_upper);
//
//    cout<<s3<<endl;
  
    const char* prompt_str{"what to do? (A/B/C/D/X)"};
    for (auto key=prompt(prompt_str); key!='X'; key=prompt(prompt_str)) {
        if(key) jump(key);
    }
    cout<<"see you next time!"<<endl;
    
    return 0;
}

