#include "in.h"
#include "register.h"

extern class In In;
extern class OperatorFactory OperatorFactory;

bool IsNum(char& temp) {
    if (temp >= '0' && temp <= '9')
        return 1;
    return 0;
}

void In::PushBack(char& temp) {
    string t(1, temp);
    this->target.push_back(t);
}

void In::Init(string InText) {
    //    string InText;
    //    cin >> InText;
    //    InText = "1+2";
    //    cout << InText << endl;

    if (*InText.begin() == '-') {
        this->target.push_back("0");
        this->target.push_back("-");
    } else {
        this->PushBack(*InText.begin());
    }

    for (auto it = InText.begin() + 1; it != InText.end(); ++it) {
        if (*it == '(' || *it == ')') {
            this->PushBack(*it);
        } else if (IsNum(*it)) {
            if (IsNum(*(it - 1)) || *(it - 1) == '.') {
                (this->target.end() - 1)->push_back(*it);
            } else {
                this->PushBack(*it);
            }
        } else if (*it == '.') {
            if (IsNum(*(it - 1))) {
                (this->target.end() - 1)->push_back(*it);
            } else if (*(it - 1) == ')') {
                throw 1;
            } else {
                this->target.push_back("0.");
            }
        } else if (*it == '-') {
            if (*(it - 1) == '(') {
                this->target.push_back("0");
                this->target.push_back("-");
            } else if (OperatorFactory.Exist(*(it - 1))) {
                this->target.erase(this->target.end() - 1);
                this->target.push_back("-");
            } else {
                this->target.push_back("-");
            }
        } else if (OperatorFactory.Exist(*it)) {
            if (OperatorFactory.Exist(*(it - 1))) {
                this->target.erase(this->target.end() - 1);
                this->PushBack(*it);
            } else {
                this->PushBack(*it);
            }
        }
    }
}

void In::ShowTarget() {
    for (auto it = this->target.begin(); it != this->target.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

void MRegister::MS() {
    this->value = stod(*(In.target.end() - 1));
}
void MRegister::MPlus() {
    this->value += stod(*(In.target.end() - 1));
}
void MRegister::MMinus() {
    this->value -= stod(*(In.target.end() - 1));
}
