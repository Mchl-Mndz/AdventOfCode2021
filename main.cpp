#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> readFile(string inputFile){
    vector<string> v;
    ifstream file (inputFile);

    while(!file.eof()){
        string temp;
        file >> temp;
        v.push_back(temp);
    }

    return v;
}

int adventOnePartOne() {
    vector<string> input = readFile("input1.txt");
    int count = 0;

    for(unsigned int i = 0; i < input.size() - 1; i++) {
        if(stoi(input[i]) < stoi(input[i+1])) {
            count++;
        }
    }

    return count;
}

int adventOnePartTwo() {
    vector<string> input = readFile("input1.txt");
    int i = 0, count = 0;

    while(i < input.size() - 3) {

        int sumThreeOne = stoi(input[i]) + stoi(input[i+1]) + stoi(input[i+2]);
        int sumThreeTwo = stoi(input[i+1]) + stoi(input[i+2]) + stoi(input[i+3]);

        if(sumThreeOne < sumThreeTwo)
            count++;

        i++;
    }

    return count;
}

int adventTwoPartOne() {
    vector<string> input = readFile("input2.txt");

    int finalHorizontal = 0, finalDepth = 0, i = 0;

    while(i < input.size() - 1) {
        string command = input[i];
        int val = stoi(input[i+1]);

        if(command == "forward")
            finalHorizontal += val;
        else if(command == "down")
            finalDepth += val;
        else if(command == "up")
            finalDepth -= val;

        i += 2;
    }
    cout << "x: " << finalHorizontal << endl << "y: " << finalDepth << endl;

    return finalHorizontal * finalDepth;
}

int adventTwoPartTwo() {
    vector<string> input = readFile("input2.txt");

    int finalHorizontal = 0, finalDepth = 0, aim = 0, i = 0;

    while(i < input.size() - 1) {
        string command = input[i];
        int val = stoi(input[i+1]);

        if(command == "forward") {
            finalHorizontal += val;
            finalDepth += aim * val;
        } else if(command == "down") {
            aim += val;
        } else if(command == "up") {
            aim -= val;
        }

        i += 2;
    }
    cout << "x: " << finalHorizontal << endl << "y: " << finalDepth << endl;

    return finalHorizontal * finalDepth;
}

int adventThreePartOne() {
    vector<string> input = readFile("input3.txt");

    int zeros[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int ones[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

    for(auto binString : input) {
        for(int j = 0; j < 12; j++) {
            if(binString[j] == '0') {
                zeros[j] = zeros[j] + 1;
            } else {
                ones[j] = ones[j] + 1;
            }
        }
    }

    string gammaBin, eppBin;

    for(int i = 0; i < 12; i++) {
        if(zeros[i] > ones[i]) {
            gammaBin += "0";
            eppBin += "1";
        } else {
            gammaBin += "1";
            eppBin += "0";
        }
    }

    int gammaDec = stoi(gammaBin, nullptr, 2);
    int eppDec = stoi(eppBin, nullptr, 2);

    return gammaDec * eppDec;
}

int adventThreePartTwo() {
    vector<string> input = readFile("input3.txt");

    int zeros[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int ones[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

    for(auto binString : input) {
        for(int j = 0; j < 12; j++) {
            if(binString[j] == '0') {
                zeros[j] = zeros[j] + 1;
            } else {
                ones[j] = ones[j] + 1;
            }
        }
    }

    vector<string> mostArray = input, leastArray = input;
    for (int j = 0; j < 12; j++) {
        for(auto binString : input) {
            if(mostArray.size() == 1)
                break;
            if(zeros[j] > ones[j] && binString[j] == '1') {
                auto position = std::find(mostArray.begin(), mostArray.end(), binString);
                if (position != mostArray.end())
                    mostArray.erase(position);
            } else if(zeros[j] < ones[j] && binString[j] == '0') {
                auto position = std::find(mostArray.begin(), mostArray.end(), binString);
                if (position != mostArray.end())
                    mostArray.erase(position);
            } else if(zeros[j] == ones[j] && binString[j] == '0') {
                auto position = std::find(mostArray.begin(), mostArray.end(), binString);
                if (position != mostArray.end())
                    mostArray.erase(position);
            }
        }
    }

    for (int j = 0; j < 12; j++) {
        for(auto binString : input) {
            if(leastArray.size() == 1)
                break;
            if(zeros[j] > ones[j] && binString[j] == '0') {
                auto position = std::find(leastArray.begin(), leastArray.end(), binString);
                if (position != leastArray.end())
                    leastArray.erase(position);
            } else if(zeros[j] < ones[j] && binString[j] == '1') {
                auto position = std::find(leastArray.begin(), leastArray.end(), binString);
                if (position != leastArray.end())
                    leastArray.erase(position);
            } else if(zeros[j] == ones[j] && binString[j] == '1') {
                auto position = std::find(leastArray.begin(), leastArray.end(), binString);
                if (position != leastArray.end())
                    leastArray.erase(position);
            }
        }
    }

    string genBin = mostArray[0];
    string scrubBin = leastArray[0];

    cout << genBin << endl << scrubBin << endl;
    int genDec = stoi(genBin, nullptr, 2);
    int scrubDec = stoi(scrubBin, nullptr, 2);

    return genDec * scrubDec;
}

int main() {
    //cout << adventOnePartOne();
    //cout << adventOnePartTwo();
    //cout << adventTwoPartOne();
    //cout << adventTwoPartTwo();
    //cout << adventThreePartOne();
    cout << adventThreePartTwo();
    return 0;
}

