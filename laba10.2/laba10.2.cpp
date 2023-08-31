#include <bits/stdc++.h>

using namespace std;

int main() {
    valarray<valarray<int>> arr;
    cout << "Enter the size of the matrix: ";//введите размер матрицы:
    int n, m, x;//количество строк и столбцов
    cin >> n >> m;
    arr.resize(n);
    cout << "Enter the matrix elements" << endl;//введите элементы матрицы
    for (int i = 0; i < n; i++) {//проходим по всем элементам строки
        arr[i].resize(m);
        for (int j = 0; j < m; j++) {//проходим по всем элементам столбца
            cin >> x;
            arr[i][j] = x;
        }
    }
    vector<int> vec;//создадим вектор чтобы найти максимальный повторяющийся элемент
    int countWithoutZero = 0; //количество строк без 0
    for (int i = 0; i < n; i++) {
        bool zero = false;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {//если в строке есть 0 меняем флаг
                zero = true;
            }
            cout << arr[i][j] << " ";
            vec.push_back(arr[i][j]);//добавили элемент в вектор
        }
        if(!zero){//если флаг поменялся не добавляем строку (так как был 0)
            countWithoutZero++;
        }
        cout << endl;
    }
    cout << "Number of rows without 0: " << countWithoutZero << endl;//Количество строк без 0:
    sort(vec.begin(), vec.end());//сортируем во возрастанию
    bool flag = false;
    while (vec.size() > 1 && !flag){//пока размер >1
        x = vec[vec.size() - 1];//сохраняем самый правый элемент в х и удаляем его з вектора
        vec.pop_back();
        if(x == vec[vec.size() - 1]){//проверка что х=последнему элементу
            cout << "The maximum number occurring in the matrix more than 1 time: " << x << endl;//Максимальное число, встречающееся в матрице более 1 раза:
            flag = true;//больше не заходим в цикл
        }
    }
    if(vec.size() <= 1 && !flag){
        cout << "There are no duplicate elements in the array" << endl; //в массиве нет повторяющихся элементов
    }
}