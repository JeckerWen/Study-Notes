#include<iostream>
#include<vector>

using Ptr = std::vector<int>*;

auto make_dynamically() {
    return new std::vector<int>();    
}

auto populate(Ptr vec) {
    for (int i; std::cout << "Pls Enter:\n", std::cin >> i; vec->push_back(i));
    return vec;   
}

void print(Ptr vec)  {
    for (const auto& i: *vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    auto vec = populate(make_dynamically());
    print(vec);
    delete vec;
}
