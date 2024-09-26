<h1><b>V0.1</b></h1>

***
<h2>Pseodokodas</h2>

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



Paleidus programą išvedamas meniu, kuriame galima pasirinkti:

![image](https://github.com/user-attachments/assets/4f6a76f9-3e67-4067-b9a2-f058b800df52)

<h2>Dabartiniai rezultatai:</h2>

![Screenshot 2024-09-26 192530](https://github.com/user-attachments/assets/86efde26-5163-44fb-90fe-add21e5d84f0)
![Screenshot 2024-09-26 192545](https://github.com/user-attachments/assets/e813c2e6-1ec9-4395-8a2c-47b11902ea28)
![Screenshot 2024-09-26 192608](https://github.com/user-attachments/assets/39b1cde5-7ae6-440e-8af7-c105f29437ad)
![Screenshot 2024-09-26 192627](https://github.com/user-attachments/assets/20c17a2b-78f6-42df-96c1-72a7bec16c59)
![Screenshot 2024-09-26 192641](https://github.com/user-attachments/assets/e45fb060-049d-41e9-ad91-0896b5475dcb)
![Screenshot 2024-09-26 192652](https://github.com/user-attachments/assets/5298e7aa-4354-47f6-9604-09032b593291)


Kaip matote, yra generuojama kažkas panašaus į hash kodą, tačiau programa turi daugybę trūkumų:

1. Nėra sutvarkytas sugeneruoto kodo ilgis - šiuo metu jis priklauso nuo įvesties ilgio bei simbolių vietos lentelėje
2. Programa yra neefektyvi - dirbant su didesniais kiekiais duomenų bus padaryta labai daug dauginimo operacijų, kas užims daug laiko
3. Jei įvestis skiriasi tik vienu simboliu, sugeneruoti kodai yra praktiškai vienodi
4. Nėra pakankamai didelės maišos, kadangi kodas yra klijuojamas
5. Tuščias failas atsakymo negrąžina
