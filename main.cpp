#include <iostream>
#include <vector>

using namespace std;

vector<int> myvectorbag;
int n, median, mode;
int average = 0;
int modeCount = 1;
int currentTarget = 0;
int currentCount = 1;
bool multiModal = true;
bool quit = false;

int main() {

    while(!quit) {
        cout << "Please enter a number (anything but a number exits): ";
        cin >> n;

        if (cin.good()) {
            myvectorbag.push_back(n);
        }
        else {
            quit = true;
            cout << endl;
        }
    }

    sort(myvectorbag.begin(), myvectorbag.end());
    cout << "Your awesome sorted vector:";
    for(vector<int>::iterator it = myvectorbag.begin(); it != myvectorbag.end(); it++) {
        cout << ' ' << *it;
        average = average + *it;
        auto nxt = next(it);
        if(*it == *nxt) {
            currentCount++;
            currentTarget = *it;
            if(currentCount == modeCount) {
                multiModal = true;
            }
            else if(currentCount > modeCount) {
                modeCount = currentCount;
                mode = currentTarget;
                multiModal = false;
            }
        }
        else {
            currentCount = 1;
            currentTarget = *it;
        }
    }
    if (myvectorbag.size() % 2 == 0) {
        median = (myvectorbag.at(myvectorbag.size()/2) + myvectorbag.at((myvectorbag.size()/2)-1))/2;
    }
    else {
        median = myvectorbag.at(myvectorbag.size()/2);
    }
    cout << endl << endl << "MEAN: " << average/myvectorbag.size() << endl;
    cout << "MEDIAN: " << median << endl;
    if(multiModal) {
        cout << "MODE: Multi-Modal";
    }
    else {
        cout << "MODE: " << mode << endl;
    }
    return 0;
}