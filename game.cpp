#include "game.h"

Game::Game(){
  score = 0;
  obstacles = ObstacleCircles();
}

void Game::Draw(){
  obstacles.Draw();
}
