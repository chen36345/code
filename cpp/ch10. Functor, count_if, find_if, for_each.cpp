#include <iostream>
#include <vector>
#include <algorithm>

//是次，我們來對vector<int>實作count_if, find_if, for_each。
//for_each、 count_if、 find_if這三個都是從std來的，能藉由iterator從起數到末 
//count_if ：數有幾個true
//find_if  ：數到true就停
//for_each ：從頭做到尾

using namespace std;

//一個任務型類別，用來比大小和計數
class Bigger_than_count{
private:
	int counted = 0;
	int base_number;
public:
	bool operator() (int i){ //這裡就是重載，在此建立Function operator。
		if( i > base_number ) //如果輸入大於base_number，會計數加一，並回傳bool
		{
			counted += 1;
			return true;
		}
		return false;
	}
  
	print_data(){ //輸出counted有多少
		cout << counted << endl;
	}
	Bigger_than_count(const int b_n):base_number(b_n){} //建構式之一
	Bigger_than_count(){}  //建構式之二
};

int main()
{
	vector<int> data_2 = {1,5,2,8,3,7,4,7,9,6}; //建立數個int型態的vector
	
  //建立類別與變數
	Bigger_than_count a ; 
	int b;
	vector<int>::iterator c;
	
	//以 for_each 舉例來說，會把data_2這個vector的值從第一位到最後一位，一個一個代到第三格的lambda
	//第三格可以放判斷函式、function、function opperator等，傳入的值必須要有一個輸入，型態必須要跟iterator指向的元素相同(如int對int,或class對class)，以下示例為lambda 輸入值為int
	for_each(data_2.begin(),data_2.end(),[](int i){ cout << i; } ); //輸出1528374796
	cout << endl;
	
	//以 count_if舉例來說，會把data_2這個vector的值從第一位到最後一位，一個一個代到lambda
	//由於count_if能統計所有回傳的bool結果是true的有多少，我們可以得出達成條件的有「8,7,7,9」 
	b = count_if( data_2.begin(),data_2.end(), [](int i){return i>6; } );
	cout << b << endl;  //4
	
	//以 find_if舉例來說，會把data_2這個vector的值從頭開始找到最後一位，找到則停止 
	//涉於判斷，所以函式的回傳勢必要是bool 
	//由於find_if一旦找到true就會回傳iterator，因此我們求得了位址
	//求得的位址與起始相減就能求得「從起點開始算的距離值」。
	c = find_if( data_2.begin(),data_2.end(), [](int i){return i>6; } );
	cout << c - data_2.begin() << endl;  //3(從起點往後走三格的位置) 
	
  //對lambda不熟的人抱歉啦。另外我在這裡說明一下今天的主題functor(function operator)好了
  //因為functor既可以被看成函式又可以看成物件class，且functor的命名跟class的命名是一樣的
  //換句話說可以當成class用又可以當函式，所以他的變化性才會這麼多，這就是為什麼很多大佬都很愛用class的原因之一
  
  
	for_each(data_2.begin(),data_2.end(),Bigger_than_count(2) ).print_data();  //類別Bigger_than_count在第三格被宣告之後當成function(因為operator()重載)
                                                                             //然後for_each跑完之後輸出Bigger_than_count，因此才能用類別裡的print_data()函式
                                                                             //詳情自己看編譯器中的for_each定義，其回傳的東西必跟輸入的第三格是一樣的形態
  //也可以老實一點，把他存起來
  //a = for_each(data_2.begin(),data_2.end(),Bigger_than_count(2) );
  //a.print_data();  //8
	
	b = count_if( data_2.begin(),data_2.end(), [](int i){return i>2; } );  //Lambda「   [](int i){return i>2; }  」輸入data_2的資料，從.begin()到.end()
                                                                         //回傳值為數字，共計收到的true有多少個
	cout << b<< endl;  //8
	
	b = count_if( data_2.begin(),data_2.end(), Bigger_than_count(2) ); //Bigger_than_count(int base_number)存成類別後，
                                                                     //(因為operator()重載)在第三格輸入能視為可輸入int i的functor
                                                                     //而此functor有bool回傳，讓count_if能接收，回傳共計收到的true有多少個
	cout << b << endl;  //8
	
	c = find_if( data_2.begin(),data_2.end(), [](int i){return i>8; } );
	cout << *c << endl; //9
	
	c = find_if( data_2.begin(),data_2.end(), Bigger_than_count(8) );  //Bigger_than_count(int base_number)存成類別後，
                                                                     //(因為operator()重載)在第三格輸入能視為可輸入int i的functor
                                                                     //而此functor有bool回傳，讓find_if能接收，收到true就代表找到，回傳iterator值
	cout << *c << endl; //9
	
}
