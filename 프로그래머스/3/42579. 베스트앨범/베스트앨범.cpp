#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> Genres, vector<int> Plays) {
    using GenreInfo = pair<int, vector<pair<int, int>>>;
    
    unordered_map<string, GenreInfo> SongInfoByGenre;
    for(int i = 0; i < Genres.size(); ++i)
    {
        const string& Genre = Genres[i]; const int Play = Plays[i];
        auto& [TotalPlayTime, SongList] = SongInfoByGenre[Genre];
        
        TotalPlayTime += Play;
        SongList.emplace_back(i, Play);
    }
    
    vector<GenreInfo> ListOfGenreInfo(SongInfoByGenre.size());
    transform(SongInfoByGenre.begin(), SongInfoByGenre.end(), ListOfGenreInfo.begin(), [](auto pair) { return pair.second; });
    
    sort(ListOfGenreInfo.begin(), ListOfGenreInfo.end(), greater<>());
    for(auto& [TotalPlayTime, SongList] : ListOfGenreInfo)
    {
        sort(SongList.begin(), SongList.end(), [](auto p, auto q) 
             {
                 if(p.second == q.second)
                 {
                     return p.first < q.first;
                 }
                 return p.second > q.second;
             });
    }
    
    vector<int> BestAlbum;
    for(const auto& [TotalPlayTime, SongList] : ListOfGenreInfo)
    {
        int SelectCnt = 0;
        for(const auto& [Id, Play] : SongList)
        {
            if(SelectCnt == 2)
            {
                break;
            }
            
            BestAlbum.emplace_back(Id);
            SelectCnt += 1;
        }
    }
    
    return BestAlbum;
}