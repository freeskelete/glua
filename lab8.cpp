#include <iostream>
using namespace std;
int main()
{
    // Пункт 1

    setlocale(0, "");
    int K = 4; // Изначальная массива
    int* A = (int*)calloc(K, sizeof(int)); // Динамический массив
    for (int i = 0; i < K; i++)
        A[i] = i + 1;
    cout << "Исходный массив\n";
    for (int i = 0; i < K; i++)
        cout << A[i] << "   ";
    int S;
    cout << endl << "Введите количество чисел, которое вы хотите ввести: ";
    cin >> S;
    K = K + S;
    A = (int*)realloc(A, K * sizeof(int));
    if (S < 0) 
    {
        cout << "Вы срезали массив" << endl;
        for (int i = 0; i < K; i++)
            cout << A[i] << "   ";
        free(A);
        return 0;
    }
    cout << "Введите " << S << " чис(ел)(ла)\n";
    bool flag = false;
    for (int i = K - S; i < K; i++)
    {
        cin >> A[i];
        if (A[i] == 0 && !flag)
        {
            flag = true;
        }
    }
    if (flag)
    {
        for (int i = 0; i < K; i++)
            if (A[i] % 2 == 0)
            {
                A[i] = 0;
            }
    }
    
    cout << "Массив после преобразования" << endl;
    for (int i = 0; i < K; i++)
        cout << A[i] << "   ";
    free(A);


    // Пункт 2

    //setlocale(0, "");
    //int M, N;
    //cout << "Ввдите размеры матрицы сначала сторки затем столбцы: ";
    //cin >> M >> N;
    ////Задаем динамический массив
    //int** A = new int* [M];
    //for (int i = 0; i < M; i++)
    //    for (int j = 0; j < N; j++)
    //        A[i] = new int[N];
    ////Заполняем массив
    //for (int i = 0; i < M; i++)
    //    for (int j = 0; j < N; j++)
    //        A[i][j] = 10 * (i + 1) + (j + 1);
    ////Вывод изначальной матрицы
    //cout << "Изначальная матрица" << endl;
    //for (int i = 0; i < M; i++)
    //{
    //    for (int j = 0; j < N; j++)
    //        cout << A[i][j] << "\t";
    //    cout << endl;
    //}
    ////Норма матрицы это сумма элементов в столбще по моудлю
    //int defA = Norma(A, M, N);
    //for (int i = 0; i < N; i++)
    //{
    //    int sum = 0;
    //    for (int j = 0; j < M; j++)
    //        sum += abs(A[j][i]);
    //    if (defA < sum)
    //        defA = sum;
    //}
    ////Создаем новый динамический массив
    //int** B = new int* [N];
    //for (int i = 0; i < N; i++)
    //    B[i] = new int[M];
    ////Транспонирование матрицы
    //for (int i = 0; i < N; i++)
    //    for (int j = 0; j < M; j++)
    //        B[i][j] = A[j][i];
    ////Удаляем старый массив
    //for (int i = 0; i < M; i++)
    //    delete[] A[i];
    //delete[] A;
    ////Вывод транспонированной матрицы
    //cout << "Транспонированная матрица" << endl;
    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < M; j++)
    //        cout << B[i][j] << "\t";
    //    cout << endl;
    //}
    ////считаем норму второй матрицы
    //int defB = Norma(B, N, M);
    ////Сравниваем две нормы
    //cout << "Норма изначальной матрицы равна - " << defA << endl << "Норма транспонированной матрицы равна - " << defB << endl;
    //if (defA == defB)
    //    cout << "Нормы матриц равны";
    //else if (defA > defB)
    //    cout << "Норма изначальной матрицы больше нормы транспонипованной матрицы";
    //else
    //    cout << "Норма транспонированной матрицы больше нормы изначальной";
    //cout << endl;
    ////Удаляем массив
    //for (int i = 0; i < N; i++)
    //    delete[] B[i];
    //delete[] B;

    return 0;
}
int Norma(int* A[], int M, int N)
{
    int max = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < M; j++)
            sum += abs(A[j][i]);
        if (max < sum)
            max = sum;
    }
    return max;
}
