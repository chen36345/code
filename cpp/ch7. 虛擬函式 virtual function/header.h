#ifndef _header_
#define _header_

#include <iostream>

using namespace std;
//在這裡，我們要驗證virtual的兩個用途
//a. 父類別的virtual function 和 子類別的override virtual function存在關係
//b. 父類別的virtual function = 0 時(純虛擬函式)狀態

class Basic{
private:
	int distance = 0;
	void ask_distance(int d){
		distance = d;
	}
	virtual void print_info() {  //虛擬函式
		cout << "距離" <<  distance << "公尺"; 
	}
	virtual int speed() = 0; //b.純虛擬函式下，其子必須重新宣告此虛擬函式(若要再宣告此成純虛擬函式也可，但此class如同父class將無法宣告)
	
public:
	int function(int c);
};

class People:public Basic{
private:
	int spd_people = 5;
public:
	virtual void print_info() override { //a.此虛擬函式若加override，會把繼承的同名虛擬函式蓋過，也就是說沒辦法使用父類的同名虛擬函式，只能用本地的虛擬函式
		cout << "行人速度" <<  spd_people << "公尺/每秒"<< endl; 
	}
	int speed(){
		return spd_people;
	}
};

class Bike:public Basic{
private:
	int spd_bike = 15;
public:
	virtual void print_info() override {
	cout << "腳踏車速度" <<  spd_bike << "公尺/每秒"<< endl; 
	}
	int speed(){
		return spd_bike;
	}
};

class Mrt:public Basic{
private:
	int spd_mrt = 100;
public:
	virtual void print_info() override {
	cout << "MRT速度" <<  spd_mrt << "公尺/每秒" << endl; 
	}
	int speed(){
		return spd_mrt;
	}
};

#endif
