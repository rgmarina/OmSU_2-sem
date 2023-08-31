#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<float> arr; //одномерный массив вещественных элементов, vector - контейнерный класс
    cout << "Fill the array with elements, if you want to finish, enter 9999: "
         << endl;//заполните массив элементами, если вы хотите закончить, введите 9999:
    float x;
    cin >> x;
    while (x != 9999) { //пока х не равен 9999
        arr.push_back(x);
        cin >> x;
    }
    sort(arr.begin(), arr.end());//сортируем массив используя алгоритм библиотеки
    float sum = 0;//сумма отрицательных элементов массива
    double proiz = 1;//произведение элементов между min и max
    //после сортировки минимальный элемент имеет индекс 0, а максиальный arr.size() - 1
    for (int i = 0; i < arr.size(); i++) {//проходим по всем элементам массива
        if (arr[i] < 0) {//если элемент отрицательный добавл€ем его в сумму отрицательных элементов
            sum += arr[i];
        }
        if (0 < i && i < arr.size() - 1) {//элементы между максимальным и минимальным элементами
            proiz *= (double) arr[i];
        }
        cout << arr[i] << " ";//выводим все элементы массива
    }
    cout << endl;
    cout << "The sum of the negative elements of the array is equal to: " << sum
         << endl;//сумма отрицательных элементов массива равна:
    cout << "The product of the numbers between the maximum and minimum element in the array: " << proiz
         << endl;//произведение чисел между максимальным и минимальным элементом в массиве:
}