# GigiQuant

## 1. Descriere

Compania GigiQuant angajeaza un manager de portofoliu. Au fost create probe de interviu bazate pe structuri de date si algoritmi in vederea indeplinirii a 4 sarcini specifice domeniului financiar si a unui task bonus:

	Task 1: calculul Sharpe Ratio folosind lista simplu inlantuita
	Task 2: identificarea oportunitatilor de arbitraj folosind 3 stive si o coada
	Task 3: diversificarea portofoliului folosind arbore binar
	Task 4: lant Markov folosind graf orientat si fractii
	Task bonus: apelarea API-ului Yahoo Finance din C si afisarea preturilor de deschidere ale unei actiuni

## 2. Structura proiectului:

	"main.c" -> deschide fisierele, identifica taskul si ruleaza codul corespunzator
	"task1.c" , "liste.h" -> implementarea pentru Sharpe Ratio
	"task2.c" , "task2.h" -> implementarea pentru arbitraj
	"task3.c" , "task3.h" -> implementarea pentru diversificare
	"task4.c" , "task4.h" -> implementarea pentru lanturi Markov si fractii
	"stiva.c" , "stiva.h" -> implementarea stivei
	"cozi.c" , "cozi.h" -> implementarea cozii
	"arbori.c" , "arbori.h" -> implementarea arborelui binar
	"grafuri.c" , "grafuri.h" -> implementarea grafului orientat 
	"bonustask/bonus.c", "bonustask/bonus.h" -> implementarea taskului bonus
	"bonustask/cJSON.c", "bonustask/cJSON.h" -> biblioteca pentru prelucrarea datelor JSON

## 3. Compilare:

Comanda se executa din directorul "src": 
```bash
gcc main.c task1.c task2.c task3.c task4.c arbori.c grafuri.c stiva.c cozi.c -o main -lm
```

## 4. Rulare:

Programul se ruleaza cu un fisier de input si unul de output:
```bash
./main input.txt output.txt
```

## 5. Task bonus - folosirea unui API:

Pentru a realiza taskul bonus am folosit codul de baza oferit in cerinta
pentru apelarea API-ului Yahoo Finance si extragerea preturilor
de deschidere, precum si biblioteca cJSON.

Am integrat acest cod in functia bonustask. Aceasta citeste din fisier
simbolul actiunii, intervalul dintre observatii si perioada solicitata.
Functia apeleaza get_open_prices si scrie in fisierul de output
informatiile solicitarii si preturile pozitive, cu doua zecimale.
Nu sunt afisate valorile lipsa sau nenumerice.

Biblioteca libcurl realizeaza cererea HTTP, iar cJSON permite
extragerea preturilor din raspunsul JSON.

Exemplu de input, disponibil in "src/bonus.in":

```text
BONUS
NVDA
1d
1mo
```

NVDA reprezinta simbolul actiunii NVIDIA, 1d indica observatii zilnice,
iar 1mo reprezinta perioada de o luna pentru care sunt solicitate datele.

Activare si compilare:

In versiunea actuala, includerea "bonus.h" si blocul if (task==5)
din "src/main.c" sunt comentate. Compilarea standard descrisa anterior
este pentru taskurile 1-4.

In vederea testarii manuale a bonusului trebuie decomentate aceste doua
portiuni. Sunt necesare biblioteca libcurl impreuna cu fisierele de
dezvoltare si accesul la internet.

Compilare din directorul "src", dupa activarea bonusului:

```bash
gcc main.c task1.c task2.c task3.c task4.c arbori.c grafuri.c stiva.c cozi.c ../bonustask/bonus.c ../bonustask/cJSON.c -I../bonustask -o main -lm -lcurl
```

Rulare din directorul "src":

```bash
./main bonus.in bonus.out
```

Preturile obtinute depind de datele returnate de API la momentul
executarii.