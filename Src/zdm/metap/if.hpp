#ifndef __CPPLEARNING_ZDM_METAP_IF_HPP__
/* --------------------------------------------------------------------------------
MIT License

Copyright (c) 2024 Zachary D Meyer
See bottom of file for full license.
--------------------------------------------------------------------------------
if.hpp

Contains an if_s struct used for template metaprogramming.
*/
#define __CPPLEARNING_ZDM_METAP_IF_HPP__


namespace zdm { namespace metap {


template <bool ACondition, typename AThen, typename AElse>
struct if_s;


template<typename AThen, typename AElse>
struct if_s<true, AThen, AElse>
{
    using type = AThen;
};


template<typename AThen, typename AElse>
struct if_s<false, AThen, AElse>
{
    using type = AElse;
};


}}


#endif // __CPPLEARNING_ZDM_METAP_IF_HPP__


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
