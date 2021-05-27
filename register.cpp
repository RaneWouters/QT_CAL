#include "register.h"
#include "operator.h"

extern class Plus Plus;
extern class Minus Minus;
extern class Times Times;
extern class Divide Divide;
extern class Mod Mod;
extern class Pow Pow;
extern class Exp Exp;

extern class Sin Sin;
extern class Cos Cos;
extern class Tan Tan;
extern class Sinh Sinh;
extern class Cosh Cosh;
extern class Tanh Tanh;
extern class Factorial Factorial;
extern class Square Square;
extern class Sqrt Sqrt;
extern class Power10 Power10;
extern class Negate Negate;
extern class Reciprocal Reciprocal;
extern class Ln Ln;
extern class Abs Abs;

void OperatorFactory::Register(string temp, class Operator& opr) {
    this->ms_register.emplace(temp, opr);
}

class Operator& OperatorFactory::Find(string temp) {
    return this->ms_register.find(temp)->second;
}

void OperatorInit(class OperatorFactory& OperatorFactory) {
    OperatorFactory.Register("+", Plus);
    OperatorFactory.Register("-", Minus);
    OperatorFactory.Register("*", Times);
    OperatorFactory.Register("/", Divide);
    OperatorFactory.Register("%", Mod);

    OperatorFactory.Register("Q", Square);
    OperatorFactory.Register("q", Sqrt);
    OperatorFactory.Register("^", Pow);
    OperatorFactory.Register("p", Power10);
    OperatorFactory.Register("!", Factorial);

    OperatorFactory.Register("s", Sin);
    OperatorFactory.Register("c", Cos);
    OperatorFactory.Register("t", Tan);
    OperatorFactory.Register("S", Sin);
    OperatorFactory.Register("C", Cos);
    OperatorFactory.Register("T", Tan);

    OperatorFactory.Register("r", Reciprocal);
    OperatorFactory.Register("e", Exp);
    OperatorFactory.Register("n", Negate);

    OperatorFactory.Register("l", Ln);
    OperatorFactory.Register("|", Abs);
}

bool OperatorFactory::Exist(string temp) {
    if (this->ms_register.end() != this->ms_register.find(temp))
        return 1;
    return 0;
}

bool OperatorFactory::Exist(char& temp) {
    string t(1, temp);
    if (this->ms_register.end() != this->ms_register.find(t))
        return 1;
    return 0;
}
