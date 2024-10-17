#include "header.h"
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

void treeFromFile(string file, FullBinaryTree& tree){
    fstream in;
    in.open(file);
    string data;
    getline(in, data); // Пропускаем строчку с именем
    getline(in, data); 
    stringstream iss(data);
        while (iss >> data){
            try {
                stoi(data);
            }
            catch (...){
                cerr << "cannot stoi string arguement" << endl;
                exit(0);
            }
            tree.insert(tree.root, stoi(data));
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
        table.insert(key, value);
    } 
    in.close(); 
}
