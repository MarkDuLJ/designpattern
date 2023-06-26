//
//  singleton.cpp
//  design_patterns
//
//  Created by Mark Du on 2023-06-26.
//

#include <iostream>
#include <string>

using namespace std;


class Leader{
    static Leader* instance_;
    Leader(){cout<<"New leader is coming..."<<endl;}
public:
    static Leader* getInstance(){
        if(instance_==NULL) instance_= new Leader;
        return instance_;
    }
    void giveSpeach(){
        cout<<"cheers!..."<<endl;
    }
};

Leader* Leader::instance_ = NULL;
int main(){
    Leader::getInstance()->giveSpeach();
    return 0;
}
