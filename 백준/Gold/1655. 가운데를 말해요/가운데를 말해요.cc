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
    priority_queue<int, vector<int>, greater<>> MinHeap;  // 중앙값보다 큰 것들만 들어감
    priority_queue<int> MaxHeap;  // 중앙값보다 작거나 같은 것들만 들어감
    
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

    auto MedianHeap = make_unique<FMedianHeap>();
    
    int N; cin >> N;
    while(N--)
    {
        int Num; cin >> Num;
        MedianHeap->Emplace(Num);
        cout << MedianHeap->Top() << "\n";
    }
    
    return 0;
}