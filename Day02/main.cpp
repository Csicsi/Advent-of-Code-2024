#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool isSafe(const std::vector<int>& level) {
    bool decreasing = true;
    bool increasing = true;
    for (size_t i = 1; i < level.size(); ++i) {
        if (level[i] < level[i - 1]) {
            increasing = false;
        } else if (level[i] > level[i - 1]) {
            decreasing = false;
        }
        if (level[i] == level[i - 1] || std::abs(level[i] - level[i - 1]) > 3) {
            return false;
        }
    }
    return increasing || decreasing;
}

int main(void) {
    std::string line;
    std::ifstream file("input");
    if (!file) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    std::vector<std::vector<int>> levels;
    while (std::getline(file, line)) {
        std::vector<int> level;
        std::istringstream iss(line);
        int value = 0;
        while (iss >> value) {
            level.push_back(value);
        }
        levels.push_back(level);
    }
    file.close();
    int count = 0;
    for (const auto& level : levels) {
        if (isSafe(level)) {
            count++;
        }
    }
    std::cout << "Number of safe levels: " << count << "\n";
    count = 0;
    for (const auto& level : levels) {
        std::vector<int> dampened;
        for (size_t i = 0; i < level.size(); ++i) {
            dampened = level;
            dampened.erase(dampened.begin() + static_cast<int>(i));
            if (isSafe(dampened)) {
                count++;
                break;
            }
        }
    }
    std::cout << "Number of safe levels after Problem Dampner: " << count << "\n";
    return 0;
}
