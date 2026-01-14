/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <variant>
#include <expected>
#include <stdexcept>

struct BInt {
    static constexpr int min = 0;
    static constexpr int max = 1000;
    
    int m_val;
    
    BInt(int val): m_val(val) {
        if ((m_val < min) || m_val > max) {
            throw std::out_of_range("val is not in range 1 to 10000");
        }
    } 
};

enum class Trait {
    Good,
    Bad
};

struct strength_hero_stats {
  std::string hero_name;
  Trait trait;
  BInt strength_rating;
};

struct agility_hero_stats {
  std::string hero_name;
  Trait trait;
  BInt agility_rating;
};

struct intelligence_hero_stats {
  std::string hero_name;
  Trait trait;
  BInt intelligence_rating;
};


using str_stats = strength_hero_stats;
using agi_stats = agility_hero_stats;
using int_stats = intelligence_hero_stats;

using var_stats = std::variant<str_stats, agi_stats, int_stats>;

template <typename... Ts>
struct Overloaded: Ts... {
    using Ts::operator()...;
};

template <typename... Ts>
Overloaded(Ts...) -> Overloaded<Ts...>;

void VerifyTest(const var_stats& stat) {
    std::visit(Overloaded(
        [](const str_stats& s) {
            std::cout << "this is strength hero" << std::endl;
        },
        [](const agi_stats& s) {
            std::cout << "this is agility hero" << std::endl;
        },
        [](const auto& s) {
            std::cout << "this is other hero" << std::endl;
        }
        ),
        stat
    );
}

int main()
{
    std::cout << "Hello World" << std::endl;
    
    var_stats str_stat = str_stats{
        .hero_name = "TideHunter",
        .trait = Trait::Good,
        .strength_rating = 700
    };
    
    VerifyTest(str_stat);
    
    var_stats agi_stat = agi_stats{
        .hero_name = "Phantom Assassin",
        .trait = Trait::Good,
        .agility_rating = 950
    };
    
    VerifyTest(agi_stat);
    
    
    var_stats int_stat = int_stats{
        .hero_name = "Invoker",
        .trait = Trait::Bad,
        .intelligence_rating = 980
    };
    
    VerifyTest(int_stat);
    
    try {
        var_stats temp_stat = agi_stats{
            .hero_name = "ursa",
            .trait = Trait::Good,
            .agility_rating = 1050
        };
    } catch (...) {
        std::cerr << "Something is wrong here" << std::endl;
    }

    return 0;
}
