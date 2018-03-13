//Gustawski Milosz Dev-C++ 5.11

#include <iostream>
using namespace std;

//----------------------------------------------------------------------------------------------------Definicja Stalych, pozostale zmienne sa zadeklarowane w funkcji main
const int H = 6;	//dana dla tablicy glownej
const int W = 6;	//dana dla tablicy glownej
const int J = 3;	//dana pomocna do obrotu tablic

//----------------------------------------------------------------------------------------------------Zerowanie tablicy glownej tablicy A
void wpisywanie(int A[H][W])
{
	for (int j = 0; j<H; j++)
	{
		for (int i = 0; i<W; i++)
		{
			A[i][j] = 0;
		}
	}
}

//----------------------------------------------------------------------------------------------------Zerowanie tablicy B, ktora jest pomocna w obrocie danej cwiartki
void wpisywanieB(int B[H][W])
{
	for (int j = 0; j<H; j++)
	{
		for (int i = 0; i<W; i++)
		{
			B[i][j] = 0;
		}
	}
}

//----------------------------------------------------------------------------------------------------Wypisanie wstepnych zasad
void zasady()
{
	cout << "Gracze na przemian ukladaja po jednym swoim pionie w wolnym polu. Wygrawa gracz, ktory " << endl;
	cout << "jako pierwszy ulozy 5 swoich pionow w jednym rzedzie (w pionie lub poziomie)" << endl;
	cout << "Wybierz pole, najpierw wpisz numer [1-6]. Potem podaj litere [A-F]." << endl;
	cout << "Po kazdym postawieniu piona gracz wybiera cwiartke, ktora chce obrocic o 90 stopni przeciwnie do wskazowek zegara" << endl;
	cout << "Pion Gracza 1: o. Pion Gracza 2: #" << endl;
}

//----------------------------------------------------------------------------------------------------Sprawdzanie czy prowadzone dana zawieraja sie w zakresie dla tury postawienia pionka
bool sprawdzanie_danych(int numer, int numer1)
{
	if (numer <= 0 || numer >= 7 || numer1 <= 0 || numer1 >= 7)
	{
		cout << "Podano bledne dane!" << endl;
		return true;
	}
	return false;
}

//----------------------------------------------------------------------------------------------------Sprawdzanie czy prowadzone dana zawieraja sie w zakresie dla obrotu cwiartki
bool sprawdzanie_obrot(int numer)
{
	if (numer <= 0 || numer >= 5)
	{
		cout << "Podano bledne dane!" << endl;
		return true;
	}
	return false;
}
 
//----------------------------------------------------------------------------------------------------Sprawdzanie czy dane pole jest puste
bool sprawdzenie_pola(int pole) {
	
	if (pole == 0)return true; //wystarczy sprawdzic czy pole jest wieksze od 0, poniewaz gdy pole jest zajete, to w dane okienko tablicy jest wpisane 1 albo 2
	return false;
}
 
//----------------------------------------------------------------------------------------------------Tura gracza numer 1
void tura1(char litera, char numer, int A[H][W], int numer1, char numerchar)
{
	bool zajete = 0;
	do {
		cout << "Tura Gracza 1." << endl << "Wybierz numer pola, w ktorym chcesz umiescic swoj pion: ";cin >> numerchar;
		
		if (numerchar =='1')	//algorytm zmieniana danych tablicowe na dane int dla danych cyfrowych
			numer = 1;
		else if (numerchar == '2')
			numer = 2;
		else if (numerchar == '3')
			numer = 3;
		else if (numerchar == '4')
			numer = 4;
		else if (numerchar == '5')
			numer = 5;
		else if (numerchar == '6')
			numer = 6;
			
			
		cout << "Wybierz litere pola, w ktorym chcesz umiescic swoj pion: ";cin >> litera;
		
		if (litera == 'A' || litera == 'a')																 //algorytm zmieniana danych tablicowe na dane int dla danych literowych
			numer1 = 1;
		else if (litera == 'B' || litera == 'b')
			numer1 = 2;
		else if (litera == 'C' || litera == 'c')
			numer1 = 3;
		else if (litera == 'D' || litera == 'd')
			numer1 = 4;
		else if (litera == 'E' || litera == 'e')
			numer1 = 5;
		else if (litera == 'F' || litera == 'f')
			numer1 = 6;
			
			
	} while (sprawdzanie_danych(numer, numer1));
	if (sprawdzenie_pola(A[numer1 - 1][numer - 1]))
		A[numer1 - 1][numer - 1] = 1;																	//wpisanie '1' w odpowiednie okienko tablicy. Liczba 1 w tablicy odnosi sie do piona gracz 1
	else
	{
		cout << endl;
		cout << "Pole jest zajete, podaj jeszcze raz" << endl;
		tura1(litera, numer, A, numer1, numerchar);
	}
}

