phone_book = ['123', '456', '789']


def solution(phone_book):
    answer = True
    phone_book.sort()
    for i in range(len(phone_book)-1):
        if phone_book[i+1].startswith(phone_book[i]):
            answer = False
            break
        if not answer:
            break

    return answer


print(solution(phone_book))
