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

    if ((checkEmailFirstPart() > 0) || (checkEmailSecondPart() > 0)){
        std::cout << "Email is non-valid";
    } else {
        std::cout << "Email is valid";
    }
return 0;
}

std::string select_fPart_email(std::string email){
    std::string fPart_email;
    for (int i; i < email.length(); i++){
        if (email[i] == '@'){
            break;
        }
        else {
            fPart_email[i] = email[i];
        }
    }
return fPart_email;
}

std::string select_sPart_email(std::string email){
    std::string sPart_email;
    for (int i = 0; i < email.length(); i++){

    }

return sPart_email;
}

int checkEmailFirstPart(std::string select_fPart_email){
    int fPart_errors = 0;


return fPart_errors;
}

int checkEmailSecondPart(std::string select_sPart_email){
    int sPart_errors = 0;

return sPart_errors;
}
