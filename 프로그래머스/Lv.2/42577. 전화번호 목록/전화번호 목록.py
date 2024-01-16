def solution(phone_book):
    phone_set = set(phone_book)
    for phone_number in phone_book:
        num_prefix = ""
        for num in phone_number:
            num_prefix += num
            
            if num_prefix == phone_number:
                continue
            
            if num_prefix in phone_set:
                return False
            
    return True