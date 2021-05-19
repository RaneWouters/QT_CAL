#ifndef _REVERSEPOLISH_H_
#define _REVERSEPOLISH_H_

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "operator.h"
#include "register.h"
using namespace std;

extern class OperatorFactory OperatorFactory;

queue<string> RPInit(vector<string>& temp) {
    queue<string> RP;
    stack<string> RP_sign;

    if(temp.empty()) {
        throw 1;
    }
    for (auto q = temp.begin(); q != temp.end(); ++q) {
        if ((*q->begin() >= '0' && *q->begin() <= '9') || (*q->begin() == '-' && *q != "-")) {
            RP.push(*q);
        } else if (*q == "(") {
            RP_sign.push(*q);
        } else if (*q == ")") {
            while (RP_sign.top() != "(") {
                RP.push(RP_sign.top());
                if(RP_sign.empty()) {
                    throw 1;
                }
                RP_sign.pop();
            }
            if(RP_sign.empty()) {
                throw 1;
            }
            RP_sign.pop();
        } else {
            if (RP_sign.empty()) {
                RP_sign.push(*q);
            } else {
                if (RP_sign.top() == "(") {
                    RP_sign.push(*q);
                } else if (OperatorFactory.Find(*q).GetPrecedence() >
                           OperatorFactory.Find(RP_sign.top())
                               .GetPrecedence()) {
                    RP_sign.push(*q);
                } else if (OperatorFactory.Find(*q).GetPrecedence() <=
                           OperatorFactory.Find(RP_sign.top())
                               .GetPrecedence()) {
                    while (
                        !RP_sign.empty() &&
                        (OperatorFactory.Find(*q).GetPrecedence() <
                         OperatorFactory.Find(RP_sign.top()).GetPrecedence())) {
                        RP.push(RP_sign.top());
                        RP_sign.pop();
                    }
                    RP_sign.push(*q);
                }
            }
        }
//        auto t = RP;
//        while (!t.empty()) {
//            cout << t.front() << ' ';
//            t.pop();
//        }
//        cout << endl;
    }
    while (!RP_sign.empty()) {
        if (RP_sign.top() != "(") {
            RP.push(RP_sign.top());
        }
        RP_sign.pop();
    }

    return RP;
}

double RPCalculate(queue<string>& temp) {
    stack<double> Value;
    while (!temp.empty()) {
        //string t = temp.front();
        if ((*temp.front().begin() >= '0' && *temp.front().begin() <= '9') || (*temp.front().begin() == '-' && temp.front() != "-")) {
            Value.push(stod(temp.front()));
            temp.pop();
        } else {
        class Operator* it = &OperatorFactory.Find(temp.front());
            if (it->GetOprand() == 2) {
                if(Value.empty()) {
                    throw 1;
                }
                ((class BinaryOperator*)it)->SetRhs(Value.top());
                Value.pop();
                if(Value.empty()) {
                    throw 1;
                }
                ((class BinaryOperator*)it)->SetLhs(Value.top());
                Value.pop();
                Value.push(((class BinaryOperator*)it)->GetValue());
                temp.pop();
            } else if (it->GetOprand() == 1) {

                //double k = Value.top();

                if(Value.empty()) {
                    throw 1;
                }
                ((class UnaryOperator*)it)->SetRhs(Value.top());
                Value.pop();

                //k = ((class UnaryOperator*)it)->GetRhs();
                //cout << "k_rhs" << k << endl;
                //k = ((class UnaryOperator*)it)->GetValue();
                //cout << "k_value" << k << endl;

                Value.push(((class UnaryOperator*)it)->GetValue());
                temp.pop();
            }
            if (temp.empty() && Value.size() == 1) {
                break;
            }
        }
    }
    return Value.top();
}

#endif
