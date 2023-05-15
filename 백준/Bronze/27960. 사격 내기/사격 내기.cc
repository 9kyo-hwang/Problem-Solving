#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    vector<bool> setted[2];
    setted[0] = vector<bool>(10, false);
    setted[1] = vector<bool>(10, false);
    
    int score = 512;
    int index = 9;
    while(score) {
        if(a >= score) {
            a -= score;
            setted[0][index] = true;
        }
        if(b >= score) {
            b -= score;
            setted[1][index] = true;
        }
        
        score /= 2;
        --index;
    }
    
    int c = 0;
    score = 1;
    for(int i = 0; i < 10; i++) {
        if(setted[0][i] && !setted[1][i] || !setted[0][i] && setted[1][i])
            c += score;
        
        score *= 2;
    }
    
    cout << c;
    
    return 0;
}