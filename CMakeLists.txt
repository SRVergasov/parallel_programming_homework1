cmake_minimum_required(VERSION 3.26)
project(tasks)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenMP REQUIRED)

add_executable(Task1 task1.cpp)
target_compile_options(Task1 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task1 PRIVATE ${OpenMP_CXX_FLAGS})

add_executable(Task2 task2.cpp)
target_compile_options(Task2 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task2 PRIVATE ${OpenMP_CXX_FLAGS})

add_executable(Task3 task3.cpp)
target_compile_options(Task3 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task3 PRIVATE ${OpenMP_CXX_FLAGS})

add_executable(Task4 task4.cpp)
target_compile_options(Task4 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task4 PRIVATE ${OpenMP_CXX_FLAGS})

add_executable(Task5 task5.cpp)
target_compile_options(Task5 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task5 PRIVATE ${OpenMP_CXX_FLAGS})
