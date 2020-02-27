#include "biblioteka.h"


int main ()

{
    srand (time(NULL));
    vector <Student> S;
    if(pasirinkimas()==1)
        versija1(S);
    else
        versija2 (S);
    return 0;
}


