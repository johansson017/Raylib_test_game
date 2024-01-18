#pragma once

#include <vector>
#include <iostream>
#include "raylib.h"
#include "structObjects.h"

class ObstacleCircles
{
  public:
    //typedef struct oCircle {
      //float size;
      //Color color;
    //} oCircle;

    ObstacleCircles();

    ~ObstacleCircles(){};

    void GenerateCircle(int&, int&);

    void Draw();

  private:
    std::vector<Vector2> spawnedCircles;
    std::vector<Vector2>::iterator iter;
    oCircle circles;

};