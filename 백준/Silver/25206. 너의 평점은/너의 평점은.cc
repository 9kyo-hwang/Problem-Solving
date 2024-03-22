#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    unordered_map<string, double> SubjectRating = 
    {
        {"A+", 4.5},
        {"A0", 4.0},
        {"B+", 3.5},
        {"B0", 3.0},
        {"C+", 2.5},
        {"C0", 2.0},
        {"D+", 1.5},
        {"D0", 1.0},
        {"F", 0.0},
    };
    
    string buffer;
    string Name, Rating;
    double Grade;
    
    double TotalGrade = 0.0, Credit = 0;
    for(int i = 0; i < 20; ++i)
    {
        getline(cin, buffer);
        istringstream ss(buffer);
        
        ss >> Name >> Grade >> Rating;
        
        if(Rating == "P")
        {
            continue;
        }
        
        TotalGrade += Grade * SubjectRating[Rating];
        Credit += Grade;
    }
    
    cout << TotalGrade / Credit;
    
    return 0;
}