#include <bits/stdc++.h>

using namespace std;

//меняет 2 элемента местами, на вход получает ссылку на массив в котором надо поменять элементы и индексы этих элементов
void swap(valarray<int> &arr, int ind1, int ind2){
    int elem = arr[ind2];
    arr[ind2] = arr[ind1];
    arr[ind1] = elem;
}

//функция сортирующая массив, на вход получает отсортированный массив
valarray<int> sortTask(valarray<int> arr){
    valarray<int> ans;
    ans.resize(arr.size());
    int iZero = 0;
    for(int i = 0; i < arr.size(); i++){//проходим по всем элементам
        if(arr[i] == 0){
            iZero = i;
            break;
        }
    }
    int c = 0;
    for(int i = iZero; i < arr.size(); i++){//проходим от 0 до конца элементов
        ans[c] = arr[i];
        c++;
    }
    for(int i = 0; i < iZero; i++){//проходим от начала до 0
        ans[c] = arr[i];
        c++;
    }
    return ans;
}

int main() {
    valarray<int> arr;
    int n, x;
    cout << "Enter the number of items: " << endl;//введите количество элементов:
    cin >> n;
    arr.resize(n);//количество элементов
    for (int i = 0; i < arr.size(); i++) {
        cout << "Enter the element: ";//введите элемент:
        cin >> x;
        arr[i] = x;
    }
    long proiz = 1;//произведение элементов с четными индексами, long намного больше размер допустимых значений, чем int
    int iFirst0 = 9999, iLast0;
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) { //проверяем четность
            proiz *= arr[i];
        }
        //запоминаем индекс первого и последнего 0
        if(iFirst0 == 9999 && arr[i] == 0){
            iFirst0 = i;
        }
        if(arr[i] == 0){
            iLast0 = i;//то это последний 0
        }
        cout << arr[i] << endl;//выводит все эелементы
    }
    int sm = 0;//сумма элементов между первым и последним 0
    for(int i = iFirst0; i < iLast0; i++){
        sm += arr[i];
    }
    cout << "The product of elements with even indices: " << proiz << endl;//произведение элементов с четными индексами:
    cout << "The sum of the elements between the first and last 0: " << sm << endl;//сумма элементов между первым и последним 0:
    sort(begin(arr), end(arr));
    //выводим в изначальном порядке
    for(auto elem : arr){
        cout << elem << " ";
    }
    cout << endl;
    arr = sortTask(arr);
    //выводим в порядке задание
    for(auto elem : arr){
        cout << elem << " ";
    }
}