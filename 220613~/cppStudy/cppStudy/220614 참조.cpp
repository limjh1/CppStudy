#include <iostream>

using namespace std;

struct StatInfo
{
	int hp; // 0
	int attack; // +4
	int defence; // +8

};

void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 9;
	info->defence = 5;
}

// Ư�� ������ �����ϴ� ���͸� ã�� �Լ�
StatInfo* FIndMosnter()
{
	// TODO : Heap �����Լ� ������ ã�ƺ�
	// ã�ҵ�!
	// return monster~;

	return nullptr; // ���͸� ��ã�ѵ�!��°��� ����� �� ����
}

void PrintInfo(StatInfo* info)
{
	if (info == nullptr) return; // null üũ

	cout << "-----------" << endl;
	cout << "hp " << info->hp << endl;
	cout << "atk " << info->attack << endl;
	cout << "def " << info->defence << endl;
	cout << "-----------" << endl;

	// * �ڿ� ���δٸ�?
	// StatInfo* const info --> info = &globalInfo; ����
	// info��� �ٱ����� ���빰(�ּ�)�� �ٲ� �� ����
	// info �ּҰ��� ���� �ٱ��� -> �� �ּҰ��� �����̴�!!
	
	// * ������ ���δٸ�?
	// const StatInfo* info --> info->hp = 100; ����
	// info�� ����Ű�� �ִ� �ٱ����� ������� �ٲ� �� ����
	// '����' �ٱ����� ���빰�� �ٲ� �� ����
	// 
	// ���ʿ� �� const�ϸ� �� ���ٲٰ� ���� �� ����
	// 
	// info [ �ּҰ� ] --> �ּҰ� [ ������ ]
	//
}

void PrintInfo(const StatInfo& info) // ���������� const�� ¦��� ���� ����� ����
{
	cout << "-----------" << endl;
	cout << "hp " << info.hp << endl;
	cout << "atk " << info.attack << endl;
	cout << "def " << info.defence << endl;
	cout << "-----------" << endl;

	// ������ �Դ�
	// info.hp = 10000; , ���� �ջ�
}

void PrintInfoByPtr(StatInfo* info)
{
	if (info == nullptr) return; // null üũ

	cout << "-----------" << endl;
	cout << "hp " << info->hp << endl;
	cout << "atk " << info->attack << endl;
	cout << "def " << info->defence << endl;
	cout << "-----------" << endl;
}

void PrintInfoByRef(const StatInfo& info) 
{
	cout << "-----------" << endl;
	cout << "hp " << info.hp << endl;
	cout << "atk " << info.attack << endl;
	cout << "def " << info.defence << endl;
	cout << "-----------" << endl;
}

// �ƹ� �ǹ̰� ����
// #define OUT 123 �ϸ� 123���� �ǹ�������
#define OUT
void ChangeInfo(OUT StatInfo& info) 
{
	info.hp = 1000;
}

// ��� ����
void ChangeInfo(StatInfo& info, StatInfo* info2)
{
	info.hp = 1000;
}

int main()
{
	StatInfo info;
	CreateMonster(&info);

	// ������ vs ����
	// ���� : �Ȱ���!
	// ���Ǽ� : ���� ��!
	// ������!
	// 1) ���Ǽ� ����
	// ���Ǽ��� ���ٴ°� �� �������� �ƴϴ�.
	// �����ʹ� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� �� �� �ִµ�,
	// ������ �ڿ������� �𸣰� ����ĥ ���� ����!
	// ex) ������� ��ģ�ٸ�?
	// ������ �� ���� �� �� �ֱ���. const ���!

	// �������) �����͵� const�� ��� ����
	// * �������� �տ� ���̴���, �ڿ� ���̴��Ŀ� ���� �ǹ̰� �޶�����!!

	// 2) �ʱ�� ����
	// ���� Ÿ���� �ٱ����� 2��° �̸�
	// -> �����ϴ� ����� ������ �ȵ�!!

	// �����Ϳ��� '����'�� �ǹ̷� ?
	// StatInfo* ptr = NULL; // NULL == 0
	// NULL���� �����ؼ� ��� �ּҵ� ����Ű�� �ʴ´ٴ� ���� ����
	// nullptrȰ���ϴ� �Ϳ��� �����Ͱ� �� ����, findMonster!!
	StatInfo* ptr = nullptr; 
	ptr = &info;
	PrintInfo(ptr); // �ּҰ��� �Ѱ��ִ� ����! �����̳�!

	// �������Ҷ��� nullptr ��üũ �ϴ°��� �߿���!! �ƴϸ� ũ���� ���� �Ͼ �ſ�

	// ������ ó������ �����ؾ���!, �����ϴ� ����� ������ �ȵȴ�
	//StatInfo& ref; 
	//ref = info;
	StatInfo& ref = info;
	PrintInfo(info); // ��������, �������� �� �� �� ����


	// ���
	// ������ ����� ����. Team by Team
	// ���� ���¼ҽ��� ���� ���� ������ ������ ���
	// �𸮾� ������ ref�� �ֿ���

	// ��ȣ ����
	// - ���� ��쵵 ����ؾ� �Ѵٸ� pointer (null check �ʼ�) ex) findMonster()
	// - ���� ��찡 ����, �ٲ��� �ʰ� �д� �뵵 (read only) --> const ref&
	// - �� �� �Ϲ����� ��� ref (��������� ȣ���� �� OUT�� ���δ�)
	ChangeInfo(OUT info); // �̷��� ��Ʈ�� �� �� ����

	// -- ��, �ٸ� ����� pointer�� ���������� �̾����ٸ�,
	// ��� pointer�� ����� (��� ������� ����)

	// �����ͷ� ����ϴ��� ������ �Ѱ��ַ���?
	// ptr[ �ּ�(&info) ]  info [data]
	// StatInfo& ref = *ptr;
	PrintInfoByRef(*ptr); // *�� ����ؼ� �� �̵��ض� �ּҰ�����

	// ������ ����ϴ��� �����ͷ� �Ѱ��ַ���?
	// �ּҰ��� �����ض�
	PrintInfoByPtr(&ref);

	return 0;
}