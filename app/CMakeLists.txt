set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(PROJECT_SOURCES
  main.cc
)

set(PROJECT_PUBLIC_HEADERS
)

set(PROJECT_PRIVATE_HEADERS
)

source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("Public headers" FILES ${PROJECT_PUBLIC_HEADERS})
source_group("Private headers" FILES ${PROJECT_PRIVATE_HEADERS})

add_executable(app.out
  ${PROJECT_SOURCES} ${PROJECT_PUBLIC_HEADERS} ${PROJECT_PRIVATE_HEADERS}
)

set_target_properties(app.out PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(app.out PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(app.out PUBLIC vw)
# Consuming Boost uuid requires BCrypt, normally this is automatically linked but vcpkg turns this feature off.
if(WIN32)
  target_link_libraries(app.out PUBLIC bcrypt)
endif()

if(TURN_OFF_DEVIRTUALIZE)
  target_compile_options(app.out PUBLIC -fno-devirtualize)
endif()