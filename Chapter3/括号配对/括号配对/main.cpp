#include <iostream>
#include "Balance.h"
using namespace std;
int main()
{
	/*string file;*/
	cout << "input path of the file" << endl;
	/*cin >> file;*/
	try {
		balance* f=new balance("D:\\SJTU Classes\\数据结构\\数据结构实现\\Chapter3\\括号配对\\括号配对\\test.txt");
		int result = f->CheckBalance();
		cout << result << " errors in total" << endl;
		delete f;
	}
	catch (const noFile& e) { e.Error(); }
	return 0;
}
