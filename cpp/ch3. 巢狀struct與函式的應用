#include <iostream>
//#include <string>
using namespace std;

struct user_info
{
	int age;
	string name;
	
	struct Ad_Ph{
	string address;
	string phone;
	} house, corr;
	
	user_info() : age(20){}
	
};

void report_info(user_info user);
void report_info_pointer(user_info *user);
void report_info_reference(user_info &user);

#include <iostream>
using namespace std;

//是次，我們要做一個能夠讓使用者輸入個人資料的程式。個人資料必須要有年齡(預設20)、名字、住家地址和電話、聯絡地址和電話。
//並探討函式呼叫中的參數傳遞， Call by value ,address 或者是 reference
//因為「住家地址和電話」、「聯絡地址和電話」有同樣的結構，那麼就做一個「地址和電話」的巢狀struct吧

//以下為巢狀struct
struct user_info
{
	int age;
	string name;
	
  //以下為第二層struct
	struct Ad_Ph{
    string address;
    string phone;
	} house, corr;
	
	user_info() : age(20){}
};

//這裡宣告三種void回傳的函式，參數傳遞分別是用value, address與reference
void report_info(user_info user);
void report_info_pointer(user_info *user);
void report_info_reference(user_info &user);

//為了好維護文本或是將來要做翻譯版，你可以這樣做
//其實不一定要這麼做，筆者覺得，用成string列出會比較知道要怎麼寫程式

string s_name = "請輸入名字";
string s_age = "請輸入年齡";
string s_address_Corr = "請輸入通訊地址";
string s_address_House = "請輸入戶籍地址";
string s_phone_Corr = "請輸入通訊電話";
string s_phone_House = "請輸入戶籍電話"; 

int main()
{
	user_info user_a;
	float temp_age;
  
  //在主程式直接問使用者資料。
	//名字 
	cout<<s_name<<endl;
	getline(cin,user_a.name);
	
	//年齡 
	cout<<s_age<<endl;
	if(!(cin>>temp_age))
		cout<<"輸入錯誤年齡格式，已設預設值20歲！"<<endl;
	else if(temp_age < 0)
		cout<<"輸入負的年齡，已設預設值20歲！"<<endl;
	else
		user_a.age = temp_age;
	//小數處理，希望不會有個白木連歲數都要加小數點
	if(temp_age != (int)temp_age)
		cout<<"偵測到小數，已換成整數處理"<<endl;
	//筆記：我們都要假設使用者常常會輸入非預期的輸入，最好能將使用者輸入做一個排錯流程，或是寫一個輸入排錯函式。
	cin.clear();
	cin.sync();
	
	//通訊 
	cout<<s_address_Corr<<endl;
	getline(cin,user_a.corr.address);
	cout<<s_phone_Corr<<endl;
	getline(cin,user_a.corr.phone);

	
	//戶籍
	cout<<s_address_House<<endl;
	getline(cin,user_a.house.address);
	cout<<s_phone_House<<endl;
	getline(cin,user_a.house.phone);
	
	//report_info(user_a);
	report_info_pointer(&user_a);
	report_info_reference(user_a);
	
}

void report_info(user_info user)
{
	printf("\n以傳值函數輸出結果：\n");
	cout<<s_name
	    <<user.name<<endl 
	    <<s_age
	    <<user.age<<endl 
	    
	    <<s_address_Corr
	    <<user.corr.address<<endl
	    <<s_phone_Corr
	    <<user.corr.phone<<endl 

	    <<s_address_House
	    <<user.house.address<<endl 
	    <<s_phone_House
	    <<user.house.phone<<endl ;
}

void report_info_pointer(user_info *user)
{
	printf("\n以指標的函數輸出結果：\n"); //注意，用法是->箭頭
	cout<<s_name
	    <<user->name<<endl 
	    <<s_age
	    <<user->age<<endl 
	
	    <<s_address_Corr
	    <<user->corr.address<<endl 
	    <<s_phone_Corr
	    <<user->corr.phone<<endl 
	    
	    <<s_address_House
	    <<user->house.address<<endl 
	    <<s_phone_House
	    <<user->house.phone<<endl ;
	
	
}

void report_info_reference(user_info& user)
{
	printf("\n以參考的函數輸出結果：\n");
	cout<<s_name
	    <<user.name<<endl 
	    <<s_age
	    <<user.age<<endl 
	    
	    <<s_address_Corr
	    <<user.corr.address<<endl 
	    <<s_phone_Corr
	    <<user.corr.phone<<endl 

	    <<s_address_House
	    <<user.house.address<<endl 
	    <<s_phone_House
	    <<user.house.phone<<endl ;

}

//整理一下結論，如果用call by value，在函式裡會複製你的引值，然後對複製的值做事情。理所當然，你對複製的值去做任何事情，不會更動到你輸入的值
//如果用call by address，雖說可以在函式裡改你要的值，但稍用不慎（如到指定址外的址）可能會更改到非預期的地方
//如果用call by reference，就能避免上述這兩個問題。
//註：環境為C++
