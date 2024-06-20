#include "iostream"

using namespace std;

string checkGender(string gender)
{
    if (
        gender == "MALE" || gender == "Male" || gender == "male" || gender == "M" || gender == "m")
        return "Male";
    else if (gender == "FEMALE" || gender == "Female" || gender == "female" || gender == "F" || gender == "f")
        return "Female";
    else
        return "";
}

bool isEmpty(string content)
{
    if (content.length() == 0)
        return true;
    return false;
}
