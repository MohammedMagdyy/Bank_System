#ifndef BANK_ACCOUNTT_H
#define BANK_ACCOUNTT_H

#include "STD_TYPES.h"
#include <stdbool.h>
#include <string.h>
#define Active 1
#define Closed 2
#define Restricted 3



struct Bank_Account_Data
{
    char Name[30];
    long long Password;
    u32 ID;   //constant for each
    char Address[60];//constant for each
    u32 Age;
    long long National_ID;
    long long Guardian_National_ID;
    char Account_Status;
    u32 balance;

};

/*
 *
 * DATA STRUCTURE
 *
 */

struct Clients_Linked_List
{

    struct Bank_Account_Data data;
    struct Clients_Linked_List *next;

};


/*                 BANK_ACCOUNT_FUNCTIONS                 */
void IntroPage();
static void Admin_Page();
static void Client_Page();
static int Exit_The_System();
static void Open_Existing_Account_Admins();
static void Open_Existing_Account_Clients();
static void Create_New_Account();
void Insert_Node(struct Clients_Linked_List *x);
struct Clients_Linked_List *Search_For_Client_ID(struct Clients_Linked_List *x,u32 ID);
struct Clients_Linked_List * Cheak_Client_ID(struct Clients_Linked_List *ptr);


/*                 OPERATION_FUNCTIONS                 */

//u16 Cheak_Number_Of_Digits( u8 * arr);
long long Generate_Password();
u8 Cheak_Name(u8 *arr);
bool hasExactly14Digits(long long number);
long long Cheak_Guardian_National_ID();
long long Cheak_National_ID();

void print();


#endif