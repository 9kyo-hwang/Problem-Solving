from collections import defaultdict
from itertools import product
from heapq import heapify, heappop, heappush

def solution(k, n, reqs):
    # Generating all possible mentor assignment combinations
    mento_assignment_combs = [
        prod for prod in product(range(1, n + 1), repeat=k) if sum(prod) == n
    ]
    
    # Organizing consultations by category
    consultations = defaultdict(list)
    for a, b, c in reqs:
        consultations[c - 1].append((a, b))

    def get_consultation_waiting(category, num_mento):
        # Initialize heap with zeros
        mento_ticks = [0] * num_mento
        heapify(mento_ticks)
        waiting = 0
        
        for tick, consultation in consultations[category]:
            fastest_mento = heappop(mento_ticks)
            
            # Adjust waiting time based on consultation time and mentor availability
            if fastest_mento > tick:
                waiting += fastest_mento - tick
                heappush(mento_ticks, fastest_mento + consultation)
            else:
                heappush(mento_ticks, tick + consultation)
                
        return waiting

    # Calculate waiting time for each mentor assignment combination
    ans = float('inf')
    for mento_assignment_comb in mento_assignment_combs:
        waiting_cur_comb = sum(
            get_consultation_waiting(category, num_mento)
            for category, num_mento in enumerate(mento_assignment_comb)
        )
        ans = min(ans, waiting_cur_comb)
    return ans
