#include "ObstacleCircles.h"

ObstacleCircles::ObstacleCircles(){
  spawnedCircles = {};
  //circles.size = 20.0f;
  //circles.color = BLUE;
}

void ObstacleCircles::GenerateCircle(int& wMonitor, int& hMonitor){
  float rX = static_cast<float>(rand()) / RAND_MAX;
  float rY = static_cast<float>(rand()) / RAND_MAX;
  rX = wMonitor * rX;
  rY = hMonitor * rY;

  Vector2 circle = (Vector2){rX, rY};
  spawnedCircles.push_back(circle);
}

void ObstacleCircles::Draw(){
  for (iter = spawnedCircles.begin(); iter != spawnedCircles.end(); iter++){
    DrawCircleV(*iter, circles.size, circles.color);
  }
}

