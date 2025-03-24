#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class: Waste Bin
class WasteBin {
protected:
    string location;
    double fillLevel; // Percentage (0-100)

public:
    WasteBin(string loc, double level) : location(loc), fillLevel(level) {}
    virtual void displayInfo() {
        cout << "Location: " << location << " | Fill Level: " << fillLevel << "%\n";
    }
    virtual ~WasteBin() {}
};

// Derived class: Recyclable Waste Bin
class RecyclableBin : public WasteBin {
public:
    RecyclableBin(string loc, double level) : WasteBin(loc, level) {}
    void displayInfo() override {
        cout << "[Recyclable] ";
        WasteBin::displayInfo();
    }
};

// Derived class: Non-Recyclable Waste Bin
class NonRecyclableBin : public WasteBin {
public:
    NonRecyclableBin(string loc, double level) : WasteBin(loc, level) {}
    void displayInfo() override {
        cout << "[Non-Recyclable] ";
        WasteBin::displayInfo();
    }
};

// Truck class to manage collection
class Truck {
private:
    string truckID;
    vector<WasteBin*> assignedBins;

public:
    Truck(string id) : truckID(id) {}
    void assignBin(WasteBin* bin) {
        assignedBins.push_back(bin);
    }
    void showAssignedBins() {
        cout << "Truck " << truckID << " assigned bins:\n";
        for (auto& bin : assignedBins) {
            bin->displayInfo();
        }
    }
};

// Function Overloading Example
void addBin(vector<WasteBin*>& bins, string type, string location, double fillLevel) {
    if (type == "Recyclable")
        bins.push_back(new RecyclableBin(location, fillLevel));
    else
        bins.push_back(new NonRecyclableBin(location, fillLevel));
}

// Exception Handling Example
double getFillLevelInput() {
    double level;
    cout << "Enter fill level (0-100): ";
    cin >> level;
    if (level < 0 || level > 100)
        throw invalid_argument("Fill level must be between 0 and 100!");
    return level;
}

int main() {
    vector<WasteBin*> bins;
    Truck truck1("T123");

    try {
        addBin(bins, "Recyclable", "Downtown", getFillLevelInput());
        addBin(bins, "Non-Recyclable", "Suburb", getFillLevelInput());
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    for (auto& bin : bins) {
        truck1.assignBin(bin);
    }

    truck1.showAssignedBins();

    // Cleanup
    for (auto& bin : bins) {
        delete bin;
    }

    return 0;
}
