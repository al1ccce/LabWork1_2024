#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
using namespace std;

struct Node{
    string val;
    Node* next;
};

struct HashBucket{
    string key;
    string value;
}; 

struct Nodedb{
    string val;
    Nodedb* prev;
    Nodedb* next;
};

struct LinkedList{
    Node* head;
    LinkedList(){
        head = nullptr;
    }
    // Список односвязный---------------------------
    void addTail(string val){
        Node* newNode = new Node{val, nullptr};
        // Если список пустой
        if (head == nullptr) { 
            head = newNode;
            return;
        }
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    void addHead(string val){
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void print(string file, string namestruct) {
        ofstream out;
        out.open(file);
        out << namestruct << endl;
        Node* current = head;
        while (current != nullptr) {
            out << current->val << endl;
            current = current->next;
        }
        out.close();
    }

    void printbash() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->val;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    void deleteHead(){
        if (head == nullptr) return;
        Node* current = head->next;
        delete head;
        head = current;
    }

    void deleteTail(){
        if (head == nullptr) return;
        // Если 1 узел в списке
        if (head->next == nullptr) {delete head; head = nullptr; return;} 
        Node* tail = head;
        // Ищем предпоследнее значение
        while (tail->next->next != nullptr) { 
            tail = tail->next;
        }       
        delete tail->next;
        tail->next = nullptr;   
    }

    void deleteValue(string value) {
        if (head == nullptr) return;
        if (head->val == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->val != value) {
            current = current->next;
        }
        // Если не найдено
        if (current->next == nullptr) {
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    bool find(string value){
        Node* current = head;
        while(current != nullptr){
            if (current->val == value){
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

struct DoubleLinkedList{
    Nodedb* head;
    Nodedb* tail;
        DoubleLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void addTail(string val){
        Nodedb* newNode = new Nodedb{val, tail, nullptr};
        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            // Если список пустой, обновляем head
            head = newNode;
        }
        tail = newNode;
    }

    void addHead(string val) {
        Nodedb* newNode = new Nodedb{val, nullptr, head};
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            // Если список пустой, обновляем tail
            tail = newNode;
        }
        head = newNode;
    }

    void deleteHead(){
        if (head == nullptr) return;
        if (head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Nodedb* current = head->next;
        delete head;
        head = current;
        head->prev = nullptr;
    }

    void deleteTail() {
        if (tail == nullptr) return; // Если список пуст, ничего не делаем
        if (head == tail) { // Если в списке только один узел
            delete tail;
            head = nullptr;
            tail = nullptr;
            return;
        }
        // Если в списке больше одного узла
        Nodedb* prevTail = tail->prev; 
        delete tail; 
        tail = prevTail; 
        tail->next = nullptr; 
    }

    void deleteValue(string value) {
        if (head == nullptr) return; // Если список пуст, ничего не делаем
        // Если значение находится в голове списка
        if (head->val == value) {
            Nodedb* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr; // Обновляем указатель prev новой головы
            } else {
                tail = nullptr; // Если список стал пустым, обновляем tail
            }
            delete temp;
            return;
        }
        Nodedb* current = head;
        while (current->next != nullptr && current->next->val != value) {
            current = current->next;
        }
        // Если значение не найдено
        if (current->next == nullptr) {
            return;
        }
        Nodedb* temp = current->next;
        current->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = current; // Обновляем указатель prev следующего узла
        } else {
            tail = current; // Если удаляемый узел был хвостом, обновляем tail
        }
        delete temp;
    }

    bool find(string value){
        Nodedb* current = head;
        while(current != nullptr){
            if (current->val == value){
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void print(string file, string namestruct) {
        ofstream out;
        out.open(file);
        out << namestruct << endl;
        Nodedb* current = head;
        while (current != nullptr) {
            out << current->val << endl;
            current = current->next;
        }
        out.close();
    }
    void printbash() {
        Nodedb* current = head;
        while (current != nullptr) {
            cout << current->val;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

struct Stack{
    Node* head;
    Stack(){
        head = nullptr;
    }  
    void addHead(string val){
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void print(string file, string namestruct) {
        ofstream out;
        out.open(file);
        out << namestruct << endl;
        Node* current = head;
        while (current != nullptr) {
            out << current->val << endl;
            current = current->next;
        }
        out.close();
    }

    void printbash() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->val;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    void deleteHead(){
        if (head == nullptr) return;
        Node* current = head->next;
        delete head;
        head = current;
    }
};

struct Vector {
    int size;
    int capacity;
    string* vec;

    Vector(int cap = 10){
        size = 0;
        capacity = cap;
        vec = new string[capacity];
    }

    void resize() {
        if (size < capacity) return;
        capacity *= 2;
        string* newVec = new string[capacity];
        for (int i = 0; i < size; ++i) {
            newVec[i] = vec[i];
        }
        delete[] vec;
        vec = newVec;
    }

    void push_back(string value) {
        resize();
        vec[size] = value; // Копируем строку
        ++size;
    }

    void push_idx(string value, int idx) {
        if (idx < 0 || idx > size) return;
        resize();
        // Сдвиг элементов вправо, начиная с конца
        for (int i = size; i > idx; --i) {
            vec[i] = vec[i - 1];
        }
        vec[idx] = value;
        ++size;
    }

    void get(int idx) {
        if (idx < 0 || idx >= size) return;
        cout << vec[idx] << endl;
    }

    void delete_idx(int idx) {
        if (idx < 0 || idx >= size) return;
        // Сдвиг элементов влево, начиная с индекса
        for (int i = idx; i < size - 1; ++i) {
            vec[i] = vec[i + 1];
        }
        --size;
    }

    void exchange(string value, int idx) {
        if (idx < 0 || idx >= size) return;
        vec[idx] = value;
    }

    void get_size() {
        cout << size << endl;
    }

    void print(string file, string namestruct) {
        ofstream out;
        out.open(file);
        out << namestruct << endl;
        for (int i = 0; i < size; i++) {
            out << vec[i] << endl;
        }
    }

    void printbash() {
        for (int i = 0; i < size; i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
};

struct Queue {
    Node* head;
    Node* tail;

    Queue(){
        head = nullptr;
        tail = nullptr;
    }

    void push(string val) {
        Node* newNode = new Node{val, nullptr};
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
    }

    void printbash() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->val;
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    void print(string file, string namestruct) {
        ofstream out;
        out.open(file);
        out << namestruct << endl;
        Node* current = head;
        while (current != nullptr) {
            out << current->val << endl;
            current = current->next;
        }
        out.close();
    }
};

struct HashTable {
    int size;
    int capacity;
    HashBucket* table;

    HashTable(int cap) : size(0), capacity(cap) {
        table = new HashBucket[capacity];
    }

    int Hash1(string key) const {
        int hashz = 0;
        for (char c : key) {
            hashz += static_cast<int>(c);
        }
        return hashz % capacity;
    }

    int Hash2(int h) const {
        return 1 + (h % (capacity - 1));
    }

    int FinalHash(string key, int attempt) const {
        int h = Hash1(key);
        int g = Hash2(h);
        return (h + attempt * g) % capacity;
    }

    string find(string key) const {
        int attempt = 0;
        int index;

        do {
            index = FinalHash(key, attempt);
            if (table[index].key == key) {
                return table[index].value;
            }
            attempt++;
        } while (attempt < capacity);

        return "";
    }

    void insert(string key, string value) {
        if (size >= capacity) {
            cout << "Таблица заполнена." << endl;
            return;
        }

        if (find(key) != "") {
            cout << "Ключ уже существует." << endl;
            return;
        }

        int attempt = 0;
        int index;

        do {
            index = FinalHash(key, attempt);
            attempt++;
        } while (!table[index].key.empty());

        table[index].key = key;
        table[index].value = value;
        size++;
    }

    bool remove(string key) {
        int attempt = 0;
        int index;

        do {
            index = FinalHash(key, attempt);
            if (table[index].key == key) {
                table[index].key = "";
                table[index].value = "";
                size--;
                cout << "Удалено." << endl;
                return true;
            }
            attempt++;
        } while (attempt < capacity);

        cout << "Ключ не найден." << endl;
        return false;
    }

    void print(string file, string namestruct){
        ofstream out;
        out.open(file);
        out << namestruct << endl;
        for (int i = 0; i < capacity; i++) {
            if (!table[i].key.empty()) {
                out << table[i].key << ' ' << table[i].value << endl;
            }
        }
    }

    void printbash(){
        for (int i = 0; i < capacity; i++) {
            if (!table[i].key.empty()) {
                cout << i << " - " << table[i].key << " - " << table[i].value << endl;
            } else {
                cout << i << " - EMPTY" << endl;
            }
        }
    }
};

struct FullBinaryTree {
    int* nodes;
    int size;
    int capacity;

    FullBinaryTree(int cap = 10) {
        size = 0;
        capacity = cap;
        nodes = new int[capacity];
    }

    void resize() {
        capacity *= 2;
        int* newNodes = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newNodes[i] = nodes[i];
        }
        delete[] nodes;
        nodes = newNodes;
    }
    
    void insert(int value) {
        if (size >= capacity) {
            resize();
        }
        nodes[size++] = value;
    }

    bool find(int value) {
        for (int i = 0; i < size; i++){
            if (nodes[i] == value){
                return true;
                break;
            }
        }
        return false;
    }

    void remove(int value) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (nodes[i] == value) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Такого элемента не существует." << endl;
            return;
        }
        nodes[index] = nodes[size - 1];
        --size;
        // Перестраиваем дерево, чтобы сохранить его структуру
        while (index > 0 && nodes[index] < nodes[(index - 1) / 2]) {
            swap(nodes[index], nodes[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void print(string file, string namestruct){
        ofstream out;
        out.open(file);
        out << namestruct << endl;
        for (int i = 0; i < size; i++){
            if (i == 1 || i == 3 || i == 7 || i == 15 || i == 31) {
                out << endl;
            }
            out << nodes[i] << ' ';
            
        }
    }

    void printbash(){
        for (int i = 0; i < size; i++){
            cout << nodes[i] << " ";
            if (i == 1 || i == 3 || i == 7 || i == 15 || i == 31) {
                cout << endl;
            }
        }
        cout << endl;
    }
};

bool isEmpty(string file){
    ifstream in;
    in.open(file);
    string data;
    getline(in, data);
    in.close();
    if (data.size() == 0){
        return true;
    }
    return false;
}

void addStructName(string file, string namestruct){
    ofstream out;
    if (isEmpty(file)){
        out.open(file);
        out << namestruct << endl;
        out.close();
    }    
}

void vectorFromFile(string file, Vector &v){
    fstream in;
    in.open(file);
    string data;
    getline(in, data); // Пропускаем строчку с именем
    while (getline(in, data)){
        v.push_back(data);
    }
    in.close(); 
}

void listFromFile(string file, LinkedList &flist){
    fstream in;
    in.open(file);
    string data;
    getline(in, data); // Пропускаем строчку с именем
    while (getline(in, data)){
        flist.addTail(data);
    } 
    in.close(); 
}

void stackFromFile(string file, Stack &stacker){
    fstream in;
    in.open(file);
    string data;
    string fulldata;
    while (getline(in, data)){
        fulldata = data + ' ' + fulldata;
    }
    in.close();
    stringstream iss(fulldata);
    while (iss >> data){
        if (data[0] != '@'){
            stacker.addHead(data);
        }

    }

}

void queueFromFile(string file, Queue &myqueue){
    fstream in;
    in.open(file);
    string data;
    getline(in, data); // Пропускаем строчку с именем
    while (getline(in, data)){
        myqueue.push(data);
    } 
    in.close(); 
}

void dlistFromFile(string file, DoubleLinkedList &dlist){
    fstream in;
    in.open(file);
    string data;
    getline(in, data); // Пропускаем строчку с именем
    while (getline(in, data)){
        dlist.addTail(data);
    } 
    in.close(); 
}

void treeFromFile(string file, FullBinaryTree &tree){
    fstream in;
    in.open(file);
    string data;
    getline(in, data); // Пропускаем строчку с именем
    while (getline(in, data)){
        stringstream iss(data);
        while (iss >> data){
            try {
                stoi(data);
            }
            catch (...){
                cerr << "cannot stoi string arguement" << endl;
                exit(0);
            }
            tree.insert(stoi(data));
        }
    } 
    in.close(); 
}

void hashFromFile(string file,  HashTable &table){
    fstream in;
    in.open(file);
    string data;
    getline(in, data); // Пропускаем строчку с именем
    while (getline(in, data)){
        string key;
        string value;
        bool findspace = false;
        for (int i = 0; i < data.size(); i++){
            if (data[i] == ' '){
                findspace = true;
                i++;
            }
            if (!findspace){
                key += data[i];
            }
            if (findspace){
                value += data[i];
            }
            
        }
        //cout << key << " AAAAA " << value;
        table.insert(key, value);
    } 
    in.close(); 
}

int main(int argc, char* argv[]){
    if (argc != 5){
        cout << "Неверная команда!";
        return 0;
    }
    cout << "-> ";
    string arg = argv[1];
    if (arg != "--file"){
        cout << "Отсутствует ключ --file!";
        return 0;
    }
    string file = argv[2];
    arg = argv[3];
    if (arg != "--query"){
        cout << "Отсутствует ключ --query!";
        return 0;
    }
    string command = argv[4];
    stringstream iss(command);
    string word;
    while (iss >> word){
        if (word == "MPUSH"){
            // 1. Добавить имечко)
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); // Только если файл пуст
            // 2. Создать структурочку и записать в нее данные из файлика)
            Vector v;
            vectorFromFile(file, v);
            // 3. Выполнение команды)
            iss >> word;
            v.push_back(word);
            // 4. Запись в файлик)
            ofstream out;
            out.open(file, ios::app);
            out << word << endl;
            cout << "Done!" << endl;
            out.close();
            return 0;
        }
        if (word == "MPUSHIDX"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            Vector v;
            vectorFromFile(file, v);
            iss >> word;
            string val = word;
            iss >> word;
            int idx = stoi(word);
            v.push_idx(val, idx);
            v.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "MGET"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            Vector v;
            vectorFromFile(file, v);
            iss >> word;
            int idx = stoi(word);
            v.get(idx);
            return 0;  
        }
        if (word == "MDEL"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            Vector v;
            vectorFromFile(file, v);
            iss >> word;
            int idx = stoi(word);
            v.delete_idx(idx);
            v.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;  
        }
        if (word == "MEXCHANGE"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            Vector v;
            vectorFromFile(file, v);
            iss >> word;
            string val = word;
            iss >> word;
            int idx = stoi(word);
            v.exchange(val, idx);
            v.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;  
        }
        if (word == "MGETSIZE"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            Vector v;
            vectorFromFile(file, v);
            v.get_size();
            return 0;  
        }
        if (word == "MPRINT"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            Vector v;
            vectorFromFile(file, v);
            v.printbash();
            return 0;  
        }
        if (word == "LPUSHT" || word == "LPUSHH"){
            string what = word;
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            LinkedList flist;
            listFromFile(file, flist);
            iss >> word;
            string val = word;
            if (what == "LPUSHT") {
                flist.addTail(val);
            }
            if (what == "LPUSHH") {
                flist.addHead(val);
            }
            //flist.printbash();
            flist.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "LDELT" || word == "LDELH"){
            string what = word;
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            LinkedList flist;
            listFromFile(file, flist);
            if (what == "LDELT") {
                flist.deleteTail();
            }
            if (what == "LDELH"){
                flist.deleteHead();
            }
            flist.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "LDEL"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            LinkedList flist;
            listFromFile(file, flist);
            iss >> word;
            string val = word;
            flist.deleteValue(val);
            flist.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "LFIND"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            LinkedList flist;
            listFromFile(file, flist);
            iss >> word;
            string val = word;
            if (flist.find(val)){
                cout << "True." << endl;
            }
            else {
                cout << "False." << endl;
            }
            return 0;
        }
        if (word == "LPRINT"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            LinkedList flist;
            listFromFile(file, flist);
            flist.printbash();
            return 0;
        }
        if (word == "SPUSH"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            Stack stacker;
            stackFromFile(file, stacker);
            iss >> word;
            string val = word;
            stacker.addHead(val);
            stacker.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "SPOP"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            Stack stacker;
            stackFromFile(file, stacker);
            stacker.deleteHead();
            stacker.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "SPRINT"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            Stack stacker;
            stackFromFile(file, stacker);
            stacker.printbash();
            return 0;
        }
        if (word == "QPUSH"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            Queue myqueue;
            queueFromFile(file, myqueue);
            iss >> word;
            string val = word;
            myqueue.push(val);
            myqueue.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "QPOP"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            Queue myqueue;
            queueFromFile(file, myqueue);
            myqueue.pop();
            myqueue.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "QPRINT"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            Queue myqueue;
            queueFromFile(file, myqueue);
            myqueue.printbash();
            return 0;
        }
        if (word == "DLPUSHT" || word == "DLPUSHH"){
            string what = word;
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            DoubleLinkedList dlist;
            dlistFromFile(file, dlist);
            iss >> word;
            string val = word;
            if (what == "DLPUSHT") {
                dlist.addTail(val);
            }
            if (what == "DLPUSHH") {
                dlist.addHead(val);
            }
            dlist.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "DLDELT" || word == "DLDELH"){
            string what = word;
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            DoubleLinkedList dlist;
            dlistFromFile(file, dlist);
            if (what == "DLDELT") {
                dlist.deleteTail();
            }
            if (what == "DLDELH") {
                dlist.deleteHead();
            }
            dlist.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "DLDEL"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            DoubleLinkedList dlist;
            dlistFromFile(file, dlist);
            iss >> word;
            string val = word;
            dlist.deleteValue(val);
            dlist.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "DLFIND"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            DoubleLinkedList dlist;
            dlistFromFile(file, dlist);
            iss >> word;
            string val = word;
            if (dlist.find(val)){
                cout << "True." << endl;
            }
            else {
                cout << "False." << endl;
            }
            return 0;
        }
        if (word == "DLPRINT"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            DoubleLinkedList dlist;
            dlistFromFile(file, dlist);
            dlist.printbash();
            return 0;
        }
        if (word == "TINSERT"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            FullBinaryTree tree;
            treeFromFile(file, tree);
            iss >> word;
            string val = word;
            try {
                stoi(val);
            }
            catch (...){
                cerr << "cannot stoi string arguement" << endl;
                exit(0);
            }            
            tree.insert(stoi(val));
            tree.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "TDEL"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            FullBinaryTree tree;
            treeFromFile(file, tree);
            iss >> word;
            string val = word;
            try {
                stoi(val);
            }
            catch (...){
                cerr << "cannot stoi string arguement" << endl;
                exit(0);
            }            
            tree.remove(stoi(val));
            tree.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "TFIND"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            FullBinaryTree tree;
            treeFromFile(file, tree);
            iss >> word;
            string val = word;
            try {
                stoi(val);
            }
            catch (...){
                cerr << "cannot stoi string arguement" << endl;
                exit(0);
            }            
            if (tree.find(stoi(val))) cout << "True." << endl;
            if (!tree.find(stoi(val))) cout << "False." << endl;
            return 0;
        }
        if (word == "TPRINT"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            FullBinaryTree tree;
            treeFromFile(file, tree);
            tree.printbash();
            return 0;
        }
        if (word == "HSET"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            HashTable tab(10);
            hashFromFile(file, tab);
            iss >> word;
            string key = word;
            iss >> word;
            string value = word;
            tab.insert(key, value);
            tab.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "HDEL"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            HashTable tab(10);
            hashFromFile(file, tab);
            iss >> word;
            string key = word;
            bool isRemoved = tab.remove(key);
            if (isRemoved) tab.print(file, namestruct);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "HFIND"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            HashTable tab(10);
            hashFromFile(file, tab);
            iss >> word;
            string key = word;
            string val = tab.find(key);
            if (!val.empty()){
                cout << val << endl;
            }
            else {
                cout << "Нет элемента по заданному ключу." << endl;
            }
            return 0;
        }
        if (word == "HPRINT"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            HashTable tab(11);
            hashFromFile(file, tab);
            tab.printbash();
            return 0;
        }
        cout << "Wrong command!" << endl;
    }
   return 0;
}