//----------------------------------------------------------------------------------------------------Tura gracza numer 2
void tura2(char litera, char numer, int A[H][W], int numer1, char numerchar)
{
	bool zajete = 0;
	do {
		cout << "Tura Gracza 2." << endl << "Wybierz numer pola, w ktorym chcesz umiescic swoj pion: ";cin >> numerchar;
		
			if (numerchar =='1') //algorytm zmieniana dane tablicowe na dane int dla danych cyfrowych
			numer = 1;
		else if (numerchar == '2')
			numer = 2;
		else if (numerchar == '3')
			numer = 3;
		else if (numerchar == '4')
			numer = 4;
		else if (numerchar == '5')
			numer = 5;
		else if (numerchar == '6')
			numer = 6;
			
			
		cout << "Wybierz litere pola, w ktorym chcesz umiescic swoj pion: ";cin >> litera;
		
		if (litera == 'A' || litera == 'a') 															//algorytm zmieniana danych tablicowe na dane int dla danych literowych
			numer1 = 1;
		else if (litera == 'B' || litera == 'b')
			numer1 = 2;
		else if (litera == 'C' || litera == 'c')
			numer1 = 3;
		else if (litera == 'D' || litera == 'd')
			numer1 = 4;
		else if (litera == 'E' || litera == 'e')
			numer1 = 5;
		else if (litera == 'F' || litera == 'f')
			numer1 = 6;
			
			
	} while (sprawdzanie_danych(numer, numer1));
	if (sprawdzenie_pola(A[numer1 - 1][numer - 1]))
		A[numer1 - 1][numer - 1] = 2;																	//wpisanie '2' w odpowiednie okienko tablicy. Liczba 1 w tablicy odnosi sie do piona gracz 2
	else
	{
		cout << endl;
		cout << "Pole jest zajete, podaj jeszcze raz" << endl;
		tura2(litera, numer, A, numer1, numerchar);
	}
}

//----------------------------------------------------------------------------------------------------Rysowanie tablicy zaleznej od wprowadzonych danych
void rysuj_tablice(int A[H][W])
{
	int n = 0;
	cout << " +-----+-----+-----+-----+-----+-----+" << endl;
	for (int j = 0; j<H; j++)
	{
		n++;    
		cout << " ";
		for (int i = 0; i <W; i++)
		{
			if (A[i][j] == 1)																				//wypisanie odpowiedniego piona w zaleznosci od danych w tabeli
				cout << "| " << "ooo" << " ";
			else if (A[i][j] == 2)
				cout << "| " << "###" << " ";
			else if (A[i][j] == 0)
				cout << "| " << "   " << " ";
		}
		cout << "|" << endl << n;
		
		for (int i = 0; i <W; i++)
		{
			if (A[i][j] == 1)
				cout << "| " << "ooo" << " ";
			else if (A[i][j] == 2)
				cout << "| " << "###" << " ";
			else
				cout << "| " << "   " << " ";
		}
		cout << "|" << endl;
		cout << " +-----+-----+-----+-----+-----+-----+" << endl;
	}
	cout << "   A     B     C     D     E     F     " << endl;
}

//----------------------------------------------------------------------------------------------------Obracanie tablicy o 90 stopni przeciwnie do wskazowek zegara dla 4 cwiartki
void odwroc4(int A[H][W], int B[H][W])
{
	B[5][5] = A[3][5];             //najpierw wpisujemy dane do tablicy pomocnej, a dopiero pozniej przesylamy je z powrotem
	B[5][4] = A[4][5];
	B[5][3] = A[5][5];
	B[4][3] = A[5][4];
	B[3][3] = A[5][3];
	B[3][4] = A[4][3];
	B[3][5] = A[3][3];
	B[4][4] = A[4][4];
	B[4][5] = A[3][4];
 
	for (int j = J; j<H ;j++)
	{
		for (int i = J; i<H ;i++)
			A[i][j] = B[i][j];
	}
}

