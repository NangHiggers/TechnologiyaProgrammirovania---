#pragma once
#include "ROUTE.h"

class RoutesList
{
public:
	RoutesList();
	~RoutesList();

	void addRoute(const ROUTE& route);
	void deleteRoute(int routeNumber);
	void sortRoutes();
	void displayRoute(int routeNumber) const;
	void displayAllRoutes() const;
	void editStartingPoint(int routeNumber, const string& newStartingPoint);
	void editEndingPoint(int routeNumber, const string& newEndingPoint);
	void editRouteNumber(int routeNumber, int newRouteNumber);
	void insertRoute(int position, const ROUTE& route);


private:
	ROUTE** routes;
	int currentSize;
	void dynamicRA();
};
