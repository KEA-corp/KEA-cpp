#include <iostream>
#include <string>
#include <vector>

using namespace std;

int var_liste[512] = { 0 };
string var_name[512] = { "unset" };
int maxset = 0;
bool DEBUGPRINT = true;

void setvar(string name, int vall) {
	for (int i = 0; i <= maxset; i++) {
		if (var_name[i] == name) {
			var_liste[i] = vall;
			return;
		}
	}
	maxset++;
	var_liste[maxset] = vall;
	var_name[maxset] = name;
}

int getvar(string name) {
	for (int i = 0; i <= maxset; i++) {
		if (var_name[i] == name) {
			return var_liste[i];
		}
	}
	cout << "variable '" << name << "' non trouvée" << endl;
	return 0;
}

vector<string> split(string x, char delim = ' ')
{
	x += delim; //includes a delimiter at the end so last word is also read
	vector<string> splitted;
	string temp = "";
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] == delim)
		{
			splitted.push_back(temp); //store words in "splitted" vector
			temp = "";
			i++;
		}
		temp += x[i];
	}
	return splitted;
}


void codeinloop(vector<string>, string nom, int max) {
	if (DEBUGPRINT) {
		cout << "demarage de la boucle: " << nom << endl;
	}
	string sauter = nom;
}

void start(string code) {
	vector<string> sortie = split(code, ';');
	codeinloop(sortie, "main", 1);
}


int main() {
	start("V 1 1;V 2 2");
	return EXIT_SUCCESS;
}