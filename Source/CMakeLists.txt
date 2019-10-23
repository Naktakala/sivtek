add_subdirectory(MeshIO)
add_subdirectory(TimerIO)
add_subdirectory(TextIO)

target_sources(sivtek PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/main.h
        ${CMAKE_CURRENT_LIST_DIR}/main.cc
        )
