#include <iostream>
using namespace std;

// 파일 분할 관리

// 객체지향 프로그래밍
// 
// 절차(procedureal)지향 프로그래밍
// - 함수(procedure)

// 데이터 + 가공(로직, 동작)

// 객체지향 = 객체
// 객체 --> 플레이어, 몬스터, GAME ROOM, 등 오브젝트

// Design Knight
// - 속성(데이터) : HP, ATK, POSITION(x,y)
// - 기능(동작)   : MOVE, ATK, DIE

// 생성자(Constructor)와 소멸자(Destructor)
// 클래스에 '소속'된 함수들을 멤버 함수
// 이 중에서 [시작]과 [끝]을 알리는 함수들
// - 시작(탄생) -> 생성자 (여러개 가능)
// - 끝(소멸) -> 소멸자 (오직 1개만)

// [암시적(Implicit) 생성자]
// 생성자를 명시적으로 만들지 않으면,
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐.
// -> 그러나 우리가 명시적(Explicit)으로 아무 생성자 하나 만들면,
// 자동으로 만들어지던 [기본 생성자]는 더 이상 만들어지지 않음..!


// class는 일종의 설계도
class Knight // 설계도 개념, CPP에서는 struct랑 비슷
{
public:
	// [1] 기본 생성자 (인자가 없음)
	Knight()
	{
		cout << "CALL Knight() Constructor" << endl;
		
		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// [2] 복사 생성자 (자기 자신의 클래스 참조 타입을 인자로 받음)
	// (일반적으로 '똑같은' 데이터를 지닌 객체가 생성되길 기대한다
	Knight(const Knight& knight)
	{
		cout << "CALL Knight Copy Constructor" << endl;

		_hp = knight._hp;
		_attack = knight._attack;
		_posX = knight._posX;
		_posY = knight._posY;
	}

	// [3] 기타 생성자
	
	// 이 중에서 인자를 1개만 받는 [기타 생성자]를 
	// [타입 변환 생성자]라고 부르기도 함

	// 명시적인 용도로만 사용할 것!
	explicit Knight(int hp)
	{
		cout << "CALL Knight(int) Constructor" << endl;

		_hp = hp;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	Knight(int hp, int attack, int posX, int posY)
	{
		_hp = hp;
		_attack = attack;
		_posX = posX;
		_posY = posY;
	}

	// 소멸자
	~Knight()
	{
		cout << "CALL ~Knight() Destructor" << endl;
	}


	// 멤버 함수 선언
	void Move(int y, int x);
	void Attack();
	void Die() 
	{ 
		// this->_hp = 0;
		_hp = 0; 
		cout << "Die" << endl; 
	};

public:
	// 멤버 변수 선언
	int _hp;
	int _attack;
	int _posY;
	int _posX;

};

// 일반 함수
void Move(Knight* Knight, int y, int x)
{
	Knight->_posX = x;
	Knight->_posY = y;
}

// 객체지향
void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

void HelloKnight(Knight k)
{
	cout << "Hello Knight" << endl;
}

// Instantiate 객체를 만든다
int main()
{
	// Knight k1; // 기본 생성자
	Knight k1(100);
	//k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	//Move(&k1, 2, 2); // 일반 함수

	Knight k2(k1); // k1과 똑같은거를 만드는거임. 복사 생성자
	Knight k3 = k1; // 이거도 복사 생성자, 생성과 동시에 복사

	// 이건 복사 생성자랑 의미가 다름
	Knight k4; // 기본 생성자로 만들고
	k4 = k1; // k1을 k4에 복사해줘

	Knight k5(100, 10, 0, 0); // 기타 생성자

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	// 암시적 형변환 -> 컴파일러가 알아서 바꿔치기
	int num = 1;

	float f = (float)num; // 명시적 < 코드로 num을 float로 변환
	double d = num; // 암시적 < 컴파일러가 알아서 변환

	//// 암시적으로 변환 explicit 붙이면 불가능
	//Knight k6;
	//k6 = 1; // 타입 변환 생성자, Knight(int hp)로 드감

	//HelloKnight(5);

	Knight k6;
	k6 = (Knight)1; // 명시적

	HelloKnight((Knight)5); // 명시적

	return 0;
}