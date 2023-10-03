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

add_executable(Task6 task6.cpp)
target_compile_options(Task6 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task6 PRIVATE ${OpenMP_CXX_FLAGS})

add_executable(Task7 task7.cpp)
target_compile_options(Task7 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task7 PRIVATE ${OpenMP_CXX_FLAGS})

add_executable(Task8 task8.cpp)
target_compile_options(Task8 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task8 PRIVATE ${OpenMP_CXX_FLAGS})

add_executable(Task9 task9.cpp)
target_compile_options(Task9 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task9 PRIVATE ${OpenMP_CXX_FLAGS})

add_executable(Task10 task10.cpp)
target_compile_options(Task10 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task10 PRIVATE ${OpenMP_CXX_FLAGS})

add_executable(Task11 task11.cpp)
target_compile_options(Task11 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task11 PRIVATE ${OpenMP_CXX_FLAGS})

add_executable(Task13 task13.cpp)
target_compile_options(Task13 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task13 PRIVATE ${OpenMP_CXX_FLAGS})

add_executable(Task14 task14.cpp)
target_compile_options(Task14 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task14 PRIVATE ${OpenMP_CXX_FLAGS})

add_executable(Task15 task15.cpp)
target_compile_options(Task15 PRIVATE -Wall ${OpenMP_CXX_FLAGS})
target_link_libraries(Task15 PRIVATE ${OpenMP_CXX_FLAGS})
