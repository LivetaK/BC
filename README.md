<h1><b>V0.2</b></h1>

***
<h2>Pseudokodas</h2>

1. Programa priima string tipo kintamąjį;
2. Verčia jį į dvejetainę sistemą, naudodama bitų rinkinius po 8;
3. Dvejetainis kodas perduodamas funkcijai, kuri iš pradžių kodą "apverčia" (angl. reverse);
4. Tada funkcija kodą siunčia į kitą - tikrinimo funkciją, kuri bitus sudedama arba pridedama, paverčia dvejetainį kodą visuomet tokio paties ilgio kodu - 256 ilgio;
5. Tada kodas grąžinamas į manipuliavimo funkciją ir ten keičiamas su sudėjimo funkcija, su iš anksčiau sugeneruotais raktais;
6. Pakeistas kodas verčiamas į dešimtainę sistemą;
7. Tada kodas siunčiamas į funkciją "skaičiavimai", kuri kodą, kuris yra minimum 64 ir maximum 128 skaitnų ilgio atitinkamai suskirsto į dalis, kuriose yra 9 ar mažiau skaitmenys, kodėl taip daroma, bus paaiškinta vėliau;
8. Kai kodas yra suskirstyutas į dalis, dalys yra tarpusavyje dauginamos, jei dalių skaičius yra lyginis, tada kodas tarsi dalinamas per pusę ir pirma dalis yra dauginama su kita pirmąja dalimi, jei dalių skaičius yra nelyginis, dauginimo principas išlieka tas pats, tačiau galinę dalį dar padauginame iš pačios pirmosios;
9. PVZ.: Dalių skaičius - 8. 1 dalis dauginama su 5, 2 dalis dauginama su 6 ir t.t..Dalių skaičius - 9. 1 dalis dauginama su 5, 2 dalis dauginama su 6 ir t.t., lieka 9 dalis, todėl vėl paimame pirmąją dalį ir ją dauginame su devintaja;
10. Viską verčiame ir kliojuojame į stringą;
11. Kodėl būtina buvo suskirstyti po maksimum 9 skaitmenis? Todėl, kad int tipo kintamasis priima maksimum 10 skaitmenų, kurių maksimumas nėra 9 999 999 999, todėl, apsisaugodami skaitmenų skaičių sumažiname vientu. Beje, sudaugindami su didžiausius int tipo skaičius, mes nepasieksime unsigned long long ribos, todėl galime drąsiai tai daryti;
12. Po šių veiksmų kodas vėl yra verčiamas į dvejetainė sistemą (bitset<8>);
13. Kodu yra manipuliuojama, tai yra, jis vėl yra skirstomas į dalis, tos dalys tarpusavyje maišomos, rotate'inamos, apverčiamos ir kodas susiklijuoja į vientisą;
14. Galiausiai kodas yra paverčiamas į šešioliktainę sistemą, tačiau vienam šešioliktainės sistemos simboliui yra naudojami 4 bitai, ne 8;
15. Hash visuomet gaunasi tokio paties ilgio, dėka tikrinimo funkcijos, nes 256 / 4 = 64.

PRADŽIA
Įvestis: string s;  
DvejetainisKodas<8> <- s;  
DvejetainisKodas <- apversti(DvejetainisKodas);  
DvejetainisKodas256 <- tikrinimas(DvejetainisKodas);  
PakeistasDvejetainisKodas256 <- DvejetainisKodas256 + raktai;  
DešimtainisKodas <- PakeistasDvejetainisKodas256;  
DaliųSąrašas <- padalinti_į_dalis(DešimtainisKodas, maksimalus_skaitmenų_skaičius = 9);  
Jeigu DešimtainisKodas mod 9 = 0 {  
	PusėIlgio <- ilgis(DaliųSąrašas) / 2;  
	Ciklui i nuo 0 iki (PusėIlgio - 1):  
		NaujaDalis[i] <- DaliųSąrašas[i] * DaliųSąrašas[i + PusėIlgio];  
} Kitu atveju {  
	PusėIlgio <- ilgis(DaliųSąrašas) / 2;  
	Ciklui i nuo 0 iki (PusėIlgio - 1):  
		NaujaDalis[i] <- DaliųSąrašas[i] * DaliųSąrašas[i + PusėIlgio];  
	NaujaDalis[PusėIlgio] <- DaliųSąrašas[0] * DaliųSąrašas[-1]; 
}  
PakeistasDešimtainisKodas <- sujungti_dalis(NaujaDalis);  
DvejetainisKodas<8> <- PakeistasDešimtainisKodas;  
rotuoti arba apversti(padalinti_į_dalis(DvejetainisKodas<8>));  
Versti_į ŠešioliktainisKodas;  
Hash <- ŠešioliktainisKodas;  
PABAIGA


