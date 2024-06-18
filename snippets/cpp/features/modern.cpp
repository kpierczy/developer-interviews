/* ============================================================================================================================ *//**
 * @file       modern.cpp
 * @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @date       Tuesday, 18th June 2024 1:06:13 pm
 * @modified   Tuesday, 18th June 2024 1:14:49 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
 * @project    Developer Interviews
 * @brief      Modern C++ features
 * 
 * 
 * @copyright Krzysztof Pierczyk © 2024
 */// ============================================================================================================================= */

#include <iostream>

/* ================================================================================================================================ */

template<typename... Ts>
struct B {
    
    B(Ts... args) {
        ((std::cout << "(" << typeid(Ts).name() << ")" << args << " "), ...);
    }

};

/* ================================================================================================================================ */

int main() {
    B b { 1, 2.0, "three" };
    return 0;
}

/* ================================================================================================================================ */
