set(
	INCLUDE_DIR
	3DEngine
)

include_directories(
	${INCLUDE_DIR}
	../
)

set(
    ALL_HEADERS
    ../${INCLUDE_DIR}/Core/core.h
    ../${INCLUDE_DIR}/Core/EntryPoint.h
    ../${INCLUDE_DIR}/Core/Layer.h
    ../${INCLUDE_DIR}/Core/Timer.h
    ../${INCLUDE_DIR}/Core/Random.h
    ../${INCLUDE_DIR}/Core/EngineLogger.h
    ../${INCLUDE_DIR}/Events/Event.h
    ../${INCLUDE_DIR}/Events/KeyEvent.h
    ../${INCLUDE_DIR}/Events/MouseEvent.h
    ../${INCLUDE_DIR}/interfaces/Window.h
    ../${INCLUDE_DIR}/Core/LayerStack.h
    ../${INCLUDE_DIR}/Events/InputPoll.h


)

set(
    ALL_SOURCES
    ${INCLUDE_DIR}/Core/Application.cpp
    ${INCLUDE_DIR}/Core/EntryPoint.cpp
    ${INCLUDE_DIR}/ImGui/ImGuiBuild.cpp
    ${INCLUDE_DIR}/Core/EngineLogger.cpp
    ${INCLUDE_DIR}/Events/Event.cpp
    ${INCLUDE_DIR}/interfaces/Window.cpp
    ${INCLUDE_DIR}/Core/Layer.cpp
    ${INCLUDE_DIR}/Core/LayerStack.cpp
    ${INCLUDE_DIR}/Events/InputPoll.cpp
)


add_library(${PROJECT_NAME} ${ALL_SOURCES} ${ALL_HEADERS})

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../${INCLUDE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)


set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

if(MSVC)
	set_target_properties(${PROJECT_NAME} PROPERTIES
    COMPILE_PDB_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
	COMPILE_PDB_NAME ${PROJECT_NAME}
  )

  install(
	  FILES "${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/${PROJECT_NAME}.pdb"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
    OPTIONAL
  )
endif()

if (BUILD_SHARED_LIBS)
	target_compile_definitions(${PROJECT_NAME}
    PUBLIC
	${PROJECT_NAME}_SHARED
  )
endif()

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "src" FILES ${all_src})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/../${INCLUDE_DIR}" PREFIX "include" FILES ${all_headers})

install(
	TARGETS ${PROJECT_NAME}
	EXPORT ${PROJECT_NAME}Config
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
	EXPORT ${PROJECT_NAME}Config
	NAMESPACE 3DEngine::
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  COMPATIBILITY SameMajorVersion
)

install(
	FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)