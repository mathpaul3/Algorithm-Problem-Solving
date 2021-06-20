participant = ["marina", "josipa", "nikola", "vinko", "filipa"]
completion = ["josipa", "filipa", "marina", "nikola"]


def solution(participant, completion):
    answer = ''

    for name in completion:
        for person in participant:
            if name == person:
                participant.remove(person)
                break
        else:
            answer = person
        if answer != '':
            break
    else:
        answer = participant[0]

    return answer


print(solution(participant, completion))
