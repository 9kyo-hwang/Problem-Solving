def solution(genres, plays):
    playlist_by_genre = {genre : [] for genre in set(genres)}
    for i, (genre, play) in enumerate(zip(genres, plays)):
        playlist_by_genre[genre].append((play, i))
                                      
    sorted_genre = sorted(playlist_by_genre.keys(), key=lambda x: sum(map(lambda y: y[0], playlist_by_genre[x])), reverse = True)
    
    answer = []
    for genre in sorted_genre:
        temp = [index for play, index in sorted(playlist_by_genre[genre], key=lambda x: (x[0], -x[1]), reverse=True)]
        answer += temp[:2]
    return answer