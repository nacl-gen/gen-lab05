cmake_minimum_required(VERSION 2.8.2)

project(Gen-lab5)

add_executable(Gen-lab5 src/Customer.h src/Customer.cpp src/main.cpp src/Movie.h src/Movie.cpp src/Rental.h src/Rental.cpp src/pricecode/PriceCode.h src/pricecode/NewReleasePriceCode.h src/pricecode/RegularPriceCode.h src/pricecode/ChildrenPriceCode.h)

include(CTest)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()

# test executable
add_executable(tests src/Customer.h src/Customer.cpp src/Movie.h src/Movie.cpp test/CustomerTest.cpp test/MovieTest.cpp test/RentalTest.cpp src/Rental.cpp src/pricecode/PriceCode.h src/pricecode/NewReleasePriceCode.h src/pricecode/RegularPriceCode.h src/pricecode/ChildrenPriceCode.h test/PriceCodeTest.cpp)
target_link_libraries(tests gtest gmock_main)
add_test(NAME tests COMMAND tests)
