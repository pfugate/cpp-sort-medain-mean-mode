#include <iostream>
#include <vector>

using namespace std;

vector<int> inputVector;
int n, median, mode;
int average, currentModeTarget = 0;
int modeCount, currentModeCount = 1;
bool multiModal = true;
bool quit = false;

int main() {
    cout << "You are about to enter the... Mean Median and Mode ZONE!!" << endl;
    while (!quit) {
        cout << "Please enter a number (anything but a number starts computation): ";
        cin >> n;

        if (cin.good()) {
            inputVector.push_back(n);
        }
        else {
            quit = true;
            cout << endl;
        }
    }
    if (inputVector.size() > 0) {
        sort(inputVector.begin(), inputVector.end());
        cout << "Your awesome sorted vector:";
        for (vector<int>::iterator it = inputVector.begin(); it != inputVector.end(); it++) {
            cout << ' ' << *it;
            average = average + *it;
            auto nxt = next(it);
            if (nxt != inputVector.end()) {
                if (*it == *nxt) {
                    currentModeCount++;
                    currentModeTarget = *it;
                    if (currentModeCount == modeCount) {
                        multiModal = true;
                    }
                    else if (currentModeCount > modeCount) {
                        modeCount = currentModeCount;
                        mode = currentModeTarget;
                        multiModal = false;
                    }
                }
                else {
                    currentModeCount = 1;
                    currentModeTarget = *it;
                }
            }

        }
        if (inputVector.size() < 2) {
            mode = currentModeTarget;
            multiModal = false;
        }
        if (inputVector.size() % 2 == 0) {
            median = (inputVector.at(inputVector.size() / 2) + inputVector.at((inputVector.size() / 2) - 1)) / 2;
        }
        else {
            median = inputVector.at(inputVector.size() / 2);
        }
        cout << endl << endl << "MEAN: " << average / inputVector.size() << endl;
        cout << "MEDIAN: " << median << endl;
        if (multiModal) {
            cout << "MODE: Multi-Modal";
        }
        else {
            cout << "MODE: " << mode << endl;
        }
    }
    else {
        cout << "Umm I need numbers to do my thing..." << endl;
    }
    return 0;
}