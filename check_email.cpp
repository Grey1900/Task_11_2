/******************************************************************************/
/* File Name: Task_11_2                                                       */
/* Data: 22.11.2022                                                           */
/* Developer: Sergey Plotnikov                                                */
/* Description: Solution for task 2 of Block 11 of the C++ study course       */
/******************************************************************************/

#include <iostream>
#include <string>

int checkEmailFirstPart();
int checkEmailSecondPart();

std::string select_fPart_email();
std::string select_sPart_email();

std::string const &correctSymbols ("!#$%&'*+-/=?^_`{|}~");

int main(){
	std::string email;
	std::cout << "Enter e-mail: ";
	std::cin >> email;
    
    /*
    if ((checkEmailFirstPart() > 0) || (checkEmailSecondPart() > 0)){
        std::cout << "Email is non-valid";
    } else {
        std::cout << "Email is valid";
    }
    */
    return 0;
}

std::string select_fPart_email(std::string email){
    
    char const sep = '@';
    std::string fPart_email = email.substr(0, email.find(sep));

    return fPart_email;
}

std::string select_sPart_email(std::string email){
    
    char const sep = '@';
    std::string sPart_email = email.substr(email.find(sep), email.length() - 1);

    return sPart_email;
}

int checkEmailFirstPart(std::string fPart_email){
    int fPart_errors = 0;
    std::string t = fPart_email;
    for (int i = 0; i < t.length(); i++) {
        if (t[0] == '.' || t[sizeof-1] == '.'){
            fPart_errors++;
        }
        else if (t[i] == t[i+1]) {
            fPart_errors++;
        }
        else if (t.length() < 1 || t.length() > 64) {
            fPart_errors++;
        }
        else if (t[i] != &correctSymbols || (t[i] < 'a' && t[i] > 'z') || (t[i] < 'A' && t[i] > 'Z')
                 || (t[i] < '0' && t[i] > '9')) {
            fPart_errors++;
        }
    }
    return fPart_errors;
}

int checkEmailSecondPart(std::string sPart_email){
    int sPart_errors = 0;

    return sPart_errors;
}
