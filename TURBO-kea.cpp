#include <iostream>
using namespace std;

int var_liste[512] = { 0 };
string var_name[512] = { "unset" };
int maxset = 0;

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

int main() {
	setvar("coucou", 42);
	cout << "coucou = " << getvar("coucou") << endl;
}