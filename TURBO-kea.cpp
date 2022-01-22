#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

int var_liste[512] = { 0 };
string var_name[512] = { "unset" };
int maxset = 0;
bool DEBUGPRINT = true;

void setvar(string name, int vall) {
	for (int i = 0; i <= maxset; i++) {
		if (var_name[i] == name) {
			if (DEBUGPRINT) {cout << "modification de: " << name << " = " << vall << endl; }
			var_liste[i] = vall;
			return;
		}
	}
	maxset++;
	if (DEBUGPRINT) {
		cout << "creation de: " << name << " = " << vall << endl;
	}
	var_name[maxset] = name;
	var_liste[maxset] = vall;
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

int string_to_int(string texte) {
	stringstream intValue(texte);
	int number = 0;
	intValue >> number;
	return number;
}

void codeinloop(vector<string> code, string nom, int max) {
	if (DEBUGPRINT) {
		cout << "demarage de la boucle: " << nom << endl;
	}
	string sauter = "";
	for (int rep = 0; rep < max; rep++) {
		for (int i = 0; i < code.size(); i++) {
			string ligne = code[i];
			if (DEBUGPRINT) {
				cout << "[" << nom << "](" << rep << "~" << i << ")*** " << ligne << " ***" << endl;
			}
			
			vector<string> args = split(ligne, ' ');
			string mode = args[0];

			if (sauter == "" || (mode == "E" && args[1] == sauter)) {
				if (sauter != "") {
					sauter = "";
				}
				if (mode == "") {
					continue;
				}

				else if (mode == "V") {
					setvar(args[1], string_to_int(args[2]));
				}

			}			
		}
	}
}

void start(string code) {
	while (code.find_first_of("\n") != string::npos) {
		code.replace(code.find("\n"), 1, ";");
	}
	vector<string> sortie = split(code, ';');
	codeinloop(sortie, "main", 1);
}

int main() {

	start("V a 1\nV b 2;V a 2");

	return EXIT_SUCCESS;
}