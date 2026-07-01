find_package(GTest REQUIRED)

add_executable(run_tests test_imt.cpp ../imt.cpp)

target_link_libraries(run_tests PRIVATE 
    GTest::gtest 
    GTest::gtest_main 
    pthread
)

include(GoogleTest)
gtest_discover_tests(run_tests)