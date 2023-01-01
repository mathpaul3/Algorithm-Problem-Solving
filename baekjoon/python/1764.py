N, M = map(int, input().split())
unheard, unseen = set(), set()

for _ in range(N):
    unheard.add(input())

for _ in range(M):
    unseen.add(input())

unheard_unseen = sorted(list(unheard & unseen))

print(len(unheard_unseen))
for name in unheard_unseen:
    print(name)