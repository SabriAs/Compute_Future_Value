#include <iostream>
using namespace std;

// code for the exponent function
double Power(double b, int e = 2){
	double result;
	for (result = 1; e > 0; e--)
		result *= b;
	return result;
}
// calculate future value
double FutureValue(double principal, double intrte, int trm){
	return principal *(Power (1 + intrte, trm));
}
// get data from user
void ReadData(double& principal, int& trm, double& intrte){
	cout << "Please specify investment amount: ";
	cin >> principal;
	cout << "\n";

	cout << "Over how many years is the future value to be computed? ";
	cin >> trm;
	cout << "\n";

	cout << "At what interest rate: ";
	cin >> intrte;

	// take the future value
	intrte /= 100.00;
	double future_value = FutureValue(principal, intrte, trm);
	
	cout << "\nThe future value for " << principal << " over " << trm << 
		" years, at an interest rate of " << intrte * 100.00 << "% is " 
		<< future_value << endl;
}
int main(){
	double principal, intrte;
	int trm;
	char continue_yn;

	do {
		ReadData(principal, trm, intrte);
		//keep asking user if want to continue input data to be read 
		cout << "\nWould you like to compute another future value? (Y/N): ";
		cin >> continue_yn;
		cout << "\n";
	} 
	while (continue_yn == 'y' || continue_yn == 'Y');
	return 0;
}