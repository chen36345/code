#include "account-1.h" //標頭檔使用
//基本上，你include了這個適當寫法的標頭檔，裡面的東西都能用到。標頭檔的函式內容寫在.cpp裡，如void Info::set_name(){getline(cin, name);}
//使用方式我就不贅述了

string int_to_sexual(Info::sexual_enum &i); //建議讀者寫在類別裡
void info_print();　//建議讀者寫在類別裡

int main() { 	
	//宣告 
	Student user_student;
	Employee user_employee;
	
  cout << "待輸入兩筆資料" << endl;
	cout << "首先是學生資料" << endl;

	user_student.get_Student_info();
	user_student.print_Student_info();

	cout << endl << "再來是員工資料" << endl;

	user_employee.ask_Employee_info();
	user_employee.print_Employee_info();
}

########################################################################
##################################Info##################################
########################################################################

string Info::get_birth_date()
{
	return birth_date;
}
string Info::get_name()
{
	return name;
}
int Info::get_sexual()
{
	return sexual;
}


void Info::set_birth_date()
{
	getline(cin, birth_date);
}
void Info::set_name()
{
	getline(cin, name);
}
void Info::set_sexual()
{
	int sexual_int;
	while(!(cin >> sexual_int) )
	{
		cin.clear();
		cin.sync();
	}
	cin.clear();
	cin.sync();
	sexual = (Info::sexual_enum)sexual_int;
}

########################################################################
################################Student#################################
########################################################################

void Student::get_Student_info()
{
	cout << "您的名字：" ; 
	set_name();
	
	cout << "您的生日：" ; 
	set_birth_date();
	
	cout << "您的性別：(男生=0,女生=1,其他請填其他數字)" ; 
	set_sexual();
	
	cout << "您的科系：" ; 
	getline(cin, department);
	
	cout << "您的學號：" ; 
	getline(cin, student_id);
}

void Student::print_Student_info()
{
	cout << endl  << "輸出學生資料中：" << endl; 
	cout << "名字：" << get_name()<< endl; 
	cout << "生日：" << get_birth_date() << endl; 
	cout << "性別：" << int_to_sexual(sexual) << endl; 
	cout << "您的科系：" << department << endl; 
	cout << "您的學號：" << student_id << endl << endl; 
}

########################################################################
################################Employee################################
########################################################################

void Employee::ask_Employee_info()
{
	string temp_job;
	
	cout << "您的名字：" ; 
	set_name();
	
	cout << "您的生日：" ; 
	set_birth_date();
	
	cout << "您的性別：(男生=0,女生=1,其他請填其他數字)" ; 
	set_sexual();
	
	cout << "您的工作職稱：" ; 
	getline(cin, temp_job);
	
	if (temp_job != "")
		job = temp_job;
		
	cout << "您的員工編號：" ; 
	getline(cin, employee_id);
	
	cout << "您的到職日期：" ; 
	getline(cin, employee_date);
}

string int_to_sexual(Info::sexual_enum &i)
{
	switch(i)
	{
		case Info::male:
			return "Male";
		case Info::female:
			return "Female";
		case Info::other:
			return "Other";
		default:
			return "Undefined.";
			break;
	}
}

void Employee::print_Employee_info()
{
	cout << endl << "輸出員工資料中：" << endl;
	cout << "名字：" << get_name()<< endl; 
	cout << "生日：" << get_birth_date() << endl; 
	cout << "性別：" << int_to_sexual(sexual) << endl; 
	cout << "您的工作職稱：" << job << endl; 
	cout << "您的員工編號：" << employee_id << endl; 
	cout << "您的到職日期：" << employee_date << endl<< endl; 
} 
	    
