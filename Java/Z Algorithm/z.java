

public class z {
    public long sumScores(String s) {
        int n = s.length();
        int left = 0, right = 0;
        int[] z = new int[n];
        long ans = n;
        for(int i = 1; i < n; ++i){
            if(i <= right){
                z[i] = Math.min(right - i + 1, z[i - left]);
            }
            while(i + z[i] < n && s.charAt(z[i]) == s.charAt(z[i] + i)){
                left = i;
                right = i + z[i]++;
            }
            ans += z[i];
        }
        return ans;
    }
}
