/******************************************************************************/
/* File Name: Task_11_2                                                       */
/* Data: 22.11.2022                                                           */
/* Developer: Sergey Plotnikov                                                */
/* Description: Solution for task 2 of Block 11 of the C++ study course       */
/******************************************************************************/

#include <iostream>
#include <string>

int checkEmailFirstPart(std::string);
int checkEmailSecondPart(std::string);
int checkAt(std::string);

std::string select_fPart_email(std::string);
std::string select_sPart_email(std::string);

std::string const correctSymbols(".!#$%&'*+-/=?^_`{|}~");

int main()
{
    std::string email;
    std::cout << "Enter e-mail: ";
    std::cin >> email;

    if (checkAt(email) != 1) {
        std::cout << "E-mail is non-valid";
    } else if ((checkEmailSecondPart(select_sPart_email(email)) > 0)
                    && (checkEmailSecondPart(select_sPart_email(email)) > 0)){
        std::cout << "E-mail is non-valid";
    } else {
        std::cout << "E-mail is valid";
    }

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
    int errors = 0, i = 0;
    std::string t = fPart_email;

    if (t[0] == '.' || t[t.length() - 1] == '.'){
        errors++;
    } else if (t[i] == '.' && t[i + 1] == '.'){
        errors++;
    } else if (t.length() < 1 || t.length() > 64){
        errors++;
    }

    for (auto c : t){
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
            continue;
        } else {
            for (auto f : correctSymbols){
                if (c == f){
                    break;
                } else {
                    errors++;
                }
                break;
            }
        }
    }
    return errors;
}

int checkEmailSecondPart(std::string sPart_email){
    int errors = 0, i = 0;
    std::string t = sPart_email;

    if (t[0] == '.' || t[t.length() - 1] == '.'){
        errors++;
    } else if (t[0] != '@') {
        errors++;
    } else if (t[i] == '.' && t[i + 1] == '.'){
        errors++;
    } else if (t.length() < 1 || t.length() > 63){
        errors++;
    }

    for (auto c : t){
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
            || (c >= 'a' && c <= 'z') || c == '.' || c == '-'){
            continue;
        } else {
            errors++;
        }
    }
    return errors;
}

int checkAt(std::string email) {
  int at = 0;

  for (auto c : email){
    if (c == '@') {
      at++;
    }
  }
  return at;
}