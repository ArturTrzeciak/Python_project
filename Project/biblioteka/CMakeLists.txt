cmake_minimum_required(VERSION 3.4)
project(biblioteka)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/Client.cpp
        src/Adress.cpp
        src/Vehicle.cpp 
        include/Vehicle.h
        src/Rent.cpp
        include/Rent.h
        include/RentException.h
        src/RentException.cpp
        include/ClientException.h
        src/ClientException.cpp
        src/ClientStart.cpp
        include/ClientTyp.h
        src/ClientTwo.cpp
        src/ClientThree.cpp
        src/ClientFour.cpp
        include/VechicleException.h include/VehicleRepository.h)

add_library(Biblioteka ${SOURCE_FILES} ${Boost_LIBRARIES})

#dolacz katalog z plikami naglowkowymi include z projektu biblioteka do sciezek
target_include_directories(Biblioteka PUBLIC include)

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
 ${CMAKE_CURRENT_SOURCE_DIR}/include
 ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_HUMAN_FILES
 Test/master.cpp
        Test/RentTest.cpp)

add_executable (TestRent ${SOURCE_TEST_HUMAN_FILES})

target_link_libraries (TestRent
 Biblioteka
 ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
 )

add_test(TestBiblioteki1 RentTest
 --report_level=detailed
 --log_level=all
 --color_output=yes
 --show_progress=true
 )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
