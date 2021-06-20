from math import comb, ceil
clothes = [["yellowhat", "headgear"], [
    "bluesunglasses", "eyewear"], ["green_turban", "headgear"]]


def solution(clothes):
    answer = 0
    cloth_type = []
    cloth_num_per_type = []
    for cloth in clothes:
        print(cloth)
        if cloth[1] in cloth_type:
            index = cloth_type.index(cloth[1])
            print(index)
            cloth_num_per_type[index] += 1
        else:
            cloth_type.append(cloth[1])
            cloth_num_per_type.append(1)

    cloth_type_num = len(cloth_type)
    print(cloth_type_num)
    print("ceil:", ceil(cloth_type_num/2))
    for i in range(1, ceil(cloth_type_num/2)+1):
        answer += comb(cloth_type_num, i)
        print("i:", i, "answer:", answer)
    print(answer)
    for i in cloth_num_per_type:
        answer *= i
    print(answer)
    return answer


print(solution(clothes))
