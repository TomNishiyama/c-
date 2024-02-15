#include <iostream>
using namespace std;

void add(int& numA, int numB) {
	numA += numB;
}

void sub(int& numA, int numB) {
	numA -= numB;
}

void mul(int& numA, int numB) {
	numA *= numB;
}

void div(int& numA, int numB) {
	if (numB != 0) {
		numA /= numB;
	}
}

void checkMenuNo(int no) {
//	if (no < 0 || no > 3) {
//		throw "無効な番号です！";
//	}
}

void checkDivZero(int value) {
//	if (value == 0) {
//		throw "ゼロで割ろうとしました！";
//	}
}
int main()
{
	int num = 0;

	cout << "//-------------------------------------------------" << endl;
	cout << "処理を選んでください。" << endl;
	cout << "0:足し算" << endl;
	cout << "1:引き算" << endl;
	cout << "2:掛け算" << endl;
	cout << "3:割り算" << endl;
	cout << endl;
	cout << "現在の値：" << num << endl;
	cout << "//-------------------------------------------------" << endl;
	cout << "=>" << flush;
	cin >> num;
	try
	{
		checkMenuNo(num);
	}
	catch (const char* str) {
		cout << str << endl;
	}         /* code */

	system("pause");
	return 0;
}

