#include<iostream>
#include<string>
#include<set>

using std::string;

class Folder;

class Message{
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const string &str = ""):
        contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&); // 
    void remove(Folder&);

    void print_debug();

private:
    string contents;    
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void addFldr(Folder *f) {
        folders.insert(f);    //将该Message保存至某个文件
    }
    void remFldr(Folder *f) {
        folders.erase(f);    
    }
};

void swap(Message&, Message&);

class Folder {
    friend void swap(Folder&, Folder&);
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void print_debug();

private:
    std::set<Message*> msgs;
    
    void add_to_Message(const Folder&);
    void remove_from_Message();
    
    void addMsg(Message *m) {
        msgs.insert(m);    
    }    
    void remMsg(Message *m) {
        msgs.erase(m);    
    }
};

void swap(Folder&, Folder&);
