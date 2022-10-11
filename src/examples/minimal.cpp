//minimal example for api
#include "../include/rlImGui.h"

int main(void)
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