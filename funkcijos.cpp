#include "biblioteka.h"

double Vidurkis (vector<int> Grade, int n)
{
    int Sum = 0;

    for (int i = 0; i < n; i++)
        Sum += Grade[i];

    return 1.0*Sum/n;
}
double Mediana (vector<int> Grade, int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (Grade[j] < Grade[i])
                swap (Grade[j], Grade[i]);

    if (n%2 == 0)
        return 1.0*(Grade[n/2] + Grade[n/2-1])/2;
    else
        return 1.0*Grade[n/2];
}
//-----------------------------

bool AllLetters (string Input)  //patikrina ar visur raides
{
    for (int i = 0; i < Input.length(); i++)
    {
        int UppercaseCharacter = toupper(Input[i]); //Kad nereiketu tikrint ar didziosios ar mazosios

        if (UppercaseCharacter < 'A' || UppercaseCharacter > 'Z')
        {
            if (UppercaseCharacter != 32)
                return false;
        }
    }
    return true;
}
//-----------------------------

bool Digits (const string & str)    //patikrina ar skaiciai
{
    return all_of (str.begin(), str.end(), ::isdigit);
}
///-----------
void Conversion (string & Text) //pavercia string tezta i Aaaa  tipa
{
    if (islower(Text.at(0)))
        Text.at(0) = toupper (Text.at(0));

    for (int i = 1; i < Text.length(); i++)
        if (isupper(Text.at(i)))
            Text.at(i) = tolower (Text.at(i));
}

///-----------------------------
void NewLine () //kad palengvintu rasyma visur
{
    cout << endl;
}
void Rasymas (int Nr, vector<Student> S, int var)
{
    int var_il = 7,  //vardo ilgis
        pav_il = 9; //pavardes ilgis

    for (int i = 0; i <= Nr; i++)
    {
        if (var_il < S[i].vardas.length()+1)  //graziam isrikiavimui
            var_il = S[i].vardas.length()+1;
        if (pav_il < S[i].pavarde.length()+1)
            pav_il = S[i].pavarde.length()+1;
    }

    NewLine();
    printf("%*s", -var_il, "Vardas");
    printf("%*s", -var_il, "Pavarde");

    int ilgis = 20;
    if (var == 1)
        cout << " Galutinis (Vid.)" << endl;
    else if (var == 2)
        cout << " Galutinis (Med.)" << endl;
    else
    {
        cout << " Galutinis (Vid.) Galutinis (Med.)" << endl;
        ilgis = 33;
    }

    for (int i = 0; i < var_il+pav_il+ilgis; i++)
        printf("-");

    if (var == 1 || var == 2)
        for (int i = 0; i <= Nr; i++)
        {
            printf("\n%*s", -var_il, S[i].vardas.c_str());
            printf("%*s", -pav_il, S[i].pavarde.c_str());
            printf("%4.2f", S[i].gv);
        }

    else
    {
        int kiekis = 0;

        while (kiekis != Nr+1)
        {
            printf("\n%*s", -var_il, S[kiekis].vardas.c_str());
            printf("%*s", -pav_il, S[kiekis].pavarde.c_str());
            printf("%-17.2f", S[kiekis].gv);
            printf("%-17.2f", S[kiekis].gm);
            kiekis++;
        }
    }
}
//-----------------------------
//-----------------------------
void Rikiavimas (vector<Student> S, int Nr) //rikiavimas
{
    sort(S.begin(), S.end(), [](const Student &lhs, const Student &rhs)
    {
        if (lhs.vardas != rhs.vardas)
            return lhs.vardas < rhs.vardas;
        else
            return lhs.pavarde < rhs.pavarde;
    });

    Rasymas (Nr, S, 3);
}
//-----------------------------


