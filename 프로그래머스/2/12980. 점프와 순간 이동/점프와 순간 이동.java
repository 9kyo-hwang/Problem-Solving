import java.util.*;

public class Solution {
    public int solution(int n) {
        int ans = 0;

        while(n > 0) {
            ans += n & 1;
            n >>= 1;
        }

        return ans;
    }
}