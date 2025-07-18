#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>



int main(void) {
    std::string line;
    std::ifstream file("input");
    if (!file) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    std::string input;
    while (std::getline(file, line)) {
        input += line;
    }
    file.close();
    std::cout << input << "\n";
  
    return 0;
}
