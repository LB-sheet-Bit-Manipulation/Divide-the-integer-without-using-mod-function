//LOGIC: 
//Observation:
//ex: 30/5 => 
//30-5=25
//25-5=20
//20-5=15
//15-5=10
//10-5=5 
//5-5=0  which is < divisor 5 so while() ke andar nhi ghusega ab aage wala.(it is last one)
//while loop ke andar ka count variable 6 baar increase hua => quotient => our answer


#include <bits/stdc++.h>
using namespace std;
 
// Function to divide a by b and
// return floor value it
int divide(int dividend, int divisor) {
 
  // Calculate sign of divisor i.e.,
  // sign will be negative only iff
  // either one of them is negative
  // otherwise it will be positive
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
 
  // Update both divisor and
  // dividend positive
  dividend = abs(dividend);
  divisor = abs(divisor);
 
  // Initialize the quotient
  int quotient = 0;
  while (dividend >= divisor) {
    dividend -= divisor;
    quotient++;
  }
  
  // Return the value of quotient with the appropriate sign.
  return quotient * sign;
}
 
// Driver code
int main() {
  int a = 10, b = 3;
  cout << divide(a, b) << "\n";
 
  a = 43, b = -8;
  cout << divide(a, b);
 
  return 0;
}

/////////////////////////////////////////// second method ///////////

int divide(long long dividend, long long divisor) {
 
  // Calculate sign of divisor i.e.,
  // sign will be negative only iff
  // either one of them is negative
  // otherwise it will be positive
  int sign = ((dividend < 0) ^
              (divisor < 0)) ? -1 : 1;
 
  // remove sign of operands
  dividend = abs(dividend);
  divisor = abs(divisor);
 
  // Initialize the quotient
  long long quotient = 0, temp = 0;
 
  // test down from the highest bit and
  // accumulate the tentative value for
  // valid bit
  for (int i = 31; i >= 0; --i) {
 
    if (temp + (divisor << i) <= dividend) {
      temp += divisor << i;
      quotient |= 1LL << i;
    }
  }
  //if the sign value computed earlier is -1 then negate the value of quotient
  if(sign==-1) quotient=-quotient;
   
  return quotient;
}
