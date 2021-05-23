#pragma once

#include <cstring>
#include <iostream>
#include <string>

struct Divide_str{
    std::string remain;
    std::string quotion;
};

namespace HQ_cal {

void StringtoValue(std::string temp, int target[]);
void Init(std::string lhs, std::string rhs);
std::string ValuetoString(int n);

int Compare(std::string lhs, std::string rhs);

std::string Plus(std::string lhs, std::string rhs);
std::string Minus(std::string lhs, std::string rhs);
std::string Times(std::string lhs, std::string rhs);
Divide_str Divide(std::string lhs, std::string rhs);

}// namespace HQ_cal
