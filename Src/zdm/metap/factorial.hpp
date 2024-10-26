#ifndef __CPPLEARNING_ZDM_METAP_FACTORIAL_HPP__
/* --------------------------------------------------------------------------------
MIT License

Copyright (c) 2024 Zachary D Meyer
See bottom of file for full license.
--------------------------------------------------------------------------------
factorial.hpp

Contains a factorial struct used to calculate factorials.
*/
#define __CPPLEARNING_ZDM_METAP_FACTORIAL_HPP__


#include <cstdint>


namespace zdm { namespace metap {


template<uint64_t ANum>
struct factorial
{
    static constexpr uint64_t           value =
        ANum * factorial<ANum - 1>::value;
};


template<>
struct factorial<0>
{
    static constexpr uint64_t           value = 1;
};


}}


#endif // __CPPLEARNING_ZDM_METAP_FACTORIAL_HPP__


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
