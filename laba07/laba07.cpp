#include <bits/stdc++.h>

using namespace std;

int main() {
    //файл должен быть с английскими символами
    ifstream input("/Users/rg_marina/CLionProjects/main/inputLaba7.dat");
    string s, text = "";
    while (getline(input, s)){ //считываем все с файла, добавляем в s
        cout << s << endl;
        text += s;
    }
    int count = std::count(text.begin(), text.end(), '.') + std::count(text.begin(), text.end(), '?') + //считаем предложение
                std::count(text.begin(), text.end(), '!');
    string x = "";
    bool first = true;
    int number = 0;
    while(x != "-1"){
        cout << "Нажмите любую клавишу если хотите вывести следуюйщее предложение, если хотите закончить введите -1" << endl;
        cin >> x;
        if(number == count){ //если равно количеству предложений
            x = "-1";
        }
        first = true;
        for(char elem : text){
            if(first){
                if(elem == ' '){
                    first = false;
                    continue;
                }
                first = false;
            }
            if(elem != '.' && elem != '?' && elem != '!'){
                cout << elem;
            }else{
                text = text.substr(text.find(elem) + 1); //первое вхождение(конец  предложение) удаляет предложение которое уже было
                cout << elem;
                break;
            }
        }
        cout <<endl;
        number++;
    }
    cout << "Количество предложений в тексте: " << count << endl;
}
