import sys

answers = []

def main():
    
    tc = int(input())

    for _ in range(tc):
        global answers
        answers = []
        N = int(input())

        make_str(N, 1, "1")

        sys.stdout.write('\n'.join(answers))
        print('\n')


    return 


def make_str(N, i, formula):
    if N == i:
        if solve(formula) == 0:
            answers.append(formula)
        return

    make_str(N, i+1, formula + " " + str(i+1))
    make_str(N, i+1, formula + "+" + str(i+1))
    make_str(N, i+1, formula + "-" + str(i+1))

    return

def solve(formula):
    result = 0
    now = ""
    before = "+"


    for s in formula:
        if s == " ": continue

        if s.isdigit():
            now += s
        else:
            if before == "+":
                result += int(now)
                now = ""
            elif before == "-":
                result -= int(now)
                now = ""
            
            before = s

    if before == "":
        result = -1
    elif before == "+":
        result += int(now)
    elif before == "-":
        result -= int(now)
    
    return result


main()
