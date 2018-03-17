#include<string>
using std::string;

class Employee{
public:
    Employee();
    Employee(const string&);
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;
    const unsigned id() const;
    void show() const;


private:
    string  name_;
    unsigned id_;
    static unsigned unique_id;
};
