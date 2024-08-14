#include <iostream>
#include <string>
#include <fstream>
#include "controller.h"
#include "toyrobot.h"

void processCommands(std::istream& input) {
   ToyRobot robot;
   Controller controller(robot);
   std::string command;

   while (std::getline(input, command)) {
      controller.Parse(command);
   }
}

int main(int argc, char* argv[]) {
   if (argc > 1) {
      // File input
      std::ifstream file(argv[1]);
      if (!file.is_open()) {
         std::cerr << "Error: Could not open file " << argv[1] << std::endl;
         return 1;
      }
      processCommands(file);
   }
   else {
      // Command line input
      processCommands(std::cin);
   }
   return 0;
}
