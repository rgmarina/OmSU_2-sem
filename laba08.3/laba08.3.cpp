#include <bits/stdc++.h>

using namespace std;

struct bus{
    string numberBus, surname, initials;
    int numberRoute;
};

void printAllBus(vector<bus> arr){//выводит все данные о всех автобусах
    for(bus b : arr){
        cout << "Bus number: " << b.numberBus << endl;
        cout << "Driver's name: " << b.surname << " " << b.initials << endl;
        cout << "Bus route: " << b.numberRoute << endl;
    }
}

void busLeftPark(vector<bus> &park, vector<bus> &route, string numberB){//отвечает за переходи автобуса из парка
    for(int i = 0; i < park.size(); i++){
        if(park[i].numberBus == numberB){
            route.push_back(park[i]);
            park.erase(park.begin() + i);
            return;
        }
    }
}

void busArrivedPark(vector<bus> &park, vector<bus> &route, string numberB){//возвращает автобус в парк
    for(int i = 0; i < route.size(); i++){
        if(route[i].numberBus == numberB){
            park.push_back(route[i]);
            route.erase(route.begin() + i);
            return;
        }
    }
}

int main() {
    vector<bus> park;
    vector<bus> route;
    cout << "If you want to add a bus, enter 1: " << endl;
    int x;
    cin >> x;
    while (x == 1) { //пока х=1 добавляем
        bus b;
        cout << "Enter the bus number: ";
        cin >> b.numberBus;
        cout << "Enter the driver's last name: ";
        cin >> b.surname;
        cout << "Enter the driver's last initials: ";
        cin >> b.initials;
        cout << "Enter the route number: ";
        cin >> b.numberRoute;
        park.push_back(b);
        cout << "If you want to add a bus, enter 1: " << endl;//добавить
        cin >> x;
    }
    cout << "The original buses in the park:" << endl;//все автобусы в парке
    printAllBus(park);
    cout << "Enter 1 if the bus left the park,\nenter 2 if the bus returned to the park,\nenter 3 if you want to see a list of all buses in the park,\nenter 4 if you want to see a list of all buses on the route,\nenter 5 if you want to end the program:";
    cin >> x;
    while(true){
        if(x == 1){//уезжает из парка
            cout << "Enter the bus number" << endl;
            string s;
            cin >> s;
            busLeftPark(park, route, s);
        }
        if(x == 2){//возвращается в парк
            cout << "Enter the bus number" << endl;
            string s;
            cin >> s;
            busArrivedPark(park, route, s);
        }
        if(x == 3){//все автобусы в парке
            printAllBus(park);
        }
        if(x == 4){//все автобусы вне парка
            printAllBus(route);
        }
        if(x == 5){//конец программы
            return 0;
        }
        cout << "Enter 1 if the bus left the park,\nenter 2 if the bus returned to the park,\nenter 3 if you want to see a list of all buses in the park,\nenter 4 if you want to see a list of all buses on the route,\nenter 5 if you want to end the program:";
        cin >> x;
    }
}