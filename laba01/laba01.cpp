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

    void resize(int m1, int n1) {
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

    void print() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void print_kus(int a, int b) {
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
    cout << "Введите размер исходной матрицы: " << endl;
    cin >> m >> n;
    Matrix matrica(m, n);
    while (true) {
        cout << "Если хотите вывести матрицу на экран нажмите 1" << endl;
        cout << "Если хотите вывести часть матрицы на экран нажмите 2" << endl;
        cout << "Если хотите изменить размер матрицы нажмите 3" << endl;
        cout << "Если хотите завершить программу нажмите 4" << endl;
        cin >> comand;
        switch (comand) {
            case 1: {
                matrica.print();
                cout << endl;
                break;
            }
            case 2: {
                int x, y;
                cout << "Введите размер куска матрицы, который необходимо вывести: " << endl;
                cin >> x >> y;
                matrica.print_kus(x, y);
                break;
            }
            case 3: {
                int x, y;
                cout << "Введите размер новой матрицы: " << endl;
                cin >> x >> y;
                matrica.resize(x, y);
                break;
            }
            case 4: {
                return 0;
            }
        }
    }
}