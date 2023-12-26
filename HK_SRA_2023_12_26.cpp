/* 
  @author : Ibrahim Ozturk
  SENG 225 Software Requirements Analysis
  Hasan Kalyoncu University
  Lecture : 2023-12-26
*/

#include <iostream>
using namespace std;

class complexNum{
    /*
                    Complex     Number
        Notation I  > a       +    b*i
        Notation J  > a       +    b*j
        real    imaginary
    */
    public:
        const char SYM_NOTATION_I       = 'i';
        const char SYM_NOTATION_J       = 'j';
        const char SYM_NOTATION_INVALID = 'X';

    private:
        float real = 0;
        float imag = 0;
        char  notation = SYM_NOTATION_I;

    public:
        //constructor method
        complexNum(float realTemp, float imagTemp){
            real = realTemp;
            imag = imagTemp;
        }

        //member method
        void display(void){
            /*  No argument, no return value
                Displays current complex number.
            */
            cout << "Current complex number: " << real << " + " << imag << notation << endl;
        }

        void setReal(float realTemp){
            real = realTemp;
        }
        void setImag(float imagTemp){
            imag = imagTemp;
        }

        float getReal(void){
            return real;
        }
        float getImag(void){
            return imag;
        }
        void setNotation(char notationTemp){
            if((notationTemp == SYM_NOTATION_I) || (notationTemp == SYM_NOTATION_J))
                notation = notationTemp;
            else
                cout << "Invalid notation, so current notation not modified!" << endl;
        }
        complexNum complexNumSum(complexNum complexNumObj);
};

complexNum complexNum::complexNumSum(complexNum complexNumObj){
    complexNum complexNumObjTemp(complexNumObj.getReal(), complexNumObj.getImag());
    float temp;
    real = real + complexNumObjTemp.getReal();
    imag = imag + complexNumObjTemp.getImag();
    return complexNumObjTemp;
}
int main(){
    cout << "*** Program is starting ***" << endl;
    complexNum complex1(8, 15);
    complexNum complex2(3, 4);
    complexNum complex3(6, 8);
    complexNum complex4(0, 0);

    complex3.setNotation(complex3.SYM_NOTATION_INVALID);
    complex3.display();
    cout << "Adding..." << endl;
    complex1.display();
    complex3.display();
    complex3.complexNumSum(complex1);
    complex3.display();
    //It is not allowed to access each variables from outside (private variable)
    //cout << "The imaginery part of c3" << c3.imag << endl;

    cout << "Loop Adding..." << endl;
    complexNum cTemp(0, 0);
    complexNum complexNumArray[] = {complex1, complex2, complex3, complex4};
    for (int ind=0; ind < 4; ind++){
        cout << "DEBUG: Will be added: ";
        complexNumArray[ind].display();
        cTemp.complexNumSum(complexNumArray[ind]);
        cout << "DEBUG: Added   total: ";
        cTemp.display();
    }
    cout << "Total : ";
    cTemp.display();
}
