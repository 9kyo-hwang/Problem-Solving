from math import ceil

LAST_EXIT = 1439  # 24 * 60 + 59

def solution(in_fees, in_records):
    entry, parking = {}, {}
    for record in in_records:
        time, license, history = record.split()
        hour, minute = map(int, time.split(':'))
        time = hour * 60 + minute
        
        if history == "IN":
            entry[license] = time
            continue
            
        entry_time = entry[license]
        del entry[license]
        
        if license not in parking:
            parking[license] = 0
        
        parking[license] += time - entry_time
    
    for license, time in entry.items():
        if license not in parking:
            parking[license] = 0
        parking[license] += (LAST_EXIT - time)
        
    
    base_time, base_fee, unit_time, unit_fee = in_fees
    answer = [base_fee] * len(parking)
    for i, (license, time) in enumerate(sorted(parking.items())):
        if time > base_time:
            answer[i] += ceil((time - base_time) / unit_time) * unit_fee
    
    return answer