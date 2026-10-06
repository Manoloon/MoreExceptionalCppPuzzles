
include(Catch)

function(add_catch_test TARGET)
    add_executable(${TARGET} ${ARGN})
    target_include_directories(${TARGET} PRIVATE ${PROJECT_SOURCE_DIR}/Src)
    target_link_libraries(${TARGET} PRIVATE Catch2::Catch2WithMain)
    catch_discover_tests(${TARGET}
        PROPERTIES
            LABELS ${TARGET}
        EXTRA_ARGS
#            --benchmark-samples 200
#            --benchmark-resamples 100000
            --reporter console
            --verbosity high)
endfunction()
# add_catch_test(
#     Puzzle_Tests
# )