void versija1 (vector <Student> &S )
{
    {
        int vari;
        string Entry;
        int Nr =-1;
        NewLine();
        string var,pav;
        cout << "Kaip norite apskaiciuoti studento galutini pazymi?\nSpauskite 1, jei norite, jog butu naudojamas studento rezultatu vidurkis,\n2, jei norite, jog butu naudojama mediana." << endl;

        while (true)
        {
            cin >> Entry;

            if (Entry == "1")
            {
                vari = 1;
                break;
            }
            else if (Entry == "2")
            {
                vari = 2;
                break;
            }
            else
                cout << Error << endl;
        }
        cin.ignore();

        while (true)
        {
            NewLine();
            cout << "Iveskite " << Nr + 2 << "-o studento varda bei pavarde, pavyzdziui, Vardenis Pavardenis, baige paspauskite Enter" << endl;
            getline (cin, Entry);

            if(!Entry.empty())
            {
                int Position = Entry.find(" "); //atskiriam varda nuo pavardes

                if(Entry.length()-1 > Position && AllLetters(Entry) == true)
                {
                    S.push_back(Student());
                    Nr++;
                    S[Nr].vardas = Entry.substr(0, Position);
                    Conversion (S[Nr].vardas);
                    S[Nr].pavarde = Entry.substr(Position+1);
                    Conversion(S[Nr].pavarde);
                    NewLine();

                    cout << "Kokiu formatu bus pateikiami studento namu darbu rezultatai?\nSpauskite 1, jei rezultatus ivesite Jus,\n2, jei norite, jog duomenys butu sugeneruoti atsitiktinai." << endl;

                    int Kiekis = 0;
                    vector <int> Pazymiai;

                    while(true)
                    {
                        cin >> Entry;

                        if (Entry == "1")
                        {
                            NewLine();
                            cout << "Veskite skaièius nuo 1-o iki 10-ies, norëdami baigti vedimà áveskite bet koká kità skaièiø." << endl;
                            while (true)
                            {
                                cin >> Entry;

                                if (Digits(Entry) == true)
                                {
                                    int Pazymys = stoi(Entry);

                                    if (Pazymys > 0 && Pazymys < 11)
                                    {
                                        Pazymiai.push_back(int());
                                        Pazymiai[Kiekis] = Pazymys;
                                        Kiekis++;
                                    }

                                    else
                                    {
                                        if (Kiekis != 0)
                                            break;
                                        else
                                            cout << "Iveskite skaiciu." << endl;
                                    }
                                }
                                else
                                    cout << Error << endl;
                            }
                            break;
                        }

                        if (Entry == "2")
                        {
                            NewLine();
                            cout << "Kiek skaiciu generuoti?" << endl;
                            while (true)
                            {
                                cin >> Entry;

                                if (Digits(Entry) == true)
                                {
                                    int Pazymys = stoi(Entry);

                                    if (Pazymys > 0)
                                    {
                                        for (int i = 0; i < Pazymys; i++)
                                        {
                                            Pazymiai.push_back(int());
                                            Pazymiai[Kiekis] = int(round(1+1.0*rand()/RAND_MAX*10));
                                            Kiekis++;
                                        }
                                        break;
                                    }
                                    else
                                    {
                                        if (Kiekis != 0)
                                            break;
                                        else
                                            cout << "Truksta duomenu." << endl;
                                    }
                                }
                                else
                                    cout << Error << endl;
                            }
                            break;
                        }
                        else
                        {
                            cin.ignore();
                            cin.clear();
                            cout << Error << endl;
                        }
                    }
                    NewLine();
                    cout << "Iveskite studento egzamino rezultata:" << endl;
                    int Exam;

                    while (true)
                    {
                        string EntryString;
                        cin >> EntryString;
                        int    Entry;

                        if (Digits(EntryString) == false)
                            Entry = -1;
                        else
                            Entry = stoi(EntryString);

                        if (Entry < 0 || Entry > 10)
                            cout << Error << endl;
                        else
                        {
                            Exam = Entry;
                            break;
                        }
                    }
                    double Av;

                    if (vari == 1)
                        Av = Vidurkis(Pazymiai, Kiekis);
                    else
                        Av = Mediana(Pazymiai, Kiekis);

                    S[Nr].gv = 1.0*(0.4*Av+0.6*Exam);
                    cin.ignore();
                    cin.clear();
                }
                else
                    cout << Error << endl;
            }

            else
            {
                if (Nr == -1)
                    cout << "Iveskite bent vieno studento duomenis." <<  endl;
                else
                {
                    Rasymas(Nr, S, vari);
                    break;
                }
            }
        }
    }
}




void versija2 (vector <Student> &S)
{
    {
        string  EntryLine,
                Var,
                Pav, Entry;
        int  Nr = -1;
        ifstream ReadFile ("kursiokai.txt");
         try
        {
            if (!ReadFile.good())
                throw "Toks failas neegzistuoja.";
        }
        catch(const char *Message)
        {
            cout << Message << endl;
        }
        {
            while (getline (ReadFile, EntryLine))
            {
                S.push_back(Student());
                istringstream ReadLine(EntryLine);
                ReadLine >> Var >> Pav;

                //if (AllLetters(Var) && AllLetters(Pav))
                {
                    Nr++;
                    S[Nr].vardas = Var;
                    S[Nr].pavarde = Pav;
                    Conversion (S[Nr].vardas);
                    Conversion (S[Nr].pavarde);

                    int Kiekis = 0;
                    vector <int> Pazymiai;

                    while (ReadLine >> Entry)
                    {
                        if (Digits(Entry))
                        {
                            int Pazymys = stoi (Entry);

                            if (Pazymys > 0 && Pazymys <11)
                            {
                                Pazymiai.push_back(int());
                                Pazymiai[Kiekis] = Pazymys;
                                Kiekis++;
                            }
                        }
                    }
                    ReadLine.end;

                    int Exam = 0;

                    if (Kiekis > 0)
                    {
                        Exam = Pazymiai[Kiekis-1];
                        S[Nr].gv = 1.0*(0.4*Vidurkis(Pazymiai, Kiekis-1)+0.6*Exam);
                        S[Nr].gm = 1.0*(0.4*Mediana(Pazymiai, Kiekis-1)+0.6*Exam);
                    }

                    else
                        cout << Error << endl;
                }
            }
            if (Nr > -1)
                Rikiavimas (S, Nr);
            else
            {
                NewLine();
                cout << "Failas yra tuscias arba duomenys suvesti netinkamai, bandykite dar karta." << endl;
            }
        }

        ReadFile.end;
    }
}

//-----------------------------

int pasirinkimas ()
{
    int var;
    cout << "Ar norite duomenis suvesti pats( iveskite 1) ar norite, kad jie butu nuskaityti is failo (iveskite 2)?" << endl;
label:
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
        cout << "Toks pasirinkimas negalimas, iveskite 1 arba 2" << endl;
        goto label;
    }
    return var;
}
