#include "biblioteka.h"

int main()
{
    /*atsitiktinių skaičių generavimui*/
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    std::uniform_int_distribution <int> dist (1, 10);

    vector <Student> S;
    Student StudentObject;
    string Entry;
    int EntryChoice;
    string::size_type LongestName = 0,
                      LongestSurname = 0;

 EntryChoice=  pasirinkimas();

    if (EntryChoice == 1)
    {
        int AverageChoice;

        NewLine();
 cout << "Kaip norite apskaiciuoti studento galutini pazymi?\nSpauskite 1, jei norite, jog butu naudojamas studento rezultatu vidurkis,\n2, jei norite, jog butu naudojama mediana." << endl;

        while (cin >> Entry)
        {
            if (Entry == "1")
            {
                AverageChoice = 1;
                break;
            }
                else if (Entry == "2")
                {
                    AverageChoice = 2;
                    break;
                }
                    else
                        cout << Error << endl;
        }
        cin.ignore();

        while (true)
        {
            NewLine();
            cout << "Iveskite " << S.size() + 1 << "-o studento varda bei pavarde, pavyzdziui, Vardenis Pavardenis, baige paspauskite Enter" << endl;
            getline (cin, Entry);

            if(!Entry.empty())
            {
                int Position = Entry.find(" ");

                if(Entry.length()-1 > Position && AllLetters(Entry) == true)
                {
                    StudentObject.Name = Entry.substr(0, Position);
                    LongestName = max(LongestName, StudentObject.Name.length());
                    Conversion(StudentObject.Name);
                    StudentObject.Surname = Entry.substr(Position + 1);;
                    LongestSurname = max(LongestSurname, StudentObject.Surname.length());
                    Conversion(StudentObject.Surname);
                    NewLine();

                    cout << "Kokiu formatu bus pateikiami studento namu darbu rezultatai?\nSpauskite 1, jei rezultatus ivesite Jus,\n2, jei norite, jog duomenys butu sugeneruoti atsitiktinai." << endl;

                    while(cin >> Entry)
                    {
                        if (Entry == "1")
                        {
                            StudentObject.Results.clear();
                            cout << "Veskite skaièius nuo 1-o iki 10-ies, noredami baigti vedima iveskite bet koki kita skaiciu." << endl;
                            while (cin >> Entry)
                            {
                                if (Digits(Entry) == true)
                                {
                                    int Mark = stoi(Entry);

                                    if (Mark > 0 && Mark < 11)
                                        StudentObject.Results.push_back(Mark);

                                    else
                                    {
                                        if (StudentObject.Results.size() != 0)
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
                        else if (Entry == "2")
                        {
                            StudentObject.Results.clear();
                            cout << "Kiek skaiciu generuoti?" << endl;

                            while (cin >> Entry)
                            {
                                if (Digits(Entry) == true)
                                {
                                    int Mark = stoi(Entry);

                                    if (Mark > 0)
                                    {
                                        for (int i = 0; i < Mark; i++)
                                            StudentObject.Results.push_back(dist(eng));
                                        break;
                                    }
                                        else
                                        {
                                            if (StudentObject.Results.size() != 0)
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
                    cout << "Iveskite studento egzamino rezultata:" << endl;

                    string EntryString;

                    while (cin >> EntryString)
                    {
                        int Entry;

                        if (Digits(EntryString) == false)
                            Entry = -1;
                            else
                                Entry = stoi(EntryString);

                        if (Entry < 0 || Entry > 10)
                            cout << Error << endl;
                            else
                            {
                                StudentObject.Exam = Entry;
                                break;
                            }
                    }

                    S.push_back(StudentObject);
                    sort (S.begin(), S.end(), CompareSurnames);

                    cin.ignore();
                    cin.clear();
                }
                else
                    cout << Error << endl;
            }

            else
            {
                if (S.size() == 0)
                    cout << "Iveskite bent vieno studento duomenis." <<  endl;


                    else
                    {auto Start = std::chrono::high_resolution_clock::now();
                    auto StartSorting = std::chrono::high_resolution_clock::now();
            vector<Student> Failed;
              std::remove_copy_if (S.begin(), S.end(), std::back_inserter(Failed), Pass);
            S.erase(std::remove_if(S.begin(), S.end(), Fail), S.end());

            //neišlaikiusieji
            std::ofstream WriteToFailed;
            WriteToFailed.open("Failed.txt");

            for (vector<Student>::iterator IT = Failed.begin(); IT != Failed.end(); IT++)
            {
                WriteToFailed << (*IT).Name << string(LongestName + 1 - (*IT).Name.size(), ' ');
                WriteToFailed << (*IT).Surname << string(LongestSurname + 1 - (*IT).Surname.size(), ' ');

                streamsize prec = cout.precision();
            if (AverageChoice==1)    WriteToFailed << std::fixed << setprecision(2) << FinalMark ((*IT), Average)  << setprecision(prec) << endl;
            else  WriteToFailed << std::fixed << setprecision(2) << FinalMark ((*IT), Median)   << setprecision(prec) << endl;

            }
            for (auto i = 0; i != LongestName + LongestSurname + 10; i++)
            WriteToFailed << endl;
            WriteToFailed.close();

            //išlaikiusieji
            std::ofstream WriteToPassed;
            WriteToPassed.open("Passed.txt");

            for (vector<Student>::iterator IT = S.begin(); IT != S.end(); IT++)
            {
                WriteToPassed << (*IT).Name << string(LongestName + 1 - (*IT).Name.size(), ' ');
                WriteToPassed << (*IT).Surname << string(LongestSurname + 1 - (*IT).Surname.size(), ' ');

                streamsize prec = cout.precision();
               if (AverageChoice==1)    WriteToPassed << std::fixed << setprecision(2) << FinalMark ((*IT), Average)  << setprecision(prec) << endl;
            else  WriteToPassed << std::fixed << setprecision(2) << FinalMark ((*IT), Median)   << setprecision(prec) << endl;
              }
            for (auto i = 0; i != LongestName + LongestSurname + 10; i++)
            WriteToPassed << endl;
            WriteToPassed.close();

            auto EndSorting = std::chrono::high_resolution_clock::now();
            cout << "Studentu skirstymas ir isvedimas uztruko " << std::chrono::duration_cast<std::chrono::milliseconds>(EndSorting - StartSorting).count() << " ms."<< endl;


                        break;
                    }
            }
        }
    }

    else if (EntryChoice == 2)
    {
        string Name,
               Surname,
               ExamScore,
               EntryLine;

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
auto Start = std::chrono::high_resolution_clock::now();

        while (getline (ReadFile, EntryLine))
        {  auto Start = std::chrono::high_resolution_clock::now();

            istringstream ReadLine(EntryLine);
            ReadLine >> Name >> Surname >> ExamScore;

            if (/*AllLetters(Name) && AllLetters(Surname) &&*/ Digits(ExamScore))
            {
                StudentObject.Name = Name;
                LongestName = max(LongestName, StudentObject.Name.length());
                Conversion(StudentObject.Name);
                StudentObject.Surname = Surname;
                LongestSurname = max(LongestSurname, StudentObject.Surname.length());
                Conversion(StudentObject.Surname);
                StudentObject.Exam = stoi(ExamScore);

                if (ReadLine)
                {
                    StudentObject.Results.clear();

                    while (ReadLine >> Entry)
                    {
                        if (Digits(Entry))
                        {
                            int Mark = stoi(Entry);

                            if (Mark > 0 &&  Mark < 11)
                                StudentObject.Results.push_back(Mark);
                        }
                    }

                    S.push_back(StudentObject);
                    ReadLine.clear();
                }
                ReadLine.end;

            }
            else
                cout << Error << endl;
                  } auto End = std::chrono::high_resolution_clock::now();
                cout << "Duomenu skaitymas uztruko: "<< std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count()<<"ms" << endl;


                    sort (S.begin(), S.end(), CompareSurnames);
 auto StartSorting = std::chrono::high_resolution_clock::now();
            vector<Student> Failed;

             std::remove_copy_if (S.begin(), S.end(), std::back_inserter(Failed), Pass);
            S.erase(std::remove_if(S.begin(), S.end(), Fail), S.end());


            //neišlaikiusieji
            std::ofstream WriteToFailed;
            WriteToFailed.open("Failed.txt");

            for (vector<Student>::iterator IT = Failed.begin(); IT != Failed.end(); IT++)
            {
                WriteToFailed << (*IT).Name << string(LongestName + 1 - (*IT).Name.size(), ' ');
                WriteToFailed << (*IT).Surname << string(LongestSurname + 1 - (*IT).Surname.size(), ' ');

                streamsize prec = cout.precision();
             WriteToFailed << std::fixed << setprecision(2) << FinalMark ((*IT), Average)  << " " << FinalMark ((*IT), Median) << setprecision(prec) << endl;
            }
            for (auto i = 0; i != LongestName + LongestSurname + 10; i++)
                WriteToFailed << "-";
            WriteToFailed << endl;
            WriteToFailed.close();

            //išlaikiusieji
            std::ofstream WriteToPassed;
            WriteToPassed.open("Passed.txt");

            for (vector<Student>::iterator IT = S.begin(); IT != S.end(); IT++)
            {
                WriteToPassed << (*IT).Name << string(LongestName + 1 - (*IT).Name.size(), ' ');
                WriteToPassed << (*IT).Surname << string(LongestSurname + 1 - (*IT).Surname.size(), ' ');

                streamsize prec = cout.precision();
                WriteToPassed << std::fixed << setprecision(2) << FinalMark ((*IT), Average)  << " " << FinalMark ((*IT), Median) << setprecision(prec) << endl;
            }
            for (auto i = 0; i != LongestName + LongestSurname + 10; i++)
                WriteToPassed << "-";
            WriteToPassed << endl;
            WriteToPassed.close();

            auto EndSorting = std::chrono::high_resolution_clock::now();
            cout << "Studentu skirstymas ir isvedimas uztruko " << std::chrono::duration_cast<std::chrono::milliseconds>(EndSorting - StartSorting).count() << " ms."<< endl;


        ReadFile.end;
    }

    if (EntryChoice == 3)
    {
         for (size_t i = 1000; i <= 10000000; i *= 10)
        {
            S.clear();

            auto Start = std::chrono::high_resolution_clock::now();
   unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    std::uniform_int_distribution <int> Interval (1, 10), Amount(10, 20);

    int NumberOfStudents = i,
        AmountOfResults = Amount(eng);

    std::ofstream Write;
    Write.open("File" + std::to_string(i) + ".txt");

    for (size_t j = 1; j <= NumberOfStudents; j++)
    {
        Write << "Vardas" + std::to_string(j) << " Pavarde" + std::to_string(j) << " " << Interval(eng);   //egzamino pažymys įrašomas PRIEŠ namų darbų rezultatus

        vector <int> Results;
        vector <int>::iterator IT;

        for (size_t k = 0; k < AmountOfResults; k++)
            Results.push_back(Interval(eng));

        for (IT = Results.begin(); IT < Results.end(); IT++)
            Write << " " << *IT;

        Write << endl;
    }
    Write.close();
           auto End = std::chrono::high_resolution_clock::now();
            cout << "File" + std::to_string(i) + ".txt generavimas uztruko " << std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count() << " ms."<< endl;
            S.clear();

            string Name,
                   Surname,
                   ExamScore,
                   EntryLine;

            ifstream ReadFile ("File" + std::to_string(i) + ".txt");

            try
            {
                if (!ReadFile.good())
                    throw "Toks failas neegzistuoja.";
            }
            catch(const char *Message)
            {
                cout << Message << endl;
            }

            while (getline (ReadFile, EntryLine))
            {
                istringstream ReadLine(EntryLine);
                ReadLine >> Name >> Surname >> ExamScore;

                StudentObject.Name = Name;
                LongestName = max(LongestName, StudentObject.Name.length());
                StudentObject.Surname = Surname;
                LongestSurname = max(LongestSurname, StudentObject.Surname.length());
                StudentObject.Exam = stoi(ExamScore);

                if (ReadLine)
                {
                    StudentObject.Results.clear();

                    while (ReadLine >> Entry)
                    {
                        if (Digits(Entry))
                        {
                            int Mark = stoi(Entry);

                            if (Mark > 0 &&  Mark < 11)
                                StudentObject.Results.push_back(Mark);
                        }
                    }
                    S.push_back(StudentObject);
                    ReadLine.clear();
                }
                ReadLine.end;
            }

            auto StartSorting = std::chrono::high_resolution_clock::now();
            vector<Student> Failed;
             std::remove_copy_if (S.begin(), S.end(), std::back_inserter(Failed), Pass);
            S.erase(std::remove_if(S.begin(), S.end(), Fail), S.end());


            //neišlaikiusieji
            std::ofstream WriteToFailed;
            WriteToFailed.open("Failed" + std::to_string(i) + ".txt");

            for (vector<Student>::iterator IT = Failed.begin(); IT != Failed.end(); IT++)
            {
                WriteToFailed << (*IT).Name << string(LongestName + 1 - (*IT).Name.size(), ' ');
                WriteToFailed << (*IT).Surname << string(LongestSurname + 1 - (*IT).Surname.size(), ' ');

                streamsize prec = cout.precision();
                WriteToFailed << std::fixed << setprecision(2) << FinalMark ((*IT), Average)  << " " << FinalMark ((*IT), Median) << setprecision(prec) << endl;
            }
            for (auto i = 0; i != LongestName + LongestSurname + 10; i++)
                WriteToFailed << "-";
            WriteToFailed << endl;
            WriteToFailed.close();

            //išlaikiusieji
            std::ofstream WriteToPassed;
            WriteToPassed.open("Passed" + std::to_string(i) + ".txt");

            for (vector<Student>::iterator IT = S.begin(); IT != S.end(); IT++)
            {
                WriteToPassed << (*IT).Name << string(LongestName + 1 - (*IT).Name.size(), ' ');
                WriteToPassed << (*IT).Surname << string(LongestSurname + 1 - (*IT).Surname.size(), ' ');

                streamsize prec = cout.precision();
                WriteToPassed << std::fixed << setprecision(2) << FinalMark ((*IT), Average)  << " " << FinalMark ((*IT), Median) << setprecision(prec) << endl;
            }
            for (auto i = 0; i != LongestName + LongestSurname + 10; i++)
                WriteToPassed << "-";
            WriteToPassed << endl;
            WriteToPassed.close();

            auto EndSorting = std::chrono::high_resolution_clock::now();
            cout << "Studentu skirstymas ir isvedimas uztruko " << std::chrono::duration_cast<std::chrono::milliseconds>(EndSorting - StartSorting).count() << " ms."<< endl;
        }
    }
    return 0;
}
