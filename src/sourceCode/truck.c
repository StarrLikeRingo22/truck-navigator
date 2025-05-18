#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996) // bypasses VS safety deprecation
#include "truck.h"
#include <stdio.h>
#include <stdlib.h>

double remainingCapacity(const struct Truck truck)
{
	return MAX_TRUCK_CAPACITY - truck.currentCapacity;
}

double remainingVolume(const struct Truck truck)
{
	return MAX_TRUCK_VOLUME - truck.currentVolume;
}


int canThisTruckAccomodate(const struct Truck truck, const struct Package package)
{
	int result = 0;
	if (remainingCapacity(truck) >= package.weight && remainingVolume(truck) >= package.size)
	{
		result = 1;
	}
	return result;
}

void updateCurrentTruck(struct Truck* truck, const struct Package package)
{
	if (truck != NULL && canThisTruckAccomodate(*truck, package))
	{
		truck->currentCapacity += package.weight;
		truck->currentVolume += package.size;
	}
}

void assignToTruck(struct Truck* truck, const struct Route route)
{
	if (truck != NULL)
	{
		truck->route = route;
	}
}

int validateShipment(double weight, double size, int row, char col)
{
	// invalid destination
	if (row <= 0 || row > 25 || col < 'A' || col > 'Y') {
		return 0;
	}
	// invalid weight
	if (weight <= 1 || weight > MAX_TRUCK_CAPACITY) {
		return 0;
	}
	// invalid size
	if (size != 1 && size != 3 && size != 5) {
		return 0; 
	}

	return 1;
}

void shipmentDetails(struct Map finalMap, struct Truck* trucks, const int numOfTrucks)
{
	int done = 0;
	int input = 0;
	double weight = 0;
	double size = 0;
	int row = 0;
	char col = 0;
	struct Package package = { 0, 0, {0, 0} };
	while (!done)
	{
		printf("Enter shipment weight, box size and destination (0 0 0x to stop): ");
		input = scanf("%lf %lf %d%c", &weight, &size, &row, &col);
		while (getchar() != '\n');
		if (input != 4)
		{
			printf("Invalid input\n");
		}
		else if (weight == 0 && size == 0 && row == 0 && col == 'x')
		{
			done = 1;
		}
		else if (row <= 0 || row > 24 || col < 'A' || col > 'Y')
		{
			printf("Invalid destination\n");
		}
		else if (weight <= 1 || weight > MAX_TRUCK_CAPACITY)
		{
			printf("Invalid weight (must be 1-2500 Kg.)\n");
		}
		else if (size != 1 && size != 3 && size != 5)
		{
			printf("Invalid size\n");
		}
		else
		{
			//subtract 1 from user input to match map row index
			struct Point destination = { row - 1, col - 'A' };
			struct Package package = { weight, size, destination };
			getBestTruckAvailable(&finalMap, trucks, package, numOfTrucks);
		}
	}
}

void getBestTruckAvailable(struct Map* finalMap, struct Truck* trucks, const struct Package shipment, const int numOfTrucks)
{
	int closestTruck = -1;
	int closestPoint = 0;
	double closestDistance = -1;
	double tempDistance = -1;

	struct Route divert = { { 0, 0 }, 0 };
	struct Route shortest; //temporary object 

	for (int i = 0; i < numOfTrucks; i++)
	{
		if (canThisTruckAccomodate(trucks[i], shipment))
		{
			closestPoint = getClosestPoint(&trucks[i].route, shipment.destination);
			tempDistance = distance(&trucks[i].route.points[closestPoint], &shipment.destination);
			if (tempDistance < closestDistance || closestDistance == -1)
			{
				closestDistance = tempDistance;
				closestTruck = i;
			}
		}
	}
	if (closestTruck != -1)
	{
		updateCurrentTruck(&trucks[closestTruck], shipment);
		if (closestTruck == 0)
		{
			printf("Ship on BLUE LINE, ");
		}
		else if (closestTruck == 1)
		{
			printf("Ship on GREEN LINE, ");
		}
		else if (closestTruck == 2)
		{
			printf("Ship on YELLOW LINE, ");
		}

		//Find diverting route
		for (int j = 1; j < trucks[closestTruck].route.numPoints; j++)
		{
			//finds shortest path for all points on route
			shortest = shortestPath(finalMap, trucks[closestTruck].route.points[j], shipment.destination);

			if (shortest.numPoints > 0 && divert.numPoints == 0) //set shortest route for first index
			{
				divert = shortest;
			}
			/*if shortest path is faster than diversion AND shortest is not zero*/
			else if ((shortest.numPoints < divert.numPoints) && (shortest.numPoints > 0))
			{
				divert = shortest;
			}
		}

		if (divert.numPoints <= 1)
		{
			printf("no diversion\n");
		}
		else
		{
			//print diversion points
			for (int k = 0; k < divert.numPoints; k++) {
				printf("%d%c", divert.points[k].row + 1, divert.points[k].col + 'A');
				if (k < divert.numPoints - 1) {
					printf(", ");
				}
				else
				{
					printf(", %d%c", shipment.destination.row + 1, shipment.destination.col + 'A');
					printf("\n");
				}
			}
		}
	}
	else
	{
		printf("Ships tomorrow\n");
	}
}
