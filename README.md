Sukurta 2020-04-15, kuomet ginantis darbą supratau klaidas (kurios iš esmės buvo analizės trūkumas), tad jas ištaisiau. 
## [Versija V1.0](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V1.1) 
**Pirmoji strategija** (t.y. studentų išskaidymas į du tipus, tačiau taip pat jų palikimas pradiniame konteineryje) yra pateikiamas [nebaigtoje V1.0](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V1.0.0) versijoje, tačiau jo spartos analizę galiu pateikti ne visą, nes vykdant su daug duomenų, pritrūksta atminties vykdyti tokią programą. Tad akivaizdu, jog tai labai neefektyvus būdas. 
**Skirstymo ir spausdinimo greitis:**

|Konteineris| 1000  |10000    | 100000   |1000000      | 
| --------- |:-----:| :------:|:--------:| -----------:|
|Std::vector| 130 ms| 12481 ms| 210124 ms| 2459024 ms  | 
|Std::Deque | 60 ms | 5842 ms | 412857ms | 52847422 ms | 
|Std::List  | 24 ms | 221 ms  | 2510 ms  | 22840ms     | 



**Antroji strategija** (t.y. studentų perkėlimas tik į vieną naują konteinerį šalinat perkeltuosiuos iš pradinio konteinerio) buvo įvykdytas jau [V0.5](https://github.com/gabijabalionyt/2-uzduotis/releases/tag/V05), tad jos spartą galite pažiūrėti šiek tiek aukščiau esančiose lentelėse. 

 **Pirmoji strategija yra geresnė laiko atžvilgniu (tą sugebėjau pastebėti iš to, kiek failų sugeneravo prieš užlūžtant kompiuteriui), nes užtruka trumpiau, bet antroji yra žymiai geresnės atminties atžvilgiu. **

**Programos sparta naudojant antrąją strategiją, ir naudojant algoritmus( *std::remove_copy_if, std::remove_if*):**



**Skirstymo ir spausdinimo greitis naudojant antrą srategiją, lyginant STD::VECTOR veikimą su ir be algoritmų:**
|  Failo dydis  | 1000 |  10000 |  100000 | 1000000  |  10000000 |
| ------------- |:----:|:------:|:-------:|:--------:|----------:|
|Su algoritmais:|24 ms | 219  ms| 2508 ms | 24191 ms |492473  ms |
|Be algoritmų:  |165 ms|13415 ms|214515 ms|3985024 ms|41862459 ms|

Taigi, algoritmai programos veikimą pagrietino beveik net 90 kartų. 

Naudojamos įrangos spartai matuoti parametrai
|                   CPU                 | RAM  |SSD    |
| ------------------------------------- |:----:| -----:|
|Intel(R) Core(TM)i3-7020U CPU @ 2.30GHz| 4 GB | 256 GB| 
