class Solution {
public:
    int len(int number) 
{ 
    // returns the length of a given number 
    return log10(number) + 1; 
} 
  
// reverse a given number 
long rev_number(long& number) 
{ 
    if ((number % 10) == number) 
        return number; 
    long last = number % 10; 
    long remaining = number / 10; 
    long l = len(remaining); 
    return last * pow(10, l) + rev_number(remaining); 
}
    int reverse(int x) {
        int low = -pow(2,31);
        int high = pow(2,31) -1;
        int sign = x<0 ? -1:1;
        signed long temp2 = x;
        if( x< 0 ) temp2 = abs(x);
        long result = rev_number(temp2);
        long temp = sign*result;
        if( temp < low || temp >high ) return 0;
        return temp;

    }
};