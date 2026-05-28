GigiQuant

1. Descriere

Compania GigiQuant angajeaza un manager de portofoliu. Au fost create probe de interviu bazate pe structuri de date si algoritmi in vederea indeplinirii a 4 sarcini specifice domeniului financiar:

	Task 1: calculul Sharpe Ratio folosind lista simplu inlantuita
	Task 2: identificarea oportunitatilor de arbitraj folosind 3 stive si o coada
	Task 3: diversificarea portofoliului folosind arbore binar
	Task 4: lant Markov folosind graf orientat si fractii

2. Structura proiectului:

	"main.c" -> deschide fisierele, identifica taskul si ruleaza codul corespunzator
	"task1.c" , "liste.h" -> implementarea pentru Sharpe Ratio
	"task2.c" , "task2.h" -> implementarea pentru arbitraj
	"task3.c" , "task3.h" -> implementarea pentru diversificare
	"task4.c" , "task4.h" -> implementarea pentru lanturi Markov si fractii
	"stiva.c" , "stiva.h" -> implementarea stivei
	"cozi.c" , "cozi.h" -> implementarea cozii
	"arbori.c" , "arbori.h" -> implementarea arborelui binar
	"grafuri.c" , "grafuri.h" -> implementarea grafului orientat 

3. Compilare:

gcc main.c task1.c task2.c task3.c task4.c arbori.c grafuri.c stiva.c cozi.c -o main -lm

4. Rulare:

Programul se ruleaza cu un fisier de input si unul de output:
	./main input.txt output.txt