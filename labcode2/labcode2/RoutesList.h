#pragma once
#include "ROUTE.h"

class RoutesList
{
public:
	RoutesList();
	~RoutesList();

	void addRoute(const ROUTE& route);
	void sortRoutes();
	void displayRoute(int routeNumber) const;
	void displayAllRoutes() const;


private:
	ROUTE** routes;
	int currentSize;
	void dynamicRA();
};

