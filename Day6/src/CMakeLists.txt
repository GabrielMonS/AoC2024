add_executable(Day6Solver)

target_sources(Day6Solver
    PRIVATE
        main.cpp
        functions.cpp
)

target_include_directories(Day6Solver
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
