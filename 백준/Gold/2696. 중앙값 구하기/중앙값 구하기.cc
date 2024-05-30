#include <iostream>
#include <queue>
#include <memory>

using namespace std;

class FMedianHeap
{
public:
    FMedianHeap() {}
    ~FMedianHeap() = default;
    
    void Emplace(int Value)
    {
        if(!MinHeap.empty() && Value < MinHeap.top())
        {
            MaxHeap.emplace(Value);
        }
        else
        {
            MinHeap.emplace(Value);
        }
        
        Heapify();
    }
    
    int Top()
    {
        return MaxHeap.size() >= MinHeap.size() ? MaxHeap.top() : MinHeap.top();
    }
    
private:
    priority_queue<int, vector<int>, greater<>> MinHeap;
    priority_queue<int> MaxHeap;
    
    void Heapify()
    {
        if(MaxHeap.size() - MinHeap.size() == 2)
        {
            MinHeap.emplace(MaxHeap.top());
            MaxHeap.pop();
        }
        else if(MinHeap.size() - MaxHeap.size() == 2) 
        {
            MaxHeap.emplace(MinHeap.top());
            MinHeap.pop();
        }
    }
};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while(T--)
    {
        auto MedianHeap = make_unique<FMedianHeap>();
        vector<int> Answer;
        
        int M; cin >> M;
        for(int i = 1; i <= M; ++i)
        {
            int N; cin >> N;
            MedianHeap->Emplace(N);
            
            if(i & 1)
            {
                Answer.emplace_back(MedianHeap->Top());
            }
        }
        
        cout << Answer.size() << "\n";
        for(int Median : Answer)
        {
            cout << Median << " ";
        }
        cout << "\n";
    }
    
    return 0;
}