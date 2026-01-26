/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

struct Tensor {
    std::vector<uint8_t> data;
    std::vector<uint16_t> size;
};

struct Box {
    float x1, y1, x2, y2;
    float score;
};

float Area(const Box& b) {
    return std::max(0.0f, b.x2 - b.x1) * std::max(0.0f, b.y2 - b.y1);
}

float Iou(const Box& a, const Box& b) {
    float ix1 = std::max(a.x1, b.x1);
    float iy1 = std::max(a.y1, b.y1);
    float ix2 = std::min(a.x2, b.x2);
    float iy2 = std::min(a.y2, b.y2);
    
    float inter = std::max(0.0f, ix2 - ix1) * std::max(0.0f, iy2 - iy1);
    
    float sum = Area(a) + Area(b) - inter;
    
    // std::cout << "debug: " << inter << " " << sum << " " << ix1 << " " << ix2  << " " << iy1 << " " << iy2 << std::endl;
    
    return (inter / sum);
}

std::vector<Box> nmsBoxes(const std::vector<Box>& b) {
    std::vector<Box> result(b.size());
    
    for (int it = 0; it < b.size(); it++) {
        std::vector<bool> suppressed(b.size(), false);    
        for (int jt = 0; jt < b.size(); jt++) {
            if (suppressed[jt]) {
                ///
            }
        }
    }
    return {};
}

int main()
{
    std::cout<<"Hello World"<<std::endl;
    
    Box* b = new Box{
        .x1 = 3,
        .y1 = 3,
        .x2 = 10,
        .y2 = 12
    };
    
    Box* c = b;
    
    // Box* a = new Box{
    //     .x1 = 4,
    //     .y1 = 5,
    //     .x2 = 9,
    //     .y2 = 9
    // };
    Box* a = new Box{
        .x1 = 3,
        .y1 = 4,
        .x2 = 11,
        .y2 = 9
    };
    
    std::cout << "check area value is: " << Area(*b) << std::endl;

    std::cout << "check iou value is: " << Iou(*c, *b) << std::endl;
    
    std::vector<Box> bb{*b, *b, *c, *a, *b};
    
    std::sort(bb.begin(), bb.end(), [](const Box& a, const Box& b) {
        return a.score > b.score;
    });

    return 0;
}
