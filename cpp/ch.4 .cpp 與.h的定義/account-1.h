//.cpp 適合放實作
//.h 標頭檔適合做包含類、子程式、變數和其他識別碼的前置聲明(from wikipedia)

#ifndef _acc_ //如果在編寫的時候會遇到redefine的情形，建議養成 #ifndef ... #define ... #endif的習慣
#define _acc_

#include <string>
#include <iostream> 

using namespace std; 

//是次，我們要利用class繼承的概念，
//建立學生(性別、名字、出生日期、department、student_id)、員工資料(性別、名字、出生日期、job、employee_id、employee_date)
//「性別、名字、出生日期」等資訊設為父類別，學生與員工設為子類別

#define sex_amount 3

enum sexual_enum {male, female, other}; //列舉性別
string sexual_name[sex_amount] = {"male","female","other"};

//父類別，「個人資料」
class Info { 
private:
	string birth_date;  
  string name;
  sexual_enum sexual; 
public :
   //取值函式
	int get_sexual();
	string get_name(); 
	string get_birth_date();
  
	 //設值函式
	void set_sexual();
	void set_name();
	void set_birth_date();
	
  Info(){}
};

//父類別Info下的子類別「學生」
class Student : public Info {
private :
	string department;
	string student_id;
	
public :
	void get_Student_info();
  void print_Student_info();
};

//父類別Info下的子類別「員工」
class Employee : public Info {
private :
	string job;
	string employee_id;
	string employee_date;
	
public:
	void ask_Employee_info();
  void print_Employee_info();
    
  Employee(){job = "一般員工";} //預設可以用預設建構式啦
};

#endif
