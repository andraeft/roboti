# roboti
@ Introducere in robotica cu Arduino

Tema 2 - matrice cu LED-uri

 

	a. Jocul ales: “Cade cerul pe mine” 
 Link: https://youtu.be/uNy5M8FOpx0?t=8m31s
 
 Descriere: Jocul incepe cu 3 linii de cer (LED-uri aprinse random, minim unul pe fiecare linie, incepand de la linia 1 in jos) si cu pamanteanul aflat pe pamant (led aprins pe linia 8, coloana 4). Pamanteanul se poate deplasa la stanga si la dreapta si poate aprinde LED-uri anterior stinse de pe cer doar vertical (pe aceeasi coloana pe care se afla pamanteanul). Scopul jocului este ca pamanteanul sa acumuleze cat mai multe puncte, adica sa completeze linii din cer - odata completate, acestea dispar. Dificultatea jocului creste in timp. Jocul se termina cand numarul de linii ale cerului devine 8.
 
 Abordare tehnica:
 
	Input: joystick
	
	Output: matrice
	
	Se afiseaza textul “HI” si se asteapta o miscare de la jucator. Astfel, jocul incepe.
	
	In functie de informatia citita de la joystick, pamanteanul se deplaseaza la stanga, la dreapta sau trage spre cer. 
	
	La comanda de tragere (functie), se vor aprinde toate LED-urile coloanei pt 0.5 secunde si se va aprinde “definitiv” ultimul LED anterior stins de pe coloana pamanteanului. 
	
	Dupa fiecare tragere, se verifica daca vreo linie a cerului este completa si, in caz afirmativ, se sterge (functie). 
	
	O alta functie este cea de generare a unei noi linii: se afla in loop, independenta de blocul in care se citeste inputul si se trage, si are un delay de cateva secunde - se aleg aleator: 
	
	-un 3<=n<=7 care va reprezenta numarul de LED-uri aprinse pe linia curenta
	
	-n numere <=7, adica pozitiile care trebuie aprinse.
	
	De asemenea, se retine numarul de linii si se updateaza la fiecare “eveniment” (tragere sau generare de linie noua). Conditia de oprire este ca aceste numar de linii sa fie mai mic decat 7.
	
	Cand conditia de oprire este intalnita, se afiseaza scorul (aka numarul de linii) si se revine la inceput (text pe ecran si asteptarea unui click de la jucator).
	
	

   	 b. Indeplinirea cerintelor
	 
Start: text pe ecran, click pe joystick

End: text, scor obtinut, optiune de restart

Niveluri/dificultate: creste viteza “caderii” la fiecare 30 de secunda
Scor: intregirea unei linii valoreaza 1 punct


    c.  Evolutie in timp
La fiecare 3 secunde, apare o noua linie (cerul coboara cu o linie). La fiecare 30 de secunde, viteza caderii creste. Jocul se termina cand cerul atinge pamantul


    d.  Metode de control:  joystick 
Deplasarea omuletului se poate face la stanga sau la dreapta, iar “impuscatul” se realizeaza dand click


     e.  Alte elemente conexe folosite: joystickul, Serial Monitor 
