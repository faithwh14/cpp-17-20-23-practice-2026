// Online C++ compiler to run C++ program online
#include <iostream>
#include <optional>
#include <string>
#include <variant>
#include <tuple>

enum class TLExist {
    TLNONE,
    TRAFFICLIGHT,
    THISERROR,
    BOTH
};

enum class TrafficLight {
    RED,
    YELLOW,
    GREEN
};

enum class ThisError {
    ERROR1,
    ERROR2,
    ERROR3,
    ERROR4,
    ERROR5
};

struct HelloWorld {
    std::optional<ThisError> error;
    std::optional<TrafficLight> trafficLight;
    bool okay = false;
};


TLExist verifyTrafficLight(const HelloWorld& helloWorld, int& count) {
    std::cout << "Attention: Count #" << std::to_string(count) << std::endl;
    TLExist tlexist = TLExist::TLNONE;

    int state = (static_cast<int>(helloWorld.error.has_value()) << 1) | static_cast<int>(helloWorld.trafficLight.has_value());
    
    ++count;
    
    return static_cast<TLExist>(std::move(state));
}

void printTLExistState(const TLExist& tlexist) {
    std::cout << "tlerror state value is ";
    switch (tlexist) {
        case TLExist::TLNONE:
            std::cout << "TLNone none exists";
            break;
        case TLExist::TRAFFICLIGHT:
            std::cout << "Trafficlight exists";
            break;
        case TLExist::THISERROR:
            std::cout << "tlerror state value is";;
            break;
        case TLExist::BOTH:  // fallout
        default:
            std::cout << "BOTH exist";
    }
    std::cout << std::endl;
}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;
    int count = 0;

    HelloWorld helloWorld{
        .okay = true
    };
    
    TLExist tlexist1 = verifyTrafficLight(helloWorld, count);
    printTLExistState(tlexist1);
    
    helloWorld.trafficLight.emplace(TrafficLight::YELLOW);
    
    TLExist tlexist2 = verifyTrafficLight(helloWorld, count);
    printTLExistState(tlexist2);
    
    helloWorld.error.emplace(ThisError::ERROR4);
    
    TLExist tlexist3 = verifyTrafficLight(helloWorld, count);
    printTLExistState(tlexist3);

    return 0;
}
