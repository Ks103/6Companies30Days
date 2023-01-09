import Queue
class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        q = Queue.PriorityQueue()
        projects = sorted(zip(Profits, Capital), key=lambda l: l[1])
        j = 0
        for i in range(k):
          while j < len(projects):
            if projects[j][1] > W:
              break
            else:
              q.put((-projects[j][0], projects[j][0]))
            j = j + 1
          if q.empty():
            break
          else:
            W += q.get()[1]
        return 
