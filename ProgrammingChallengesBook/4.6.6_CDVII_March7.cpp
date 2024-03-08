#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Record {
    string license;
    string time;
    string action;
    int location;
};

struct FareStructure {
    vector<int> tolls;
};

int calculateToll(const Record& entry, const Record& exit, const FareStructure& fare) {
    int startHour = stoi(entry.time.substr(6, 2));
    int endHour = stoi(exit.time.substr(6, 2));
    int totalToll = 0;
    
    for (int hour = startHour; hour < endHour; ++hour) {
        totalToll += fare.tolls[hour];
    }
    
    return totalToll;
}

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore();
    
    for (int t = 0; t < testCases; ++t) {
        FareStructure fare;
        for (int i = 0; i < 24; ++i) {
            int toll;
            cin >> toll;
            fare.tolls.push_back(toll);
        }
        
        cin.ignore();
        
        vector<Record> records;
        string line;
        while (getline(cin, line) && line != "") {
            stringstream ss(line);
            Record record;
            ss >> record.license >> record.time >> record.action >> record.location;
            records.push_back(record);
        }
        
        map<string, int> bill;
        map<string, int> trips;
        
        for (int i = 0; i < records.size(); i += 2) {
            Record entry = records[i];
            Record exit = records[i + 1];
            
            int toll = calculateToll(entry, exit, fare);
            int tripCost = toll + 100;
            bill[entry.license] += tripCost;
            trips[entry.license]++;
        }
        
        cout << fixed << setprecision(2);
        for (const auto& entry : bill) {
            string license = entry.first;
            int totalCost = entry.second + 200;
            cout << license << " $" << totalCost / 100.0 << endl;
        }
        
        if (t < testCases - 1) {
            cout << endl;
        }
    }
}