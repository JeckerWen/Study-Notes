#include<iostream>
#include"Employee.h"


unsigned Employee::unique_id = 0;

Employee::Employee() {
    id_ = unique_id++;    
}

Employee::Employee(const string& name) {
    name_ = name;
    id_ = unique_id++;    
}

const unsigned Employee::id() const {
    return id_;    
}

void Employee::show() const {
    std::cout << "id = " << id_ << "   name = "
              << name_ << std::endl;    
}

int main()
{
    Employee e1, e2("a");
    e1.show();
    e2.show();
}
