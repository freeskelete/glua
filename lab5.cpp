#include <iostream>
#include <math.h>

int main () {
    const int K = 20;
    int array[K];

    int n;
    std::cout << "Vvedite N: ";
    std::cin >> n;

    for (int i = 0; i<n; i++){
        std::cin >> array[i];
    }
    
    int tmp = 0;
    bool flag = false, digitEqual;
    for (int i = 0; i<n; i++){
        tmp = array[i];
        digitEqual = true; 
        if (tmp < 10){
            continue;
        }
        if (tmp < 100 && tmp % 10 == (tmp / 10)){
            flag = true;
            break;
        }
        else {
            while (tmp>10){
            if (tmp % 10 != (tmp / 10) % 10){
                digitEqual = false;
                break;
            }
            tmp /= 10;
        }
        if (digitEqual){
            flag = true;
            break;
        }   
        }
        
    }
    if (flag) {
        std::cout << "Yes";
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (array[i] > array[j]){
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
    else {
        std::cout << "No";
    }
    for (int i = 0; )
}
