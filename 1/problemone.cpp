
#include <iostream>
#include <fstream>

int main () {
    std::string input;
    int x, current_sum=0, max=0;

    std::ifstream MyReadFile("input_probone");

    while (getline (MyReadFile, input)) {
        if (input == "") {
            if (current_sum > max) {
                max = current_sum;
            }
            current_sum = 0;
        } else {
            current_sum += std::stoi(input);
        }
    }

    MyReadFile.close();
    
    std::cout << max;
}