***

<h2><b>Testavimas</b></h2>

<h3>Mano sugeneruoti failai: </h3>

![Screenshot 2024-10-03 200803](https://github.com/user-attachments/assets/a289f5c7-4f34-4733-a9d3-36b5db4fa305)
![Screenshot 2024-10-03 200820](https://github.com/user-attachments/assets/b6a0a22a-011d-4d96-a112-c8b068c6933d)
![Screenshot 2024-10-03 200829](https://github.com/user-attachments/assets/13767260-07f1-4dc0-9da1-aa8450dbe2a4)
![Screenshot 2024-10-03 200838](https://github.com/user-attachments/assets/b0454554-2fe4-4d29-8b8e-1a5d76114057)
![Screenshot 2024-10-03 200852](https://github.com/user-attachments/assets/8e08f11c-580e-42f6-842f-5b859c257160)
![Screenshot 2024-10-03 200901](https://github.com/user-attachments/assets/e3a4b6d8-f817-43df-bc6f-ae988d65f3de)

<h3> Testavimas su konstitucija.txt </h3>

![Screenshot 2024-10-03 203704](https://github.com/user-attachments/assets/51eef497-4854-46f8-8484-14b56db34feb)

<h3> Testavimas su atsitiktinėmis poromis </h3>

Testavusi failą su atsitiktinėmis poromis išsiaiškinau, kad kolizijų kaip ir nėra:

![Screenshot 2024-10-03 221100](https://github.com/user-attachments/assets/4b4bbefb-d483-41b7-9a5d-340d032f5f47)

Tačiau, testavusi failą su poromis, tarp kurių skiriasi tik vienas simbolis, išsiaiškinau, kad kolizijų vis dėlto yra:

![image](https://github.com/user-attachments/assets/cd404ce7-8e9d-4cb4-a546-211e1b86899d)


<h3>PALYGINIMAS</h3>

![Screenshot 2024-10-03 205514](https://github.com/user-attachments/assets/a5ae1535-7ad9-4611-a8d2-048fc4df5ec9)

<h2>Išvados</h2>
Kaip matote, kuo didesnis input, tuo pranašesnė tampa tampa antra versija, taip ėvyksta todėl, kad pirmoje versijoje kiekvienas simbolis buvo keičiamas į tam tikrą nustatytą skaitinę reikšmę, kas, apdorojant didesnius duomenis, atima labai daug laiko.

<h3>Pataisyti trūkumai</h3>

1. Hash visuomet gaunasi tokio paties ilgio;
2. Dirbant su didesniais kiekiais duomenų, programa užtrunka ilgiau, tačiau ne taip ilgai, kaip užtrukdavo pirmoje versijoje;
3. Net tada, kai įvetis skiriasi tik vienu simboliu, išvestis skiriasi nemažai;
4. Yra pakankamai didelė maiša;
5. Tuščias failas taip pat turi savo hash.

<h3>Dabartiniai trūkumai</h3>
Kaip matote, tarp panašių įvesčių vis dar gaunasi panašūs ar vienodi hash, tai bus pataistyta V0.2.1.




<h1><b>V0.1</b></h1>

***
<h2>Pseudokodas</h2>

1. Programa priima string tipo kintamąjį
2. Paverčia jį simbolių rinkiniu ir kiekvieną simbolį konvertuioja į tam tikrą jau nustatytą skaitinę reikšmę
3. Paimamama pirmojo simbolio reikšmė ir sudauginama su antrojo simbolio reikšme
4. Gauta sandauga dauginama su trečio simbolio skaitine reikšme ir.t.t.
5. Kadangi naudojamas int duomenų tipas, kuris siekia 2147483647, galiausiai jsi persipildo
6. Kai yra pasiekiamas persipildymas (angl. Owerflow) int reikšmė tampa neigiama, nes tarsi apsisuka kilpa
7. Programa sustoja tuo momentu, kai užfiksuoja persipildymą ir pakeičia dabartinę neigiamą int reikšmę teigiama
8. Gautas skaičius is dešimtainės sistemos yra verčiamas į šešioliktainę ir įdedamas į išvesties vektorių
9. Programa kartoja šiuos veiksmus tol kol baigiasi visi įvesties simboliai
10. Jei atlikus veiksmus su paskutiniuoju simboliu, sandauga > 0, t. y. nepasiekė int max ribos, ji "priklijuojama prie išvesties vektoriaus

PRADŽIA  
input: string S;  
sandauga <- 1;  
kiekvienam simboliui iš S {  
    skaicius <- convertToNumber(simbolis)  
    sandauga <- sandauga * skaicius  
    jei sandauga < 0 tada{  
      sandauga <- -sandauga  
      hexKodas <- convertToHex(sandauga)  
      outputVector.pushback(hexKodas)  
      sandauga <- 1  
      }  
}  
jei sandauga <> 1 ir visi simboliai baigesi, tada  
outputVector.pushback(sandauga)  
return outputVector  
PABAIGA  

***
Paleidus programą išvedamas meniu, kuriame galima pasirinkti:

![image](https://github.com/user-attachments/assets/4f6a76f9-3e67-4067-b9a2-f058b800df52)

<h2><b>Testavimas</b></h2>

<h3>Mano sugeneruoti failai: </h3>

![Screenshot 2024-09-26 192652](https://github.com/user-attachments/assets/53b5bf97-e474-488a-a153-e3c72ef5b078)
![Screenshot 2024-09-26 192641](https://github.com/user-attachments/assets/c6c98240-c81a-47d6-b5a4-286e21a63157)
![Screenshot 2024-09-26 192627](https://github.com/user-attachments/assets/1f4bbe27-ada1-47ef-af01-bf4f8532cd5f)
![Screenshot 2024-09-26 192608](https://github.com/user-attachments/assets/09760859-67aa-4cff-b100-20519a095ea9)
![Screenshot 2024-09-26 192545](https://github.com/user-attachments/assets/b9f1020f-50b3-4a93-a2fa-3bcd75e01e31)
![Screenshot 2024-09-26 192530](https://github.com/user-attachments/assets/47c5360a-88be-4c4d-981d-0339cf423da4)


<h3> Testavimas su konstitucija.txt </h3>

![Screenshot 2024-09-26 230133](https://github.com/user-attachments/assets/40e8857c-fc04-40e9-a939-f3670d639e80)

***
<h2>Išvados</h2>
Kaip matote, yra generuojama kažkas panašaus į hash kodą, tačiau programa turi daugybę trūkumų:

1. Nėra sutvarkytas sugeneruoto kodo ilgis - šiuo metu jis priklauso nuo įvesties ilgio bei simbolių vietos lentelėje
2. Programa yra neefektyvi - dirbant su didesniais kiekiais duomenų bus padaryta labai daug dauginimo operacijų, kas užims daug laiko
3. Jei įvestis skiriasi tik vienu simboliu, sugeneruoti kodai yra praktiškai vienodi
4. Nėra pakankamai didelės maišos, kadangi kodas yra klijuojamas
5. Tuščias failas atsakymo negrąžina
