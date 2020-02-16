#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
#include <ctype.h>
#include <algorithm>

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::setw;
using std::vector;

struct duomenys
{
    string vardas, pavarde;
    int n;  //namu darbu kiekis
    vector <int> p; //rodykle i masyvo pradzia
    int e;  //egzamino rezultatas
    double vid=0;   //vidurkis
    double med=0;   //mediana
    double gv,gm;
};

int main ()
{    srand ( time ( NULL ));

    int k;
     label1:
    cout << "Iveskite kiek zmoniu bus" << endl;
    cin>>k;
    while(cin.fail())      //jeigu ne int tipo
    {
        cout << "Klaida, turite ivesti skaiciu" << std::endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> k;
    }
    if (k<=0)
        goto label1;

    vector <duomenys> A;

    srand ( time ( NULL ));
    int var;


    for(int i=0; i<k; i++)
    {
        A.push_back(duomenys());
        std::cout << "Iveskite savo varda ir pavarde:" << endl;
        A.push_back(duomenys());
        cin >> A[i].vardas >> A[i].pavarde;

label:
        cout << "Iveskite namu darbu kieki:" << endl;
        cin >> A[i].n;
        while(cin.fail())      //jeigu ne int tipo
        {
            cout << "Klaida, turite ivesti skaiciu" << std::endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> A[i].n;
        }
        if (A[i].n<=0 )
        {
            cout << "Klaida! Turi buti bent vienas namu darbas"<< endl;    //jei 0 grizta atgal
            goto label;
        }


label2:
        cout << "Jei norite pats ivesti vertinimus parasykite 1, jei norite, kad pazymiai butu atsitiktinai generuojami parasykite 2" << endl;
        cin >> var;
        while(cin.fail())      //jeigu ne int tipo
        {
            cout << "Klaida, turite ivesti 1 arba 2" << std::endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> var;
        }
        if(var<1 or var>2)
        {
            cout << "Toks pasirinkimas negalimas" << endl;
            goto label2;
        }
        int b;
        if(var==1)
        {
            cout << "Iveskite namu darbu ivertinimus:" << endl;
            for(int j=0; j<A[i].n; j++)
            { cin >>b;
label3:         A[i].p.push_back(b);
                while(cin.fail())      //jeigu ne int tipo
                {
                    cout << "Klaida, turite ivesti skaiciu" << std::endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >>b;
                    A[i].p.push_back(b);}
                if ( b<1 or b>10)
                    goto label3;
            }
        }
        else
        {
            cout << "Sugeneruoti namu darbu ivertinimai yra:" <<endl;
            for(int j=0; j<A[i].n; j++)
            {
                b=  1 + ( double ) rand ()/ RAND_MAX*9;
                 A[i].p.push_back(b);
                cout <<A[i].p[j] << endl;
            }
        }

label5:
        cout << "Jei norite pats ivesti egzamino vertinima parasykite 1, jei norite, kad ivertinimas butu sugeneruotas atsitiktinai iveskite 2" << endl;
        cin >> var;
        while(cin.fail())      //jeigu ne int tipo
        {
            cout << "Klaida, turite ivesti 1 arba 2" << std::endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> var;
        }
        if(var<1 or var>2)
        {
            cout << "Toks pasirinkimas negalimas" << endl;
            goto label5;
        }

        if(var==1)
        {
            cout << "Iveskite egzamino ivertinima:" << endl;

label6:
            cin >> A[i].e;
            while(cin.fail())      //jeigu ne int tipo
            {
                cout << "Klaida, turite skaiciu" << std::endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> A[i].e;
            }
            if ( A[i].e<1 or A[i].e>10)
                goto label6;
        }

        else
        {
            cout << "Sugeneruotas egzamino rezultatas yra:" <<endl;
            A[i].e=  1 + ( double ) rand ()/ RAND_MAX*9;
            cout <<A[i].e << endl;
        }

    }
///vidurkis ir mediana
{
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<A[i].n; j++)
            A[i].vid+=A[i].p[j];
        A[i].vid/=A[i].n;
    }
    int laik;
    for(int z=0; z<k; z++)
    {
        for (int i = 0; i < A[z].n-1; i++)
            for (int j = i; j < A[z].n; j++)
                if(A[z].p[i]>A[z].p[j])
                {
                    laik=A[z].p[i];
                    A[z].p[i]=A[z].p[j];
                    A[z].p[j]=laik;
                }
    }

    for(int i=0; i<k; i++)
        if(A[i].n%2==0)
            A[i].med =(A[i].p[A[i].n/2-1]+A[i].p[A[i].n/2])/2.0;
        else
            A[i].med=A[i].p[A[i].n/2] ;
                for(int i=0; i<k; i++)
cout << A[i].vid << " " << A[i].med <<endl;
}

///GALUTINIS

{
    for(int i=0; i<k; i++)
    {
        A[i].gv=0.4*A[i].vid+0.6*A[i].e;
        A[i].gm=0.4*A[i].med+0.6*A[i].e;
    }

}

///    rasymas
   cout << "Pavarde" <<std::right << setw(20) << "Vardas" << std::right <<setw(20) << "VidGalutinis" << std::right << setw(20) << "MedGalutinis" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    for (int i=0; i<k; i++)
    {
        cout << A[i].pavarde << std::right << setw(20) << A[i].vardas << std::right << setw(20) << std::fixed << std::setprecision(2) << std::right << A[i].gv << setw(20) << std::right << A[i].gm << endl;
    }


    return 0;
}

