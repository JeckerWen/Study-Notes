#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<utility>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;
using std::cin;
using Famliy = map<string, vector<std::pair<string, string>>>;

auto make_families()
{
    Famliy families;
    for (string ln; cout << "The famliy's Last name is:\n",cin >> ln && ln != "@q"; )
        for (string cn, birth; cout << "|-Children's names:\n", cin >> cn && cn != "@q",
             cout << "|-Children's birthday is:\n", cin >> birth && cn != "@q";)
            families[ln].push_back(make_pair(cn, birth));
    return families;
}

auto print(Famliy const& families)
{
    for (const auto& c: families)    
    {
        cout << "Famliy's last name is: "<< c.first << ":\n";
        for (const auto& child: c.second) 
            cout << child.first << "'s birthday is " << child.second << endl;;
        cout << "\n";    
    }
}

int main()
{
    print(make_families());
}
