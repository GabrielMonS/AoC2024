add_executable(Day5Solver)

target_sources(Day5Solver
    PRIVATE
        main.cpp
        functions.cpp
)

target_include_directories(Day5Solver
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
