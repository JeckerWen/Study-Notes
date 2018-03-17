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


int main()
{
    Employee e1;
    std::cout << e1.id() << std::endl;
}
