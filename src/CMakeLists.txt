set(BINARY ${CMAKE_PROJECT_NAME})

add_executable(${BINARY}_run main.cpp MorseCoder.cpp MorseCoder.h LetterChecker.cpp LetterChecker.h)

find_package(Boost 1.7 REQUIRED)

target_include_directories(${BINARY}_run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${BINARY}_run PRIVATE ${Boost_INCLUDE_DIRS}) 
target_link_libraries(${BINARY}_run ${Boost_LIBRARIES})

add_library(${BINARY}_lib MorseCoder.cpp MorseCoder.h)

target_include_directories(${BINARY}_lib PRIVATE ${Boost_INCLUDE_DIRS}) 
target_link_libraries(${BINARY}_lib ${Boost_LIBRARIES})