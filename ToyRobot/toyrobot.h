#ifndef TOYROBOT_H
#define TOYROBOT_H

#include <string>
#include <unordered_map>

// Table top dimension
#define GRID_SIZE_X  5
#define GRID_SIZE_Y  5

enum Direction {
   UNKNOWN = -1,
   NORTH,
   EAST,
   SOUTH,
   WEST
};

class ToyRobot {
public:
   ToyRobot();
   ~ToyRobot();

   void Place(int _x, int _y, Direction _dir);
   void Move();
   void Left();
   void Right();
   int GetX();
   int GetY();
   Direction GetDirection();
   std::string Report() const;

   // Maps for direction conversions
   static const std::unordered_map<std::string, Direction> directionMap;

private:
   int x, y;
   Direction direction;
   bool isPlaced;
   bool isPositionValid(int x, int y);
   std::string GetDirectionString(Direction dir) const;

};

#endif // TOYROBOT_H
