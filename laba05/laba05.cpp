#include <bits/stdc++.h>

using namespace std;

struct scanInfo {
    string model;//название модели
    int price, optr, grey;//цена, оптическое разрешение, число градаций серого
    int xSize, ySize;//горизонтальный/вертикальный размер области сканирование
};

void printScanInfo(scanInfo elem) {
    cout << "Model: " << elem.model << endl;
    cout << "Price: " << elem.price << endl;
    cout << "Optr: " << elem.optr << endl;
    cout << "Grey: " << elem.grey << endl;
    cout << "xХy size: " << elem.xSize << "Х" << elem.ySize << endl;
}

void printScanInfoVector(vector<scanInfo> list) {
    for (scanInfo elem: list) {
        printScanInfo(elem);
    }
}

int addBinFile(vector<scanInfo> list, ofstream &out) {
    if (!out.is_open()) {
        cout << "File is not open" << endl;
        return -1;
    }
    string uppend = "";
    string binary = bitset<16>(list.size()).to_string();
    uppend += binary;
    for (scanInfo elem: list) {
        for (char c: elem.model) {
            binary = bitset<8>((int) c).to_string();
            cout << (int) c << ' ' << binary << endl;
            uppend += binary;
        }
        binary = bitset<32>(elem.price).to_string();
        uppend += binary;
        binary = bitset<32>(elem.optr).to_string();
        uppend += binary;
        binary = bitset<32>(elem.grey).to_string();
        uppend += binary;
        binary = bitset<32>(elem.xSize).to_string();
        uppend += binary;
        binary = bitset<32>(elem.ySize).to_string();
        uppend += binary;
    }
    out << uppend;
    return 0;
}

unsigned long toInt(std::string const &s) {
    static const std::size_t MaxSize = CHAR_BIT * sizeof(unsigned long);
    if (s.size() > MaxSize) return 0; // handle error or just truncate?

    std::bitset<MaxSize> bits;
    std::istringstream is(s);
    is >> bits;
    return bits.to_ulong();
}

int printScanFromFile(int numberScan, ifstream &in) { //numberScan - номер сканера который надо вывести
    if (!in.is_open()) {
        cout << "File is not open" << endl;
        return -1;
    }
    string inp;
    in >> inp;
    string s = "";
    for (int i = 0; i < 16; i++) {
        s += inp[i];
    }
    int size = toInt(s);
    if (size < numberScan) {
        cout << "The printer number to output is greater than the number of printers in the file" << endl;
        return -1;
    }
    int start = 16 + (numberScan - 1) * 184;
    int i = start;
    bool end = false;
    scanInfo scanner;
    s = "";
    while(!end){
        s+=inp[i];
        if(i == start + 7){
            scanner.model += char(toInt(s));
            s = "";
        }
        if(i == start + 15){
            scanner.model += char(toInt(s));
            s = "";
        }
        if(i == start + 23){
            scanner.model += char(toInt(s));
            s = "";
        }
        if(i == start + 55){
            scanner.price = toInt(s);
            s = "";
        }
        if(i == start + 87){
            scanner.optr = toInt(s);
            s = "";
        }
        if(i == start + 119){
            scanner.grey = toInt(s);
            s = "";
        }
        if(i == start + 151){
            scanner.xSize = toInt(s);
            s = "";
        }
        if(i == start + 183){
            scanner.ySize = toInt(s);
            s = "";
        }
        if(i == start + 183){
            end = true;
        }
        i++;
    }
    printScanInfo(scanner);
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ifstream input(
            "D:/laba05/inputLaba05.txt");
    string s;
    vector<scanInfo> arr;
    while (getline(input, s)) {
        stringstream ss(s);
        string str;
        scanInfo elem;
        ss >> str;
        elem.model = str;
        ss >> str;
        elem.price = stoi(str);
        ss >> str;
        elem.optr = stoi(str);
        ss >> str;
        elem.grey = stoi(str);
        ss >> str;
        elem.xSize = stoi(str);
        ss >> str;
        elem.ySize = stoi(str);
        arr.push_back(elem);
    }
    input.close();
    ofstream out("D:/laba05/outLaba05.txt");
    printScanInfoVector(arr);
    addBinFile(arr, out);
    out.close();
    ifstream in("D:/laba05/inputLaba05.txt");
    printScanFromFile(3, in);
}