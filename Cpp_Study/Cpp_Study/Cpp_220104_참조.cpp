#include <iostream>
using namespace std;

// ����

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void CreateMonster(StatInfo* info)
{
	info->hp = 199;
}

void CreateMonster(StatInfo info)
{
	info.hp = 100;
}

// ���� �������� �ʴ´ٸ�, ���� �� �ϴ� ���� ����

// 1) �� ���� ���

void PrintInfoByCopy(StatInfo info)
{
	cout << "----------------------" << endl;
	cout << "HP"<< info.hp << endl;
	cout << "----------------------" << endl;
}

// 2) �ּ� ���� ���
StatInfo globalInfo;
void PrintInfoByPtr(StatInfo* info)
{
	if (info == nullptr)
		return;

	cout << "----------------------" << endl;
	cout << "HP" << info->hp << endl;
	cout << "----------------------" << endl;

	// �� �ڿ� ���δٸ�?
	// StatInfo* const info
	// info��� �ٱ����� ���빰(�ּ�)�� �ٲ� �� ����
	// info�� �ּҰ��� ���� �ٱ��� -> �� �ּҰ��� �����̵�.

	// �� �տ� ���δٸ�?
	// const StatInfo* info
	// info '����Ű�� �ִ�' �ٱ����� ���빰�� �ٲ� �� ����
	// ���� �ٱ����� ���빰�� �ٲ� �� ����

	// --> �� �� �ϰ������ �� �ʿ� ������ const StatInfo* const info

	// info[ �ּҰ� ]
	info = &globalInfo; // -> �� ��

	info->hp = 10000; // -> �� ��

}

// StatInfo ����ü�� 1000����Ʈ¥�� �����̶��
// - (�� ����) 1000����Ʈ �����ؾ���
// - (�ּ� ����) 8����Ʈ ����
// - (���� ����) 8����Ʈ ����

// �� ����ó�� ���ϰ� ����ϸ鼭 �ּ� ����ó�� �ּҰ��� �̿��� �ϼ�����

// 3) ���� ���� ���

void PrintInfoByRef(const StatInfo& info)
{
	cout << "----------------------" << endl;
	cout << "HP" << info.hp << endl;
	cout << "----------------------" << endl;

	// info.hp = 1000; --> ���� ���� �Ұ���
}

#define OUT
void ChangeInfo(OUT StatInfo& info)
{

}

int main()
{
	// 4����Ʈ ������ �ٱ��� ���	
	int number = 1;

	// * �ּҸ� ��� �ٱ���
	int* ptr = &number;
	*ptr = 2; // �ּҸ� Ÿ�� �̵��ؼ� �ָ� �ִ� �ּҿ� 2�� �ִ´�
	
	// �ο췹��(�����) �������� ���� �۵� ����� int*�� �Ȱ���
	// �����غ��� �����͸� 100% �Ȱ���
	int& reference = number;

	// C++ ���������� number��� �ٱ��Ͽ� �� �ٸ� �̸��� �ο��� ��.
	// number��� �ٱ��Ͽ� referecne��� �ٸ� �̸��� ������ ��
	// ������ reference�� �� �����ų� ������ ���� number�� �����ų� ������ ��
	reference = 3; // number�� 3�� ��

	// ���� ����� ����ϴ� ������?
	// ���� ���� �����ε�

	StatInfo info;
	CreateMonster(&info);

	//PrintInfoByCopy(info);
	/*PrintInfoByPtr(&info);
	PrintInfoByRef(info);*/

	// ������ vs ����
	// ���� : �Ȱ���
	// ���Ǽ� : ���� > ������

	// 1) ���Ǽ� ����
	// ���Ǽ��� ���ٴ°� �� ������ �ƴ�
	// �����ʹ� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� �� �� ����
	// ������ �ڿ������� �𸣰� ����ĥ ���� ����
	// ex) ���� �Ѽ�? --> const�� ����Ͽ� ����

	// ���� �����͵� const ��� ����
	// * �������� �տ� ���̴���, �ڿ� ���̴��Ŀ� ���� �ǹ̰� �޶���

	// 2) �ʱ�ȭ ����
	// �����ϴ� ����� ������ �ȵ�
	// �ݸ� �����ʹ� �׳� � �ּҶ�� �ǹ� --> ����� ���� ���Ҽ�������
	// �����Ϳ��� '����'�� �ǹ�?
	StatInfo* pointer2 = nullptr; // ��� �ּҵ� ����Ű�� ����
	// ���� Ÿ���� �̷� nullptr

	StatInfo* pointer = &info;
	PrintInfoByPtr(pointer);

	StatInfo& reference1 = info;
	//reference1 = info;
	PrintInfoByRef(reference1);


	// ���
	// Team by team
	// �׷��� ���� ������ ������
	// �𸮾� ���� --> reference �ֿ�

	// - ���� ��� ����ؾ��Ѵٸ� ������ ! --> nullptrȰ�� (Ư�� ������ �����Ѵ� ���� ã��)
	// - ���� ��� ���� �д� �뵵(readonly) --> const reference&
	// - �� �� �Ϲ����� ��� ref (��������� ȣ���� �� out�� ����)
	// ��, ��� ��� x �����͸� ������ ������ ����
	ChangeInfo(OUT info);

	// �����ͷ� ����ϴ��� ������ �ѱ����?
	// pointer[ �ּ�(&info) ]
	PrintInfoByRef(*pointer); // �ּҿ� ���� �� �����͸� �����ض�

	// ������ ����ϴ��� �����ͷ� �ѱ����?
	PrintInfoByPtr(&reference1); // �������� �ּҰ��� �����ض�

	// * ������ ���� �� �ּҸ� Ÿ�� ���� ������ ����
	// & �ּҰ� ���� �� �������� �ּҰ��� �ѱ�

	return 0;
}