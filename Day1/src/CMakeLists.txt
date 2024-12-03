add_executable(Day1Solver)

target_sources(Day1Solver
    PRIVATE
        main.cpp
        functions.cpp
)

target_include_directories(Day1Solver
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
