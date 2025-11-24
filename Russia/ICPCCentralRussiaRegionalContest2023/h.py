import heapq
import sys

n, a, k, p = map(int, input().split())

heap = []

val = a
for i in range(n):
    if len(heap) < 5:
        heapq.heappush(heap, val)
    else:
        if val > heap[0]:
            heapq.heapreplace(heap, val)

    val = (val * k) % p

heap.sort()

for i in range(len(heap)):
    sys.stdout.writelines(f"{heap[i]} ")

sys.stdout.writelines('\n')
