/* --------------------------------------------------------------------------------
MIT License

Copyright (c) 2024 Zachary D Meyer
See bottom of file for full license.
--------------------------------------------------------------------------------
toilet_runner/main.cpp

Reads a dictionary file and outputs every toiletified word.
*/
#include <filesystem>
#include <iostream>

#include "toilet_runner/app/runner.hpp"


int main(
    int                                 argc
,   char**                              argv
)
{
    if( argc != 2 )
    {
        std::cerr << "Arguments: toilet_runner PATH_TO_FILE\n";
        return 1;
    }

    std::filesystem::path               file_path( argv[ 1 ] );

    auto result = toilet_runner::app::get_toilet_words_from_file( file_path );

    if( !result )
    {
        switch( result.error() )
        {
        using enum toilet_runner::app::error_code;

        case file_not_found:
            std::cerr << "File " << file_path << " not found!\n";
            return 2;
        case filesystem_error:
            std::cerr << "Unknown filesystem error occured!\n";
            return 3;
        case memory_error:
            std::cerr << "Unknown memory error occured!\n";
            return 4;
        }
    }

    for( const auto& word_pair : *result )
    {
        std::cout << word_pair.first << "\t" << word_pair.second << "\n";
    }

    return 0;
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
