add_subdirectory(InputParser)
add_subdirectory(StringOps)

target_sources(sivtek PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/textio.h
        )