cmake_minimum_required(VERSION 3.8)
project(rlImGui)

set(SOURCE_FILES
    src/rlImGui.cpp
)

set(HEADER_FILES
    src/include/rlImGui.h
    src/include/rlImGuiColors.h
)

set(FA_FILES
    lib/FontAwesome/FA6FreeSolidFontData.h
    lib/FontAwesome/IconsFontAwesome6.h
)

include_directories(src/include)

add_subdirectory(lib/raylib)
add_subdirectory(lib/ImGui)

add_library(rlImGui ${SOURCE_FILES} ${FA_FILES})
set_target_properties(rlImGui PROPERTIES OUTPUT_NAME "rlImGui")

target_link_libraries(rlImGui ImGui raylib)

install(TARGETS rlImGui
		DESTINATION lib)
install(FILES ${HEADER_FILES} 
		DESTINATION include/rlImGui)

option(EXAMPLES "Build rlImGui examples." OFF)
if (EXAMPLES)
    add_executable(Editor src/examples/editor.cpp)
    add_executable(Simple src/examples/simple.cpp)
    target_link_libraries(Editor ImGui raylib rlImGui)
    target_link_libraries(Simple ImGui raylib rlImGui)
endif()
