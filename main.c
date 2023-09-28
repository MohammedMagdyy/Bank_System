#include "Bank_Accountt.h"

int main()
{
    struct Clients_Linked_List d;
    strcpy(d.data.Name,"Mohammed Ali Ahmed Sameh");
    strcpy(d.data.Address,"Cairo Egypt");
    d.data.balance=1000;
    d.data.Age=30;
    d.data.ID=8888;
    d.data.Password=1234567891;
    d.data.Account_Status=Active;

    Insert_Node(&d);

    strcpy(d.data.Name,"Ali Ali Ahmed Ja3fr");
    strcpy(d.data.Address,"Alex Egypt");
    d.data.balance=15000;
    d.data.Age=50;
    d.data.ID=1885;
    d.data.Password=1234567899;
    d.data.Account_Status=Active;

    Insert_Node(&d);

IntroPage();



    return 0;
}