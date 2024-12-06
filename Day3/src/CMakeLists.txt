add_executable(Day3Solver)

target_sources(Day3Solver
    PRIVATE
        main.cpp
        functions.cpp
)

target_include_directories(Day3Solver
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
