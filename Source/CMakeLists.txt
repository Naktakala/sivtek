add_subdirectory(TextIO)
add_subdirectory(LogIO)
add_subdirectory(MeshIO)

target_sources(sivtek PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/main.h
        ${CMAKE_CURRENT_LIST_DIR}/main.cc
        )
