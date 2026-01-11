// Online C++ compiler to run C++ program online
#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <type_traits>

using var_t = std::variant<int, std::string, float, std::vector<int>>;

struct A {
    void operator()(int a, int b) const {
        std::cout << "check this A callable operator: " << a + b << std::endl;
    }
};

template <typename... Ts>
struct Overloaded: Ts... {
    using Ts::operator()...;
};

template <typename... Ts>
Overloaded(Ts...) -> Overloaded<Ts...>;

void RunOverloadVariant(const var_t& t) {
    std::visit(
        Overloaded{
            [](const std::string& s) {
                std::cout << "this is strong type" << std::endl;
            },
            [](const int& i) {
                std::cout << "this is integer type" << std::endl;
            },
            [](const auto& a) {
                std::cout << "ignore the rest" << std::endl;
            }
        },
        t
    );
}

void RunVariant(const var_t& t) {
    std::visit(
        [](auto&& arg) {
            // if constexpr (std::is_same_v(decltype(arg), std::string)) {
            if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, std::string>) {
                std::cout << "check the string value is: " << arg << std::endl;
            } else if constexpr (std::is_same_v<std::decay_t<decltype(arg)>, std::vector<int>>) {
                std::cout << "Hello world this is vector" << std::endl;
                std::cout << "ATTENTION CHECK VECTOR: ";
                for (auto& a: arg) {
                    std::cout << a << " ";
                }
                std::cout << std::endl;
            } else {
                std::cout << "checking this one two three" << std::endl;
            }
        },
        t
    );
}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;
    
    var_t a = std::vector<int>{1, 21, 3, 44, 5};
    // var_t b = 3.1415;
    var_t b = 31415;
    var_t c = 333000;
    var_t d = "Hello World";
    
    RunVariant(a);
    RunVariant(b);
    
    A testA;
    testA(2, 3);
    
    RunOverloadVariant(a);
    RunOverloadVariant(b);

    return 0;
}
