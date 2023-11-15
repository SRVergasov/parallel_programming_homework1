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

# MPI
find_package(MPI REQUIRED)

add_executable(MPI1 mpi/task1_1/task1_1.cpp)
target_link_libraries(MPI1 PUBLIC MPI::MPI_CXX)

add_executable(MPI2 mpi/task1_2/task1_2.cpp)
target_link_libraries(MPI2 PUBLIC MPI::MPI_CXX)

add_executable(MPI3 mpi/task1_3/task1_3.cpp)
target_link_libraries(MPI3 PUBLIC MPI::MPI_CXX)

add_executable(MPI4 mpi/task1_4/task1_4.cpp)
target_link_libraries(MPI4 PUBLIC MPI::MPI_CXX)

add_executable(MPI5 mpi/task1_5/task1_5.cpp)
target_link_libraries(MPI5 PUBLIC MPI::MPI_CXX)

add_executable(MPI21_ mpi/task2_1/task2_1.cpp)
target_link_libraries(MPI21_ PUBLIC MPI::MPI_CXX)

add_executable(MPI22 mpi/task2_2/task2_2.cpp)
target_link_libraries(MPI22 PUBLIC MPI::MPI_CXX)

add_executable(MPI23 mpi/task2_3/task2_3.cpp)
target_link_libraries(MPI23 PUBLIC MPI::MPI_CXX)

add_executable(MPI24 mpi/task2_4/task2_4.cpp)
target_link_libraries(MPI24 PUBLIC MPI::MPI_CXX)

add_executable(MPI25 mpi/task2_5/task2_5.cpp)
target_link_libraries(MPI25 PUBLIC MPI::MPI_CXX)

add_executable(MPI31 mpi/task3_1/task3_1.cpp)
target_link_libraries(MPI31 PUBLIC MPI::MPI_CXX)

add_executable(MPI32 mpi/task3_2/task3_2.cpp)
target_link_libraries(MPI32 PUBLIC MPI::MPI_CXX)

add_executable(MPI33 mpi/task3_3/task3_3.cpp)
target_link_libraries(MPI33 PUBLIC MPI::MPI_CXX)

add_executable(MPI34 mpi/task3_4/task3_4.cpp)
target_link_libraries(MPI34 PUBLIC MPI::MPI_CXX)

add_executable(MPI35 mpi/task3_5/task3_5.cpp)
target_link_libraries(MPI35 PUBLIC MPI::MPI_CXX)