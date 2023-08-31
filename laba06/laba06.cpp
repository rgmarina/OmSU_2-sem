#include <bits/stdc++.h>

using namespace std;

class Matrix {
public:
    double **mat;
    int m;
    int n;

    Matrix(int m2, int n2) {
        m = m2;
        n = n2;
        mat = new double *[m2];
        for (int i = 0; i < m2; i++) {
            mat[i] = new double[n2];
            for (int j = 0; j < n2; j++) {
                mat[i][j] = 1;
            }
        }
    }

    void resize(int m1, int n1) {//при вызове изменяется размер и новые поле заполняется 0
        double **new_mat;
        new_mat = new double *[m1];
        for (int i = 0; i < m1; i++) {
            new_mat[i] = new double[n1];
            for (int j = 0; j < n1; j++) {
                new_mat[i][j] = 0;
            }
        }
        int m_vost, n_vost;
        m_vost = m1 > m ? m : m1;
        n_vost = n1 > n ? n : n1;
        for (int i = 0; i < m_vost; i++) {
            for (int j = 0; j < n_vost; j++) {
                new_mat[i][j] = mat[i][j];
            }
        }
        mat = new_mat;
        m = m1;
        n = n1;
    }

    void resize(int m1, int n1, int elem) { //две функции с одинаковыми названиями, но в этой еще +1 элемент
        double **new_mat;//при вызове новые поля заполняются введенным числом
        new_mat = new double *[m1];
        for (int i = 0; i < m1; i++) {
            new_mat[i] = new double[n1];
            for (int j = 0; j < n1; j++) {
                new_mat[i][j] = elem;
            }
        }
        int m_vost, n_vost;
        m_vost = m1 > m ? m : m1;
        n_vost = n1 > n ? n : n1;
        for (int i = 0; i < m_vost; i++) {
            for (int j = 0; j < n_vost; j++) {
                new_mat[i][j] = mat[i][j];
            }
        }
        mat = new_mat;
        m = m1;
        n = n1;
    }

    void print() { //функция отвечает за исходную матрицу
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void print_kus(int a, int b) { //функция отвечает за вывод кусочка матрицы
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }


};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, comand;
    cout << "Enter the size of the original matrix: " << endl; //размер исходной матрицы
    cin >> m >> n;//считываем размеры основной матрицы
    Matrix matrica(m, n);
    while (true) {
        cout << "If you want to display the matrix on the screen, press 1"
             << endl; //если хотите вывести матрицу на экран нажмите 1
        cout << "If you want to display a part of the matrix on the screen, press 2"
             << endl; //если хотите вывести часть матрицы на экран нажмите 2
        cout << "If you want to change the size of the matrix, press 3"
             << endl; //если хотите изменить размер матрицы нажмите 3
        cout << "If you want to end the program, press 4" << endl; //если хотите завершить программу нажмите 4
        cin >> comand;
        switch (comand) {
            case 1: {
                matrica.print(); //выводим основную матрицу
                cout << endl;
                break;
            }
            case 2: {
                int x, y;
                cout << "Enter the size of the matrix piece to be output: "
                     << endl; //введите размер куска матрицы, который необходимо вывести:
                cin >> x >> y; //вводим размер куска матрицы
                matrica.print_kus(x, y);
                break;
            }
            case 3: {
                int x, y;
                cout
                        << "If the size of the new matrix is larger than the old one, enter the number with the third value - the new elements of the matrix." //если размер новой матрицы больше старой введите третьим значением число - новые элементы матрицы
                        << endl;
                cout << "Enter the size of the new matrix: " << endl; //введите размер новой матрицы:
                cin >> x >> y;
                if (x > m || y > n) {//сравниваем основную матрицу и новые значения
                    int c;
                    cin >> c;
                    matrica.resize(x, y, c); //размеры новой матрицы +дополнительный элемент(если больше основной)
                } else {
                    matrica.resize(x, y); //рамер новой матрицы, если на меньше основной
                }
                break;
            }
            case 4: {
                return 0; //конец программы
            }
        }
    }
}