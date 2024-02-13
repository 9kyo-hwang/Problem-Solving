from itertools import combinations, product
from collections import defaultdict
from typing import *
from bisect import bisect_left


def get_list_of_combo_sum(dices, indices):
    list_combos: List[int] = []
    for pips in product(range(6), repeat=len(indices)):
        sum_combo: int = sum(dices[i][j] for i, j in zip(indices, pips))  # i번째 주사위 j번째 눈
        list_combos.append(sum_combo)
    return sorted(list_combos)


def solution(dice):
    answer: List[int] = []
    
    n: int = len(dice)
    dice_indices: Set[int] = set(range(n))
    max_win_cnt: int = 0
    for A in combinations(range(n), n // 2):
        B: Set[int] = dice_indices.difference(A)
        
        A_list: List[int] = get_list_of_combo_sum(dice, A)
        B_list: List[int] = get_list_of_combo_sum(dice, B)
        
        win_cnt: int = 0
        for A_combo_sum in A_list:
            win_cnt += bisect_left(B_list, A_combo_sum)
        
        if win_cnt > max_win_cnt:
            max_win_cnt = win_cnt
            answer = A
        
    return [i + 1 for i in answer]