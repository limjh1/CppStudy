#include <iostream>
using namespace std;

// �ݹ� �Լ�

class Item
{
public:

public:
	int _itemId = 0;
	int _rarity = 0;
	int _owenrId = 0;

};

class FindByOwnerId
{
public:
	bool operator()(const Item* item)
	{
		return (item->_owenrId == _owenrId);
	}

public:
	int _owenrId;
};

class FindByRarity
{
public:
	bool operator()(const Item* item)
	{
		return (item->_rarity == _rarity);
	}

public:
	int _rarity;
};

template<typename T>
Item* FindItem(Item items[], int itemCount, T selector)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];

		// TODO ���� üũ
		if (selector(item))
			return item;
	}

	return nullptr;
}

int main()
{
	// �Լ� ������ + �Լ� ��ü + ���ø�
	// �ݹ� (CallBack) : �ٽ� ȣ��, ������ ȣ��

	// ������ ���� �� �̷� �ݹ��� ������ ���� �����Ѵ�.
	// ex) MoveTask �ǽ� ��

	// � ��Ȳ�� �Ͼ�� -> �� ����� ȣ������
	// eX) UI ��ų ��ư�� ������ -> ��ų�� ���� �Լ��� ȣ��

	Item items[10];
	items[3]._owenrId = 100;
	items[8]._rarity = 2;

	FindByOwnerId functor1;
	functor1._owenrId = 100;

	FindByRarity functor2;
	functor2._rarity = 1;

	Item* item1 = FindItem(items, 10, functor1);
	Item* item2 = FindItem(items, 10, functor2);


	return 0;
}