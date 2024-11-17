#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    std::string city;
    int n;

    // Read the input city name
    cin >> city;

    // Read the number of cities
    cin >> n;

    std::vector<std::string> cities(n);
    
    // Read the cities into the vector
    for (int i = 0; i < n; ++i) {
        std::cin >> cities[i];
    }

    std::vector<std::string> greaterCities;

    // Find cities that are lexicographically greater than the input city
    for (const auto& c : cities) {
        if (c > city) {
            greaterCities.push_back(c);
        }
    }

    // Output the number of cities greater than the input city
    std::cout << greaterCities.size() << std::endl;

    // Output each greater city
    for (const auto& gCity : greaterCities) {
        std::cout << gCity << std::endl;
    }

    return 0;
}    