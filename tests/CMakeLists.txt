include (FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.16.0
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(Catch2)

add_executable(engine_tests test_hello.cpp)

target_link_libraries(engine_tests PRIVATE engine_core engine_warnings Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(engine_tests)