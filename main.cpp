#include <iostream>
#include "raylib.h"
using namespace std;

struct Ball {
    float x, y;
    float speedX, speedY;

    void draw() {
        DrawCircle((int) x, (int) y, 5.0f, WHITE);
    }
};

struct Paddle {
    float x, y;
    float speed;
    float width, height;

    void draw() {
        DrawRectangle(x, y, width, height, WHITE);
    }
};

int main() {

    InitWindow(800, 600, "Pong");
    SetWindowState(FLAG_VSYNC_HINT);

    Ball ball;
     ball.speedX = 100;
     ball.speedY = 300;
     ball.x = GetScreenWidth() / 2.0f;
     ball.y = GetScreenHeight() / 2.0f;

     Paddle leftPaddle;
     leftPaddle.x = 50;
     leftPaddle.y = GetScreenHeight() / 2 - 50;
     leftPaddle.width = 10;
     leftPaddle.height = 100;
     leftPaddle.speed = 500;

     Paddle rightPaddle;
     rightPaddle.x = 50;
     rightPaddle.y = GetScreenHeight() / 2 - 50;
     rightPaddle.width = 10;
     rightPaddle.height = 100;
     rightPaddle.speed = 500;

    cout << "Started!\n";

    while (!WindowShouldClose()) {

        ball.x += GetFrameTime() * ball.speedX;
        ball.y += GetFrameTime() * ball.speedY;

        if (ball.y < 0) {
            ball.y = 0;
            ball.speedY *= -1;
        }
        if (ball.y > GetScreenHeight()) {
            ball.y = GetScreenHeight();
            ball.speedY *= -1;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            
            ball.draw();
            
            rightPaddle.draw();
            leftPaddle.draw();

            DrawFPS(50, 50);
        EndDrawing();

    }

    
    //Destroy and close everything (cause memory leaks) once exiting the program
    CloseWindow();
    return 1;
}