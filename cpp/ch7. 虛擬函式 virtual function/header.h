#ifndef _header_
#define _header_

#include <iostream>

using namespace std;

class Basic{
private:
	int distance = 0;
	void ask_distance(int d){
		distance = d;
	}
	virtual int speed() = 0;
	
public:
	int function(int c);
};

class People:public Basic{
private:
	int spd_people = 5;
	
public:
	int speed(){
		return spd_people;
	}
};

class Bike:public Basic{
private:
	int spd_bike = 15;
	
public:
	int speed(){
		return spd_bike;
	}
};

class Mrt:public Basic{
private:
	int spd_mrt = 100;
	
public:
	int speed(){
		return spd_mrt;
	}
};


#endif
