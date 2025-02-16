# rlImGui
A Raylib integration with DearImGui

This repository is forked from the [original](https://github.com/raylib-extras/rlImGui)
 by [@raylib-extras](https://github.com/raylib-extras).

rlImgui provides a backend for [Dear ImGui](https://github.com/ocornut/imgui) using [Raylib](https://www.raylib.com/). 

# Building
This version of rlImGui is setup to use CMake to generate a static library. Optionally, examples can be built 
as well. rlImGui can be used as a static library, or by directly including the files into your game project.

## Commands

```sh
cmake -B bin && cmake --build bin -j$(nproc)
```

Build with examples:

```sh
cmake -B bin -DEXAMPLES=ON && cmake --build bin -j$(nproc)
```

# Setup

Using rlImGui in your code is very easy. Once you have included the library, or source files for rlImGui and ImGui in your project, simply do the following.
```
#include "rlImGui/rlImGui.h"	// include the API header

int main(int argc, char** argv)
{   
    int screenWidth = 900;
    int screenHeight = 600;

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "raylib-Extras [ImGui] example - ImGui Demo");

    // before your game loop
    rlImGuiSetup(true); 	// sets up ImGui with ether a dark or light default theme

    // inside your game loop, between BeginDrawing() and EndDrawing()
    rlImGuiBegin();			// starts the ImGui content mode. Make all ImGui calls after this

    rlImGuiEnd();			// ends the ImGui content mode. Make all ImGui calls before this

    // after your game loop is over, before you close the window

    rlImGuiShutdown();		// cleans up ImGui

    return 0;
}
```

# Examples
There are three example programs in the examples folder.

## Simple
This is the most simple use of ImGui in raylib, it just shows the ImGui demo window.
![image](https://user-images.githubusercontent.com/322174/136596910-da1b60ae-4a39-48f0-ae84-f568bc396870.png)


## Editor
This is a more complex example of ImGui, showing how to use raylib 2d and 3d cameras to draw into ImGui windows using render textures.
![image](https://user-images.githubusercontent.com/322174/136596949-033ffe0a-2476-4030-988a-5bf5b6e2ade7.png)

# Extras

## rlImGuiColors.h
This file has a converter to change Raylib colors into ImGui Colors

## Font Awesome Icons
Support for Font Awesome 6 https://fontawesome.com/ is built into rlImGui and enabled by default. You can simply
#include "extras/IconsFontAwesome6.h"
To use the ICON_FA macros for any icon in the free set.

If you wish to disable font awesome support you can #define NO_FONT_AWESOME


# Images
Raylib textures can be drawn in ImGui using the following functions
```
void rlImGuiImage(const Texture *image);
bool rlImGuiImageButton(const Texture *image);
void rlImGuiImageSize(const Texture *image, int width, int height);
void rlImGuiImageRect(const Texture* image, int destWidth, int destHeight, Rectangle sourceRect);
```

# C vs C++
ImGui is a C++ library, so rlImGui uses C++ to create the backend and integration with Raylib.
The rlImGui.h API only uses features that are common to C and C++, so rlImGui can be built as a static library and used by pure C code. Users of ImGui who wish to use pure C must use an ImGui wrapper, such as [https://github.com/cimgui/cimgui].


