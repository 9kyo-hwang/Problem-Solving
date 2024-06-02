from math import ceil

LAST_EXIT = 1439  # 24 * 60 + 59

def solution(in_fees, in_records):
    histories = {}
    for record in in_records:
        time, license, history = record.split()
        h, m = map(int, time.split(':'))
        time = h * 60 + m
        
        if license not in histories:
            histories[license] = []
        histories[license].append(time)
    
    parking = {}
    for license, history in histories.items():
        if len(history) & 1:
            history.append(LAST_EXIT)
        
        parking[license] = sum(exit - entry for entry, exit in zip(history[0::2], history[1::2]))
            
    base_time, base_fee, unit_time, unit_fee = in_fees
    answer = [base_fee] * len(parking)
    for i, (license, time) in enumerate(sorted(parking.items())):
        if time > base_time:
            answer[i] += ceil((time - base_time) / unit_time) * unit_fee
    
    return answer