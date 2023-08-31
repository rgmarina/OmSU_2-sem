#include <string>
#include <iostream>
using namespace std;
class CFile {
public:
    CFile() : _is_open(false), _position(0), _length(0) {
        cout << "CFile construct was called" << endl;  // Конструктор по умолчанию
    }
    CFile(const string &path) : _path(path), _is_open(false), _position(0), _length(0) {
        cout << "CFile overload construct was called. Path is " << _path << endl;
        open();  // Конструктор с параметром - путь к файлу
    }
    virtual ~CFile() {  // Виртуальный деструктор
        if (_is_open)
            close();
        cout << "CFile destruct was called. Path is " << _path << endl;
    }
    virtual bool open() {  // Виртуальный метод открытие файла
        if (_is_open) {
            return true;
        }
        _is_open = true;  // Открыть файл
        cout << "CFile open was called" << endl;
        return true;
    }
    virtual void close() {  // Виртуальный метод закрытие файла
        _is_open = false;  // Закрыть файл
        cout << "CFile close was called" << endl;
    }
    virtual void seek(int pos) {  // Виртуальный метод перемещение позиции чтение/записи
        _position = pos;    // ѕереместить позицию чтение/записи в указанное место
        cout << "CFile seek was called" << endl;
    }
    virtual int read(char *buf, int size) {  // Виртуальный метод чтение данных из файла
        if (!_is_open)
            return 0;
        cout << "CFile read was called" << endl;
        return size;
    }
    virtual int write(const char *buf, int size) {  // Виртуальный метод записи данных в файл
        if (!_is_open)  // Записать данные в файл
            return 0;
        cout << "CFile write was called" << endl;
        return size;
    }
    virtual int getPosition() const {  // Виртуальный метод получения текущей позиции в файле
        return _position;  // Получить текущую позицию в файле
    }
    virtual int getLength() const {  // Виртуальный метод получения длины файла
        return _length;  // Получить длину файла
    }
protected:
    bool _is_open; // флаг открытого файла
    std::string _path; // путь к файлу
    int _position; // текущая позиция в файле
    int _length; // длина файла
};
struct MyData {  // определение структуры MyData, содержащей единственное поле - целочисленный счетчик
    int count;
};
class CMyDataFile : public CFile {  // определение класса CMyDataFile, производного от CFile
public:
// Конструктор по умолчанию, инициализирующий родительский класс CFile,
// выделяющий память дл€ объекта MyData и инициализирующий заголовок файла
    CMyDataFile() : CFile(), data(new MyData), _header("MyDataFileHeader") {
        cout << "CMyDataFile construct was called" << endl;
    }

// Перегруженный конструктор, принимающий путь к файлу,
// инициализирующий родительский класс CFile,
// выделяющий память для объекта MyData и инициализирующий заголовок файла,
// а затем открывающий файл
    CMyDataFile(const std::string &path) : CFile(path), data(new MyData), _header("MyDataFileHeader") {
        cout << "CMyDataFile overload construct was called. Path is " << _path << endl;
        open();
    }

// деструктор, освобождающий память, закрывающий файл
// и выводящий информацию о завершении жизни объекта
    ~CMyDataFile() {
        close();
        delete data;
        cout << "CMyDataFile destruct was called. Path is " << _path << endl;
    }
    bool open() override {  // переопределенный метод открытия файла, читающий заголовок файла и проверяющий его на соответствие
        bool ok = CFile::open();
        if (ok) {
            _position = _header.size();  // чтение заголовка файла
            cout << "CMyDataFile open was called" << endl;
            int header_size = _header.size();
            char *header_buf = new char[header_size];
            int read_size = CFile::read(header_buf, header_size);
            if (read_size != header_size) {
                cout << "Error reading header" << endl;
                ok = false;
            } else {
                std::string read_header(header_buf, header_size);
                if (read_header != _header) {
                    cout << "Wrong header" << endl;
                    ok = false;
                } else {
                    cout << "Header is OK" << endl;
                }
            }
            delete[] header_buf;
        }
        return ok;
    }
    void close() override {  // переопределенный метод закрытия файла, записывающий заголовок файла и закрывающий файл
        _position = 0;  // сохранение заголовка файла
        int header_size = _header.size();
        char *header_buf = new char[header_size];
        std::copy(_header.begin(), _header.end(), header_buf);
        CFile::write(header_buf, header_size);
        delete[] header_buf;
        CFile::close();
        cout << "CMyDataFile close was called" << endl;
    }
    int read(MyData *data) {  // объявление функции чтения данных
        if (!_is_open) // если файл не открыт, возвращаем 0
            return 0;
        int read_size = CFile::read(reinterpret_cast<char *>(data), sizeof(MyData));  // читаем данные в структуру MyData
        cout << "CMyDataFile read was called" << endl; // выводим сообщение о вызове функции
        return read_size; // возвращаем количество прочитанных байт
    }
    int write(const MyData *data) {  // обэявление функции записи данных
        if (!_is_open) // если файл не открыт, возвращаем 0
            return 0;
        int write_size = CFile::write(reinterpret_cast<const char *>(data), sizeof(MyData));  // записываем данные структуры MyData в файл
        cout << "CMyDataFile write was called" << endl; // выводим сообщение о вызове функции
        return write_size; // возвращаем количество записанных байт
    }
private:
    MyData *data; // указатель на данные
    std::string _header; // заголовок файла
};
int main() {
    CMyDataFile file("data.bin");  // создаем экземпляр класса CMyDataFile для работы с файлом "data.bin"
    if (file.open()) { // если файл успешно открыт
        MyData data; // создаем объект структуры MyData
        data.count = 42; // задаем значение пол€ count
        file.write(&data); // записываем данные в файл
        file.close(); // закрываем файл
    }
}
