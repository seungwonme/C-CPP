#include <iostream>

typedef struct USERDATA
{
    int age;
    char name[32];
} USERDATA;

void printUserData(USERDATA* pUser)
{
    printf("%d, %s\n", pUser->age, pUser->name);
}

int main()
{
    USERDATA* pNewUser = new USERDATA;
    pNewUser->age = 10;
    strlcpy(pNewUser->name, "Hoon", sizeof(pNewUser->name));

    printUserData(pNewUser);
    return 0;
}
