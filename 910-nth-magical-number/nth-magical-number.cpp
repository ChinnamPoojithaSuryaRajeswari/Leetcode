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
//     long long gcd(long long int a, long long int b) {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }

// long long lcm(int a, int b) {
//     return (a / gcd(a, b)) * b;
// }

// int nthMagicalNumber(int n, int a, int b) {
//     int e = 1e9 + 7;
//     long long l = min(a, b), h = (long long)n * min(a, b), mini = h;
    
//     while (l <= h) {
//         long long m = (l + h) / 2;
        
//         // Counts multiples of a, b, and both a and b
//         long long k = m / a;
//         long long p = m / b;
//         long long o = m / lcm(a, b);

//         // If the number of magical numbers <= m is >= n
//         if (k + p - o >= n) {
//             mini = min(mini, m);  // Update the result if m is a valid candidate
//             h = m - 1;             // Search in the lower half
//         } else {
//             l = m + 1;             // Search in the upper half
//         }
//     }

//     return int(mini % e);  // Return the result modulo 1e9+7
}
};