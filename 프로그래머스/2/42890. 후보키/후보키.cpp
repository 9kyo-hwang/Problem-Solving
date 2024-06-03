#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool IsUnique(const vector<vector<string>>& Relation, const int RowSize, const int ColSize, int AttributeSet)
{
    // Binary Attribute Set -> Indices List
    vector<int> Columns;
    for(int Column = 0; Column < ColSize; ++Column)
    {
        // 1101 & 0001: 1 -> 0110 & 0001: 0 -> 0011 & 0001: 1 -> 0001 & 0001: 1 => 1, 3, 4 column
        if((AttributeSet >> Column) & 1)
        {
            Columns.emplace_back(Column);
        }
    }
    
    unordered_set<string> Set;
    for(int Row = 0; Row < RowSize; ++Row)  // 모든 행에대해
    {
        string Attributes{};
        for(int Column : Columns)  // AttributeSet에 속하는 Column을 순회하며
        {
            Attributes += Relation[Row][Column];
        }
        Set.emplace(Attributes);  // 해당 조합을 Set에 넣는다.
    }
    
    return Set.size() == RowSize;  // 그 조합들이 하나도 중복되지 않으면 후보키 자격이 존재함
}

bool IsMinimal(const vector<int>& CandidateKeys, int AttributeSet)
{
    for(int CandidateKey : CandidateKeys)
    {
        // AttributeSet에 속하는 속성들이 이미 CandidateKey로 사용되었다면 Cut
        if((AttributeSet & CandidateKey) == CandidateKey)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> Relation)
{
    const size_t RowSize = Relation.size(), ColSize = Relation.front().size();
    vector<int> CandidateKeys;
    
    // 0001(1번 column), 0010(2번 column), 0011(1, 2번 column), ...
    for(int AttributeSet = 1; AttributeSet < (1 << ColSize); ++AttributeSet)
    {
        if(!IsMinimal(CandidateKeys, AttributeSet)) continue;
        if(!IsUnique(Relation, RowSize, ColSize, AttributeSet)) continue;
        
        CandidateKeys.emplace_back(AttributeSet);
    }
    
    return CandidateKeys.size();
}