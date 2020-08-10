#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

//是次來實作vector、queue、set、map等容器



using namespace std;

struct Info{
	int ID;
	string Name;
	Info(int i,string n): ID(i),Name(n){
	}
	void print_info(){
		cout << ID << ":" << Name <<endl;
	}
};

void vector_test();
void queue_test();
void set_test();
void map_test();

int main()
{
	vector_test();
	queue_test();
	set_test();
	map_test();
}

//第一題：輸入訊息”Test only”至一vector，並以字串”Test_stl”尋找不同點並刪除與取代
void vector_test()
{
	cout << "第一題" << endl ; 
	
	string test_1 = "Test only";
	string test_2 = "Test_stl";
  
	vector<char> vec_c;　//宣告vector容器
  
	for(int i = 0;i < test_1.length(); i++)
	    vec_c.push_back(test_1[i]); //插入字元 
	
	for(Vec_c::iterator i = vec_c.begin() ;i != vec_c.end(); i++)
	    cout << *i ; //輸出訊息 
	    
	cout << endl;
	
	int erase_where; //找尋相異之座標
	
	for(int i = 0;i < vec_c.size(); i++)
	{
		erase_where = i;
		if(vec_c[i]!=test_2[i])
			break;
	}
	
	vec_c.erase(vec_c.begin()+erase_where,vec_c.end()); //刪除指定的元素位置到結尾
	
	for(int i = erase_where;i < test_2.length(); i++)
	    vec_c.push_back(test_2[i]); //插入字元
	    
	for(vector<char>::iterator i = vec_c.begin() ;i != vec_c.end(); i++)
	    cout << *i ;
	cout << endl;
}

//第二題：使用Queue，移入和移出struct 
//Queue的自由度很低，只能一個資料一個資料的尾進頭出
void queue_test()
{
	cout << "第二題" << endl ; 
	queue<Info> q;
	q.push(Info(12,"Jang")); //到最後一個元素後方添加
	q.push(Info(14,"Wang"));
	q.push(Info(16,"Liu"));
	for(int i =0;i <3;i++)
	{
		q.front().print_info(); 
		q.pop(); //第一個元素移出
	}
}

//資料依序加入set容器內 “ABC” / “AB” / “AAC”,具有尋找元素的功能
//此容器具有排列的功能，但只能唯一。若希望元素能不唯一，請使用multiset
void set_test()
{
	cout << "第三題" << endl ; 
	set<string> set_string;
	string temp;
	
	set_string.insert("ABC");
	set_string.insert("AB");
	set_string.insert("AAC");
	cout << "找字：";  
	while(!(cin >> temp))
	{
		cout << "重打！";  
	}
	bool exist = set_string.count(temp);
	if (exist)
	{
		cout << temp << " found" << endl;
	}
	else
	{
		cout << temp << " not found" << endl;
		set_string.insert(temp);
	}
	for(set<string>::iterator it = set_string.begin(); it != set_string.end(); it ++)
	{
		cout << *it << " " ;
	}
	
	cout << endl ;
}

//資料依序加入map容器內,以int ID 為key,  string name 為value 實作該容器
//由使用者輸入ID, 找出是否存在,找到或找到後移除
//此容器具有排列的功能，但key只能唯一。若希望key能不唯一，請使用multimap
void map_test()
{
	bool exist, exist1;
	int ID;
	int del_ID;
	
	map<int,string> Key_value;
	
	cout << "第四題" << endl ; 
	
	Key_value[1] = "Liang";
	Key_value[2] = "Wang";
	Key_value[3] = "Feng";
	
	cout << "找ID" << endl ; 
	
	while(!(cin >> ID))
	{
		cout << "重打！";  
	}
	exist = Key_value.count(ID);
	if (exist)
		cout << "found" << endl ;
	else
	{
		cout << "not found" << endl ;
		Key_value[ID] = "Unknown";
	}
	
	for(map<int,string>::iterator it = Key_value.begin(); it != Key_value.end(); it ++)
	{
		cout << it->first << " " << it->second << ", " ;
	}
	cout << endl ;
	cout << "刪ID" << endl ; 
	
	while(!(cin >> del_ID))
	{
		cout << "重打！";  
	}
	exist1 = Key_value.count(del_ID);
	if(exist1)
	{
		cout << "detected." << endl ;
		Key_value.erase(del_ID);
	}
	else
		cout << "data not exits!" << endl ;
		
	for(map<int,string>::iterator it = Key_value.begin(); it != Key_value.end(); it ++)
	{
		cout << it->first << " " << it->second <<"," ;
	}
}

