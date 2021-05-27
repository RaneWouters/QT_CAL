#ifndef _IN_H_
#define _IN_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsNum(char&);

class In {
   public:
    In() = default;
    void Init(string);
    void CE() { this->target.erase(this->target.end() - 1); };
    void C() { this->target.clear(); };
    void ShowTarget();
    void PushBack(char&);

    vector<string>& GetVec() { return this->target; }

    friend class MRegister;

   private:
    vector<string> target;
};

class MRegister {
   public:
    MRegister() = default;

    double MR() { return this->value; }
    void MC() { this->value = 0; }

    void MS();
    void MPlus();
    void MMinus();

   private:
    double value = 0;
};

// void In::Init() {
//    string a;
//    while(cin >> a) {
//        if(a == "pi"){
//            a = "3.141592653";
//        }
//        this->target.push_back(a);
//    }

//    this->target.push_back("(");
//    this->target.push_back("3");
//    this->target.push_back("-");
//    this->target.push_back("4");
//    this->target.push_back(")");
//}

#endif
