#include <iostream>
#include <math.h>

int main() {
    const int K = 20;
    const int N = 10;
    const int M = 10;
    int array[K];

    // пункт 1
    int n;
    std::cout << "Vvedite N: "; 
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    int tmp = 0;
    bool flag = false, digitEqual;
    for (int i = 0; i < n; i++) {
        tmp = array[i];
        digitEqual = true;
        if (tmp < 11) {
            continue;
        }
        if (tmp < 100 && tmp % 10 == (tmp / 10)) {
            flag = true;
            break;
        }
        else {
            while (tmp > 10) {
                if (tmp % 10 != (tmp / 10) % 10) {
                    digitEqual = false;
                    break;
                }
                tmp /= 10;
            }
            if (digitEqual) {
                flag = true;
                break;
            }
        }

    }
    if (flag) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (array[i] > array[j]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }

    // вывод
    else {
        std::cout << "No" << std::endl;
    }
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << std::endl;
    }
    
    // // Доп 1.
     if (flag) {
         int sum_digit_massive[N];
         int tmp = 0;
         int sum_digit = 0;
         for (int i = 0; i < n; i++){
             tmp = array[i];
             while (tmp){
                 sum_digit += abs(tmp % 10);
                 tmp /= 10;
             }
             sum_digit_massive[i] = sum_digit;
             sum_digit = 0;
         }
         for (int i = 0; i < n - 1; i++){
             for (int j = 0; j < n - i - 1; j++){
                 if (sum_digit_massive[j] > sum_digit_massive[j+1]){
                     tmp = array[j];
                     array[j] = array[j+1];
                     array[j+1] = tmp;
                     tmp = sum_digit_massive[j];
                     sum_digit_massive[j] = sum_digit_massive[j+1];
                     sum_digit_massive[j+1] = tmp;
                 }
             }
         }
     }
     // Вывод
     std::cout << "Sorted massive (optional 1.): ";
     std::cout << "[";
     for (int i = 0; i < n-1; i++){
         std::cout << array[i] << ", ";
     }
     std::cout << array[n - 1] << "]" << std::endl;
    
    // пункт 2
    short matrix[N][M];
    short nn, mm;
    std::cout << "Vvedite N i M: " << std::endl;
    std::cin >> nn >> mm;
    std::cout << "Enter matrix: " << std::endl;
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < mm; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int min_sum = INT_MAX;
    int min_row = -1;
    for (int i = 0; i < nn; i++) {
        int sum = 0;
        for (int j = 0; j < mm; j++) {
            sum += matrix[i][j];
        }
        if (abs(sum) < min_sum) {
            min_sum = sum;
            min_row = i;
        }
    }

    for (int j = 0; j < mm; ++j) {
        matrix[min_row][j] = 0;
    }
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < mm; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
