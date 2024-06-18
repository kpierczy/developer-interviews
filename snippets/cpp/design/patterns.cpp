/* ============================================================================================================================ *//**
 * @file       concepts.cpp
 * @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @date       Tuesday, 18th June 2024 1:06:13 pm
 * @modified   Tuesday, 18th June 2024 1:14:05 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
 * @project    Developer Interviews
 * @brief      Design patterns basics
 * 
 * 
 * @copyright Krzysztof Pierczyk © 2024
 */// ============================================================================================================================= */

#include <iostream>

/* ================================================================================================================================ */

template<typename T>
class B
{
    T& _impl() {
        return static_cast<T&>(*this);
    }

    const T& _impl() const {
        return static_cast<const T&>(*this);
    }

public:

    void foo() const {
        _impl()._foo_impl();
    }
};

/* ================================================================================================================================ */

template<typename T>
struct C :
    public B<T>
{
    void _foo_impl() const {
        std::cout << "C::_foo_impl()" << std::endl;
    }
};

/* ================================================================================================================================ */

struct D :
    public C<D>
{
    void _foo_impl() {
        std::cout << "D::_foo_impl()" << std::endl;
    }
};

/* ================================================================================================================================ */

int main() {
    D d;
    d.foo();
    return 0;
}

/* ================================================================================================================================ */
