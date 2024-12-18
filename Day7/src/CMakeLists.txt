add_executable(Day7Solver)

target_sources(Day7Solver
    PRIVATE
        main.cpp
        functions.cpp
)

target_include_directories(Day7Solver
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
