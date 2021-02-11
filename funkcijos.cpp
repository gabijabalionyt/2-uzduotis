#include "biblioteka.h"

/*vidurkis*/
//-----------------------------
double Average (vector<int> Grade)
{
    if (Grade.size() == 0)
        throw std::domain_error ("Skai�iavim� atlikti negalima. �veskite duomenis.");

    return std::accumulate (Grade.begin(), Grade.end(), 0.0)/Grade.size();
}
//-----------------------------

/*mediana*/
//-----------------------------
double Median (vector<int> Grade)
{
    typedef vector <int>::size_type VecSize;
    VecSize size = Grade.size();

    if (size == 0)
        throw std::domain_error ("Skai�iavim� atlikti negalima. �veskite duomenis.");

    sort (Grade.begin(), Grade.end());

    VecSize Middle = size / 2;

    if (size % 2 == 0)
        return (Grade[Middle-1] + Grade[Middle])/2;
    else
        return Grade[Middle];
}
//-----------------------------

//-----------------------------

/*apskai�iuojamas galutinis pa�ymys*/
//-----------------------------
double FinalMark (double Exam, double Score)
{
    return 0.4 * Score + 0.6 * Exam;
}
//-----------------------------
double FinalMark (double Exam, const vector<int> & Homework)
{
    if (Homework.size() == 0)
        throw std::domain_error("Studentas neatliko n� vieno nam� darbo.");
    return FinalMark (Exam, Average(Homework));
}
//-----------------------------
double FinalMark (const Student& S, double (*Criteria)(vector<int>))
{
    return FinalMark(S.Exam, Criteria(S.Results));
}
//-----------------------------

/*tikrinama, ar �vestos/nuskaitomos
TIK raid�s*/
//-----------------------------
bool AllLetters (string Input)
{
    for (int i = 0; i < Input.length(); i++)
    {
        int UppercaseCharacter = toupper(Input[i]);

        if (UppercaseCharacter < 'A' || UppercaseCharacter > 'Z')
        {
            if (UppercaseCharacter != 32)
                return false;
        }
    }
    return true;
}
//-----------------------------

/*tikrinama, ar �vesti/nuskaitomi
TIK skai�iai*/
//-----------------------------
bool Digits (const string & str)
{
    return all_of (str.begin(), str.end(), ::isdigit);
}
//-----------------------------

/*gra�iam pateikimui - student� vardai
bus pateikiami i� did�i�j� raid�i�,
net jeigu �vedimo/nuskaitymo
atveju �ie studento duomenys buvo �vesti
ma�osiomis raid�mis*/
//-----------------------------
void Conversion (string & Text)
{
    if (islower(Text.at(0)))
        Text.at(0) = toupper (Text.at(0));

    for (int i = 1; i < Text.length(); i++)
        if (isupper(Text.at(i)))
            Text.at(i) = tolower (Text.at(i));
}
//-----------------------------

/*lygina student� pavardes rikiavimui*/
//----------------------------
bool CompareSurnames (const Student& x, const Student& y)
{
    return x.Surname < y.Surname;
}
//-----------------------------

/*nauja eilut�*/
//-----------------------------
void NewLine ()
{
    cout << endl;
}
//-----------------------------

/*fail� generavimo funkcija*/
//-----------------------------
void GenerateFiles (size_t Value)
{
//    atsitiktini� skai�i� generavimui
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    std::uniform_int_distribution <int> Interval (1, 10), Amount(10, 20);

    int NumberOfStudents = Value,
        AmountOfResults = Amount(eng);

    std::ofstream Write;
    Write.open("File" + std::to_string(Value) + ".txt");

    for (size_t j = 1; j <= NumberOfStudents; j++)
    {
        Write << "Vardas" + std::to_string(j) << " Pavard�" + std::to_string(j) << " " << Interval(eng);   //egzamino pa�ymys �ra�omas PRIE� nam� darb� rezultatus

        vector <int> Results;
        vector <int>::iterator IT;

        for (size_t k = 0; k < AmountOfResults; k++)
            Results.push_back(Interval(eng));

        for (IT = Results.begin(); IT < Results.end(); IT++)
            Write << " " << *IT;

        Write << endl;
    }
    Write.close();
}
int pasirinkimas ()
{
    int var;
    cout << "Ar norite duomenis suvesti pats( iveskite 1) ar norite, kad jie butu nuskaityti is failo (iveskite 2), ar norite generuoti 5 tekstinius failus (iveskite 3)" << endl;
label:
    cin >> var;

    while(cin.fail())      //jeigu ne int tipo
    {
        cout << "Klaida, turite ivesti 1 arba 2 arba 3" << std::endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> var;
    }
    if(var<1 or var>3)
    {
        cout << "Toks pasirinkimas negalimas, iveskite 1 arba 2 arba 3" << endl;
        goto label;
    }
    return var;
}

