#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node *next; //ссылка на следующий
};

class LinkedList {
public:
    LinkedList(int d) { //создаем список заданного размера
        head = nullptr;//ссылка в пустоту
        size = d; //размер списка
        if (size > 0) {
            head = new Node;
            Node *pNode = head;//тоже хранит ссылку
            head->data = 1; //положили 1 в голову
            for (int i = 1; i < size; i++) {
                pNode->next = new Node; //создали новую часть списка
                pNode = pNode->next; //передвинули указатель
                pNode->data = i + 1; //положили 2
                pNode->next = nullptr; //ссылка на следующий(0)
            }
        }
    }


    void PrintList() { //выводим весь список
        Node *pNode = head;
        while ((pNode->next) != nullptr) { //пока не конец списка
            PrintNode(pNode); //выводим текущее значение
            pNode = pNode->next; //переходим на следующую часть списка
        }
        cout << pNode->data << endl; //выводим последний элемент
    }

    //добавление элемента в конец
    void push_back(int d) {
        Node *pNode = head;
        while ((pNode->next) != nullptr) {  //пока есть указатель на следующий элемент
            pNode = pNode->next; //переходим к следующему
        }
        pNode->next = new Node; //добавляяет в место пустоты Node
        pNode = pNode->next;
        pNode->data = d; //переходим к следующему значению
        pNode->next = nullptr; //указатель = 0
        size++; //увеличиваем размер
    }

    //добавление элемента в начало
    void push_front(int elem) {
        Node *zNode = head;
        Node *pNode = new Node;
        pNode->data = elem; //новое значение, которое пришло на вход
        pNode->next = zNode; //следующее к z
        head = pNode;
        size++;
    }

    //поиск elemNode, вернет Node, передаем индекс
    Node *FindNode(int elem) {
        Node *fNode = head;
        for (int i = 0; i < elem; i++) { //идем по индксам до определенного
            fNode = fNode->next;
        }
        return fNode;
    }

    //поиск элемента elemint, даем знаение, вернет индекс
    int FindCountOfNode(int elem) {
        Node *fNode = head;
        for (int i = 0; i < size; i++) { //идем через весь список
            if (fNode->data == elem) { //не равен ли текущий тому кому ищем
                return i;
            }
            fNode = fNode->next;
        }
        return -1;
    }

    //добавить элемент, после индекса
    void AddNext(int elem, int ind) {
        Node *fNode = head;
        for (int i = 0; i < size; i++) { //идем во всю длину
            if (fNode->data == ind) { //элемент после которого надо вставить (ind)
                Node *zNode = new Node;
                zNode->data = elem;
                zNode->next = fNode->next;
                fNode->next = zNode;
                size++;
                break;
            }
            fNode = fNode->next;
        }
    }

    //добавить элемент, перед индексом
    void AddPrew(int elem, int ind) {
        Node *fNode = head;
        for (int i = 0; i < size; i++) {
            if (fNode->next->data == ind) {
                Node *zNode = new Node;
                zNode->data = elem;
                zNode->next = fNode->next;
                fNode->next = zNode;
                size++;
                break;
            }
            fNode = fNode->next; //пока не встретим нужное
        }
    }

    //удалить Node с ind индексом
    void DeleteNode(int ind) {
        Node *pNode = head;
        Node *prew = pNode;
        for (int i = 0; i < ind; i++) { //доходим до нужного индекса
            prew = pNode; //хранит ссылку на предыдущий
            pNode = pNode->next;
        }
        prew->next = pNode->next; //ссылка на через элемент
        delete pNode;
        size--; //размер -1
    }


    //получить длину списка
    int getSize() const {
        return size;
    }

private:
    Node *head; //ссылка на голову
    int size; //размер всего списка

    void PrintNode(Node *pNode) {
        cout << pNode->data << " -> ";
    }
};

int main() {
    int n;//длина списка=последний элемент
    cin >> n;

    LinkedList list = LinkedList(n); //конструктор класса
    list.PrintList();
    cout << endl;

    list.push_front(111); //добавить в начало
    list.PrintList();
    cout << endl;

    list.push_back(999);
    list.PrintList();
    cout << endl;

    cout << (list.FindNode(4))->data << endl;
    cout << endl;
    cout << (list.FindCountOfNode(999)) << endl;
    cout << endl;

    list.AddNext(333, 3);
    list.PrintList();
    cout << endl;

    list.AddPrew(222, 3);
    list.PrintList();
    cout << endl;

    list.DeleteNode(4);
    list.PrintList();
    cout << endl;

    cout << list.getSize() << endl;
}
