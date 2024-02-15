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
    if (no < 0 || no > 3) {
        throw "無効な番号です！";
    }
}

void checkDivZero(int value) {
    if (value == 0) {
        throw "ゼロで割ろうとしました！";
    }
}
int main()
{
    cout<< "//-------------------------------------------------"<<endl;
    cout<<"処理を選んでください。"<<endl;
    cout<< "//-------------------------------------------------"<<endl;
}

