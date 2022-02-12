#include <iostream>
using namespace std;

// 타입 변환 (포인터)

class Knight
{
public:
	int _hp = 0;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	Item(const Item* item)
	{
		cout << "Item(const Item&)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Item" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {}; // 이런 저런 정보들로 인해 비대해진 
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};
class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		// _itemType = IT_WEAPON;

		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}
	~Weapon()
	{
		cout << "~Weapon()" << endl;
	}
	virtual void Test()
	{
		cout << "Test Weapon" << endl;
	}
public:
	int _damage = 0;

};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		// _itemType = IT_ARMOR;

		cout << "Armor()" << endl;
	}
	~Armor()
	{
		cout << "~Armor()" << endl;	
	}
public:
	int _defence = 0;
};
void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{
	item->Test();
}

int main()
{
	// 복습
	{
		// Stack [ type(4) dbid(4) dummy(4096) ]
		Item item;

		// 동적 할당
		// Stack [ 주소(4~8) ] -> Heap [ type(4) dbid(4) dummy(4096) ]
		Item* item2 = new Item();

		TestItem(item);
		TestItem(*item2);
			
		TestItemPtr(&item);
		TestItemPtr(item2);

		// delete안하면 메모리 누수(Memory Leak) -> 점점 가용 메모리 줄어들어서 CRASH
		delete item2;
	}

	// 배열
	{
		cout << "----------------------" << endl;

		// 진짜 아이템이 100개 있는 것 (스택 메모리에 올라와 있는)
		Item item3[100] = {};

		cout << "----------------------" << endl;

		// 아이템이 100개 있는 것이 아님.
		// 아이템을 가리키는 바구니가 100개. 실제 아이템은 1개도 없을 수도 있음
		Item* item4[100] = {};

		for (int i = 0; i < 100; i++)
		{
			item4[i] = new Item();
		}

		cout << "----------------------" << endl;

		for (int i = 0; i < 100; i++)
		{
			delete(item4[i]);
		}
	}

	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{
		// Stack [ 주소 ] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();

		// Stack [ 주소 ]
	//	Item* item = (Item*)knight;
	//	item->_itemType = 2;
	//	item->_itemDbId = 1;

		delete knight;
	}

	// 부모 -> 자식 변환 테스트
	{
		Item* item = new Item();
			
		// 명시적으로만 가능하지만 크래시
		// Weapon* weapon = (Weapon*)item;
		// weapon->_damage = 10;

		delete item;
			
	}

	// 자식 -> 부모 변환 테스트
	{
		Weapon* weapon = new Weapon();

		// 암시적으로도 가능
		Item* item = weapon;

		TestItemPtr(item);

		delete weapon;
	}

	// 명시적으로 타입 변환할 때는 항상 조심해야함
	// 암시적으로 될 때는 항상 안전한가?
	// -> 평생 명시적으로 타입 변환(캐스팅)은 안 하면 되는거 아닌가?

	Item* inventory[20] = {}; // 이런식으로 무기 방어구를 한번에 만드려면 Item으로 생성하는 것

	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2; // 0 1

		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;
		case 1:
			inventory[i] = new Armor();
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
		{
			continue;
		}

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	// 중요함	
	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
		{
			continue;
		}

		//if (item->_itemType == IT_WEAPON)
		//{
		//	Weapon* weapon = (Weapon*)item;
		//	delete weapon;
		//}
		//else
		//{
		//	Armor* armor = (Armor*)item;
		//	delete armor;
		//}

		// 최상위 계층의 소멸자가 가상함수가 되면 자식 계층들의 소멸자도 다 가상함수가 되어서
		// 한방에 delete 가능
		delete item;

	}

	// [결론]
	// - 포인터 vs 일반 타입 : 차이를 이해해야함
	// - 포인터 사이의 타입 변환(캐스팅)을 할 땐 매우 조심해야함 특히, 명시적 변환
	// 면접에서 중요한 내용
	// - 부모 자식 관계에서 부모 클래스의 소멸자에는 까먹지 말고 virtual을 붙이자


	return 0;
}