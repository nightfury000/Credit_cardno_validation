#include<bits/stdc++.h>
using namespace std;

bool isNumberString(string s){
    int len = s.length();
    for(int i = 0; i < len; i++){
        if(s[i] < '0' || s[i] > '9'){
            return false;
        }
        return true;
    }
}

int main(){
    string ccNumber;
    cout << "Implementation of Luhn Algorithm to validate cc number" << endl;

    while(true){
        cout << "Please enter cc number" << endl;
        cin >> ccNumber;
        
        //entering "exit" quits the program.
        if(ccNumber == "exit"){
            break;
        }

        else if(!isNumberString(ccNumber)) {
            cout << "Bad input! ";
            continue;
        }

        int len = ccNumber.length();
        int EvenDigitDoubleSum = 0;

    //here we go from right to left for even places and double each of the place if resulting digit in that place is greater than nine
    //then individual digit addition is done if double is 9 or less than it so it is directly calculated in sum 
        
        for(int i = len - 2; i >= 0; i = i - 2){                // for getting even digit places
            int d_ouble ((ccNumber[i] - 48) * 2);               // doubling them
            if(d_ouble > 9){                                    //for checking if the resulting digits are greater than 9
                d_ouble = (d_ouble/10) + (d_ouble%10);          // adding both digits
            }
            EvenDigitDoubleSum += d_ouble; 
        }

        
        //during odd digit addition we directly take the sum off odd digit places
        for(int i = len - 1; i >= 0; i = i-2){                   //for getting odd digit places
            EvenDigitDoubleSum += (ccNumber[i] - 48);            // here ccNumber[i] gives ASCII value so we subtract 48(ascii value of 0) to get int value. 
        } //after this loop we get sum of both even and odd digits 


        cout << (EvenDigitDoubleSum % 10 == 0 ? "Valid" : "Invalid!") << endl; // conditional ternary operator is used, if the sum is divisble by 10 then only cc is valid
        continue;
        
    }
    
    return 0;
}




