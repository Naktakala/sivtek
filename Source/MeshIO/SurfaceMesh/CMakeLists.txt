target_sources(sivtek PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/surfacemesh.h
        ${CMAKE_CURRENT_LIST_DIR}/surfacemesh_util_updateconnections.cc
        ${CMAKE_CURRENT_LIST_DIR}/surfacemesh_io_obj.cc
        ${CMAKE_CURRENT_LIST_DIR}/surfacemesh_io_vtk.cc
        ${CMAKE_CURRENT_LIST_DIR}/surfacemesh_io_silo.cc
        ${CMAKE_CURRENT_LIST_DIR}/surfacemesh_util_silo.cc
        )