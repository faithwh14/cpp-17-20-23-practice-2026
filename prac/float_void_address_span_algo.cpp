/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <span>
#include <cstdint>
#include <algorithm>

struct Tensor {
    void* data;
    size_t size;
    
    bool hasdata() const {
        if (data == nullptr) {
            return false;
        }
        return true;
    }
    
    void checksize() const {
        std::cout << "check size is: " << (size / sizeof(float)) << std::endl;
    }
};

int main()
{
    std::cout<<"Hello World" << std::endl;
    
    std::vector<float> haha{2.0f, 3.0f, 1.5f};
    
    Tensor tensor;
    tensor.data = haha.data();
    tensor.size = haha.size() * sizeof(float);

    float* hehe = static_cast<float*>(tensor.data);
    
    tensor.checksize();
    
    for (auto it = 0; it < (tensor.size / sizeof(float)); it++) {
        std::cout << "checking one two three: " << hehe[it] << std::endl;   
    }
    if (tensor.data) {
        std::cout << "this is correct" << std::endl;
    } else {
        std::cout << "this is wrong" << std::endl;
    }
    
    auto sp = std::span<float>(static_cast<float*>(tensor.data), tensor.size / sizeof(float));
    
    std::cout << "check index 0 of sp: " << sp[0] << std::endl;
    
    std::cout << "check this maximum value: " << *std::max_element(sp.begin(), sp.end()) << std::endl;
    
    std::cout << "check this minimum value: " << *std::min_element(sp.begin(), sp.end()) << std::endl;

    return 0;
}
