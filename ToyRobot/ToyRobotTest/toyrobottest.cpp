#include "stdafx.h"
#include "CppUnitTest.h"

#include "../toyrobot.cpp"
#include "../controller.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ToyRobotTest
{		

   TEST_CLASS(ToyRobotTest)
	{
	public:
		
      TEST_METHOD(ToyRobot_Constructor)
      {
         ToyRobot toyRobot;

         Assert::AreEqual(toyRobot.GetX(), -1);
         Assert::AreEqual(toyRobot.GetY(), -1);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(UNKNOWN));
      }

      TEST_METHOD(ToyRobot_Place_0_0_N)
      {
         ToyRobot toyRobot;

         toyRobot.Place(0, 0, NORTH);
         Assert::AreEqual(toyRobot.GetX(), 0);
         Assert::AreEqual(toyRobot.GetY(), 0);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(NORTH));
      }

      TEST_METHOD(ToyRobot_Place_2_3_W)
      {
         ToyRobot toyRobot;

         toyRobot.Place(2, 3, WEST);
         Assert::AreEqual(toyRobot.GetX(), 2);
         Assert::AreEqual(toyRobot.GetY(), 3);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(WEST));
      }

      TEST_METHOD(ToyRobot_Place_OutofBounds)
      {
         ToyRobot toyRobot;

         toyRobot.Place(5, 5, SOUTH);
         Assert::AreEqual(toyRobot.GetX(), -1);
         Assert::AreEqual(toyRobot.GetY(), -1);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(UNKNOWN));
      }

      TEST_METHOD(ToyRobot_Move_X)
      {
         ToyRobot toyRobot;
         toyRobot.Place(0, 0, EAST);
         toyRobot.Move();
         Assert::AreEqual(toyRobot.GetX(), 1);
         Assert::AreEqual(toyRobot.GetY(), 0);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(EAST));
      }

      TEST_METHOD(ToyRobot_Move_Y)
      {
         ToyRobot toyRobot;
         toyRobot.Place(0, 0, NORTH);
         toyRobot.Move();
         Assert::AreEqual(toyRobot.GetX(), 0);
         Assert::AreEqual(toyRobot.GetY(), 1);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(NORTH));
      }

      TEST_METHOD(ToyRobot_Move_X_OutofBounds)
      {
         ToyRobot toyRobot;
         toyRobot.Place(4, 4, EAST);
         toyRobot.Move();
         Assert::AreEqual(toyRobot.GetX(), 4);
         Assert::AreEqual(toyRobot.GetY(), 4);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(EAST));
      }

      TEST_METHOD(ToyRobot_Move_Y_OutofBounds)
      {
         ToyRobot toyRobot;
         toyRobot.Place(4, 4, NORTH);
         toyRobot.Move();
         Assert::AreEqual(toyRobot.GetX(), 4);
         Assert::AreEqual(toyRobot.GetY(), 4);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(NORTH));
      }

      TEST_METHOD(ToyRobot_Move_Unplaced)
      {
         ToyRobot toyRobot;
         toyRobot.Move();
         Assert::AreEqual(toyRobot.GetX(), -1);
         Assert::AreEqual(toyRobot.GetY(), -1);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(UNKNOWN));
      }

      TEST_METHOD(ToyRobot_Left)
      {
         ToyRobot toyRobot;
         toyRobot.Place(0, 0, NORTH);
         toyRobot.Left();
         Assert::AreEqual(toyRobot.GetX(), 0);
         Assert::AreEqual(toyRobot.GetY(), 0);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(WEST));
      }

      TEST_METHOD(ToyRobot_Right)
      {
         ToyRobot toyRobot;
         toyRobot.Place(0, 0, NORTH);
         toyRobot.Right();
         Assert::AreEqual(toyRobot.GetX(), 0);
         Assert::AreEqual(toyRobot.GetY(), 0);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(EAST));
      }

      TEST_METHOD(ToyRobot_Left_Unplaced)
      {
         ToyRobot toyRobot;
         toyRobot.Left();
         Assert::AreEqual(toyRobot.GetX(), -1);
         Assert::AreEqual(toyRobot.GetY(), -1);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(UNKNOWN));
      }

      TEST_METHOD(ToyRobot_Right_Unplaced)
      {
         ToyRobot toyRobot;
         toyRobot.Left();
         Assert::AreEqual(toyRobot.GetX(), -1);
         Assert::AreEqual(toyRobot.GetY(), -1);
         Assert::AreEqual(int(toyRobot.GetDirection()), int(UNKNOWN));
      }
	};
}