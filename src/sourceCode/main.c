#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "truck.h"

int main(void)
{
	// Initialize the base map and routes
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	// Add the routes to the map
	struct Map finalMap = addRoute(&baseMap, &blueRoute);
	finalMap = addRoute(&finalMap, &greenRoute);
	finalMap = addRoute(&finalMap, &yellowRoute);

	// Initialize trucks for each route
	struct Truck trucks[3] = { {0, 0}, {0, 0}, {0, 0} };
	assignToTruck(&trucks[0], blueRoute);
	assignToTruck(&trucks[1], greenRoute);
	assignToTruck(&trucks[2], yellowRoute);
	int numOfTrucks = 3;

	printf("=================\n");
	printf("Seneca Polytechnic Deliveries\n");
	printf("=================\n");

	shipmentDetails(baseMap, trucks, numOfTrucks);

	printf("Thanks for shipping with Seneca!\n");

	return 0;
}