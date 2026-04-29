#include "raylib.h"
#include "vec2.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Fluid Simulator");
    
    SetTargetFPS(60);
    
    Vec2 v1 = {2, 3};
    Vec2 v2 = {7, 12};
    Vec2 v3 = v1 + v2;

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(TextFormat("Sum: <%f, %f>", v3.x, v3.y), 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
