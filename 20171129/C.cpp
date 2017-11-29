#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Stu {
	int id;
	string name;
	int chinese;
	int math;
	int english;
	int total;
};

bool operator<(const Stu& a, const Stu& b) {
	if (a.total > b.total)
		return true;
	else if (a.total < b.total)
		return false;
	if (a.chinese > b.chinese)
		return true;
	else if (a.chinese < b.chinese)
		return false;
	if (a.math > b.math)
		return true;
	else if (a.math < b.math)
		return false;
	return false;
}

int main() {
	int n;
	cin >> n;
	Stu* stu = new Stu[n];
	for (int i=0;i<n;i++) {
		int id, a, b, c;
		string name;
		cin >> id >> name >> a >> b >> c;
		stu[i].id = id;
		stu[i].name = name;
		stu[i].chinese = a;
		stu[i].math = b;
		stu[i].english = c;
		stu[i].total = a + b + c;
	}
	stable_sort(stu, stu + n);
	for (int i=0;i<n;i++) {
		cout << stu[i].id << " " << stu[i].name << " " << stu[i].total << endl;
	}
	delete[] stu;
	return 0;
}