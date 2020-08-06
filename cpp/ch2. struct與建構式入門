#include <iostream>
using namespace std;

//是次，建立一個struct存放使用者資訊，裡面要有名字和年齡(預設20) 
//筆記:struct 跟 class的使用方法很像，最大的不同點是說：struct預設為public(誰都能用)；class預設為private(只有自己能用)；

//宣告struct
struct user_info
{
	int age;
	string name;
	
	//下面的建構式會在主程式做使用。因為示範建構式的使用方法，我在這裡建立四種 
	user_info() : age(20){}
	user_info(string n) : name(n) {age = 20;}   //這些建構式後皆有大括號，倒是可以在裡面做你想做的事情。
	user_info(int a) : age(a) {}
	user_info(int a, string n ) : name(n), age(a) {}
  
  //註記：「user_info(int a=20) : age(a) {} 」會跟 「user_info() : age(20){}」有衝突只能擇一，因為如果使用user_info()會讓編譯器不知道你要用的是前者還是後者
	
	void print_ingo(){  //印出資料的函式
		cout << age << ", " << name << endl; 
	}
}; //分號不要忘記，太常把他給忘了

int main()
{
	user_info user_A;     //預設20歲，名字為""
	user_A.print_ingo(); 
	
	user_info user_B(15); //設定15歲，名字為""
	user_B.print_ingo();
	
	user_info user_C("李嚴"); //預設20歲，名字為"李嚴"
	user_C.print_ingo();
	
	user_info user_D(17,"李嚴"); //設定17歲，名字為"李嚴"
	user_D.print_ingo();
}
