#include <bits/stdc++.h>

using namespace std;

struct student {
    string surname, initials;
    int numberGroup;
    vector<int> grade; //успеваемость
};

int main() {

    vector <student> arr; //хранит все структуры
    cout << "If you want to add a student, enter 1: " << endl;//если хотите добавить студента введите 1:
    int x;
    cin >> x; //записываем в переменную х
    while (x == 1) {
        student st; //элемент структуры(все 4 пол€)
        cout << "Enter the student's last name: ";//введите фамилию студента:
        cin >> st.surname;
        cout << "Enter the student's initials: ";//введите инициалы студента:
        cin >> st.initials;
        cout << "Enter the student group number of the student: ";//введите номер группы студента студента:
        cin >> st.numberGroup;
        int y;
        cout << "Enter the student's grades, if the grades are over, enter 0: " << endl;//вводите оценки студента, если оценки кончились введите 0:
        cin >> y;
        while (y != 0) { //пока у не равен 0
            st.grade.push_back(y); //добавляй в конец
            cin >> y; //записываем в переменную у
        }
        arr.push_back(st);
        cout << "If you want to add a student, enter 1: " << endl;//если хотите добавить студента введите 1:
        cin >> x;
    }
    sort(arr.begin(), arr.end(),
         [](student a, student b) { //сортируем по возрастанию номера группы (от начала до конца)
             return a.numberGroup < b.numberGroup; //сравниваем номер группы
         });
    int c = 0;
    for (auto st: arr) { //идем по всем студентам
        int sm = 0; //сумма оценок
        for (int z: st.grade) {
            sm += z;
        }
        if (ceil((float) sm / (float) st.grade.size()) > 4) { //если средний балл >4 то выводим этого студента
            c++;
            cout << st.surname << " " << st.initials << endl;
            cout << st.numberGroup << endl;
        }
    }
    if (c == 0 && !arr.empty()) {
        cout << "There are no students with an average score of more than 4" << endl;//студенты с средним баллом больше 4
    }
}