#include <iostream>

using namespace std;

//是次，我們要建立一個矩形資訊存放的class，class裡面必須有長和寬，以運算子< > ==等達到面積比較功能
//換句話說，我們得告訴程式要如何比較兩個class，勢必要用到運算子重載。

class Rect{
private:
	float length;
	float width;
	
public:
	bool operator>  (const Rect& r) const; 
	bool operator<  (const Rect& r) const;
	bool operator== (const Rect& r) const;
  //上述的重載，是要告訴程式運算元要如何對類別運用或比較。
  //結構為 回傳形態 operator() (引入參數) {做的事情};
  
  //筆者建議，函式引入參數都要用參考的方式引入，且要養成適時加上const的習慣：
  //保證不會變動任何參數，就在小括號後加const。                           例: void fun(int &i) const {...};
  //保證不會變動引入參數，就在引入參數形態前加上const。                    例: void fun(const int &i) const {...};
  //輸出的值要保證不能被修改(但可以被複製)，就在函式形態前加上const。       例: const int fun1(int &i) {...};
  
  Rect():length(0),width(0){}
	Rect(const Rect& r) //複製建構式 
	{
		length = r.length;
		width = r.width;
	}
	Rect(float l, float w):length(l),width(w){} 
	
	void print_Rect();
};

void compare_area(Rect& a,Rect& b);
void compare_equal(Rect& a,Rect& b);
void input_param(float a_l = 0.0, float a_w = 0.0, float b_l = 0.0, float b_w = 0.0 );

int main()
{
	Rect rect_A(12,19.7);
	Rect rect_B( rect_A); //Rect rect_B= rect_A;
	rect_A.print_Rect();
	rect_B.print_Rect();
	compare_area(rect_A,rect_B);//相同矩形做比較
	
  Rect rect_C(5,7);
	Rect rect_D(9,11);
	rect_C.print_Rect();
	rect_D.print_Rect();
	compare_equal(rect_C,rect_D);//不相同矩形做比較
	
	input_param(12,2,23,4); //輸入測試
	input_param();
	
	return 0;
}

//###############################################
//################Rect函式宣告####################
//###############################################

bool Rect::operator< (const Rect& r) const
{
	return (length * width < r.length * r.width);
}

bool Rect::operator> (const Rect& r) const
{
	return (length * width > r.length * r.width);
}

bool Rect::operator== (const Rect& r) const
{
	bool length_same = (length == r.length);
	bool width_same = (width == r.width);
	return length_same && width_same;
}

void Rect::print_Rect()
{
  cout << "Length : " << length <<" width : " << width << endl;
}

//###############################################
//####################全域宣告####################
//###############################################


void compare_area(Rect& a,Rect& b)
{
	if(a >b)
		cout << "前者面積大於後者" << endl;
	else if(a <b)
		cout << "前者面積小於後者" << endl;
	else
		cout << "前者面積等於後者" << endl;
}

void compare_equal(Rect& a,Rect& b)
{
	if(a == b)
		cout << "前者與後者完全相等" << endl;
	else
		cout << "前者與後者不完全相等" << endl;
}

void input_param(float a_l, float a_w , float b_l, float b_w )
{
	cout << "\n這是一個比較兩個矩形的程式" << endl; 
	Rect rect_A(a_l, a_w);
	Rect rect_B(b_l, b_w);
	
	if (a_l == 0) //空函式，讓使用者自己輸入
	{
		cout << "輸入第一個矩形長: " ; 
		cin >> a_l;
		cout << "輸入第一個矩形寬: " ; 
		cin >> a_w;
		rect_A = Rect(a_l, a_w);
		rect_B = rect_A;
		/*
		cout << "輸入第二個矩形長: " ; 
		cin >> b_l;
		cout << "輸入第二個矩形寬: " ; 
		cin >> b_w;
		*/
	}
	else
		cout << "使用預設參數: " << endl; 

	rect_A.print_Rect();
	rect_B.print_Rect();
	
	compare_area(rect_A,rect_B);
	compare_equal(rect_A,rect_B);	 
}
