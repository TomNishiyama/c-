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
        throw "�����Ȕԍ��ł��I";
    }
}

void checkDivZero(int value)
{
    if (value == 0)
    {
        throw "�[���Ŋ��낤�Ƃ��܂����I";
    }
}
int main()
{
    int num = 0;
    int menunum = 0;
    while (true)
    {
        cout << "//-------------------------------------------------" << endl;
        cout << "������I��ł��������B" << endl;
        cout << "0:�����Z" << endl;
        cout << "1:�����Z" << endl;
        cout << "2:�|���Z" << endl;
        cout << "3:����Z" << endl;
        cout << endl;
        cout << "���݂̒l�F" << num << endl;
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
            cout << "�l =>" << flush;
            cin >> addnum;
            add(num, addnum);
              cout << "���� =>" << num << endl;
            break;
        case 1:
            cout << "�l =>" << flush;
            cin >> subnum;
            sub(num, subnum);
              cout << "���� =>" << num << endl;
            break;
        case 2:
            cout << "�l =>" << flush;
            cin >> mulnum;
            mul(num, mulnum);
              cout << "���� =>" << num << endl;
            break;
        case 3:
            cout << "�l =>" << flush;
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
              cout << "���� =>" << num << endl;
            break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}
