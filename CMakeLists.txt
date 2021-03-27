cmake_minimum_required(VERSION 3.17)
project(QuantumWell)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-static -O3")

add_executable(QuantumWell main.cpp function.cpp function.h fEven.cpp fEven.h fOdd.cpp fOdd.h
        eigenEnergies.cpp eigenEnergies.h Chromosome.cpp Chromosome.h Population.cpp Population.h random.h random2.h)