#include <iostream>
using namespace std;

// �Լ� ������

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:
	Item() : _itemId(0), _rarity(0), _ownerId(0)
	{

	}

public:
	int _itemId; // �������� �����ϱ� ���� ID
	int _rarity; // ��͵�
	int _ownerId; // ������ ID

};

//Item* FindItemByItemId(Item items[], int itemCount, int itemId)
//{
//	for (int i = 0; i < itemCount; i++)
//	{
//		Item* item = &items[i];
//		// TODO ����
//		if (item->_itemId == itemId)
//			return item;
//	}
//
//	return nullptr;
//}

// typedef bool(ITEM_SELECTOR)(Item* item);
typedef bool(ITEM_SELECTOR)(Item*, int);

Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];

		if (selector(item, value) == true)
			return item;
	}

	return nullptr;
}

bool IsRareItem(Item* item, int value)
{
	return item->_rarity >= value;
}

bool IsOwnerItem(Item* item, int ownerId)
{
	return item->_ownerId == ownerId;
}

int main()
{
	int a = 10;

	// �ٱ��� �ּ�
	// pointer [ �ּ� ] -> �ּ� [      ]

	typedef int DATA;

	// 1) ������   *
	// 2) ���� �̸� pointer 
	// 3) ������ Ÿ�� DATA == int
	DATA* pointer = &a;

	// �Լ�
	// int�� return�ϰ� �Ű������� int a , int b �޴� �Լ��� FUNC_TYPE���� ������
	typedef int(FUNC_TYPE)(int a, int b);
	using FUNC_TYPE = int(int a, int b);

	// 1) ������   *
	// 2) ���� �̸� fn
	// 3) ������ Ÿ�� FUNC_TYPE -> �Լ�(���ڴ� int, int ��ȯ�� int)
	FUNC_TYPE* fn;

	// �Լ� ������
	fn = Sub; // return�̶� �Ű������� ��� �����ϱ� ���� �� ����

	// �Լ��� �̸��� �Լ��� ���� �ּ� (�迭�� ����)
	//int res = Add(1, 2);
	int res = fn(1, 2); // �⺻ ����
	cout << res << endl;

	int res2 = (*fn)(1, 2); // �Լ� �����ʹ� *(���� ������) �پ �Լ� �ּ� !
	cout << res << endl;

	Item items[10] = {};
	items[3]._rarity = 2; // RARE
	Item* rareItem = FindItem(items, 10, IsOwnerItem, 100);


	return 0;
}