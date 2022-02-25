#include <iostream>
using namespace std;

// 콜백 함수

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

		// TODO 조건 체크
		if (selector(item))
			return item;
	}

	return nullptr;
}

int main()
{
	// 함수 포인터 + 함수 객체 + 템플릿
	// 콜백 (CallBack) : 다시 호출, 역으로 호출

	// 게임을 만들 때 이런 콜백의 개념이 자주 등장한다.
	// ex) MoveTask 실습 등

	// 어떤 상황이 일어나면 -> 이 기능을 호출해줘
	// eX) UI 스킬 버튼을 누르면 -> 스킬을 쓰는 함수를 호출

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