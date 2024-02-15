#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Appointment {
    int startTime;
    int endTime;
};

int getTimeInMinutes(const string& timeStr) {
    int pos = timeStr.find(':');
    int hours = stoi(timeStr.substr(0, pos));
    int minutes = stoi(timeStr.substr(pos + 1));
    return hours * 60 + minutes;
}

int main() {
    vector<Appointment> appointments;
    int maxTime = 0;
    int start = 600;
    int end = 1080;
    string line;
    while (getline(cin, line)) {
        int s = stoi(line);
        for (int i = 0; i < s; ++i) {
            string start, end;
            getline(cin, start, ' ');
            getline(cin, end, ' ');
            appointments[i].startTime = getTimeInMinutes(start);
            appointments[i].endTime = getTimeInMinutes(end);
            getline(cin, line);
        }
        getline(cin, line);
        appointments[s].startTime = appointments[s - 1].endTime;
        appointments[s].endTime = getTimeInMinutes(line);
    }
    maxTime = appointments[0].startTime - start;
    for(int i=1; i<appointments.size(); i++){
        maxTime = max(maxTime, (appointments[i].startTime - appointments[i-1].endTime));
    }
    maxTime = max(( end-appointments[appointments.size()-1].endTime), maxTime);
    cout << maxTime/60 << " "<< maxTime%60;
}
