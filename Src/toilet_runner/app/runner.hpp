#ifndef __CPPLEARNING_TOILETRUNNER_APP_RUNNER_HPP__
/* --------------------------------------------------------------------------------
MIT License

Copyright (c) 2024 Zachary D Meyer
See bottom of file for full license.
--------------------------------------------------------------------------------
toilet_runner/app/runner.hpp

Parses a text file with one word per line and returns a vector of strings
that are toiletified.
*/
#define __CPPLEARNING_TOILETRUNNER_APP_RUNNER_HPP__


#include <cstdint>
#include <expected>
#include <filesystem>
#include <string>
#include <vector>
#include <utility>



namespace toilet_runner { namespace app {


using string_pair = std::pair<std::string, std::string>;


enum class error_code : std::int8_t
{
    file_not_found
,   filesystem_error
,   memory_error
};


[[nodiscard]]
std::expected<std::vector<string_pair>, error_code>
get_toilet_words_from_file(
    const std::filesystem::path&        a_file_path
);


}}


#endif


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