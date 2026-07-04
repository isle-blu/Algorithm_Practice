# 구명보트

def solution(people, limit):
    answer = 0
    people.sort(reverse = True)
    
    back_idx = len(people) - 1
    for i in people:
        if i == 0:
            break
        
        if limit - i >= people[back_idx]:
            people[back_idx] = 0
            back_idx -= 1
        
        answer += 1
    
    return answer