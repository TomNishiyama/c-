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
        throw "ñ≥å¯Ç»î‘çÜÇ≈Ç∑ÅI";
    }
}

void checkDivZero(int value)
{
    if (value == 0)
    {
        throw "É[ÉçÇ≈äÑÇÎÇ§Ç∆ÇµÇ‹ÇµÇΩÅI";
    }
}
int main()
{
    int num = 0;
    int menunum = 0;
    while (true)
    {
        cout << "//-------------------------------------------------" << endl;
        cout << "èàóùÇëIÇÒÇ≈Ç≠ÇæÇ≥Ç¢ÅB" << endl;
        cout << "0:ë´ÇµéZ" << endl;
        cout << "1:à¯Ç´éZ" << endl;
        cout << "2:ä|ÇØéZ" << endl;
        cout << "3:äÑÇËéZ" << endl;
        cout << endl;
        cout << "åªç›ÇÃílÅF" << num << endl;
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
            cout << "íl =>" << flush;
            cin >> addnum;
            add(num, addnum);
              cout << "åãâ  =>" << num << endl;
            break;
        case 1:
            cout << "íl =>" << flush;
            cin >> subnum;
            sub(num, subnum);
              cout << "åãâ  =>" << num << endl;
            break;
        case 2:
            cout << "íl =>" << flush;
            cin >> mulnum;
            mul(num, mulnum);
              cout << "åãâ  =>" << num << endl;
            break;
        case 3:
            cout << "íl =>" << flush;
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
              cout << "åãâ  =>" << num << endl;
            break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}
