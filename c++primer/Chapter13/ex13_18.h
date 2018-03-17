#include<string>
using std::string;

class Employee{
public:
    Employee();
    Employee(const string&);
    const unsigned id() const;


private:
    string  name_;
    unsigned id_;
    static unsigned unique_id;
};
