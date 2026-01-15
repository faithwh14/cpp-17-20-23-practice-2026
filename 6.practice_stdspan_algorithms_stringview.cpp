/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string_view>
#include <span>
#include <array>
#include <list>
#include <numeric>
#include <algorithm>
#include <string>
#include <ranges>

void printstrview(std::string_view strview) {
    std::cout << "This value is: " << strview << std::endl;
    // auto pos = a.find("hello");
    auto pos = strview.find("hello123");
    if (pos == std::string_view::npos) {
        std::cout << "hello is not found" << std::endl;
    } else {
        std::cout << "hello is found" << std::endl;
    }
}

void printvec(std::span<int> spanval) {
    if (spanval.empty()) {
        std::cout << "this is the empty span, exit" << std::endl;
        return;
    }
    std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
    
    std::cout << "spanval: " << spanval.size() << std::endl;
    auto sub = spanval.subspan(1, 3);
    
    std::cout << "sub size is: " << sub.size() << std::endl;

    std::cout << "check maximum value: " << *std::max_element(spanval.begin(), spanval.end()) << std::endl;
    std::cout << "the minimum value is : " << *std::min_element(spanval.begin(), spanval.end()) << std::endl;
    
    std::cout << "check 11 exists: " << (std::find(spanval.begin(), spanval.end(), 111) != spanval.end()) << std::endl;
    
    bool anyretval = std::any_of(spanval.begin(), spanval.end(), [](int v) {
        return v > 23;
    });
    std::cout << "Any of spanval bigger than 23: " << anyretval << std::endl;
    
    std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
    
    std::transform(spanval.begin(), spanval.end(), spanval.begin(), [](int x) {
        return x * 3;
    });
    
    std::cout << "check again the maximum * 2: ? " << *std::max_element(spanval.begin(), spanval.end()) << std::endl;
    
    std::cout << "BEFORE SIZE IS: " << spanval.size() << std::endl;
    
    auto mid = std::partition(spanval.begin(), spanval.end(), [](int x) {
        return x > 150;
    });
    
    std::cout << "check the mid value is: " << *mid << std::endl;
    
    int sum = std::accumulate(spanval.begin(), spanval.end(), 0);
    std::cout << "CHECK >> SUM IS: " << sum << std::endl;
}

int main()
{
    std::cout<<"Hello World" << std::endl;
    std::string var_a = "";
    
    for (int it = 0; it < 20; it++) {
        var_a += " hello world";
    }
    
    printstrview(var_a);
    
    std::vector<int> spanval1 = {11, 22, 33, 44, 55};
    std::array<int, 10> spanval2 = {11, 22};

    printvec(spanval1);
    printvec(spanval2);
    
    std::cout << "check spanval2 size is: " << spanval2.size() << std::endl;
    
    int spanval3[6] = {11, 22, 33, 44, 55, 111};
    
    printvec(spanval3);
    
    std::vector<int> spanval4 = {};
    printvec(spanval4);
    
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
    std::cout << "the current spanval1 size is: " << spanval1.size() << std::endl;
    auto new_end = std::remove_if(spanval1.begin(), spanval1.end(), [](int x) {
        return x % 2 == 0;
    });
    spanval1.erase(new_end, spanval1.end());
    std::cout << "the spanval1 size after removed is: " << spanval1.size() << std::endl;
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;

    return 0;
}
