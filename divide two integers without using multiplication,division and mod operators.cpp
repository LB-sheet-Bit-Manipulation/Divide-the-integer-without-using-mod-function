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


//Issue:
//Iska bit manipulation wala solution nhi samza. See it later
//return me maine * ka use kiya hai. check if its allowed or not!!
//negative values pe kaam nhi karra BC saala. See on online compiler

#include<iostream>
#include<cmath>     //to use abs()
using namespace std;

int Divide(int dividend,int divisor)
{
	int quotient=0;

	while(abs(dividend)>=abs(divisor))  
	{
		dividend=dividend-divisor;
		quotient++;
	}
	
	//agar dono mese ek bhi negative hai to pura answer negative hoga
	if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
	{
		int new_quotient=(quotient*(-1));
		return new_quotient;
	}
	else //else answer is positive
	{
		return quotient;
	}
	
}

int main() 
{ 
	//bitwise operations becomes undefined in negative numbers. so unsigned int is used.
	int a,b;
	
	cout<<"\nEnter number (dividend) ";
	cin>>a;
	cout<<"\nDivide it by (divisor) =>  ";
	cin>>b;
	
	if(b==0)
	{
		cout<<"\nDivisor can't be 0";
	}
	else
	{
		//calling our function
		cout<<"\nDivision gives quotient as =>  "<<" "<<Divide(a,b);
	}
		
	return 0;
}
