/* ============================================================================================================================ *//**
 * @file       computations.cpp
 * @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @date       Wednesday, 19th June 2024 10:49:07 am
 * @modified   Wednesday, 19th June 2024 11:16:03 am by Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @project    Developer Interviews
 * @brief      Computation implementation review 
 * 
 * 
 * @copyright Krzysztof Pierczyk © 2024
 */// ============================================================================================================================= */

#include <vector>

/* ======================================================= some_computation ======================================================= */

template<typename ColletionT>
auto const& some_computation(ColletionT collection) {
    
    int elem = -1;

    for(int i = 0; i < collection.size(); ++i) {
        if(
            collection[i] < 2 &&
            collection[i] > -2 ||
            collection[i] == 15 &&
            ~collection[i] ^ 0x0F == 0x20
        ) {
            elem = 5 + collection[i] < 2 || i < 1
                ? i
                : i - 1;
            break;
        }
    }

    if(elem == -1) {
        return -1;
    }

    return collection[elem] * collection[elem];
}

/* ====================================================== some_transformation ===================================================== */

template<typename ColletionT>
auto some_transformation(ColletionT collection) {

    int sum = 0;
    for(int i = 0; i < collection.size(); ++i) {
        sum += collection[i];
    }

    std::vector<float> result;

    for(auto e : collection) {
        result.push_back(e * sum * 2.0);
    }

    return result;
}

/* ================================================================================================================================ */
