#include "header.h"
//是次，我們來做一個能輸入日期與天數判斷的程式
//能達到以字串或數字存放時間功能，以運算元做加減，以及到達指定天數的功能
/////////////////////////////////////////////////////////////////
//////////////////////////////主程式//////////////////////////////
/////////////////////////////////////////////////////////////////

int main()
{
  //輸入時間
	Date date_a(19950103);
	date_a.print_time();
	Date date_b("1994/12/24"); //相信有一部分的人一定會犯的錯誤，如果你要丟字面值，你的建構式的引入參數要是const，並保證函式不會變更到此字面值
	date_b.print_time();
	
	Date date_c(date_b); //複製
	
	cout << date_a.get_time_string() << endl ;
	cout << date_b.get_time_string() << endl ;
	
	int diff_date = date_a - date_b; //計算相差天數
	
	date_b = date_b.to_Date(1000); //自訂 to_Date 到達指定的天數
	
	return 0;
}

/////////////////////////////////////////////////////////////////
//////////////////////////////Date //////////////////////////////
/////////////////////////////////////////////////////////////////

void Date::d_str_to_date(const string& date_string) //能將字串2020/02/02轉換成時間 
{
	bool right_format = true;
	if (date_string.length() != 10) //如果字串非10個字
	{
		cout << date_string << "is wrong length, system must stop." << endl;
		exit(0);
	}
	for(int i=0;i<date_string.length() ; i++) //從左到右確認格式
	{
		switch(i)
		{
			case 4: //結論來說跟case 7執行一樣的東西
			case 7: //判斷第五格與第八格是否為斜線
				if (date_string[i]!='/')
					right_format = false;
					break;
			default: //其他位置一定要是數字
				if (!isdigit(date_string[i]))
					right_format = false;
					break;
		}
	}
	
	if (right_format) //如果格式正確
	{
		string temp;
		//存日期
		temp.assign(date_string, 0, 4);
		year = atoi(temp.c_str());
		temp.assign(date_string, 5, 2);
		month = atoi(temp.c_str());
		temp.assign(date_string, 8, 2);
		day = atoi(temp.c_str());
	}
	else
	{
		cout << date_string << "is wrong format, system must stop." << endl;
		exit(0); //不要跟我一樣對使用者不友善，一言不合就exit人家
	}
	check_month_day();
}


string Date::get_time_string() //能將class的時間輸出成字串格式 
{
	int a =  year * 10000 + month * 100 + day  ;
	string temp_string = std::to_string(a);
	return temp_string;
}

void Date::ymd_to_date(int yyyymmdd)  //將數字20200202轉換成時間  
{
	if (yyyymmdd/10000000 >=1)
	{
		year = yyyymmdd / 10000 ;
		month = (yyyymmdd - year * 10000 ) /100;
		day = yyyymmdd - year * 10000 - month * 100;
	}
	else
	{
		cout << yyyymmdd << "is wrong format." << endl;
		exit(0);
	}
	
	check_month_day();

}

time_t Date::date_to_time_t()  // 時間(年月日)轉換成time_t 
{
	tm ltm = {0};
	ltm.tm_mday = day;
	ltm.tm_mon = month;
	ltm.tm_year = year - 1900;
	
	time_t t1 = mktime(&ltm);
	return t1;
}

void Date::print_time()  //印出時間 
{
	cout << "時間為" << year << "年" << month << "月" << day << "日" << endl;
	//time_t at_time = 
}

void Date::check_month_day() //其實筆者覺得這一個function還能優化，有興趣再做哈
{
	if ( (!(month <= 12)) || (!(day <= 31)))
	{
		cout << "wrong format." << endl;
		exit(0);
	}
}

Date Date::to_Date(int to_day) //以date的日期為原點，輸入指定的天數並到達該日
{
	int temp =  int( date_to_time_t() )  + to_day * 86400;
	time_t t_temp = (time_t)temp;
	tm *ltm = localtime(&t_temp);
	
	cout <<  "經過" << to_day << "天之後的時間為：" 
	     <<  ltm->tm_year + 1900 << "年" << ltm->tm_mon << "月" << ltm->tm_mday << "日" << endl;
	Date out_date(ltm->tm_year + 1900  , ltm->tm_mon , ltm->tm_mday);
	return out_date;
}
