# 큰 수 만들기 - 오답 

def solution(number, k):
    max_num = number[0]
    total = 0
    cnt = 0
    target_cnt = 1
    idx = 1
    while total <= k:
        if max_num > number[idx]:
            cnt += 1
            total += 1
            idx += 1
            
        elif max_num == number[idx]:
            number = number[0 : target_cnt] + number[target_cnt + cnt + 1:]
            target_cnt += 1
            idx = target_cnt
        else:
            max_num = number[idx]
            total += target_cnt
            if total >= k:
                number = number[0 : target_cnt] + number[target_cnt + cnt + 1:]
                cnt = 0
                break
        
            number = number[idx:]
            
            cnt = 0
            target_cnt = 1
            idx = 1
            
            if idx >= len(number):
                break
        

    if total > k:
        if cnt == 0:
            number = number[total-k:]
        else:
            number = number[:1] + number[2:] 

    return number