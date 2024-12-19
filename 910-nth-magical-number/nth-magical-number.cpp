class Solution {
public:
    long long gcd(long long int a, long long int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
    long long lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
    int nthMagicalNumber(int n, int a, int b) {
            int e = 1e9 + 7;
    long long l = min(a, b), h = (long long)n * min(a, b), mini = h;
   
        while(l<=h){
            long long m = (l+h)/2,k,p,o;
            k = m/a;
            p = m/b;
            o = (m/(lcm(a,b)));
            if(k+p-o >= n){
                mini = min(mini,m);
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return int(mini%e);
    }
};