#include "Xor.h"   //����ͷ�ļ�
using namespace std;
int main() {
	int n;
	cout << "������Ҫ���ܵ��ַ�������:" << endl;
	cin >> n;    //��ȡn
	string** p =NULL;         //����һ��ָ�����飬ÿ����Ա����ָ��һ��string���͵�ָ�� ��������ΪNULL
	
	if (p == nullptr) {       //�ж�һ�£�����ǿյģ�����new���п���
		p = new string * [n];//���ٿռ�Ĵ�С��n������
	}
	if (p == nullptr) {
		return -1;            //�������ʧ�ܣ���ô����-1
	}
	if (p != nullptr) {
		goto Start;          //������ٳɹ���goto��start���� ��ʼִ��
	}
End:                       //ִ�н���֮�����ת��
	if (p != nullptr) {      //ִ�н���֮�� pӦ�ò��ǿգ���ô�ͷſռ䣬�˳�����
		delete *p;
		p = nullptr;//ɾ����������ÿ�
		return 0;
	}
Start:                      //����ʼ����ת��
	cout << "�������ַ������ո��س���ʾ����һ���������벻Ҫ����n��" << endl;
	for (int i = 0; i < n; i++) {
		string temp;                  //����һ�������洢����ʱ��string ���뵽������֮���ٸ��������p[i]���ٿռ䲢���롣
		cin >> temp;
		p[i] = new string(temp);     //���� ��ֵ
	}
	int dec=2;                       //����һ�������ж��������ı���
	while (dec != 0 && dec != 1) {    //����û���û�����룬��������Ĳ���0����1����ô�����û��������룬�������ִ�ж�����
		cout << "0.��������1.��������������0��1" << endl;
		cin >> dec;
	}
	for (int i = 0; i < n; i++) {                       //����һ��ð������
		for (int k = 0; k < n - i-1; k++) {
			string a, b;                               //��Ȼ����������ʱ��string �����洢���� ����ת����const char*��ʽ��������strcmp���бȽ�
			a = *p[k];
			b = *p[k + 1];
			if (dec == 1) {
				if (strcmp(a.c_str(), b.c_str())) {                  //�Ƚ�����һ����ͬ����ĸ��ascii��С ���Ҹ���dec��1����0ѡ��ͬ������ʽ��������
					string* tempp = p[k];                            //����һ����ʱ��ָ�룬�����ߵ�˳��
					p[k] = p[k + 1];
					p[k + 1] = tempp;
				}
			}
			else if (dec == 0) {                                 //ͬ�� ����dec=0�����
				if (!strcmp(a.c_str(), b.c_str())) {
					string* tempp = p[k];
					p[k] = p[k + 1];
					p[k + 1] = tempp;
				}
			}
		}
	}
	cout << "�������Ȳ�ͬ����ĸ��ASCIIֵ����󣬽�����£�"<<endl;
	for (int i = 0; i < n; i++) {                           //���������
		cout<< *p[i]<<endl;
	}
	string key;
	cout << "���������Կ��" << endl;
	cin >> key;                                                   //���û�������Կ
	for (int i = 0; i < n; i++) {                          //��ָ�������е�ÿ����Ա��������ͬ����
		string encrypted;                                 //����һ������string �������õ�
		encrypted = XorEn(key, *p[i]);                    //���ü��ܺ��� ��ý��д��string����
		cout << "���ܺ������" << i+1 << "�ǣ�";
		for (const char& c : encrypted) {                  //���������е�ÿ�����֡�
			if (c == '\n') continue;
			cout << "0x"<<std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(c) << " ";//��16������ʽ���
		}
		cout << endl;
		encrypted = XorEn(key,encrypted);                 //�������ٽ��н��� ��Ȼ�㷨һ�� ֻҪ������ͬ�ĺ�����һ�ξͿ�����
		cout << "������" << i + 1 << "���н����ǣ�";
		for (const char& c : encrypted) {                //ͬ�����б���
			cout << c;                                  //����ֻҪ�򵥵�ֱ������ַ��Ϳ�����
		}
		cout << endl;
	}
	goto End;                                          //���ܳ���ִ�н����ˣ�������ת��End �����ڴ� ���˳�����
}