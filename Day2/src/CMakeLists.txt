add_executable(Day2Solver)

target_sources(Day2Solver
    PRIVATE
        main.cpp
        functions.cpp
)

target_include_directories(Day2Solver
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
