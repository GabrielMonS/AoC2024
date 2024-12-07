add_executable(Day4Solver)

target_sources(Day4Solver
    PRIVATE
        main.cpp
        functions.cpp
)

target_include_directories(Day4Solver
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
