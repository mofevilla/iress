#include "controller.h"
#include <sstream>
#include <stdexcept>
#include <vector>
#include <iostream>

Controller::Controller(ToyRobot& robot) 
: robot(robot) 
{}

void Controller::Parse(const std::string& command) {

   std::string action;
   action = command.substr(0, command.find(" "));

   if (action == "PLACE") HandlePlace(command);
   else if (action == "MOVE") HandleMove();
   else if (action == "LEFT") HandleLeft();
   else if (action == "RIGHT") HandleRight();
   else if (action == "REPORT") HandleReport();
}

void Controller::HandlePlace(const std::string& args) {

   std::istringstream stringStream(args);
   std::string token;

   std::vector<std::string> tokens;

   try {
      if (!getline(stringStream, token, ' ')) throw std::invalid_argument("Invalid format");
      
      // Parse x, y and direction
      while (getline(stringStream, token, ',')) {
         tokens.push_back(token);
      }

      if (tokens.size() != 3) throw std::invalid_argument("Invalid number of args");
      // Get second token as y
      const int x = stoi(tokens.at(0)); // Get first token as x 
      const int y = stoi(tokens.at(1)); // Get second token as y
      Direction direction = ToyRobot::directionMap.at(tokens.at(2)); // Get third token as direction

      // Place the robot
      robot.Place(x, y, direction);
   }
   catch (const std::invalid_argument&) {
      std::cerr << "Invalid format of PLACE command" << std::endl;
   }
}

void Controller::HandleMove() 
{
   robot.Move();
}

void Controller::HandleLeft() 
{
   robot.Left();
}

void Controller::HandleRight() 
{
   robot.Right();
}

void Controller::HandleReport() 
{
   std::cout << robot.Report() << std::endl;
}
