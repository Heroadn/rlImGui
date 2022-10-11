cmake_minimum_required(VERSION 3.8)
project(rlImGui)

#policies
#from https://github.com/eliasdaler/imgui-sfml/blob/master/CMakeLists.txt
#just changed some names

# In CMake 3.12+ this policy will automatically take the rlImGui_ROOT environment variables
# into account as hints for the find_package calls.
if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()
# In CMake 3.13+ this policy enables you to define normal variables with option names as if you defined
# these options. Useful for add_subdirectory(rlImGui)
if(POLICY CMP0077)
  cmake_policy(SET CMP0077 NEW)
endif()

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

#options
set(IMGUI_BUILD_EXAMPLES OFF CACHE BOOL "Build Imgui examples" FORCE)
set(IMGUI_DEMO ON CACHE BOOL "Build imgui_demo.cpp" FORCE)
set(EXAMPLES OFF CACHE BOOL  "Build rlImGui examples." FORCE)

#subdirectories
add_subdirectory(lib/raylib)
add_subdirectory(lib/imgui)

#adding libs
add_library(rlImGui ${SOURCE_FILES} ${FA_FILES})
set_target_properties(rlImGui PROPERTIES OUTPUT_NAME "rlImGui")
target_include_directories(rlImGui PUBLIC ${imgui_SOURCE_DIR} )
target_link_libraries(rlImGui PUBLIC raylib imgui imgui-glfw imgui-opengl3 )

install(TARGETS rlImGui
		DESTINATION lib)
install(FILES ${HEADER_FILES} 
		DESTINATION include/rlImGui)

if (EXAMPLES)
    add_executable(Editor src/examples/editor.cpp)
    add_executable(Simple src/examples/simple.cpp)
    add_executable(Basic src/examples/basic.cpp)
    target_link_libraries(Editor rlImGui)
    target_link_libraries(Simple rlImGui)
    target_link_libraries(Basic rlImGui)
endif()
