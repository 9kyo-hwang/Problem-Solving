import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        Integer[] boxedQ1 = Arrays.stream(queue1)
            .boxed()
            .toArray(Integer[]::new);
        Integer[] boxedQ2 = Arrays.stream(queue2)
            .boxed()
            .toArray(Integer[]::new);
        
        Queue<Integer> q1 = new LinkedList<>(Arrays.asList(boxedQ1));
        Queue<Integer> q2 = new LinkedList<>(Arrays.asList(boxedQ2));
        long sum1 = Arrays.stream(queue1).sum();
        long sum2 = Arrays.stream(queue2).sum();
        
        int cycle = (q1.size() + q2.size()) * 2;
        int count = 0;
        while(cycle > 0) {
            if(sum1 < sum2) {
                int elem = q2.poll();
                q1.offer(elem);
                
                sum1 += elem;
                sum2 -= elem;
                
                count += 1;
            } else if(sum1 > sum2) {
                int elem = q1.poll();
                q2.offer(elem);
                
                sum1 -= elem;
                sum2 += elem;
                
                count += 1;
            } else {
                return count;
            }
            
            cycle -= 1;
        }
        
        return -1;
    }
}