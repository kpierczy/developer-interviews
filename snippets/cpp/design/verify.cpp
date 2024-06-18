/* ============================================================================================================================ *//**
 * @file       verify.cpp
 * @author     Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @maintainer Krzysztof Pierczyk (krzysztof.pierczyk@gmail.com)
 * @date       Tuesday, 18th June 2024 1:06:13 pm
 * @modified   Tuesday, 18th June 2024 1:23:32 pm by Krzysztof Pierczyk (k.pierczyk@wb.com.pl)
 * @project    Developer Interviews
 * @brief      Runtime verification library API design
 * 
 * 
 * @copyright Krzysztof Pierczyk © 2024
 */// ============================================================================================================================= */

/* ================================================================================================================================ */

namespace ver { /* ... */ }

struct value_1 { int val; };
struct value_2 { int val; };

struct expectations_provider
{
    static constexpr ver::expectations_table expectations {
        ver::value( [](value_1 v){ return v.val; }   ).expected( ver::in            { 0, 1, 2 }  ),
        ver::value( &value_2::val                    ).expected( ver::in_range      (3, 5)       ),
        ver::value( std::type_identity<int>{ }       ).expected( ver::outside       { 6, 7, 8 }  ),
        ver::value( float{ }                         ).expected( ver::outside_range (0.0f, 1.0f) ),
    };
    
    struct errors_mask;
    
    // Optional
    template<
        typename ValueT,
        typename ExpectationT
    > void on_check_failure(
        const ValueT&,
        const ExpectationT&
    );
    
    // Obligatory
    template<
        typename ValueT,
        typename ExpectationT
    > void on_check_failure(
        const ValueT&,
        const ExpectationT&
    );

    // Optional
    void reset();

    // Optional
    std::optional<errors_mask> get_result() const;    
};

/* ================================================================================================================================ */

int main() {

    ver::verifier<expectations_provider> verifier;

    auto errors_mask = verifier.verify(
        value_1{ 1 },
        value_2{ 6 },
        7,
        0.5f
    );

    assert(errors_mask.has_value());
    
    return 0;
}

/* ================================================================================================================================ */
