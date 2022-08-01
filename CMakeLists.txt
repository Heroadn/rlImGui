cmake_minimum_required(VERSION 3.8)
project(rlImGui)

set(SOURCE_FILES
    src/rlImGui.cpp
)

set(HEADER_FILES
    src/include/rlImGui.h
    src/include/rlImGuiColors.h
)

set(EXTRA_FILES
    extras/FA6FreeSolidFontData.h
    extras/IconsFontAwesome6.h
)

include_directories(src/include)

add_subdirectory(lib/raylib)
add_subdirectory(lib/ImGui)

add_library(rlImGui ${SOURCE_FILES} ${EXTRA_FILES})
set_target_properties(rlImGui PROPERTIES OUTPUT_NAME "rlImGui")

target_link_libraries(rlImGui ImGui)
target_link_libraries(rlImGui raylib)

install(TARGETS rlImGui
		DESTINATION lib)
install(FILES ${HEADER_FILES} 
		DESTINATION include/rlImGui)