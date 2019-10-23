add_subdirectory(ParaviewFunctions)


target_sources(sivtek PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/meshcontinuum.h
        ${CMAKE_CURRENT_LIST_DIR}/meshcontinuum_io_vtk.cc
        ${CMAKE_CURRENT_LIST_DIR}/meshcontinuum_io_silo.cc
        ${CMAKE_CURRENT_LIST_DIR}/meshcontinuum_util_silo.cc
        ${CMAKE_CURRENT_LIST_DIR}/meshcontinuum_io_abaqus.cc
        )