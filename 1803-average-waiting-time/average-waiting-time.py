class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        s=0
        i=0
        at=0
        tt=customers[0][0]
        while(i<len(customers)):
            at=customers[i][0]
            if(at>tt):
                tt=at+customers[i][1]
            else:
                tt+=customers[i][1]
            s+=(tt-at)
            i+=1
            print(tt)
        return (s)/len(customers)