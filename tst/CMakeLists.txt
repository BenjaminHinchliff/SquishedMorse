set(BINARY ${CMAKE_PROJECT_NAME}_tst)

add_executable(${BINARY} main.cpp 
    "MorseCoderTest.cpp"
    "../src/MorseCoder.h"
    "../src/MorseCoder.cpp"
    "LetterCheckerTest.cpp"
    "../src/LetterChecker.h"
    "../src/LetterChecker.cpp"
)

target_include_directories(${BINARY} PRIVATE "../src")

# GTEST
enable_testing()
find_package(GTest CONFIG REQUIRED)
target_link_libraries(${BINARY} PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
add_test(AllTestsInMain ${BINARY})