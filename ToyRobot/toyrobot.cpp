#include "toyrobot.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

const std::unordered_map<std::string, Direction> ToyRobot::directionMap = {
   { "NORTH", NORTH },
   { "EAST", EAST },
   { "SOUTH", SOUTH },
   { "WEST", WEST }
};

ToyRobot::ToyRobot() 
: x(-1)
, y(-1)
, direction(UNKNOWN)
, isPlaced(false) 
{
}

ToyRobot::~ToyRobot()
{
}

void ToyRobot::Place(int _x, int _y, Direction _dir) 
{
   if (!isPositionValid(_x, _y)) return; // Ignore "PLACE" command if x and y are invalid
   x = _x;
   y = _y;
   direction = _dir;
   isPlaced = true;
}

void ToyRobot::Move() 
{
   if (!isPlaced) return; // Ignore "MOVE" command if not yet placed

   switch (direction) {
      case NORTH: if (y < (GRID_SIZE_Y - 1)) ++y; break;
      case SOUTH: if (y > 0) --y; break;
      case EAST: if (x < (GRID_SIZE_X - 1)) ++x; break;
      case WEST: if (x > 0) --x; break;
      default: break;
   }
}

void ToyRobot::Left() 
{
   if (!isPlaced) return; // Ignore "LEFT" command if not yet placed

   direction = static_cast<Direction>((direction + 3) % 4); // Rotate left
}

void ToyRobot::Right()
{
   if (!isPlaced) return; // Ignore "RIGHT" command if not yet placed

   direction = static_cast<Direction>((direction + 1) % 4); // Rotate right
}

std::string ToyRobot::GetDirectionString(Direction dir) const
{
   for (const auto& dir : directionMap)
   {
      if (dir.second == direction) return dir.first;
   }
}

std::string ToyRobot::Report() const 
{
   if (!isPlaced) return ""; // Report nothing if not yet placed

   std::ostringstream oss;
   oss << x << "," << y << "," << GetDirectionString(direction);
   return oss.str();
}

bool ToyRobot::isPositionValid(int x, int y)
{
   // Check if x and y are still in bounds
   if (x < 0 || x >= GRID_SIZE_X || y < 0 || y >= GRID_SIZE_Y) return false;
   return true;
}

int ToyRobot::GetX()
{
   return x;
}

int ToyRobot::GetY()
{
   return y;
}

Direction ToyRobot::GetDirection()
{
   return direction;
}
