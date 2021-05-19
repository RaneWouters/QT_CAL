#ifndef _REGISTER_H_
#define _REGISTER_H_

#include <map>
#include <memory>
#include <queue>
using namespace std;

extern double RPCalculate(queue<string>& temp);

class OperatorFactory {
   public:
    OperatorFactory() = default;
    void Register(string, class Operator&);
    class Operator& Find(string);
    bool Exist(string);
    bool Exist(char&);

   protected:
    static map<string, class Operator&> ms_register;
};

void OperatorInit(class OperatorFactory&);

#endif
