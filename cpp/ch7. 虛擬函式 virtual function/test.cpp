#include "header.h"

int main()
{
	People people;
	Bike bike;
	Mrt mrt;
	int d;
	cout<<"距離(公尺)? " ; 
	cin >> d;
	
	cout<<"徒步行走的時間為" << people.function(d) << "秒" <<endl ; 
	cout<<"騎腳踏車的時間為" << bike.function(d) << "秒" <<endl ; 
	cout<<"搭乘捷運的時間為" << mrt.function(d) << "秒" <<endl ; 

	return 0;
}


int Basic::function(int d)
{
	ask_distance(d);
	return distance / speed();
}