//----------------------------------------------------------------------------------------------------Obracanie tablicy o 90 stopni przeciwnie do wskazowek zegara dla 3 cwiartki
void odwroc3(int A[H][W], int B[H][W])
{
	B[0][5] = A[0][3];				//najpierw wpisujemy dane do tablicy pomocnej, a dopiero pozniej przesylamy je z powrotem
	B[0][4] = A[1][3];
	B[0][3] = A[2][3];
	B[1][3] = A[2][4];
	B[2][3] = A[2][5];
	B[2][4] = A[1][5];
	B[2][5] = A[0][5];
	B[1][5] = A[0][4];
	B[1][4] = A[1][4];
 
	for (int j = J; j<H; j++)
	{
		for (int i = 0;i<J;i++)
			A[i][j] = B[i][j];
	}
}

//----------------------------------------------------------------------------------------------------Obracanie tablicy o 90 stopni przeciwnie do wskazowek zegara dla 2 cwiartki
void odwroc2(int A[H][W], int B[H][W])
{
	B[0][0] = A[2][0];				//najpierw wpisujemy dane do tablicy pomocnej, a dopiero pozniej przesylamy je z powrotem
	B[1][0] = A[2][1];
	B[2][0] = A[2][2];
	B[0][1] = A[1][0];
	B[0][2] = A[0][0];
	B[1][2] = A[0][1];
	B[2][1] = A[1][2];
	B[2][2] = A[0][2];
	B[1][1] = A[1][1];
 
	for (int j = 0; j<J; j++)
	{
		for (int i = 0; i<J ;i++)
			A[i][j] = B[i][j];
	}
}

//----------------------------------------------------------------------------------------------------Obracanie tablicy o 90 stopni przeciwnie do wskazowek zegara dla 1 cwiartki
void odwroc1(int A[H][W], int B[H][W])
{
	B[5][0] = A[5][2];				//najpierw wpisujemy dane do tablicy pomocnej, a dopiero pozniej przesylamy je z powrotem
	B[4][0] = A[5][1];
	B[3][0] = A[5][0];
	B[3][1] = A[4][0];
	B[3][2] = A[3][0];
	B[4][2] = A[3][1];
	B[5][2] = A[3][2];
	B[5][1] = A[4][2];
	B[4][1] = A[4][1];
 
	for (int j = 0; j<J ;j++)
	{
		for (int i = J; i<H ;i++)
			A[i][j] = B[i][j];
	}
}


//----------------------------------------------------------------------------------------------------Tura obrotu, w ktorej gracz podaje ktora cwiartke chcialby obrocic
void tura_obrot(int A[H][W], int B[H][W],char numerchar)
{
	int numer;
	do {
		cout << "Podaj numer cwiartki, ktora chcialbys obrocic: ";cin >> numerchar;
		
		if(numerchar =='1') // algorytm zmiany danych liczbowych z tablicy na dane liczbowe typu int
			numer = 1;
		else if (numerchar == '2')
			numer = 2;
		else if (numerchar == '3')
			numer = 3;
		else if (numerchar == '4')
			numer = 4;
			
		if (numer == 1) // algorytm wybrania odpowiedniej cwiartki na podstawie wprowadzonych danych
			odwroc1(A, B);
		else if (numer == 2)
			odwroc2(A, B);
		else if (numer == 3)
			odwroc3(A, B);
		else if (numer == 4)
			odwroc4(A, B);
	} while (sprawdzanie_obrot(numer));
 
	system("cls");
	rysuj_tablice(A);
}

//----------------------------------------------------------------------------------------------------Sprawdzenie czy dany gracz wygral w poziomie
bool poziomo(int A[H][W], int* wygrana1, int* wygrana2)
{
	int gracz1 = 0;
	int gracz2 = 0;
 
	for (int j = 0;j<H;j++)
	{
		for (int i = 0;i<W;i++)
		{
			if (A[i][j] == 1)
			{
				gracz1++;    //inkrementujemy dana jesli pion danego gracza znajduje sie w danym okienku tablicy
				gracz2 = 0;
			}
			if (A[i][j] == 2)
			{
				gracz1 = 0;
				gracz2++;
			}
			if (A[i][j] == 0)
			{
				gracz1 = 0;
				gracz2 = 0;
			}
			if (gracz1 >= 5)
			{
				(*wygrana1) = 1; 	//przesylamy znacznik wygrana1 = 1, gdy gracz 1 ma 5 albo wiecej pionow w poziomie
				return true;
			}
			if (gracz2 >= 5)
			{
				(*wygrana2) = 1;	//przesylamy znacznik wygrana2 = 1, gdy gracz 2 ma 5 albo wiecej pionow w poziomie
				return true;
			}
		}
	}
	gracz1 = 0; //jesli nie udalo sie znalezc 5 pionow to zerujemy obie funkcje 
	gracz2 = 0;
	return false;
}

