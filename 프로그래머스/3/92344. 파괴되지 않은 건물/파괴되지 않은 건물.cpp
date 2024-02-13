#include <string>
#include <vector>
#include <iostream>

#define Integer static_cast<int>

using namespace std;

struct SkillInfo
{
    int Type, R1, C1, R2, C2, Degree;
    
    SkillInfo(const vector<int>& Info) : Type(Info[0]), R1(Info[1]), C1(Info[2]), R2(Info[3]), C2(Info[4]), Degree(Info[5]) { }
};

enum class ESkillType
{
    NONE,
    ATTACK,
    HEAL,
};

vector<vector<int>> GetWeightMatrix(const int N, const int M, const vector<vector<int>>& InSkills)
{
    vector WeightMatrix(N + 1, vector(M + 1, 0));
    for(const vector<int>& SkillRow : InSkills)
    {
        SkillInfo Skill(SkillRow);
        if(Skill.Type == Integer(ESkillType::ATTACK))
        {
            WeightMatrix[Skill.R1][Skill.C1] -= Skill.Degree;
            WeightMatrix[Skill.R2 + 1][Skill.C2 + 1] -= Skill.Degree;
            
            WeightMatrix[Skill.R1][Skill.C2 + 1] += Skill.Degree;
            WeightMatrix[Skill.R2 + 1][Skill.C1] += Skill.Degree;
        }
        else if(Skill.Type == Integer(ESkillType::HEAL))
        {
            WeightMatrix[Skill.R1][Skill.C1] += Skill.Degree;
            WeightMatrix[Skill.R2 + 1][Skill.C2 + 1] += Skill.Degree;
            
            WeightMatrix[Skill.R1][Skill.C2 + 1] -= Skill.Degree;
            WeightMatrix[Skill.R2 + 1][Skill.C1] -= Skill.Degree;
        }
    }
    
    for(int i = 0; i <= N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            WeightMatrix[i][j + 1] += WeightMatrix[i][j];
        }
    }
    
    for(int j = 0; j <= M; ++j)
    {
        for(int i = 0; i < N; ++i)
        {
            WeightMatrix[i + 1][j] += WeightMatrix[i][j];
        }
    }
       
    return WeightMatrix;
}

int solution(vector<vector<int>> Board, vector<vector<int>> Skills) 
{
    const int N = Board.size(), M = Board[0].size();
    vector<vector<int>> WeightMatrix = GetWeightMatrix(N, M, Skills);
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            Board[i][j] += WeightMatrix[i][j];
        }
    }
    
    int answer = 0;
    for(const vector<int>& Row : Board)
    {
        for(const int& Col : Row)
        {
            answer += (Col > 0);
        }
    }
    return answer;
}