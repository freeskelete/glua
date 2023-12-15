#include <iostream>
#include <fstream>

// Проверка столбцов, натуральных абсолютных и сортировка. Пункт 1.
using namespace std;
int n = 0;
int mas[12][12];
bool read()
{
    ifstream file("size_massiv.txt");
    if (file.is_open())
    {

        int num;
        file >> num;
        n = num;
        int i = 0, j = 0;
        while (!file.eof())
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    file >> mas[i][j];
                }
            }
        }
        file.close();
        return true;
    }
    else
    {
        cout << "Невозможно считать файл";
        return false;
    }
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mas[i][j] << '\t';
        }
        cout << endl;
    }
}

bool equal_col()
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            for (int c = i + 1; c < n - 1; c++)
            {
                if (mas[j][i] != mas[j][c])
                {
                    flag = false;
                    break;
                }
            }

        }
        if (flag)
        {
            return flag;
        }
    }
    return 0;
}
bool simple_number()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool flag = true;
            for (int c = 2; c <= sqrt(abs(mas[i][j])); c++)
            {
                if (abs(mas[i][j]) % c == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return flag;
            }
        }
    }
    return 0;
}

void Sort()
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int sum1 = 0, sum2 = 0;
            for (int p = 0; p < n; p++)
            {
                sum1 += mas[i][p];
                sum2 += mas[i + 1][p];
            }
            if (sum1 > sum2)
            {
                for (int c = 0; c < n; c++)
                {
                    swap(mas[i][c], mas[i + 1][c]);
                }
            }
        }
    }
}


void write()
{
    ofstream file("result.txt");
    if (file.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                file << mas[i][j] << '\t';
            }
            file << endl;
        }
        file.close();
    }
    else
        cout << "Запись не возможна\n";
}

// Перегруз функции. Пункт 2
int function(int x) // Вовзращение суммы для целого(integer)
{
    int sum = 0;
    while (x)
    {
        sum += abs(x) % 10;
        x /= 10;
    }
    return sum;
}
double function(double x) // Возвращение целой части для дробного(float/double)
{
    if (x < 0 && int(x) == x)
    {
        return int(x);
    }
    else if (x < 0)
    {
        return int(x) - 1;
    }
    return int(x);
}
void main()
{
    // Запуск пункта 1

    setlocale(0, "");
    if (read())
    {
        cout << "Исходная матрица\n";
        print();
        if (equal_col() && simple_number())
            Sort();
        cout << "Преобразованная матрица" << endl;
        write();
        print();
    }

    // Запуск пункта 2

    /*setlocale(0, "");
    int x;
    cout << "Введите целое число" << endl;
    cin >> x;
    cout<<function(x)<< endl;
    double y;
    cout << "Введите дробное число" << endl;
    cin >> y;
    cout << function(y);*/

}
