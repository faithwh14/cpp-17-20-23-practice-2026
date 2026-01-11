/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string_view>
#include <span>
#include <array>
#include <vector>

void process_span(std::span<const int> sp) {
    std::cout << "==============================================================" << std::endl;
    std::cout << "is the sp empty: " << sp.empty() << std::endl;
    std::cout << "the sp size is: " << sp.size() << std::endl;
    
    std::span<const int> subsp = sp.subspan(1, 4);
    std::cout << "the size of the sub span is: " << subsp.size() << std::endl;
    std::cout << "the first integer is: " << sp.front() << std::endl;
    std::cout << "the last integer is: " << sp.back() << std::endl;
    
    std::span<const int> sp1 = sp.subspan(0, sp.size() - 2);
    std::cout << "the last integer after deducted two is: " << sp1.back() << std::endl;
    std::cout << "==============================================================\n" << std::endl;
}

void process_strview(std::string_view strview) {
    std::cout << "==============================================================" << std::endl;
    std::cout << "the size of the stringview is: " << strview.size() << std::endl;
    
    std::cout << "is the stringview empty: " << (strview.empty() ? "it is empty" : " it is not empty") << std::endl;
    
    std::string_view substrview;
    size_t firstsub = 2;
    size_t lastsub = 5;
    if (strview.size() < lastsub) {
        std::cerr << "the last substring index is higher than the total size" << std::endl;
    } else {
        substrview = strview.substr(firstsub, lastsub - firstsub);
    }
    if (substrview.empty()) {
        std::cout << "the sub stringview is empty" << std::endl;
    } else {
        std::cout << "the sub stringview is not empty: " << substrview << std::endl;   
    }
    
    std::cout << "the first latter of the stringview is: " << strview.front() << std::endl;
    std::cout << "the last letter of the stringview is: " << strview.back() << std::endl;
    
    size_t removenum = 5;
    // if (removenum <= strview.size()) {
    //     strview.remove_suffix(removenum);
    // }
    // if (removenum <= strview.size()) {
    //     strview.remove_prefix(removenum);
    // }
    
    // size_t target = "today";
    size_t target_pos = strview.find("today");
    if (target_pos == std::string_view::npos) {
        std::cout << "the target 'today' is not found in the stringview" << std::endl;
    } else {
        std::cout << "the target 'today is found in the stringview': " << target_pos << std::endl;
    }
    
    
    std::cout << "==============================================================\n" << std::endl;
}


int main()
{
    std::cout<<"Hello World" << std::endl;
    
    std::string strtext = "hello world, today is a good day";
    const char* chartext = "hello this is me, nice to meet you today";
    
    std::string_view strstrview{strtext};
    std::string_view charstrview{chartext, 10};
    
    process_strview(strstrview);
    process_strview(charstrview);
    
    std::cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n" << std::endl;
    
    int arr[4] = {11, 22, 33, 44};
    std::array<int, 9> stdarray = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    std::vector<int> stdvector = {123, 324, 345, 456, 845, 567};
    
    std::span<int> sp{arr};
    
    std::cout << "check the second index arr value: " << arr[1] << std::endl;
    
    std::cout << "check the second index sp value: " << sp[1] << std::endl;
    
    process_span(arr);
    process_span(stdarray);
    process_span(stdvector);

    return 0;
}

// /******************************************************************************

// Welcome to GDB Online.
// GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
// C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
// Code, Compile, Run and Debug online from anywhere in world.

// *******************************************************************************/
// #include <iostream>

// int main()
// {
//     std::cout<<"Hello World" << std::endl;
    
//     int arr[5] = {11, 22, 33, 44, 55};
//     std::array<int, 5> stdarr = {111, 222, 333, 444, 555};
//     // int* arrptr = stdarr.data();
//     int* arrptr = arr;
    
//     // for (int it = 0; it < 4; it++) {
//     //     arrptr++;
//     // }
//     for (int it = 0; it < 6; it++) {
//         arrptr++;
//     }
    
//     std::cout << "get the arr index 5: " << *arrptr << std::endl;  // unsafe

//     return 0;
// }
