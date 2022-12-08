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
int len = correctSymbols.size();

int main()
{
    std::string email;
    std::cout << "Enter e-mail: ";
    std::getline(std::cin, email);

    if (checkAt(email) == 1 
            && checkEmailFirstPart(select_fPart_email(email)) == 0 
            && checkEmailSecondPart(select_sPart_email(email)) == 0) {
        std::cout << "E-mail is valid";
    } else {
        std::cout << "E-mail is non-valid";
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
    std::string sPart_email = email.substr(email.find(sep) + 1, email.size() - 1);

    return sPart_email;
}

int checkEmailFirstPart(std::string fPart_email){
    std::string t = fPart_email;
    int errors = 0, i = 0, s = t.size();

        for (int i = 0; i < s; i++){
        char dot1, dot2;
        dot1 = t[i];
        dot2 = t[i+1];
        if (dot1 == '.' && dot1 == dot2) {
            errors++;
            break;
        }
    }

    if (errors == 0){
        if (t[0] == '.' || t[s - 1] == '.'){
            errors++;
        } else if (s < 1 || s > 64){
            errors++;
        }

        if (errors == 0){
            for (auto c : t){
                if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
                    continue;
                } else {
                    for (auto f : correctSymbols){
                        if (c == f){
                            break;
                        } else (c != f);{
                            i++;
                            if (len == i){
                                errors += 1;
                                break;
                            }
                        }
                     }
                }
            }
        }
    }
    return errors;
}

int checkEmailSecondPart(std::string sPart_email){
    std::string t = sPart_email;
    int errors = 0, s = t.size();


    for (int i = 0; i < s; i++){
        char dot1, dot2;
        dot1 = t[i];
        dot2 = t[i+1];
        if (dot1 == dot2) {
            errors++;
            break;
        }
    }

    if (errors == 0){
        if (t[0] == '.' || t[s - 1] == '.'){
            errors++;
        } else if (s < 1 || s > 64) {
            errors++;
        }

        if (errors == 0){
            for (auto c : t){
                if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
                        || c == '.' || c == '-'){
                    continue;
                } else {
                    errors++;
                }
            }
        }
    }
    return errors;
}

int checkAt(std::string email){
    int at = 0;

    for (auto c : email){
        if (c == '@'){
            at++;
        }
    }
    return at;
}