#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const double SAND_MIN_WEIGHT = 49.9;
const double SAND_MAX_WEIGHT = 50.1;
const double GRAVEL_MIN_WEIGHT = 49.9;
const double GRAVEL_MAX_WEIGHT = 50.1;
const double CEMENT_MIN_WEIGHT = 24.9;
const double CEMENT_MAX_WEIGHT = 25.1;

struct Sack {
    char contents;
    double weight;
};

bool checkSack(Sack sack) {
    if (sack.contents == 'S' && (sack.weight < SAND_MIN_WEIGHT || sack.weight > SAND_MAX_WEIGHT)) {
        cout << "Rejected: Incorrect weight for sand sack.\n";
        return false;
    } else if (sack.contents == 'G' && (sack.weight < GRAVEL_MIN_WEIGHT || sack.weight > GRAVEL_MAX_WEIGHT)) {
        cout << "Rejected: Incorrect weight for gravel sack.\n";
        return false;
    } else if (sack.contents == 'C' && (sack.weight < CEMENT_MIN_WEIGHT || sack.weight > CEMENT_MAX_WEIGHT)) {
        cout << "Rejected: Incorrect weight for cement sack.\n";
        return false;
    } else if (sack.contents != 'S' && sack.contents != 'G' && sack.contents != 'C') {
        cout << "Rejected: Invalid contents for the sack.\n";
        return false;
    }
    return true;
}

void checkOrder() {
    int numCement, numGravel, numSand;
    vector<Sack> sacks;

    cout << "Enter number of cement sacks required: ";
    cin >> numCement;
    cout << "Enter number of gravel sacks required: ";
    cin >> numGravel;
    cout << "Enter number of sand sacks required: ";
    cin >> numSand;

    for (int i = 0; i < numCement; ++i) {
        Sack sack;
        cout << "Enter content (C/G/S) and weight for cement sack " << i + 1 << ": ";
        cin >> sack.contents >> sack.weight;
        sacks.push_back(sack);
    }

    for (int i = 0; i < numGravel; ++i) {
        Sack sack;
        cout << "Enter content (C/G/S) and weight for gravel sack " << i + 1 << ": ";
        cin >> sack.contents >> sack.weight;
        sacks.push_back(sack);
    }

    for (int i = 0; i < numSand; ++i) {
        Sack sack;
        cout << "Enter content (C/G/S) and weight for sand sack " << i + 1 << ": ";
        cin >> sack.contents >> sack.weight;
        sacks.push_back(sack);
    }

    double totalWeight = 0.0;
    int sacksRejected = 0;

    for (int i = 0; i < sacks.size(); ++i) {
        if (!checkSack(sacks[i])) {
            sacksRejected++;
        } else {
            totalWeight += sacks[i].weight;
        }
    }

    cout << "Total weight of the order: " << totalWeight << " kilograms.\n";
    cout << "Number of sacks rejected from the order: " << sacksRejected << "\n";

    double regularPrice = (numCement * 3) + (numGravel * 2) + (numSand * 2);
    int numSpecialPacks = min(numCement, min(numGravel / 2, numSand / 2));
    double discountPrice = numSpecialPacks * 10 + regularPrice - (numSpecialPacks * 7);

    if (numSpecialPacks > 0) {
        cout << "Regular price for the order: $" << regularPrice << "\n";
        cout << "New price for the order with discount: $" << discountPrice << "\n";
        cout << "Amount saved: $" << regularPrice - discountPrice << "\n";
    } else {
        cout << "Regular price for the order: $" << regularPrice << "\n";
    }
}

int main() {
    checkOrder();
    return 0;
}

