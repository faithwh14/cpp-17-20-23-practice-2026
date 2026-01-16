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
// All pick, random, single draft

enum class MatchingQuality {
    Good,
    Normal,
    Bad
};

class GameMode {
    public:
    const MatchingQuality& GetMatchingQuality() const {
        return mQuality;
    }
    // Do not reveal matching time

    protected:
    GameMode(const MatchingQuality& quality): mQuality(quality) {}
    void SetMatchingTime(const MInt& m) {
        matching_time = m;
    }
    
    private:
    MInt matching_time {300};
    MatchingQuality mQuality;
};

class AllPick: public GameMode {
    public:
    AllPick(): GameMode(MatchingQuality::Good) {
        SetMatchingTime(200);
    }
};

class Random: public GameMode {
    public:
    Random(): GameMode(MatchingQuality::Good) {
        SetMatchingTime(350);
    }
};

class SingleDraft: public GameMode {
    public:
    SingleDraft(): GameMode(MatchingQuality::Bad) {
        SetMatchingTime(450);
    }
};

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// TODO: Incomplete side
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class IGamePlay {
    public:
    ~IGamePlay() = default;

    virtual void StartGame() = 0;
    virtual void QuitGame() = 0;
    virtual void PauseGame() = 0;
    
    protected:
    IGamePlay() = default;
};

class MatchingQueue {
    public:
    MatchingQueue() {}
    ~MatchingQueue() {}
    
    private:
    static constexpr int radiant{5};
    static constexpr int dire{5};
};

class DoTA2GamePlay: public IGamePlay {
    public:
    explicit DoTA2GamePlay() {}
    ~DoTA2GamePlay() {}
    
    void StartGame() override {
        // TODO
    }
    void QuitGame() override {
        // TODO
    }
    void PauseGame() override {
        // TODO
    }
    
    // private:
    
};

class DoTA2Player;  // TODO: mmr, rank medal, region

}  // namespace dota2

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

using namespace dota2;

int main()
{
    std::cout<<"Hello World" << std::endl;
    
    TideHunter tidehunter{
        DeadInTheWaterFacet()
    };
    
    SingleDraft singleDraft;
    std::cout << "Check the single draft matching quality: ";
    switch (singleDraft.GetMatchingQuality()) {
        case MatchingQuality::Good: {
            std::cout << "Good Matching Quality" << std::endl;
            break;
        }
        case MatchingQuality::Normal: {
            std::cout << "Normal Matching Quality" << std::endl;
            break;
        }
        case MatchingQuality::Bad: {
            std::cout << "Bad Matching Quality" << std::endl;
            break;
        }
        default: {
            std::cout << "Unknown Matching Quality" << std::endl;
        }
    }

    return 0;
}
