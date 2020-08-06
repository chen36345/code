#include <iostream>
#include <ctime>
#include <time.h>  
#include <stdlib.h>

using namespace std;

class Date{
private:
	int year;
	int month;
	int day;

public:
	void d_str_to_date(const string &date_string);
	void ymd_to_date(int yyyymmdd);	
	void print_time();
	string get_time_string();
	time_t date_to_time_t();
	Date to_Date(int to_day);
	void check_month_day();
	
	Date(const Date& d){  //複製建構式 
		day = d.day;
		month = d.month;
		year = d.year;
	}
	
	Date(int y, int m, int d):year(y),month(m),day(d)	{	}
	
	Date(const string &date_string)
	{
		d_str_to_date(date_string);
    }
    
	Date(int yyyymmdd){
		ymd_to_date(yyyymmdd);
	}
	
	int operator- (Date& b)
	{
		int diff_time_t = ( int( date_to_time_t() ) - int( b.date_to_time_t() )  )  /  86400 ;
	    cout << "相差"  <<  diff_time_t  <<  "天" <<endl ; 
	    return diff_time_t;
	}
	
};
