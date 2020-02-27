# 2 uzduotis
## Programos tikslas
Programa nuskaito mokinio duomenis, paskaičiuoja galutinį studento pažymį naudojant vidurkį ir medianą.
Yra du versijos V0.1 [Releases]( https://github.com/gabijabalionyt/2-uzduotis/releases) vienas su vektoriais, kitas su dinaminiais masyvais, tačiau abu atlieka visiškai vienodą funkciją.
Nuo V0.2 versijos visi veiksmai yra atliekami tik su vektoriais bei atsiranda galimybė duomenis nuskaityti iš failo.


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
