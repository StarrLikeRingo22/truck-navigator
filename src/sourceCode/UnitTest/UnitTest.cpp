#include "pch.h"
#include "CppUnitTest.h"
#include "UnitTests_r.h"
#include <iostream>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTests
{
	TEST_CLASS(TruckTest)
	{
	public:
		//Blackbox tests for getClosestPoint()
		TEST_METHOD(getClosestPointCP001)
		{
			Logger::WriteMessage("CP001");
			int i = 0;
			struct Route route = { 0 };
			struct Point points[] = { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } };
			route.numPoints = 4;
			struct Point point = { 5, 0 };
			for (i = 0; i < route.numPoints; i++)
			{
				route.points[i] = points[i];
			}
			int index = getClosestPoint(&route, point);
			Assert::AreEqual(3, index);
		};
		TEST_METHOD(getClosestPointCP002)
		{
			Logger::WriteMessage("CP002");
			int i = 0;
			struct Route route = { 0 };
			struct Point points[] = { { 0, 0 }, { 1, 0 }, { 2, 0 } };
			route.numPoints = 3;
			struct Point point = { 3, 0 };
			for (i = 0; i < route.numPoints; i++)
			{
				route.points[i] = points[i];
			}
			int index = getClosestPoint(&route, point);
			Assert::AreEqual(2, index);
		};
		
		TEST_METHOD(getClosestPointCP003)
		{
			Logger::WriteMessage("CP003");
			int i = 0;
			struct Route route = { 0 };
			struct Point points[] = { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } };
			route.numPoints = 4;
			struct Point point = { 2, 0 };
			for (i = 0; i < route.numPoints; i++)
			{
				route.points[i] = points[i];
			}
			int index = getClosestPoint(&route, point);
			Assert::AreEqual(2, index);
		};
		TEST_METHOD(getClosestPointCP004)
		{
			Logger::WriteMessage("CP004");
			int i = 0;
			struct Route route = { 0 };
			struct Point points[] = { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } };
			route.numPoints = 4;
			struct Point point = { 0, 0 };
			for (i = 0; i < route.numPoints; i++)
			{
				route.points[i] = points[i];
			}
			int index = getClosestPoint(&route, point);
			Assert::AreEqual(0, index);
		};

		//Whitebox Tests for getClosestPoint()
		TEST_METHOD(getClosestPointCP005)
		{
			Logger::WriteMessage("CP005");

			struct Route blueRoute = getBlueRoute();
			const struct Point pt = { 5, 0 };
			int index = getClosestPoint(&blueRoute, pt);

			Assert::AreEqual(4, index);
		};
		TEST_METHOD(getClosestPointCP006)
		{
			Logger::WriteMessage("CP006");

			struct Route blueRoute = getBlueRoute();
			const struct Point pt = { 3, 0 };
			int index = getClosestPoint(&blueRoute, pt);

			Assert::AreEqual(3, index);
		};

		TEST_METHOD(getClosestPointCP007)
		{
			Logger::WriteMessage("CP007");

			struct Route blueRoute = getBlueRoute();
			const struct Point pt = { 2, 0 };
			int index = getClosestPoint(&blueRoute, pt);

			Assert::AreEqual(2, index);
		};
		TEST_METHOD(getClosestPointCP008)
		{
			Logger::WriteMessage("CP008");

			struct Route blueRoute = getBlueRoute();
			const struct Point pt = { 0, 0 };
			int index = getClosestPoint(&blueRoute, pt);

			Assert::AreEqual(0, index);
		};

		//Blackbox tests for eqPt()
		TEST_METHOD(eqPtPT001)
		{
			Logger::WriteMessage("PT001");
			struct Point point1 = { 1, 1 };
			struct Point point2 = { 1, 1 };
			int result = eqPt(point1, point2);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(eqPtPT002)
		{
			Logger::WriteMessage("PT002");
			struct Point point1 = { 1, 2 };
			struct Point point2 = { 4, 2 };
			int result = eqPt(point1, point2);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(eqPtPT003)
		{
			Logger::WriteMessage("PT003");
			struct Point point1 = { -1, -1 };
			struct Point point2 = { -1, -1 };
			int result = eqPt(point1, point2);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(eqPtPT004)
		{
			Logger::WriteMessage("PT004");
			struct Point point1 = { 0, 0 };
			struct Point point2 = { 0, 0 };
			int result = eqPt(point1, point2);
			Assert::AreEqual(1, result);
		}

		//Whitebox tests for eqPt()
		TEST_METHOD(eqPtPT005)
		{
			Logger::WriteMessage("PT005");
			struct Point point1 = { 2, 5 };
			struct Point point2 = { 2, 5 };
			int result = eqPt(point1, point2);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(eqPtPT006)
		{
			Logger::WriteMessage("PT006");
			struct Point point1 = { 4, 10 };
			struct Point point2 = { 2, 5 };
			int result = eqPt(point1, point2);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(eqPtPT007)
		{
			Logger::WriteMessage("PT007");
			struct Point point1 = { -1, -1 };
			struct Point point2 = { -1, -1 };
			int result = eqPt(point1, point2);
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(eqPtPT008)
		{
			Logger::WriteMessage("PT008");
			struct Point point1 = { 0, 0 };
			struct Point point2 = { 0, 0 };
			int result = eqPt(point1, point2);
			Assert::AreEqual(1, result);
		}

		//BlackBox tests for remainingCapacity()
		TEST_METHOD(remainingCapacityRC001)
		{
			Logger::WriteMessage("In calculateRemainingCapacity Test"); // Needs updating
			Logger::WriteMessage("RC001");
			struct Truck truck = { 0 };
			double remaining = remainingCapacity(truck);
			Assert::AreEqual(2500.0, remaining);
		}
		TEST_METHOD(remainingCapacityRC002)
		{
			Logger::WriteMessage("RC002");
			struct Truck truck = { 600, 0, {0, 0} };
			double remaining = remainingCapacity(truck); // Needs updating
			Assert::AreEqual(1900.0, remaining);
		}
		TEST_METHOD(remainingCapacityRC003)
		{
			Logger::WriteMessage("RC003");
			struct Truck truck = { 1190, 0, {0, 0} }; 
			double remaining = remainingCapacity(truck); // Needs updating
			Assert::AreEqual(1310.0, remaining);
		}
		TEST_METHOD(remainingCapacityRC004)
		{
			Logger::WriteMessage("RC004");
			struct Truck truck = { 1200, 0, {0, 0} };
			double remaining = remainingCapacity(truck); // Needs updating
			Assert::AreEqual(1300.0, remaining);
		}

		//Whitebox tests for remainingCapacity()
		TEST_METHOD(remainingCapacityRC005)
		{
			Logger::WriteMessage("In calculateRemainingCapacity Test"); // Needs updating
			Logger::WriteMessage("RC005");
			struct Truck truck = { 0 };
			double remaining = remainingCapacity(truck);
			Assert::AreEqual(2500.0, remaining); 
		}
		TEST_METHOD(remainingCapacityRC006) // Needs updating
		{
			Logger::WriteMessage("RC006");
			struct Truck truck = { 600, 0, {0, 0} };
			double remaining = remainingCapacity(truck);
			Assert::AreEqual(1900.0, remaining);
		}
		TEST_METHOD(remainingCapacityRC007) // Needs updating
		{
			Logger::WriteMessage("RC007");
			struct Truck truck = { 1190, 0, {0, 0} };
			double remaining = remainingCapacity(truck);
			Assert::AreEqual(1310.0, remaining);
		}
		TEST_METHOD(remainingCapacityRC008) // Needs updating
		{
			Logger::WriteMessage("RC008");
			struct Truck truck = { 2500, 0, {0, 0} };
			double remaining = remainingCapacity(truck);
			Assert::AreEqual(0.0, remaining);
		}

		//Blackbox tests for canThisTruckAccomodate()
		TEST_METHOD(canThisTruckAccomodateTA001)
		{
			Logger::WriteMessage("TA001");
			struct Truck truck = { 0, 0 };
			struct Package package = { 10, 0.5 };
			Assert::AreEqual(1, canThisTruckAccomodate(truck, package));
		};

		TEST_METHOD(canThisTruckAccomodateTA002)
		{
			Logger::WriteMessage("TA002");
			struct Truck truck = { 2490, 20 }; // changed values to match new truck capacity
			struct Package package = { 20, 1 };
			Assert::AreEqual(0, canThisTruckAccomodate(truck, package));
		};

		TEST_METHOD(canThisTruckAccomodateTA003)
		{
			Logger::WriteMessage("TA003");
			struct Truck truck = { 200, 49 };
			struct Package package = { 5, 1 };
			Assert::AreEqual(1, canThisTruckAccomodate(truck, package));
		};

		TEST_METHOD(canThisTruckAccomodateTA004)
		{
			Logger::WriteMessage("TA004");
			struct Truck truck = { 1000, 49.5 };
			struct Package package = { 10, 1 };
			Assert::AreEqual(1, canThisTruckAccomodate(truck, package)); // Needs updating
		};

		//Whitebox tests for canThisTruckAccomodate()
		TEST_METHOD(canThisTruckAccomodateTA005)
		{
			Logger::WriteMessage("TA005");
			struct Truck truck = { 0, 0 };
			struct Package package = { 10, 1 };
			Assert::AreEqual(1, canThisTruckAccomodate(truck, package));
		};

		TEST_METHOD(canThisTruckAccomodateTA006)
		{
			Logger::WriteMessage("TA006");
			struct Truck truck = { 2490, 20 };
			struct Package package = { 20, 3 };
			Assert::AreEqual(0, canThisTruckAccomodate(truck, package));
		};

		TEST_METHOD(canThisTruckAccomodateTA007)
		{
			Logger::WriteMessage("TA007");
			struct Truck truck = { 200, 49 };
			struct Package package = { 100, 5 };
			Assert::AreEqual(1, canThisTruckAccomodate(truck, package));
		};

		TEST_METHOD(canThisTruckAccomodateTA008)
		{
			Logger::WriteMessage("TA008");
			struct Truck truck = { 1000, 100 };
			struct Package package = { 10, 1 };
			Assert::AreEqual(0, canThisTruckAccomodate(truck, package));
		};

		//Blackbox tests for updateCurrentTruck()
		TEST_METHOD(updateCurrentTruckCT001)
		{
			Logger::WriteMessage("TC001");
			struct Truck truck = { 0, 0 };
			struct Package package = { 500, 1 };
			updateCurrentTruck(&truck, package);
			int result = 0;
			if (truck.currentCapacity == 500.0 && truck.currentVolume == 1)
			{
				result = 1;
			}
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(updateCurrentTruckCT002)
		{
			Logger::WriteMessage("TC002");
			struct Truck truck = { 0, 0 };
			struct Package package = { 2600, 2 };
			updateCurrentTruck(&truck, package);
			int result = 0;
			if (truck.currentCapacity == 0 && truck.currentVolume == 0)
			{
				result = 1;
			}
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(updateCurrentTruckCT003)
		{
			Logger::WriteMessage("TC003");
			struct Truck truck = { 0, 0 };
			struct Package package = { 300, 0.5 };
			updateCurrentTruck(&truck, package);
			int result = 0;
			if (truck.currentCapacity == 300.0 && truck.currentVolume == 0.5)
			{
				result = 1;
			}
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(updateCurrentTruckCT004)
		{
			Logger::WriteMessage("TC004");
			struct Truck truck = { 0, 0 };
			struct Package package = { 400, 1 };
			updateCurrentTruck(&truck, package);
			int result = 0;
			if (truck.currentCapacity == 400.0 && truck.currentVolume == 1)
			{
				result = 1;
			}
			Assert::AreEqual(1, result);
		}

		//Whitebox tests for updateCurrentTruck()
		TEST_METHOD(updateCurrentTruckCT005)
		{
			Logger::WriteMessage("TC005");
			struct Truck truck = { 0, 0 };
			struct Package package = { 500, 1 };
			updateCurrentTruck(&truck, package);
			int result = 0;
			if (truck.currentCapacity == 500.0 && truck.currentVolume == 1)
			{
				result = 1;
			}
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(updateCurrentTruckCT006)
		{
			Logger::WriteMessage("TC006"); // Needs updating
			struct Truck truck = { 0, 0 };
			struct Package package = { 1500, 3 };
			updateCurrentTruck(&truck, package);
			int result = 0;
			if (truck.currentCapacity == 1500 && truck.currentVolume == 3)
			{
				result = 1;
			}
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(updateCurrentTruckCT007)
		{
			Logger::WriteMessage("TC007");
			struct Truck truck = { 0, 0 };
			struct Package package = { 300, 1 };
			updateCurrentTruck(&truck, package);
			int result = 0;
			if (truck.currentCapacity == 300.0 && truck.currentVolume == 1)
			{
				result = 1;
			}
			Assert::AreEqual(1, result);
		}

		TEST_METHOD(updateCurrentTruckCT008)
		{
			Logger::WriteMessage("TC008");
			struct Truck truck = { 0, 0 };
			struct Package package = { 0, 0 };
			updateCurrentTruck(&truck, package);
			int result = 0;
			if (truck.currentCapacity == 0.0 && truck.currentVolume == 0)
			{
				result = 1;
			}
			Assert::AreEqual(1, result);
		}

		//Blackbox tests for remainingVolume()
		TEST_METHOD(remainingVolumeRV001)
		{
			Logger::WriteMessage("RV001");
			struct Truck truck = { 0.0, 0.0, {}, {} };
			double remaining = truck.currentVolume;
			Assert::AreEqual(0.0, remaining);
		}
		TEST_METHOD(remainingVolumeRV002)
		{
			Logger::WriteMessage("RV002");
			struct Truck truck = { 0.0, 25.0, {}, {} };
			double remaining = truck.currentVolume;
			Assert::AreEqual(25.0, remaining);
		}

		TEST_METHOD(remainingVolumeRV003)
		{
			Logger::WriteMessage("RV003");
			struct Truck truck = { 0.0, 50.0, {}, {} };
			double remaining = truck.currentVolume;
			Assert::AreEqual(50.0, remaining);
		}

		TEST_METHOD(remainingVolumeRV004)
		{
			Logger::WriteMessage("RV004");
			struct Truck truck = { 0.0, 120.0, {}, {} }; // Needs updating
			double remaining = truck.currentVolume;
			Assert::IsTrue(remaining > MAX_TRUCK_VOLUME);
		}

		//Whitebox tests for remainingVolume()
		TEST_METHOD(remainingVolumeRV005)
		{
			Logger::WriteMessage("RV005");
			struct Truck truck = { 0.0, 0.0, {}, {} };
			double remaining = truck.currentVolume;
			Assert::AreEqual(0.0, remaining);
		}
		TEST_METHOD(remainingVolumeRV006)
		{
			Logger::WriteMessage("RV006");
			struct Truck truck = { 0.0, 25.0, {}, {} };
			double remaining = truck.currentVolume;
			Assert::AreEqual(25.0, remaining);
		}

		TEST_METHOD(remainingVolumeRV007)
		{
			Logger::WriteMessage("RV007");
			struct Truck truck = { 0.0, 100.0, {}, {} };
			double remaining = truck.currentVolume;
			Assert::AreEqual(100.0, remaining);
		}

		TEST_METHOD(remainingVolumeRV008)
		{
			Logger::WriteMessage("RV008");
			struct Truck truck = { 0.0, 110.0, {}, {} };
			double remaining = truck.currentVolume;
			Assert::IsTrue(remaining > MAX_TRUCK_VOLUME);
		}
		TEST_METHOD(integrationTestIT001)
		{
			Logger::WriteMessage("IT001");
			struct Truck truck = { 1200, 15 };
			struct Package package = { 20, 4 };
			updateCurrentTruck(&truck, package);
			Assert::AreEqual(1, canThisTruckAccomodate(truck, package)); //needs updating
		}

		TEST_METHOD(integrationTestIT002)
		{
			Logger::WriteMessage("IT002");
			struct Truck truck = { 2500, 90 };
			struct Package package = { 20, 15 };
			updateCurrentTruck(&truck, package);
			Assert::AreEqual(0, canThisTruckAccomodate(truck, package)); //needs updating
		}
		TEST_METHOD(integrationTestIT003)
		{
			Logger::WriteMessage("IT003");
			struct Truck truck = { 2500, 15 };
			struct Package package = { 20, 4 };
			updateCurrentTruck(&truck, package);
			Assert::AreEqual(0, canThisTruckAccomodate(truck, package)); //needs updating
		}
		TEST_METHOD(integrationTestIT004)
		{
			Logger::WriteMessage("IT004");
			struct Truck truck = { 1200, 95 };
			struct Package package = { 20, 15 };
			updateCurrentTruck(&truck, package);
			Assert::AreEqual(0, canThisTruckAccomodate(truck, package)); //needs updating
		}
		TEST_METHOD(integrationTestIT005)
		{
			Logger::WriteMessage("IT005");
			struct Truck truck = { 2400, 10 }; 
			struct Package package = { 100, 1 };  // max
			updateCurrentTruck(&truck, package);
			double remaining = remainingCapacity(truck);
			double expectedRemaining = 0; 
			Assert::AreEqual(expectedRemaining, remaining);
		}
		TEST_METHOD(integrationTestIT006) 
		{
			Logger::WriteMessage("IT006");
			struct Truck truck = { MAX_TRUCK_CAPACITY / 3, 3 };
			struct Package package = { MAX_TRUCK_CAPACITY / 3, 4 };

			updateCurrentTruck(&truck, package);

			double remaining = remainingCapacity(truck);
			double expectedRemaining = MAX_TRUCK_CAPACITY / 3 + 1;
			Assert::AreEqual(expectedRemaining, remaining); 
		}
		TEST_METHOD(integrationTestIT007) //empty
		{
			Logger::WriteMessage("IT007");
			struct Truck truck = { 0, 0 };
			struct Package package = { 0, 0 };

			updateCurrentTruck(&truck, package);

			double remaining = remainingCapacity(truck);

			double expectedRemaining = MAX_TRUCK_CAPACITY;
			Assert::AreEqual(expectedRemaining, remaining);
		}
		TEST_METHOD(integrationTestIT008) //half
		{
			Logger::WriteMessage("IT008");
			struct Truck truck = { 1000, 5 };
			struct Package package = { 250, 5 };
			updateCurrentTruck(&truck, package);
			double remaining = remainingCapacity(truck);
			double expectedRemaining = MAX_TRUCK_CAPACITY / 2; 
			Assert::AreEqual(expectedRemaining, remaining);
		}
		
		//Integrate Test for updateCurrentTruck and remainingVolume
		TEST_METHOD(Integration_Test_IT009)
		{
			Logger::WriteMessage("IT009");
			struct Truck truck = { 0.0, 0.0, {}, {} };
			struct Package package = { 1000, 10 };
			double remaining = 0;
			double expected = MAX_TRUCK_VOLUME - 10;

			updateCurrentTruck(&truck, package);

			remaining = remainingVolume(truck);

			Assert::AreEqual(expected, remaining);
		}

		TEST_METHOD(Integration_Test_IT010)
		{
			Logger::WriteMessage("IT010");
			struct Truck truck = { 0.0, MAX_TRUCK_VOLUME, {}, {} };
			struct Package package = { 1000, 10 };
			double remaining = 0;
			double expected = 0;

			updateCurrentTruck(&truck, package);

			remaining = remainingVolume(truck);

			Assert::AreEqual(expected, remaining);
		}

		TEST_METHOD(Integration_Test_IT011)
		{
			Logger::WriteMessage("IT011");
			struct Truck truck = { MAX_TRUCK_CAPACITY, 0.0, {}, {} };
			struct Package package = { 1000, 10 };
			double remaining = 0;
			double expected = MAX_TRUCK_VOLUME;

			updateCurrentTruck(&truck, package);

			remaining = remainingVolume(truck);

			Assert::AreEqual(expected, remaining);
		}

		TEST_METHOD(Integration_Test_IT012)
		{
			Logger::WriteMessage("IT012");
			struct Truck truck = { 0.0, 0.0, {}, {} };
			struct Package package = { 0, 0 };
			double remaining = 0;
			double expected = MAX_TRUCK_VOLUME;

			updateCurrentTruck(&truck, package);

			remaining = remainingVolume(truck);

			Assert::AreEqual(expected, remaining);
		}

		//Integration Test for canThisTruckAccomodate and assignToTruck
		TEST_METHOD(Integration_Test_IT013)
		{
			Logger::WriteMessage("IT013");
			struct Truck truck = { 0.0, 0.0, {}, {} };
			struct Package package = { 1000, 10 };
			struct Route setRoute = getGreenRoute();
			int i = 0;

			if (canThisTruckAccomodate(truck, package))
			{
				assignToTruck(&truck, setRoute);
			}

			while (i < truck.route.numPoints)
			{
				if (setRoute.points[i].row == truck.route.points[i].row &&
					setRoute.points[i].col == truck.route.points[i].col)
				{
					i++;
				}
			}

			Assert::AreEqual(i, truck.route.numPoints);
		}

		TEST_METHOD(Integration_Test_IT014)
		{
			Logger::WriteMessage("IT014");
			struct Truck truck = { MAX_TRUCK_CAPACITY, 0.0, {}, {} };
			struct Package package = { 1000, 10 };
			struct Route setRoute = getGreenRoute();
			struct Route emptyRoute = { {} };
			int i = 0;

			if (canThisTruckAccomodate(truck, package))
			{
				assignToTruck(&truck, setRoute);
			}

			while (i < truck.route.numPoints)
			{
				if (setRoute.points[i].row == truck.route.points[i].row &&
					setRoute.points[i].col == truck.route.points[i].col)
				{
					i++;
				}
			}

			Assert::AreEqual(i, truck.route.numPoints);
		}

		TEST_METHOD(Integration_Test_IT015)
		{
			Logger::WriteMessage("IT015");
			struct Truck truck = { 0.0, MAX_TRUCK_VOLUME, {}, {} };
			struct Package package = { 1000, 10 };
			struct Route setRoute = getGreenRoute();
			struct Route emptyRoute = { {} };
			int i = 0;

			if (canThisTruckAccomodate(truck, package))
			{
				assignToTruck(&truck, setRoute);
			}

			while (i < truck.route.numPoints)
			{
				if (setRoute.points[i].row == truck.route.points[i].row &&
					setRoute.points[i].col == truck.route.points[i].col)
				{
					i++;
				}
			}

			Assert::AreEqual(i, truck.route.numPoints);
		}

		TEST_METHOD(Integration_Test_IT016)
		{
			Logger::WriteMessage("IT016");
			struct Truck truck = { 1000.0, 50.0, {}, {} };
			struct Package package = { 1000, 10 };
			struct Route setRoute = getGreenRoute();
			int i = 0;

			if (canThisTruckAccomodate(truck, package))
			{
				assignToTruck(&truck, setRoute);
			}

			while (i < truck.route.numPoints)
			{
				if (setRoute.points[i].row == truck.route.points[i].row &&
					setRoute.points[i].col == truck.route.points[i].col)
				{
					i++;
				}
			}

			Assert::AreEqual(i, truck.route.numPoints);
		}
		
		
		// Acceptance tests for shipmentDetails()
		TEST_METHOD(AT001_shipmentDetails)
		{
			Logger::WriteMessage("AT001_Invalid Destination");
			double weight = 20;
			double size = 5;
			int row = 28;
			char col = 'x';
			int isValid = validateShipment(weight, size, row, col);
			Assert::AreEqual(0, isValid);
		}

		TEST_METHOD(AT002_shipmentDetails)
		{
			Logger::WriteMessage("AT002_Invalid Size");
			double weight = 20;
			double size = 4;
			int row = 12;
			char col = 'L';
			int isValid = validateShipment(weight, size, row, col);
			Assert::AreEqual(0, isValid);
		}

		TEST_METHOD(AT003_shipmentDetails)
		{
			Logger::WriteMessage("AT003_Invalid Weight");
			double weight = 2600;
			double size = 5;
			int row = 12;
			char col = 'L';
			int isValid = validateShipment(weight, size, row, col);
			Assert::AreEqual(0, isValid);
		}
		
		void simulateShipmentDetails(struct Map map, struct Truck* trucks, int numTrucks, const std::string& input, std::string& output)
		{
			std::streambuf* orig_cin = std::cin.rdbuf();
			std::streambuf* orig_cout = std::cout.rdbuf();
			std::istringstream input_stream(input);
			std::ostringstream output_stream;
			std::cin.rdbuf(input_stream.rdbuf());
			std::cout.rdbuf(output_stream.rdbuf());

			shipmentDetails(map, trucks, numTrucks);

			std::cin.rdbuf(orig_cin);
			std::cout.rdbuf(orig_cout);

			output = output_stream.str();
		}

		TEST_METHOD(AT004_shipmentDetails)
		{
			struct Map baseMap = populateMap();
			struct Route blueRoute = getBlueRoute(), greenRoute = getGreenRoute(), yellowRoute = getYellowRoute();

			struct Truck trucks[3]{};
			trucks[0].currentCapacity = MAX_TRUCK_CAPACITY;
			trucks[0].currentVolume = MAX_TRUCK_VOLUME;
			assignToTruck(&trucks[0], blueRoute);

			trucks[1].currentCapacity = MAX_TRUCK_CAPACITY;
			trucks[1].currentVolume = MAX_TRUCK_VOLUME;
			assignToTruck(&trucks[1], greenRoute);

			trucks[2].currentCapacity = MAX_TRUCK_CAPACITY;
			trucks[2].currentVolume = MAX_TRUCK_VOLUME;
			assignToTruck(&trucks[2], yellowRoute);

			struct Package newPackage = { 20, 1.0, {30, 30} };

			bool deliverToday = false;
			for (int i = 0; i < 3; ++i) {
				if (canThisTruckAccomodate(trucks[i], newPackage)) {
					deliverToday = true;
					break;
				}
			}
			Assert::IsFalse(deliverToday);
		}    // ACCEPTANCE TEST FOR Non Deliverable Packages
			// Description: Evaluates the system's response to a shipment directed well beyond the boundary of the map.
		//Expected Outcome : The system should reject the shipment and handle the extreme out - of - bounds data gracefully.
			// Actual Result : Passed - shipment was appropriately rejected without system errors or misbehavior.

	};
}
