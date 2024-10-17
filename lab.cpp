#include "header.h"

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
            addStructName(file, word); // Только если файл пуст, не ссать
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
            tree.insert(tree.root,stoi(val));
            tree.print(stoi(val), file);
            cout << "Done!" << endl;
            return 0;
        }
        if (word == "TFULL"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            FullBinaryTree tree;
            treeFromFile(file, tree);
            cout << boolalpha << tree.isFull() << endl;
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
            if (tree.search(stoi(val)) == nullptr){
                cout << "False." << endl;
            } else {
                cout << "True" << endl;
            }
            return 0;
        }
        if (word == "TPRINT"){
            iss >> word;
            string namestruct = '@' + word;
            addStructName(file, word); 
            FullBinaryTree tree;
            treeFromFile(file, tree);
            cout << endl;
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
