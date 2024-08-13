#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include "toyrobot.h"

class Controller {
public:
   Controller(ToyRobot& robot);
   void Parse(const std::string& command);

private:
   ToyRobot& robot;
   void HandlePlace(const std::string& args);
   void HandleMove();
   void HandleLeft();
   void HandleRight();
   void HandleReport();
};

#endif // CONTROLLER_H
