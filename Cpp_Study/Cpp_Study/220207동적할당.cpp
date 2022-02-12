#include <iostream>
using namespace std;

// 동적 할당

// 메모리 구조 복습
// - 실행 코드가 저장되는 영역 -> 코드 영역
// - 전역(global) / 정적(static) 변수 -> 데이터 영역
// - 지역변수/매개 변수 -> 스택 영역
// - 동적 할당 -> 힙 영역

// 실제 상황)
// - MMORPG 동시 접속 1명~5만명, 몬스터 1마리~500만마리
// - 몬스터 생성 이벤트 -> 5분동안 몬스터가 10배 많이 나옴 -> 5천만마리..

// - 스택 영역
// 함수가 끝나면 같이 정리되는 불안정한 메모리
// 잠시 함수에 매개변수를 넘긴다거나, 하는 용도로는 ok
// - 메모리 영역
// 프로그램이 실행되는 도중에는 '무조건' 사용되는

// 희망사항)
// - 필요할 때만 사용하고, 필요없으면 반납하는 메모리
// - 생성/소멸 시점을 관리할 수 있는 메모리
// ==> Heap 영역
// 동적할당과 연관된 함수/연산자 : malloc / free, new / delete, new[] / delete[]

// malloc
// - 할당할 메모리 크기를 건내준다.
// - 메모리 할당 후 시작 주소를 가리키는 포인터를 반환해준다. (메모리 부족 NULL)

// free
// - malloc 혹은 기타 calloc, realloc 등 할당된 영역을 해제
// - 힙 관리자가 할당/미할당 여부를 구분해서 관리

// new / delete
// - c++ 추가됨
// - malloc/free 함수, new/delete 연산자(operator)

// new[] / delete[]
// - new 가 malloc에 비해 좋긴 한디, 배열과 같이 N개 데이터를 같이 할당하려면?
// malloc/free vs new/delete
// - 사용 편의성 : new/delete WIN
// - 타입에 상관없이 특정한 크기의 메모리 영역을 할당하려면 -> malloc/free WIN

// 둘의 가장 근본적인 차이
// - new/delete는 생성타입이 클래스일 경우 생성자/소멸자를 호출해준다



class Monster
{
public:
	Monster()
	{
		_hp = 100;
		_x = 5;
		_y = 1;

		cout << "생성자" << endl;
	}

	~Monster()
	{
		cout << "~소멸자" << endl;
	}
public:

	int _hp;
	int _x;
	int _y;
};

// Monster monster[500 * 10000];

int main()
{
	// 유저 영역 [메모장] [LOL] ...
	// -----------------------
	// 커널 영역 (windows등의 핵심 코드)

	// 유저 영역) 운영체제에서 제공되는 API 호출
	// 커널 영역) 메모리 할당해서 건내줌
	// 유저 영역) 씀

	// [                                         ]
	// c++ 에서는 기본적으로 CRT(c런타임 라이브러리)의 [힙 관리자]를 통해 힙 영역 사용
	// 단, 정말 원한다면 직접 API를 통해 힙을 생성하고 관리 가능(MMORPG 서버 메모리 폴링)

	// void* 는 무엇일까
	// *가 있으니까 포인터는 포인터(주소를 담는 바구니) --> OK
	// 타고 가면 void 아무것도 없다? --> NO
	// 타고 가면 void 뭐가 있는지 모르겠으니까 너가 적당히 변환해서 사용해라 --> OK
	void* pointer = malloc(sizeof(Monster));

	Monster* m1 = (Monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	// Heap Overflow
	// - 유효한 힙 범위를 초과해서 사용하는 문제

	// free하지 않으면 메모리 누수
	free(pointer);

	// use after free 방지 null로 밀어주기
	//pointer = nullptr;
	//m1 = nullptr;

	// Double free
	// - 대부분 Crash만 남
	// free(pointer);

	// Use-After-Free
	// - 프로그래머 입장 : 못찾음	
	//m1->_hp = 100;
	//m1->_x = 1;
	//m1->_y = 2;

	Monster* m2 = new Monster;
	m2->_hp = 200;
	m2->_x = 2;
	m2->_y = 3;
	delete m2;

	Monster* m3 = new Monster[5];
	m3->_hp = 200;
	m3->_x = 2;
	m3->_y = 3;

	Monster* m4 = (m3 + 1);
	m4->_hp = 200;
	m4->_x = 2;
	m4->_y = 3;
	delete[] m3;

	return 0;
}