#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
class EnandDe {
private:string Origin, Destring, Enstring;
	   char key;
public:
	EnandDe(string c,char key1) {
		Origin = c;
		Destring = c;
		Enstring = c;
		key = key1;
	}
	int Encrypto() {
		int len = Origin.length();
		for (int i = 0; i < len; i++) {
			Enstring[i] = Origin[i] ^ key;
		}
		cout << "����֮���ǣ�" << endl;
		for (char c : Enstring) {
			int value = static_cast<int>(c);
			std::cout << std::setw(2) << std::setfill('0') << std::hex << value;
			cout << " ";
		}
		cout << endl;
		return 0;
	}
	int Decrypto() {
		int len = Origin.length();
		for (int i = 0; i < len; i++) {
			Destring[i] = Enstring[i] ^ key;
		}
		cout <<"�������ٽ��н����ǣ�"<< Destring << endl;
		return 0;
	}
};
int main() {
	string Origin;
	char key;
	cout << "�������Ƕ�һ���ַ��е�ÿ����ĸ�����һ��key��ĸ�����������"<<endl<<"��������Ҫ���ܵ��ַ�����" << endl;
	getline(cin, Origin);
	cout<< "������Key��Ӧ��Ϊһ����ĸ��" << endl;
	cin >> key;
	EnandDe Enstring(Origin,key);
	Enstring.Encrypto();
	Enstring.Decrypto();
	return 0;
}