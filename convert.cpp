#include <iostream>
#include <math.h>
using namespace std;
long long int xorn = 177451812;
long long int add = 8728348608;
int s[] = {11,10,3,8,4,6};
long long int dec(string x) {
    string table = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
    long long int tr[123] = {};
    for (long long int i = 0; i < 58; i++) {
        tr[table[i]]=i;
    }
    long long int r = 0;
    for(long long int i = 0; i < 6; i++) {
        r += ((long long int)pow(58, i) * tr[x[s[i]]]);
    }
    return (r - add) ^ xorn;
}
string enc(long long int x) {
	string table = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
    char tr[123] = {};
    for (long long int i = 0; i < 58; i++) {
        tr[table[i]]=i;
    }
    x = (x ^ xorn) + add;
    string r = "BV1  4 1 7  ";
    for(long long int i = 0; i < 6; i++) {
        r[s[i]] = table[(long long int)floor(x/(long long int)pow(58, i))%58];
    }
    return r;
}
int main() {
	int ch = 0;
	cout << "Please choose operation:\n1.av2BV\n2.BV2av\n";
	cin >> ch;
	if(ch == 1) {
		cout << "Please input av number, except \"av\":";
		long long int av;
		cin >> av;
		cout << enc(av) << endl;
	} else if(ch == 2) {
		cout << "Please input BV string, ay attention to uppercase and lowercase:";
		string BV;
		cin >> BV;
		cout << "av" << dec(BV) << endl;
	} else {
		cerr << "ERROR!" << endl;
		return -1;
	}
    return 0;
}
