
#include <iostream>
#include <fstream>
#include <numeric>

int main () {
    std::string input;
    int current_sum=0, top_three[3] = {0, 0, 0};
    int sum=0;

    std::ifstream MyReadFile("input_probone");
    //std::ifstream MyReadFile("dummydata");

    while (getline (MyReadFile, input)) {
        // empty line means elf data has ended
        if (input == "") {
            // check if it belongs to the top three
            for (int x=0; x < 3; x++) {
                // if it does, then push back
                if (current_sum > top_three[x]) {
                    if (x==0) {
                        top_three[x+2] = top_three[x+1];
                        top_three[x+1] = top_three[x];
                    } else if (x==1)
                        top_three[x+1] = top_three[x];

                    // assign
                    top_three[x] = current_sum;

                    // reset sum and leave the loop
                    current_sum = 0;
                    break;
                }
            }
        } else {
            current_sum += std::stoi(input);
        }
    }

    MyReadFile.close();
    
    for (int x=0; x < 3; x++) std::cout << top_three[x] << "\n";
    for (int x=0; x < 3; x++) sum += top_three[x];
    std::cout << std::fixed << sum;
}

