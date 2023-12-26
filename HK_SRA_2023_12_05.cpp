#include <iostream>
using namespace std;

/*
  SENG 225 
  Software Requirements Analysis
  @Hasan Kalyoncu University
  Lecture : 2023-12-05
*/
/*
    Write code to calculate the factorial of an entered number.
*/
void calc_factorial(int number);
bool check_input(int number);

int main(){
    int number;
    cout << "*** Calculation of the number factorial!***" << endl;

    while(true){
        cout << "\nPlease type a number: " << endl;
        cout << "*** Inputs must be between [1, 100] ***" << endl;
        cin  >> number;
        //cout << number << endl;
        if(check_input(number))
            calc_factorial(number);
        else
            cout << "Please type a valid number!" << endl;
    }
    return 0;
}

bool check_input(int number){
    if(number > 0 && number <= 100)
        return true;
    else
        return false;
}
void calc_factorial(int number){
    int counter, result=1;
    for(counter=number; counter > 1; counter--) //decrementing from number to 2
        result = result * counter;

    cout << number << "! = " << result;
}
