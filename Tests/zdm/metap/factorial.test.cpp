/* --------------------------------------------------------------------------------
MIT License

Copyright (c) 2024 Zachary D Meyer
See bottom of file for full license.
--------------------------------------------------------------------------------
factorial.test.cpp

Tests the factorial struct.
*/
#include <catch2/catch_all.hpp>

#include "zdm/metap/factorial.hpp"


TEST_CASE(
    "zdm::metap::factorial: Test 0"
,   "[unit-test][zdm::metap][zdm::metap::factorial]"
)
{
    STATIC_REQUIRE( zdm::metap::factorial<0>::value == 1 );
}


TEST_CASE(
    "zdm::metap::factorial: Test 1"
,   "[unit-test][zdm::metap][zdm::metap::factorial]"
)
{
    STATIC_REQUIRE( zdm::metap::factorial<1>::value == 1 );
}


TEST_CASE(
    "zdm::metap::factorial: Test 6"
,   "[unit-test][zdm::metap][zdm::metap::factorial]"
)
{
    STATIC_REQUIRE( zdm::metap::factorial<6>::value == 720 );
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
