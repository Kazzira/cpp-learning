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
