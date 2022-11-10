********** READ ME **********
	Functia add_last
Prima data verificam daca vectorul este sau nu gol si daca este, il alocam.
Daca nu este gol, atunci il realoc cu ce se afla cat era inainte si cat mai vreau
sa adaug.
Variabila inceput retine adresa initiala a vectorului.
Vectorul primeste valoarea variabilei len pentru a ajunge in locul in care trebuie sa adaug, 
apoi ma mut cu cat e necesar(header), urmand ca in final sa ma intorc la inceput.

	Functia print
Verific daca am ce sa afisez si daca am, retin adresa initiala, dupa care verific ce tip am.
Pentru tipul 1, mai intai afisez ce tip am. Retin in 2 variabile (dim_nume1 si dim_nume2) dimensiunile
celor doua nume, dupa afisez dupa bitii corespunzatori si ma deplasez cu cat e necesar. Afisez valoarea
celor doua bancnote. Cresc contorul si verific daca am ajuns la final. Daca nu am ajuns,
cresc arr cu cat m am deplasat.
Acelasi algoritm am aplicat si la tipul 2 si tipul 3, diferenta facand numarul de biti
al bancnotelor.

	Functia find
Daca indexul este real, atunci verific ce dimensiune am la void si ma mut cu 4 ca head 
are 8 si primii 4 biti sunt pentru char. Dupa, maresc indexul si ma deplasez pentru
a extrage dimensiunea void din nou si afisez urmand procedeul de la functia print.

	Functia delete_at
Retin in variabila inceput adresa de start a vectorului.
Variabila stergere este un index de care ma folosesc pentru stergere.
Variabila dim_void extrage dimensiunea data.
Cat timp indexul de stergere nu ajunge la index, acesta creste, ma 
deplasez in arr si retin cu cat am facut o, apoi extrag din nou dimensiunea la data
urmatoare. Copiez la vectorul arr ce se afla peste elementul destinat stergerii, 
cu exact dimensiunea intregului vector, mai putin cu cat m am mutat pana la momentul
curent si elementul de sters. Apoi, arr ia adresa de inceput, iar len se micsoreaza cu
dimensiunea elementului sters.
In final se realoca vectorul cu cat e necesar.

	Functia main
Aloc dinamic variabila comanda prin care primesc ce comanda va fi executata.
Pentru comanda insert: citesc tipul si il stochez, declar, aloc si citesc cele doua
nume si bancnote. Aloc cat e nevoie sa bag in void data, apoi le adaug pe rand si
am grija sa aloc si sa ma deplasez cu cat e necesar. In final adaug in arr si maresc
lungimea. Dezaloc memoria. Pentru celelalte tipuri am urmat acelasi algoritm.
Petru comanda print am facut afisarea.
Pentru comanda find am citit un index in plus si am apelat.
Pentru functia delete_at am citit indexul si am apelat.
Cu comanda exit inchei tot si dezaloc memoria.