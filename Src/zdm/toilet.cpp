/*
--------------------------------------------------------------------------------
MIT License

Copyright (c) 2024 Zachary D Meyer
See bottom of file for full license.
--------------------------------------------------------------------------------
toilet.hpp

Transforms a word that has a substring that beings with t, middle l and ends
with t, and replaces that with toilet.
*/
#include <regex>


#include "zdm/toilet.hpp"


std::expected<std::string, zdm::toilet_error_code>
zdm::get_toiletified_word(
    const std::string&                  a_word
)
{
    static const std::regex             toilet_matcher(R"([Tt][^Tt]+[Ll][^Tt]+[Tt])");

    if( a_word.find( ' ' ) != std::string::npos )
    {
        return std::unexpected( zdm::toilet_error_code::string_has_space );
    }

    std::string                         new_word = std::regex_replace(
        a_word
    ,   toilet_matcher
    ,   "toilet"
    );

    if( new_word == a_word )
    {
        return std::unexpected( zdm::toilet_error_code::invalid_word );
    }

    return std::expected<std::string, zdm::toilet_error_code>( std::move( new_word ) );
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
