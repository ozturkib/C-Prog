/* 
  @author : Ibrahim Ozturk
  SENG 225 Software Requirements Analysis
  Hasan Kalyoncu University
  Lecture : 2023-12-19
*/

#include <iostream>
using namespace std;

class mobilePhone{
    private:
        string IMEI = "000000000000000";

    public:
        string brandName;
        string modelName;
        int yearManufactured;
        int sizeScreen;
        int sizeRAM;
        int memory = 512;
        void setModelName(string mdlName);

        mobilePhone(string brName, string mdlName){ //constructor
            brandName = brName;
            modelName = mdlName;
            cout << "Object is created with " << brandName << "--" << modelName << endl;
        }
        void showPhoneDetails(void){
            cout << "Mobile phone: " << endl;
            cout << "Bran Name : " << brandName << endl;
            cout << "Model Name : " << modelName << endl;
        }

        void setBrandName(string brName){
            brandName = brName;
            cout << "Brand name SET to " << brandName;
        }
        void setIMEI(string newIMEI, string password){
            if((password == "1234") && (checkIMEI(newIMEI) == true))
                IMEI = newIMEI;
            else{
                if(password != "1234")
                    cout << "You arenot authorized to modify the IMEI!"<< endl;
                else if(checkIMEI(newIMEI) != true)
                    cout << "Invalid IMEI!" << endl;
            }
        }
        void showIMEI(void) const {
            cout << "\nIMEI of : " << brandName << " = " << IMEI << endl;
        }

        bool checkIMEI(string IMEI){
            /*
                Check all digits are numeric!
                Check length of typed number is 15!

                Example invalid case: "0000A0000000000"
                Example invalid case: "0000000000000001"
                Example VALID case  : "000012121200000"
                Example VALID case  : "456745487429150"
            */
            /*
                isdigit('k')  returns 0: false
                isdigit('5')  returns 1: true
                isdigit accepting only single character!
            */
            /*
                Returns true  if IMEI is valid
                Returns false if IMEI is invalid.
            */
            bool validity = true;
            if(IMEI.length() == 15){
                for(int ind=0; ind < IMEI.length(); ind++){
                    if (isdigit(IMEI[ind]) == false)
                        validity = false;
                }
            }
            else
                validity = false;

            return validity;
        }


};

void mobilePhone::setModelName(string mdlName){
    modelName = mdlName;
    cout << "Model name SET to " << modelName;
}

int main(){
    cout << "*** Class - Object***" << endl;
    mobilePhone mobilePhoneSamsungS23("Samsung", "S23");
    mobilePhoneSamsungS23.setIMEI("000000033300000", "1234");
    mobilePhoneSamsungS23.showIMEI();
}
