/* ============================================================================================================================ *//**
 * @file       api.cpp
 * @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @date       Wednesday, 19th June 2024 10:49:07 am
 * @modified   Wednesday, 19th June 2024 11:19:24 am by Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @project    Developer Interviews
 * @brief     API design review 
 * 
 * 
 * @copyright Krzysztof Pierczyk © 2024
 */// ============================================================================================================================= */

#include <iostream>

/* =========================================================== SomeClass ========================================================== */

/**
 * @brief Generic value holder
 */
template<typename T>
class SomeClass
{
private:

    T value;

public:

    SomeClass(T value) :
        value{ value }
    { }

public:

    operator T() {
        return value;
    }

    template<typename U>
    operator U() {
        return ((U) value);
    }

    auto& get_value() {
        return value;
    }

    void set_value(T value) {
        this->value = value;
    }

    void print() {
        std::cout << value << std::endl;
    }

};

/* ========================================================= some_function ======================================================== */

template<typename ColletionT>
auto const& some_function(ColletionT collection) {
    return collection[5];
}

/* =========================================================== vector_3d ========================================================== */

template<typename T>
class vector_3d
{
private:

    T _x;
    T _y;
    T _z;

public:

    enum component {
        x,
        y,
        z,
    };

public:

    vector_3d(T x, T y, T z) :
        _x(x),
        _y(y),
        _z(z)
    { }

public:

    vector_3d operator+(vector_3d const& other) {
        return vector_3d( _x + other._x, _y + other._y, _z + other._z );
    }

    vector_3d operator-(vector_3d const& other) {
        return vector_3d( _x - other._x, _y - other._y, _z - other._z );
    }
    
    vector_3d operator*(T other) {
        return vector_3d( _x * other, _y * other, _z * other );
    }

    vector_3d operator/ (T div) {
        return vector_3d( _x / div, _y / div, _z / div );
    }

    template<typename StreamT>
    friend StreamT& operator<<(
        StreamT &out,
        const vector_3d &v
    ) {
        out << "{ " << v._x << ", " << v._y << ", " << v._z << " }";
        return out;
    }
    
    T get_x(){
        return _x;
    }

    T get_y(){
        return _y;
    }

    T get_z(){
        return _z;
    }

    T get_component(component c) {
        switch(c) {
            case x: return _x;
            case y: return _y;
            case z: return _z;
        }
    }

};

/* ================================================================================================================================ */
