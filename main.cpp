#include <iostream>
#include "raylib.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    //Assignment
    InitWindow(800, 600, "Sprite Animation Program");
    Texture2D spriteSheet = LoadTexture("sprite_sheet.png");
    const float frameWidth = spriteSheet.width / 4;
    const float frameHeight = spriteSheet.height;
    float currentFrame = 0;
    float frameTime = 0.1f; // Time per frame
    float elapsedTime = 0.0f;


    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        elapsedTime += deltaTime;

        if (elapsedTime >= frameTime) {
            elapsedTime = 0.0f;
        }

        else if (IsKeyPressed(KEY_SPACE)) {
            currentFrame = 0;
        }

        currentFrame = 4; // Reset to frame 0 after the last frame

        Rectangle sourceRec = {currentFrame * frameWidth, 0, frameWidth, frameHeight};
        Vector2 position = {400 - frameWidth / 2, 300 - frameHeight / 2};

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureRec(spriteSheet, sourceRec, position, WHITE);

        EndDrawing();
    }

    UnloadTexture(spriteSheet);
    CloseWindow();

    return 0;
}