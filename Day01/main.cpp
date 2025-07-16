#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
    std::string line;
    std::ifstream file("input");
    if (!file) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    std::vector<int> list1;
    std::vector<int> list2;
    while (std::getline(file, line)) {

        list1.push_back(std::stoi(line.substr(0, line.find_first_of(' '))));
        list2.push_back(std::stoi(line.substr(line.find_first_of(' ') + 1)));
    }
    file.close();

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());
    int dist = 0;
    for (size_t i = 0; i < list1.size(); ++i) {
        dist += std::abs(list1[i] - list2[i]);
    }
    std::cout << "Total distance: " << dist << "\n";
    int similarity = 0;
    for (size_t i = 0; i < list1.size(); ++i) {
        int count = 0;
        for (size_t j = 0; j < list2.size(); ++j) {
            if (list1[i] == list2[j]) {
                ++count;
            }
        }
        similarity += count * list1[i];
    }
    std::cout << "Total similarity: " << similarity << "\n";
}
