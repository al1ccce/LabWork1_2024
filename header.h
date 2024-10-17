#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
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

struct tNode{
    int value;
    tNode* left;
    tNode* right;

    tNode(int val) : value(val), left(nullptr), right(nullptr){}
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
    tNode* root;  

    FullBinaryTree(){
        root = nullptr;
    }
    void insert(tNode*& root, int value) {
        if (root == nullptr) {
            // Создаем новый узел, если дерево пустое
            tNode* newroot = new tNode(value);
            root = newroot;
            return;
        }
        if (value <= root->value) {
            // Рекурсивно добавляем в левое поддерево
            insert(root->left, value);
        } else {
            // Рекурсивно добавляем в правое поддерево
            insert(root->right, value);
        }

    }

    void print(int value, string file) {
        ofstream out;
        out.open(file, ios::app);
        out << ' ' << value;
        out.close(); 
    }
    // Вернет nullptr, если отсутствует элемент
    tNode* search(int value) {
        return searchHelp(root, value);
    }
    tNode* searchHelp(tNode* node, int value) {
        if (node == nullptr || node->value == value) {
            return node;
        }

        if (value < node->value) {
            return searchHelp(node->left, value);
        } else {
            return searchHelp(node->right, value);
        }
    }

    bool isFull() {
        return isFullHelp(root);
    }

    bool isFullHelp(tNode* node) {
        if (node == nullptr) {
            return true;
        }
        // Проверяем, что узел имеет либо 0, либо 2 дочерних узла
        if ((node->left == nullptr && node->right != nullptr) ||
            (node->left != nullptr && node->right == nullptr)) {
            return false;
        }
        // Рекурсивно проверяем левое и правое поддеревья
        return isFullHelp(node->left) && isFullHelp(node->right);
    }

    void printbash(){
        printbabash(root, 0);
    }

    void printbabash(tNode* root, int level)
    {
        if (root != nullptr)
        {
            printbabash(root->right, level + 1);
            for (int i = 0; i < level; i++) cout << "   ";
            cout << root->value << endl;
            printbabash(root->left, level + 1);
        }
    }
};
void addStructName(string file, string namestruct);
void vectorFromFile(string file, Vector &v);
void listFromFile(string file, LinkedList &flist);
void stackFromFile(string file, Stack &stacker);
void queueFromFile(string file, Queue &myqueue);
void dlistFromFile(string file, DoubleLinkedList &dlist);
void treeFromFile(string file, FullBinaryTree& tree);
void hashFromFile(string file,  HashTable &table);