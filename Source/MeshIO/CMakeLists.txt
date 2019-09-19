add_subdirectory(Cell)
add_subdirectory(MeshHandler)
add_subdirectory(SurfaceMesh)
add_subdirectory(MeshContinuum)
add_subdirectory(Region)
add_subdirectory(Boundary)
add_subdirectory(VolumeMesher)
#add_subdirectory(ObjHandler)
#add_subdirectory(SiloHandler)
#add_subdirectory(VtkHandler)

target_sources(sivtek PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/meshio.h
        ${CMAKE_CURRENT_LIST_DIR}/meshiovector.h
        ${CMAKE_CURRENT_LIST_DIR}/meshiomatrix3x3.h
        ${CMAKE_CURRENT_LIST_DIR}/meshiofaces.h
        ${CMAKE_CURRENT_LIST_DIR}/meshio_getmeshhandler.cc
        )