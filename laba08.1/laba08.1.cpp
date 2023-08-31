#include <bits/stdc++.h>

using namespace std;

int square(vector<pair<int, int>> arr) { //все вершины многоугольника
    int sum = 0;
    int x = arr[0].first;
    int y = arr[0].second;
    int x1 = x;
    int y1 = y;
    int x2, y2;
    for (int i = 1; i < arr.size(); i++) {
        x2 = arr[i].first;
        y2 = arr[i].second;
        sum += (x1 + x2) * (y2 - y1); //площадь многоугольника
        x1 = x2;
        y1 = y2;
    }
    sum += (x + x2) * (y - y2);
    return abs(sum) / 2; //модуль
}

bool check(vector<pair<int, int>> first, vector<pair<int, int>> second) {
    //пройдем по всем точкам второго многоугольника и проверим что они внутри первого
    for (auto point: second) {
        bool result = false;
        int j = first.size() - 1;
        for (int i = 0; i < first.size(); i++) {
            if ((first[i].second < point.second && first[j].second >= point.second ||
                 first[j].second < point.second && first[i].second >= point.second) &&
                //проверка все ли вершины лежат внутри другого многоугольника
                (first[i].first + (point.second - first[i].second) / (first[j].second - first[i].second) *
                                  (first[j].first - first[i].first) < point.first))
                result = !result;
            j = i;
        }
        if (!result) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices in the first and second polygon: "
         << endl; //введите количество вершин в первом и втором многоугольнике:
    cin >> n >> m;
    vector<pair<int, int>> firstArr; //хранит 2 значения
    vector<pair<int, int>> secondArr;
    int x, y;
    for (int i = 0; i < n; i++) { //пока все координаты
        cin >> x >> y;
        firstArr.push_back({x, y});
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        secondArr.push_back({x, y});
    }
    cout << "The area of the first polygon: " << square(firstArr) << endl; //площадь первого многоугольнинка:
    cout << "The area of the second polygon: " << square(secondArr) << endl; //площадь втрого многоугольнинка:
    cout << "The second polygon lies strictly inside the first one: " << check(firstArr, secondArr)
         << endl; //проверка лежит ли оно  0 - не лежит; второй многоугольник лежит строго внутри первого:
}