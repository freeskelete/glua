/*
#include <iostream>
int N;
int a;
int sum = 0;
int b = 0;
int max_index = 0;
using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    cout << "Введи количество элементов последовательности";
    cin >> N;
    cout << "Введите " << N << "элементов последовательности";

    double even_sum = 0, double odd_sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a % 2 == 0) {
            sum += a;
            if (a > b) {
                b = a;
                max_index = i + 1;

            }
        }

        if (i & 1){
            odd_sum += a;
        }
        else {
            even_sum += a;
        }


    }
    cout << "Сумма чётных чисел = " << sum << endl;
    cout << "Максимальное чётное значение = " << b << endl;
    cout << "Номер наибольшего чётного в последовательности - " << max_index;

    return 0;

}
*/


#include <iostream>
#include <cmath>
using namespace std;
int a;
int mun = 10;
int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int x;
    cout << " Введите число, меньше чем 1 000 000 000 " << endl;
    cin >> x;
    if (x < pow(10, 9)) {
        if (x < 0) {
            x *= -1;
        }

        while (x > 0) {
            a = x % 10;
            x /= 10;
            if (mun > a && a != 0 && a != 7) {
                mun = a;
            }
        }

        cout << "Наименьшая цифра в числе: " << mun;
    }
    else {
        cout << "Введено неверное значение";
    }
    return 1;
}
