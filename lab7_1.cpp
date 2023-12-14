#include <iostream>
#include <fstream>
using namespace std;
int Size=0;
int mas[12][12];
bool read()
{
    ifstream file("size_mas_variables.txt");
    if (file.is_open())
    {

        int num;
        file >> num;
        Size = num;
        int i = 0, j = 0;
        while (!file.eof())
        {
            for (int i = 0; i < Size; i++)
            {
                for (int j = 0; j < Size; j++)
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
        cout << "Файл не открыт чтение не возможно";
        return false;
    }
}
void print()
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            cout << mas[i][j]<<'\t';
        }
        cout << endl;
    }
}
bool mimic_col()
{
    for (int i = 0; i < Size-1; i++)
    {
        bool flag = true;
        for (int j = 0; j < Size; j++)
        {
            if (mas[j][i]!=mas[j][i+1])
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
    return 0;
}
bool simple_number()
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            bool flag=true;
            for (int c = 2; c <= sqrt(abs(mas[i][j])); c++)
            {
                if (abs(mas[i][j])%c==0)
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
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size-1; j++)
        {
            if (abs(mas[i][j]) > abs(mas[i][j + 1]))
            {
                swap(mas[i][j], mas[i][j + 1]);
            }
        }
    }
}
void write()
{
    ofstream file("result_matrix.txt");
    if (file.is_open())
    {
        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size; j++)
            {
                file << mas[i][j] << '\t';
            }
            file << endl;
        }
        file.close();
    }
    else
        cout << "Файл не открыт запись не возможна\n";
}
int function(int x)
{
    int sum=0;
    while (x)
    {
        sum += abs(x) % 10;
        x /= 10;
    }
    return sum;
}
double function(double x)
{
    if (x<0&&int(x)==x)
    {
        return int(x);
    }
    else if (x<0)
    {
        return int(x)-1;
    }
    return int(x);
}
void main()
{
    // Пункт 1

    /*setlocale(0, "");
    if (read())
    {
        cout << "Исходная матрица\n";
        print();
        if (mimic_col() && simple_number())
            Sort();
        cout << "Преобразованная матрица" << endl;
        write();
        print();
    }*/

    // Пункт 2

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

