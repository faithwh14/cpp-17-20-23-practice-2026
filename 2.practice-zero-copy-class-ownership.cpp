// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>

class H1 {
    public:
    explicit H1(std::vector<int>&& data): m_data(std::move(data)) {}
    // ~H1() {}
    
    // H1(const H1& h1): m_data(h1.m_data) {}
    H1(const H1& other) = delete;
    H1& operator=(const H1& other) = delete;
    
    H1(H1&& other) noexcept : m_data(std::move(other.m_data)) {}
    H1& operator=(H1&& other) noexcept {
        if (this != &other) {
            m_data = std::move(other.m_data);
        }
        
        return *this;
    }
    
    const std::vector<int>& data() const {
        return m_data;
    }
    
    private:
    std::vector<int> m_data;
};

void printVectorValue(const std::vector<int>& h) {
    std::cout << "check the vector value here: ";
    for (const auto& h_: h) {
        std::cout << std::to_string(h_) << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;
    
    std::vector<int> hval;
    for (int it = 0; it < 10000; it++) {
        hval.emplace_back(1000 + it);
    }
    
    H1 h1(std::move(hval));
    // H1 h1(hval);  // copy not allow
    // H1 h2(h1);
    H1 h3(std::move(h1));
    
    const std::vector<int> h1data = h1.data();
    const std::vector<int> h3data = h3.data();
    
    printVectorValue(h1data);
    printVectorValue(h3data);

    return 0;
}
