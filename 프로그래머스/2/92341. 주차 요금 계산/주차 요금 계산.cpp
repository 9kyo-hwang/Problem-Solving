#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

tuple<int, string, string> RecordParser(const string& InRecord)
{
    istringstream SS(InRecord);
    string Buffer;
    
    // 1. Time Parsing
    SS >> Buffer;
    int Pos = Buffer.find(':');
    int Hour = stoi(Buffer.substr(0, Pos));
    int Minute = stoi(Buffer.substr(Pos + 1));
    int Time = Hour * 60 + Minute;
    
    // 2. License Parsing
    SS >> Buffer;
    string License = Buffer;
    
    // 3. History Parsing
    SS >> Buffer;
    string History = Buffer;
    
    return {Time, License, History};
}

constexpr int LAST_EXIT = 1439;  // 23 * 60 + 59

tuple<int, int, int, int> FeeParser(const vector<int>& InFees)
{
    return {InFees[0], InFees[1], InFees[2], InFees[3]};
}

vector<int> solution(vector<int> InFees, vector<string> InRecords) 
{
    map<string, int> EntryMap, ParkingMap;
    for(const string& Record : InRecords)
    {
        const auto& [Time, License, History] = RecordParser(Record);
        if(History == "IN")
        {
            EntryMap[License] = Time;
            continue;
        }
        
        int EntryTime = EntryMap[License];
        EntryMap.erase(License);
        
        ParkingMap[License] += Time - EntryTime;
    }
    
    for(const auto& [License, EntryTime] : EntryMap)
    {
        ParkingMap[License] += LAST_EXIT - EntryTime;
    }
    
    const auto& [BaseTime, BaseFee, UnitTime, UnitFee] = FeeParser(InFees);
    vector<int> Answer(ParkingMap.size(), BaseFee);
    int Index = 0;
    for(auto& [License, Time] : ParkingMap)
    {
        if(Time > BaseTime)
        {
            Answer[Index] += ceil((double)(Time - BaseTime) / (double)UnitTime) * UnitFee;
        }
        ++Index;
    }
    return Answer;
}