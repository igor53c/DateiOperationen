// DateiOperationen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool dateiErstellen(string);
bool dateiLesen(string);
bool dateiKopieren(string, string);
void dateiInfo(string);
int getByteCount(string);

int main()
{

	locale::global(locale("German_germany"));

	string dateiname, quelldatei, zieldatei;

	cout << "Bitte Datei: " << endl;

	getline(cin, dateiname);

	if (!dateiErstellen(dateiname))
	{
		exit(-1);
	}

	if (!dateiLesen(dateiname))
	{
		exit(-1);
	}

	cout << "Bitte QuellDatei: " << endl;

	getline(cin, quelldatei);

	cout << "Bitte ZielDatei: " << endl;

	getline(cin, zieldatei);

	if (!dateiKopieren(quelldatei, zieldatei))
	{
		exit(-1);
	}

	cout << "Bitte Datei: " << endl;

	getline(cin, dateiname);

	dateiInfo(dateiname);

	return EXIT_SUCCESS;
}

bool dateiErstellen(string dateiname)
{
	ofstream datei(dateiname, ios::out);

	if (datei.fail())
	{
		cerr << "Fehler" << endl;
		return false;
	}

	datei << "1.Textzeile\n";
	datei << "2.Textzeile\n";
	datei << "3.Textzeile\n";

	datei.close();

	cout << "OK" << endl;

	return true;
}

bool dateiLesen(string dateiname)
{
	string zeile;

	ifstream datei(dateiname, ios::in);

	if (datei.fail())
	{
		cerr << "Fehler" << endl;
		return false;
	}

	cout << "OK" << endl;

	while (!datei.eof())
	{
		getline(datei, zeile);
		cout << zeile << endl;
	}

	datei.close();

	return true;
}

bool dateiKopieren(string quelldatei, string zieldatei)
{
	ifstream quelle(quelldatei, ios::in | ios::binary);

	if (quelle.fail())
	{
		cerr << "Fehler" << endl;
		return false;
	}

	ofstream ziel(zieldatei, ios::out | ios::binary);

	if (ziel.fail())
	{
		cerr << "Fehler" << endl;

		quelle.close();
		
		return false;
	}

	ziel << quelle.rdbuf();

	quelle.close();

	ziel.close();

	cout << "OK" << endl;

	return true;
}

void dateiInfo(string dateiname)
{
	cout << "Datei info: " << dateiname << endl;

	printf("Anzahl Zeichen: %d\n", getByteCount(dateiname));

}

int getByteCount(string dateiname)
{
	int retValue = 0;
	char c;

	ifstream datei(dateiname, ios::in | ios::binary);

	if(datei.fail())
	{
		cerr << "Fehler" << endl;

		return retValue;
	}

	/*while (datei.get(c))
	{
		retValue++;
	}*/

	datei.seekg(0, ios::end);

	retValue = datei.tellg();

	return retValue;
}