//----------------------------------------------------------------------------------------------------Sprawdzenie czy dany gracz wygral w pionie
bool pionowo(int A[H][W], int* wygrana1, int* wygrana2)
{
	int gracz1 = 0;
	int gracz2 = 0;
	for (int j = 0; j<W ;j++)
	{
		for (int i = 0; i<H; i++)
		{
			if (A[j][i] == 1)
			{
				gracz1++;  //inkrementujemy dana jesli pion danego gracza znajduje sie w danym okienku tablicy
				gracz2 = 0;
			}
			if (A[j][i] == 2)
			{
				gracz1 = 0;
				gracz2++;
			}
			if (A[j][i] == 0)
			{
				gracz1 = 0;
				gracz2 = 0;
			}
			if (gracz1 >= 5)
			{
				(*wygrana1) = 1;	//przesylamy znacznik wygrana1 = 1, gdy gracz 1 ma 5 albo wiecej pionow w pionie
				return true;
			}
			if (gracz2 >= 5)
			{
				(*wygrana2) = 1;	//przesylamy znacznik wygrana2 = 1, gdy gracz 2 ma 5 albo wiecej pionow w pionie
				return true;
			}
		}
	}
	gracz1 = 0;	//jesli nie udalo sie znalezc 5 pionow to zerujemy obie funkcje
	gracz2 = 0;
	return false;
}
 
//----------------------------------------------------------------------------------------------------Sprawdzenie obu warunkow wygranej tj w pionie i poziomie
bool sprawdz(int A[H][W], int* wygrana1, int* wygrana2)
{
	if(pionowo(A, wygrana1, wygrana2) || poziomo(A, wygrana1, wygrana2)) return 1;
	return 0;
}

//----------------------------------------------------------------------------------------------------Wyznaczenie zwyciezcy i wypisanie odpowiedniej formulki
void wygrana(int A[H][W], int* wygrana1, int* wygrana2)
{
	if (sprawdz(A, wygrana1, wygrana2) && (*wygrana1) == 1)
	{
		cout << "Wygrywa Gracz 1!" << endl;
		system("PAUSE");
		exit(1);
	}
	(*wygrana1) = 0;
	(*wygrana2) = 0;
	
	if (sprawdz(A, wygrana1, wygrana2) && (*wygrana2) == 1) 
	{
		cout << "Wygrywa Gracz 2!" << endl;
		system("PAUSE");
		exit(1);
	}
	(*wygrana1) = 0;
	(*wygrana2) = 0;
}


int main()
{
	char litera; //dana zlozaca do wprowadzenia danych do funkcji tura
	char numerchar; //dana zlozaca do wprowadzenia danych do funkcji tura
	int numer1,numer; //dane pomocnicze, na ktore zamieniane sa powyzsze char'y
	int A[H][W]; // tablica glowna
	int B[H][W]; // tablica pomocnicza
	int wygrana1 = 0;
	int wygrana2 = 0;
	wpisywanie(A);
	wpisywanie(B);
	zasady();
	rysuj_tablice(A);
	while (true)
	{
		tura1(litera, numer, A, numer1, numerchar);
		system("cls");
		rysuj_tablice(A);
		wygrana(A, &wygrana1, &wygrana2); 
		wpisywanie(B);					
		tura_obrot(A, B, numerchar);
		wygrana(A, &wygrana1, &wygrana2);
		tura2(litera, numer, A, numer1, numerchar);
		system("cls");
		rysuj_tablice(A);
		wygrana(A, &wygrana1, &wygrana2);
		wpisywanie(B);
		tura_obrot(A, B, numerchar);
		wygrana(A, &wygrana1, &wygrana2);
	}
	return 0;
}

