# 2 uzduotis
## Programos tikslas
Programa nuskaito mokinio duomenis, paskaičiuoja galutinį studento pažymį naudojant vidurkį ir medianą.
Yra du versijos V0.1 [Releases]( https://github.com/gabijabalionyt/2-uzduotis/releases) vienas su vektoriais, kitas su dinaminiais masyvais, tačiau abu atlieka visiškai vienodą funkciją.
Nuo V0.2 versijos visi veiksmai yra atliekami tik su vektoriais bei atsiranda galimybė duomenis nuskaityti iš failo.
Nuo V0.4 yra galimybė generuoti atsitiktinius failus ir yra skaičiuojamas programos laikas.

## Įdiegimo ir naudojimosi instrukcija
• Norinti gauti programą pirmiausia reikia parsisiųsti vieną iš jos versijų iš [Releases](https://github.com/gabijabalionyt/2-uzduotis/releases) 

• Parsisiųsti ir įsirašyti kokią nors **C++** palaikančią programą (*codeblocks, visual studio ar kita*)

• Atsidaryti programos kodą viena iš parsisiųstų programų ir paleisti kodą.

• Programos naudojimasis bus paprastas, nes visi nurodymai bus parodomi ekrane.

## Programos realizacija
## [Versija V0.1](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V0%2C1 )

Šią programos versiją prašyta realizuoti dviem būdais: naudojant C tipo masyvą bei std::vector tipo konteinerį. Šioje vesrsijoje nuskaitomi studentų duomenys: vardas ir pavardė, namų darbų rezultatai (vartotojas gali pasirinkti, ar už namų darbus gauti pažymiai bus sugeneruoti atsitiktinai, ar vartotojas juos įves pats/pati) bei egzamino pažymys dešimtbalėje sistemoje. Galutinis studento pažymys apskaičiuojamas naudojant studento namų darbų pažymių vidurkį ir medianą. Įvykdžius programą, vartotojui pateikiama lentelė, kurioje atspausdinamas studento vardas, pavardė bei galutinis pažymys.

## [Versija V0.2](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V0.2)

Šioje programos versijoje tęsiama programos realizacija, kurioje buvo naudojamas std::vector tipo konteineris. Vartotojas pasirenka kokius duomenis naudoti - įvestus paties/pačios ar nuskaitytus iš tekstinio duomenų failo pavadinimu kursiokai.txt, kurio struktūra atrodo taip:

Vardas      Pavardė      ND1 ND2 ND3 ND4 ... NDn Egzaminas
Vardas1     Pavardė1     1   2   3   4       10  5
Vardas2     Pavardė2     2   3   4   5       5   10
...
Išvedant duomenis studentai išrikiuojami alfabetiškai pagal vardus.

## [Versija V0.3](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V0.3)

Programoje naudojamos funkcijos perkeltos į atskirą funkcijų failą pavadinimu **funkcijos.cpp**, o bibliotekos, funkcijų deklaracijos ir struktūra, kuri buvo naudojama ir ankstesnėse programos realizacijose, aprašyta **biblioteka.h** faile. Šioje versijoje kartą panaudojamas išimčių valdymas (angl. Exception Handling) try/catch - tikrinama, ar tekstinis duomenų failas *kursiokai.txt* egzistuoja.


***try
{
  if (!ReadFile.good())
      throw "Toks failas neegzistuoja."; 
}
catch (const char *Message)
{
      cout << Message << endl;
}***


Išvedant duomenis studentai rikiuojami alfabetiškai, tik šįkart pagal studentų pavardes.


## [Versija V0.4](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V0.4)

Šioje programos realizacijoje pridėta galimybė sugeneruoti penkis skirtingo dyžio failus, kuriuose studentų vardai ir pavardės pateikiami šabloniškai, o namų darbai bei jų kiekis sugeneruojami atsitiktinai. Sugeneruoti duomenų failai atrodo taip:

Vardas      Pavardė      Egzaminas ND1 ND2 ND3 ND4 ... NDn
Vardas1     Pavardė1     5         1   2   3   4       10
Vardas2     Pavardė2     10        2   3   4   5       5
...
Studentai, kurių galutinis balas mažesnis nei 5.0, įrašomi į Protingi.txt failą, egzaminą išlaikiusieji (gavę 5.0 ar daugiau) - į Kvaili.txt.

Atlikus spartos analizę, gaunami į apačioje pateiktą pavyzdį panašūs reluztatai:

File10.txt generavimas užtruko 1 ms.
Studentų skirstymas ir išvedimas užtruko 2 ms.
File100.txt generavimas užtruko 6 ms.
Studentų skirstymas ir išvedimas užtruko 7 ms.
File1000.txt generavimas užtruko 60 ms.
Studentų skirstymas ir išvedimas užtruko 356 ms.
...
