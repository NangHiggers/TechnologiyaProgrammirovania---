#pragma once
#include <string>
using namespace std;

class ROUTE
{
public:
	ROUTE();
	ROUTE(int RouteNum, const string& StartingPoint, const string& EndingPoint);
	~ROUTE();

	string getStartingPoint() const;
	string getEndingPoint() const;
	int getRouteNum() const;
	void setStartingPoint(const string& StartingPoint);
	void setEndingPoint(const string& EndingPoint);
	void setRouteNum(int RouteNum);

	friend ostream& operator<<(ostream& os, const ROUTE& route);
	friend istream& operator>>(istream& is, ROUTE& route);

private:
	string StartingPoint;
	string EndingPoint;
	int RouteNum;
};

