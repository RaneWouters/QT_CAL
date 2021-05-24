#include "HQ.h"
#include <cstring>
#include <string>
#include <vector>

namespace HQ_cal {

constexpr int N = 1e5;

int a[N];
int b[N];
int value[2 * N];

}  // namespace HQ_cal

void HQ_cal::StringtoValue(std::string temp, int target[]) {
    int lenth = temp.length();
    for (int q = 0; q < lenth; ++q) {
        target[q] = temp[lenth - 1 - q] - '0';
    }
}

void HQ_cal::Init(std::string lhs, std::string rhs) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(value, 0, sizeof(value));

    StringtoValue(lhs, a);
    StringtoValue(rhs, b);
}

std::string HQ_cal::ValuetoString(int n) {
    std::string target;
    for (int q = n - 1; q >= 0; --q) {
        target += (char)(value[q] + '0');
    }
    return target;
}

int HQ_cal::Compare(std::string lhs, std::string rhs) {
    return (lhs.length() == rhs.length()) ? (lhs >= rhs)
                                          : (lhs.length() - rhs.length());
}

std::string HQ_cal::Plus(std::string lhs, std::string rhs) {
    Init(lhs, rhs);
    int lenth = std::max(lhs.length(), rhs.length());
    int step = 0;
    for (int q = 0; q < lenth; ++q) {
        value[q] = (a[q] + b[q] + step) % 10;
        step = (a[q] + b[q] + step) / 10;
    }
    if (step != 0) {
        value[lenth++] = step;
    }
    return ValuetoString(lenth);
}

std::string HQ_cal::Minus(std::string lhs, std::string rhs) {
    Init(lhs, rhs);
    int lenth = lhs.length();

    for (int q = 0; q < lenth; ++q) {
        if (a[q] < b[q]) {
            a[q] += 10;
            --a[q + 1];
        }
        value[q] = a[q] - b[q];
    }
    while (lenth > 1 && value[lenth - 1] == 0)
        --lenth;

    return ValuetoString(lenth);
}

std::string HQ_cal::Times(std::string lhs, std::string rhs) {
    Init(lhs, rhs);
    int lenth1 = lhs.length();
    int lenth2 = rhs.length();
    int step = 0;

    for (int q = 0; q < lenth2; ++q) {
        for (int i = 0; i < lenth1; ++i) {
            value[q + i] = a[i] * b[q] + step + value[q + i];
            step = value[q + i] / 10;
            value[q + i] %= 10;
        }
    }

    std::string t = ValuetoString(lenth1 + lenth2);
    while (*t.begin() == '0') {
        t.erase(t.begin());
    }
    return t;
}

Divide_str HQ_cal::Divide(std::string lhs, std::string rhs) {
    int lenth1 = lhs.length();
    int lenth2 = rhs.length();
    std::string remain, quotion;

    if (lenth1 < lenth2) {
        remain = "0";
        quotion = lhs;
        return {remain, quotion};
    }

    std::string temp;
    if (lenth1 != lenth2) {
        temp = lhs.substr(0, lenth1 - lenth2 + 1);
    } else {
        temp = lhs;
    }

//    std::cout << "lhs: " << lhs << std::endl;
//    std::cout << "temp: " << temp << std::endl;

    for (int i = 0; i <= lenth1 - lenth2; ++i) {
        int count = 0;

//        std::cout << "temp: " << temp << std::endl;

        while (Compare(temp, rhs) > 0) {
//            std::cout << "compare: " << Compare(temp, rhs);
            temp = Minus(temp, rhs);
            ++count;
        }

//        std::cout << "temp: " << temp << std::endl;

        remain += std::to_string(count);

//        std::cout << "remain: " << remain << std::endl;

        if (i != lenth1 - lenth2) {
            temp += lhs.at(lenth2 + i);
        }
    }
    quotion = temp;

    while (*remain.begin() == '0') {
        remain.erase(remain.begin());
    }

    return {remain, quotion};
}
