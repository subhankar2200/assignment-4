#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
class Shape
{
private:
    int size;

public:
    void Move()
    {
        char c[50] = "Moving the Object to Given Coordinates ......";
        gotoxy(50, 8);
        for (int i = 0; i < 50; i++)
        {
            cout << c[i];
            Sleep(200);
        }
    }
    void Intro()
    {
        char intro[200] = "\t\t\t\tOOP Theory Project\n\t\t\tSubmitted By - Roushan Singh\n\t\t\tSubmitted To-" ;
        for ( int i = 0; i < strlen(intro); i++)
        {
            cout << intro[i];
            Sleep(100);
        }
        Sleep(2000);
    }
    void gotoxy(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
};
class Complex : public Shape
{
private:
    int x = 0, y = 0, size = 15;

public:
    void Choice()
    {
        int a = 0, b = 0;
        char c;
        cout << "Do you want to move shape (Yes-Y and No-N): ";
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            cout << "Enter the next coordinate to move : ";
            cin >> a >> b;
            system("CLS");
            FastHeart();
            x = a;
            y = b;
            Move();
            Sleep(3000);
            system("CLS");
            SlowHeart();
        }
        else
            SlowHeart();
        system("pause");
    }
    void SlowHeart()
    {
        gotoxy(x, y++);
        for (int i = size / 2; i < size; i += 2)
        {
            for (int j = 1; j < size - i; j += 2)
            {
                Sleep(5);

                cout << " ";
            }
            for (int j = 1; j < i + 1; j++)
            {
                Sleep(5);

                cout << "*";
            }

            for (int j = 1; j < size - i + 1; j++)
            {
                Sleep(5);

                cout << " ";
            }
            for (int j = 1; j < i + 1; j++)
            {

                Sleep(5);

                cout << "*";
            }
            gotoxy(x, y++);
        }
        for (int i = size; i > 0; i--)
        {
            for (int j = 0; j < size - i; j++)
            {
                Sleep(5);

                cout << " ";
            }
            for (int j = 1; j < i * 2; j++)
            {
                Sleep(5);

                cout << "*";
            }
            gotoxy(x, y++);
        }
    }
    void FastHeart()
    {
        gotoxy(x, y++);
        for (int i = size / 2; i < size; i += 2)
        {
            for (int j = 1; j < size - i; j += 2)
            {
                cout << " ";
            }
            for (int j = 1; j < i + 1; j++)
            {
                cout << "*";
            }

            for (int j = 1; j < size - i + 1; j++)
            {
                cout << " ";
            }
            for (int j = 1; j < i + 1; j++)
            {
                cout << "*";
            }
            gotoxy(x, y++);
        }
        for (int i = size; i > 0; i--)
        {
            for (int j = 0; j < size - i; j++)
            {
                cout << " ";
            }
            for (int j = 1; j < i * 2; j++)
            {
                cout << "*";
            }
            gotoxy(x, y++);
        }
    }
};
class SimpleShape : public Shape
{
public:
    int x = 0, y = 0, n = 15;
    void SetData()
    {
        cout << "Enter the Size for Simple Shape: ";
        cin >> this->n;
    }
};
class Box : public SimpleShape
{
private:
public:
    void Choice()
    {
        int a = 0, b = 0;
        char c;
        cout << "Do you want to move shape (Yes-Y and No-N): ";
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            cout << "Enter the next coordinate to move : ";
            cin >> a >> b;
            system("CLS");
            FastBox();
            x = a;
            y = b;
            Move();
            Sleep(3000);
            system("CLS");
            SlowBox();
        }
        else
            SlowBox();
        system("pause");
    }
    void SlowBox()
    {
        int i, j, k;
        gotoxy(x, y++);
        cout << " ";
        for (i = 0; i < this->n; i++)
        {
            if (i == 0)
            {
                for (j = 2; j < this->n; j++)
                {
                    cout << "_";
                    Sleep(150);
                }
            }
            else if (i == (this->n - 1))
            {
                for (j = 0; j < this->n; j++)
                {
                    Sleep(150);
                    if (j == 0 || j == (this->n - 1))
                    {
                        cout << "|";
                    }
                    else
                        cout << "_";
                }
            }
            else
            {
                for (k = 0; k < this->n; k++)
                {
                    if (k == 0 || k == (this->n - 1))
                    {
                        Sleep(150);

                        cout << "|";
                    }
                    else
                        cout << " ";
                }
            }
            gotoxy(x, y++);
        }
    }
    void FastBox()
    {
        int i, j, k;
        gotoxy(x, y++);
        cout << " ";
        for (i = 0; i < this->n; i++)
        {
            if (i == 0)
            {
                for (j = 2; j < this->n; j++)
                {
                    cout << "_";
                }
            }
            else if (i == (this->n - 1))
            {
                for (j = 0; j < this->n; j++)
                {
                    if (j == 0 || j == (this->n - 1))
                    {
                        cout << "|";
                    }
                    else
                        cout << "_";
                }
            }
            else
            {
                for (k = 0; k < this->n; k++)
                {
                    if (k == 0 || k == (this->n - 1))
                    {

                        cout << "|";
                    }
                    else
                        cout << " ";
                }
            }
            gotoxy(x, y++);
        }
    }
};
class Tent : public SimpleShape
{
private:
    int x = 0, y = 0, n = 15;

public:
    void Choice()
    {
        int a = 0, b = 0;
        char c;
        cout << "Do you want to move shape (Yes-Y and No-N): ";
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            cout << "Enter the next coordinate to move : ";
            cin >> a >> b;
            system("CLS");
            FastTent();
            x = a;
            y = b;
            Move();
            Sleep(3000);
            system("CLS");
            Slowtent();
        }
        else
            Slowtent();
        system("pause");
    }
    void Slowtent()
    {
        int i, j, k;
        gotoxy(x, y++);
        for (i = 0; i < n; i++)
        {
            Sleep(150);
            for (j = 0; j <= (n - i); j++)
            {
                if (i <= n - 1)
                    cout << " ";
            }
            cout << "/";
            for (int a = 0; a <= i; a++)
            {
                if (a == i)
                    cout << "\\";
                else
                {
                    if (i == (n - 1))
                    {
                        Sleep(100);
                        cout << "__";
                    }
                    else
                        cout << "  ";
                }
            }
            gotoxy(x, y++);
        }
    }
    void FastTent()
    {
        int i, j, k;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= (n - i); j++)
            {
                if (i <= n - 1)
                    cout << " ";
            }
            cout << "/";
            for (int a = 0; a <= i; a++)
            {
                if (a == i)
                    cout << "\\";
                else
                {
                    if (i == (n - 1))
                    {
                        cout << "__";
                    }
                    else
                        cout << "  ";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    system("CLS");
    Shape S;
    Complex C;
    SimpleShape Si;
    Box B;
    Tent T;
    int c = 0;
    S.Intro();
    while (c != 4)
    {
        system("CLS");
        cout << "Shape Selection : \n1-Complex Shape\n2-Box\n3-Tent\n4-Exit\nYour Choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            C.Choice();
            break;
        case 2:
            B.Choice();
            break;
        case 3:
            T.Choice();
            break;
        case 4:
            return 0;
        default:
            cout << "\nWrong Input !!\nRestarting the Program !!\n";
            system("pause");
            main();
        }
    }
}