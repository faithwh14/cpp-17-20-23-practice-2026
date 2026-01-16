/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <expected>
#include <variant>
#include <string_view>
#include <span>
#include <array>
#include <vector>
#include <stdexcept>
#include <string>

// class IMoBAGame {
//     public:
    
// };

namespace dota2 {

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Stat
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
struct MInt {
    static constexpr int min_n = 0;
    static constexpr int max_n = 500;
    
    int m_n;
    
    MInt(int n): m_n(n) {
        if ((m_n < min_n) || (m_n > max_n)) {
            throw std::out_of_range("The value is out of range value!");
        }
    }
};

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Hero Attributes
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
enum class PrimaryAttribute {
    Strength,
    Agility,
    Intelligence
};

enum class HeroPosition {
    Carry,
    Mid,
    Offlane,
    Support,
    HardSupport
};

struct Attribute {
    MInt strength;
    MInt agility;
    MInt intelligence;
};

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// URSA
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

struct BearDownFacet {
    BearDownFacet() {
        std::cout << "THIS IS BEAR DOWN FACET OF URSA" << std::endl;
    }
    MInt movement = 300;
};

struct SaveStrengthFacet {
    SaveStrengthFacet() {
        std::cout << "THIS IS SAVE STRENGTH FACET OF URSA" << std::endl;
    }
    MInt strength = 200;
};

template <typename FC>
class BaseHero {
    protected:
    BaseHero(const std::string& n, const PrimaryAttribute& p,
            const MInt& strval, const MInt& agival, const MInt& intval,
            const HeroPosition& h, FC&& facet):
                name(n), pAttr(p), attr(Attribute{
                    .strength = strval,
                    .agility = agival,
                    .intelligence = intval
                }), pos(h), m_facet(facet) {}
    virtual ~BaseHero() {}

    protected:
    std::string name;
    PrimaryAttribute pAttr;
    Attribute attr;
    HeroPosition pos;

    FC m_facet;
};


using UrsaFacet = std::variant<BearDownFacet, SaveStrengthFacet>;
class Ursa: public BaseHero<UrsaFacet> {
    public:
    explicit Ursa(UrsaFacet facet): BaseHero("Ursa", PrimaryAttribute::Agility, 20,
        30, 15, HeroPosition::Carry, std::move(facet)){
        std::cout << "This is Ursa Constructor" << std::endl;                   
    }  
};

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// TIDEHUNTER
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Krill Eater
// Dead in the Water
struct KrillEaterFacet {
    KrillEaterFacet() {
        std::cout << "THIS IS KRILLEATERFACET FROM TIDEHUNTER" << std::endl;
    }
};

struct DeadInTheWaterFacet {
    DeadInTheWaterFacet() {
        std::cout << "THIS IS DeadInTheWaterFacet FROM TIDEHUNTER" << std::endl;
    }
};

using TidehunterFacet = std::variant<KrillEaterFacet, DeadInTheWaterFacet>;
class TideHunter: public BaseHero<TidehunterFacet> {
    public:
    explicit TideHunter(TidehunterFacet facet): BaseHero("Tidehunter", PrimaryAttribute::Strength,
        30, 10, 13, HeroPosition::Offlane, std::move(facet)) {
        std::cout << "This is Tidehunter Constructor" << std::endl;                       
    }
};

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// template <class... Ts>
// struct Overloaded {
//     using Overloaded::operator()...;
// };

// template <class... Ts>
// Overloaded::Overloaded(class... Ts): Ts...

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

class DoTA2 {
    public:
    explicit DoTA2() {}
    ~DoTA2() {}
};

};

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

using namespace dota2;

int main()
{
    std::cout<<"Hello World" << std::endl;
    
    TideHunter tidehunter{
        DeadInTheWaterFacet()
    };

    return 0;
}
