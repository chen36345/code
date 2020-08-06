#include <iostream> 
using namespace std; 

//樣板的格式大致上可以如此寫道:
//template <typename Tobj1> 
//Tobj1 funs(Tobj1 a){...}
//stl裡有很多用template做的，像是string, vector...etc，所以不要小看樣板的能力。

//第一個例子是函式
template <typename Tobj1,typename Tobj2> Tobj1 adder(Tobj1 a, Tobj2 b)
{
	return a + b;
}

//第二個例子是類別
template <typename Tobj1> class Info{
private:
	Tobj1 name;
public:
	void set_function(Tobj1 temp)
	{
		name = temp;
	}
	
	Tobj1 get_function()
	{
		return name;
	}
};


int main()
{
	
  //第一個樣板用途是可將2個相同資料型別的相加後回傳
	string odd = "odd" ;
	string lot = "lot" ;
	cout << adder( 5, 9) << endl;
	cout << adder( 9.5 ,1.11) << endl;
	cout << adder( odd ,lot) << endl;
	cout << adder( 5,9.1) << endl;
	

	//第二個樣板是做出能存放不同形式的class
	
	Info<float> info_float;
	Info<int> info_int;
	Info<string> info_string;
	
	info_float.set_function(5.7);
	cout << info_float.get_function() << endl;
	
	info_int.set_function(5);
	cout << info_int.get_function() << endl;
	
	info_string.set_function(odd);
	cout << info_string.get_function() << endl; 
	
}

//巢狀template有興趣可以自己研究看看呦
