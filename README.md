<h1><b>V0.2</b></h1>

***
<h2>Pseudokodas</h2>

***

<h2><b>Testavimas</b></h2>

<h3>Mano sugeneruoti failai: </h3>











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
