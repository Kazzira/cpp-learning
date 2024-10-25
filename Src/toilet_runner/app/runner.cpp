/* --------------------------------------------------------------------------------
MIT License

Copyright (c) 2024 Zachary D Meyer
See bottom of file for full license.
--------------------------------------------------------------------------------
toilet_runner/app/runner.cpp

Parses a text file with one word per line and returns a vector of strings
that are toiletified.
*/
#include <expected>
#include <filesystem>
#include <fstream>
#include <new>
#include <string>
#include <vector>

#include "zdm/toilet.hpp"

#include "toilet_runner/app/runner.hpp"


namespace {


void
fill_vector_with_toilet_words(
    std::ifstream&                  ifs
,   std::vector<toilet_runner::app::string_pair>&
                                    toilet_words
)
{
    std::string                     line;

    while( std::getline( ifs, line ) )
    {
        auto result = zdm::get_toiletified_word( line );

        if( result )
        {
            toilet_words.push_back( { std::move( line ), std::move( *result ) } );
        }
    }
}


}


std::expected<
    std::vector<toilet_runner::app::string_pair>
,   toilet_runner::app::error_code
>
toilet_runner::app::get_toilet_words_from_file(
    const std::filesystem::path&        a_file_path
)
{
    using toilet_runner::app::string_pair;

    std::vector<string_pair>            toilet_words;
    constexpr auto                      file_flags = std::ios::in;

    try
    {
        if( !std::filesystem::exists( a_file_path ) )
        {
            return std::unexpected( error_code::file_not_found );
        }

        std::ifstream                       ifs(
            a_file_path, file_flags
        );

        if( !ifs )
        {
            return std::unexpected( error_code::filesystem_error );
        }

        fill_vector_with_toilet_words( ifs, toilet_words );
        return toilet_words;
    }
    catch( const std::filesystem::filesystem_error& )
    {
        return std::unexpected( error_code::filesystem_error );
    }
    catch( const std::bad_alloc& )
    {
        return std::unexpected( error_code::memory_error );
    }
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
