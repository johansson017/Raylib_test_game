#include <iostream>
#include "raylib.h"
#include <vector>

double timeSinceLastSpawn;
std::vector<Vector2>::iterator iterCircle;

//void getResolution(int& horizontal, int& vertical){
    //RECT desktop;

    //const HWND hDesktop = GetDesktop
//}
void getResolution(int* horizontal, int* vertical, int& cMonitor){
    *horizontal = GetMonitorWidth(cMonitor);
    *vertical = GetMonitorHeight(cMonitor);
}

void setupWindowFullscreen(int& cMonitor, int& wMonitor, int& hMonitor){
    Vector2 wPos = GetMonitorPosition(cMonitor);
    SetWindowPosition(wPos.x, wPos.y);
    SetWindowSize((1+wMonitor), hMonitor);
}

void drawMouseCircle(){
    Vector2 pMouse = GetMousePosition();
    DrawCircleV(pMouse, 20.0f, RED);
}

void spawnObstacleCircles(std::vector<Vector2>& obstacleCircles, int& wMonitor, int& hMonitor){
    
    if (timeSinceLastSpawn > 1.5){
        float rX = static_cast<float>(rand()) / RAND_MAX;
        float rY = static_cast<float>(rand()) / RAND_MAX;
        rX = wMonitor*rX;
        rY = hMonitor*rY;
        Vector2 circle = (Vector2){rX, rY};
        obstacleCircles.push_back(circle);
    }
    timeSinceLastSpawn = GetTime();
    //DrawCircle(wMonitor*rX, hMonitor*rY, circleSize, BLUE);
}

void drawObstacleCircles(std::vector<Vector2>& obstacleCircles){
    for (iterCircle = obstacleCircles.begin(); iterCircle != obstacleCircles.end(); iterCircle++){
        DrawCircleV(*iterCircle, 20.0f, BLUE);
    }
}

void collectedCircle(std::vector<Vector2>& obstacleCircles, Vector2& pMouse, int& score){
    for (iterCircle = obstacleCircles.begin(); iterCircle < obstacleCircles.end(); iterCircle++){
        if (CheckCollisionCircles(*iterCircle, 20.0f, pMouse, 20.0f)){
            score++;
            iterCircle = obstacleCircles.erase(iterCircle);
        }
    }
}

int main(){
    int horizontal = 800;
    int vertical = 600;
    int cMonitor = 1;
    srand(time(NULL));

    InitWindow(horizontal, vertical, "My first program");
    SetTargetFPS(60);
    HideCursor();

    int wMonitor = GetMonitorWidth(cMonitor)/2;
    int hMonitor = GetMonitorHeight(cMonitor)/2;
    //std::cout << wMonitor << " " << hMonitor << std::endl;

    setupWindowFullscreen(cMonitor, wMonitor, hMonitor);

    std::vector<Vector2> obstacleCircles = {};
    spawnObstacleCircles(obstacleCircles, wMonitor, hMonitor);

    int score = 0;
    while (!WindowShouldClose())
    {
        Vector2 pMouse = GetMousePosition();
        //checkCircleCollision(obstacleCircles, pMouse);
        if (GetTime() - timeSinceLastSpawn >= 0.5) {
            spawnObstacleCircles(obstacleCircles, wMonitor, hMonitor);
        }

        collectedCircle(obstacleCircles, pMouse, score);

        /* BEGIN DRAWING*/
        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircleV(pMouse, 20.0f, RED);
        drawObstacleCircles(obstacleCircles);


        /* Draw details */
        DrawFPS(0,0);
        DrawText(TextFormat("%i", score), wMonitor*0.97, hMonitor*0.95, wMonitor/50, RED);

        EndDrawing();
    }
    return 0;
}
