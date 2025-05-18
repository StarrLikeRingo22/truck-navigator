#ifndef TRUCK_H
#define TRUCK_H

#include "mapping.h"

#define MAX_CAPACITY 100 // Maximum number of boxes (assumed smallest box is 0.5m^3)
#define MAX_TRUCK_CAPACITY 2500 // Maximum weight in kilos
#define MAX_TRUCK_VOLUME 100   // Maximum volume in cubic meters


#ifdef __cplusplus
extern "C" {
#endif // For Unit Testing as extern "C" linkage prevents us from overloading functions

//Information for each package
struct Package
{
	double weight;
	double size;
	struct Point destination;
};

//Information for each truck 
struct Truck {
	double currentCapacity; // weight inside
	double currentVolume; // space inside
	struct Package packages[MAX_CAPACITY];
	struct Route route;
};

// //Point on map and if it is building
// struct Coordinate
// {
// 	char row;
// 	char col;
// 	bool isBuilding;
// };

// //Area with list of coordinates
// struct Area
// {
// 	Coordinate* coordinates[AREA_SIZE];
// 	int noOfCoords;
// };

//Commented out and included the points from mapping files


/** Calculates the remaining weight of a truck.
* @param truck A truck structure representing the truck's current load
* @return The remaining capcity of the truck as a double
*/
double remainingCapacity(const struct Truck truck);

/** Calculates the remaining space inside a truck.
* @param truck A truck structure representing the truck's current load
* @return The remaining capcity of the truck as a double
*/
double remainingVolume(const struct Truck truck);

/** Finds the most suitable truck for a package
* @param truck A truck structure representing the truck's current load
* @param package A package structure representing the packages
* @return a boolean value indicating whether a truck can accomodate a package
*/
int canThisTruckAccomodate(const struct Truck truck, const struct Package package);

/**
 * Updates a truck's load with a given shipment.
 * @param truck A reference to a Truck structure representing the truck's current load.
 * @param box A Box structure representing the shipment.
 */
void updateCurrentTruck(struct Truck* truck, const struct Package package);

/** Assigns a route to a truck.
 * @param truck A reference to a Truck structure representing the truck.
 * @param route A reference to a Route structure to assign to the truck.
 */
void assignToTruck(struct Truck* truck, const struct Route route);

/** Validates the shipment details.
 * @param weight - A double representing the weight of the shipment.
 * @param size - A double representing the size of the shipment.
 * @param row - The row index of the destination on the map. 
 * @param col - The column letter of the destination on the map. 
 * @returns - An integer value indicating whether the shipment is valid.
 */
int validateShipment(double weight, double size, int row, char col);

/** 
 * Allows user to input shipment details.
 * @param finalMap A map structure representing the map and locations.
 * @param truck An array of truck structures representing the trucks' current loads.
 * @param numOfTrucks An integer representing the number of trucks.
 * @return A Box structure representing the shipment details.
 */
void shipmentDetails(struct Map finalMap, struct Truck* trucks, const int numOfTrucks);

/** Finds the truck with the most available space.
 * @param finalMap A map structure representing the map and locations.
 * @param trucks An array of truck structures representing the trucks' current loads.
 * @param shipment A package structure representing the shipment to be delivered.
 * @param numOfTrucks An integer representing the number of trucks.
 * @return The remaining weight and capacity of the most unoccupied truck.
 */
void getBestTruckAvailable(struct Map* finalMap, struct Truck* trucks, const struct Package package, const int numOfTrucks);

#ifdef __cplusplus
}
#endif


#endif 
