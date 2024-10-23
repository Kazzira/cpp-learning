/* --------------------------------------------------------------------------------
MIT License

Copyright (c) 2024 Zachary D Meyer
See bottom of file for full license.
--------------------------------------------------------------------------------
toilet.test.cpp

Unit tests for toilet.cpp.
*/
#include <expected>

#include <catch2/catch_all.hpp>

#include "zdm/toilet.hpp"



TEST_CASE(
    "zdm::get_toiletified_word: String with space gives correct error"
,   "[unit-test][zdm][zdm::get_toiletified_word]"
)
{
    std::string                         input {"Invalid Word"};
    std::expected<std::string, zdm::toilet_error_code>
                                        result = zdm::get_toiletified_word( input );

    REQUIRE( !result );
    REQUIRE( result.error() == zdm::toilet_error_code::string_has_space );
}


TEST_CASE(
    "zdm::get_toiletified_word: test that Television returns invalid word error"
,   "[unit-test][zdm][zdm::get_toiletified_word]"
)
{
    std::string                         input {"Television"};
    std::expected<std::string, zdm::toilet_error_code>
                                        result = zdm::get_toiletified_word( input );

    REQUIRE( !result );
    REQUIRE( result.error() == zdm::toilet_error_code::invalid_word );
}


TEST_CASE(
    "zdm::get_toiletified_word: test that twilight returns toilet"
,   "[unit-test][zdm][zdm::get_toiletified_word]"
)
{
    std::string                         input {"twilight"};
    std::expected<std::string, zdm::toilet_error_code>
                                        result = zdm::get_toiletified_word( input );

    REQUIRE( result );
    REQUIRE( *result == std::string( "toilet" ) );
}


/*
MIT License

Copyright (c) 2024 Zachary D Meyer

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
