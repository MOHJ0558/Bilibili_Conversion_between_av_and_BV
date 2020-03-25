#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;
long long int xorn = 177451812;
long long int add = 8728348608;
int s[] = {11, 10, 3, 8, 4, 6};
const string TABLE = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
long long int tr[123] = {};
long long int dec(string x) {
	long long int r = 0;
	for(long long int i = 0; i < 6; i++) {
		r += ((long long int)pow(58, i) * tr[x[s[i]]]);
	}
	return (r - add) ^ xorn;
}
string enc(long long int x) {
	x = (x ^ xorn) + add;
	string r = "BV1  4 1 7  ";
	for(long long int i = 0; i < 6; i++) {
		r[s[i]] = TABLE[(long long int)floor(x / (long long int)pow(58, i)) % 58];
	}
	return r;
}
int main() {
	for (long long int i = 0; i < 58; i++) {
		tr[TABLE[i]] = i;
	}
	start:
	int ch = 0;
	cout << "Please choose operation:\n1.av to BV\n2.BV to av\n";
	cin >> ch;
	if(ch == 1) {
		cout << "Please enter av number: av";
		long long int av;
		cin >> av;
		cout << enc(av) << endl;
		cout << "Whether to export to BV.txt?[y/n] ";
		char isCopy;
		cin >> isCopy;
		if(isCopy == 'y' || isCopy == 'Y') {
			ofstream saveBV("BV.txt");
			saveBV << "av" << av << " -> " << enc(av);
			saveBV.close();
		}
	} else if(ch == 2) {
		cout << "Please enter BV string, including the letters \"BV\": ";
		string BV;
		cin >> BV;
		cout << "av" << dec(BV) << endl;
		cout << "Whether to export to av.txt?[y/n] ";
		char isCopy;
		cin >> isCopy;
		if(isCopy == 'y' || isCopy == 'Y') {
			ofstream saveBV("av.txt");
			saveBV << BV << " -> av" << dec(BV);
			saveBV.close();
		}
	} else {
		cerr << "ERROR!" << endl;
		return -1;
	}
	cout << "continue?[y/n] ";
	char con;
	cin >> con;
	if (con == 'y' || con == 'Y') {
		goto start;
	}
	return 0;
}
