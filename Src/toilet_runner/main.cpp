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
