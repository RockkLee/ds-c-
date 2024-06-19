#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>

int main() {
    // Vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6); // Add an element to the end

    std::cout << "Vector: ";
    for(int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    // List
    std::list<int> lst = {1, 2, 3, 4, 5};
    lst.push_back(6); // Add an element to the end
    lst.push_front(0); // Add an element to the beginning

    std::cout << "List: ";
    for(int i : lst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Map
    std::map<int, std::string> mp;
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";

    std::cout << "Map: ";
    for(const auto& pair : mp) {
        std::cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    std::cout << std::endl;

    // Set
    std::set<int> st = {1, 2, 3, 4, 5};
    st.insert(6); // Add an element

    std::cout << "Set: ";
    for(int i : st) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
