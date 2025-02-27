#include <iostream>
using namespace std;

void add(int &numA, int numB)
{
    numA += numB;
}

void sub(int &numA, int numB)
{
    numA -= numB;
}

void mul(int &numA, int numB)
{
    numA *= numB;
}

void Div(int &numA, int numB)
{

    numA /= numB;
}

void checkMenuNo(int no)
{
    if (no < 0 || no > 3)
    {
        throw "無効な番号です！";
    }
}

void checkDivZero(int value)
{
    if (value == 0)
    {
        throw "ゼロで割ろうとしました！";
    }
}
int main()
{
    int num = 0;
    int menunum = 0;
    while (true)
    {
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
        cin >> menunum;
        try
        {
            checkMenuNo(menunum);
        }
        catch (const char *str)
        {
            cout << str << endl;
            system("pause");
            system("cls");
        }
        int addnum = 0;
        int subnum = 0;
        int mulnum = 0;
        int divnum = 0;
        switch (menunum)
        {
        case 0:
            cout << "値 =>" << flush;
            cin >> addnum;
            add(num, addnum);
              cout << "結果 =>" << num << endl;
            break;
        case 1:
            cout << "値 =>" << flush;
            cin >> subnum;
            sub(num, subnum);
              cout << "結果 =>" << num << endl;
            break;
        case 2:
            cout << "値 =>" << flush;
            cin >> mulnum;
            mul(num, mulnum);
              cout << "結果 =>" << num << endl;
            break;
        case 3:
            cout << "値 =>" << flush;
            cin >> divnum;
            try
            {
                checkDivZero(divnum); /* code */
            }
            catch (const char *str)
            {
                cout << str << endl;
                break;
            }

            Div(num, divnum);
              cout << "結果 =>" << num << endl;
            break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}
