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

// 특정 조건을 만족하는 몬스터를 찾는 함수
StatInfo* FIndMosnter()
{
	// TODO : Heap 영영게서 뭔가를 찾아봄
	// 찾았따!
	// return monster~;

	return nullptr; // 몬스터를 못찾앗따!라는것을 사용할 수 있음
}

void PrintInfo(StatInfo* info)
{
	if (info == nullptr) return; // null 체크

	cout << "-----------" << endl;
	cout << "hp " << info->hp << endl;
	cout << "atk " << info->attack << endl;
	cout << "def " << info->defence << endl;
	cout << "-----------" << endl;

	// * 뒤에 붙인다면?
	// StatInfo* const info --> info = &globalInfo; 막힘
	// info라는 바구니의 내용물(주소)를 바꿀 쑤 없음
	// info 주소값을 갖는 바구니 -> 이 주소값이 고정이다!!
	
	// * 이전에 붙인다면?
	// const StatInfo* info --> info->hp = 100; 막힘
	// info가 가리키고 있는 바구니의 내용들을 바꿀 수 없음
	// '원격' 바구니의 내용물을 바꿀 수 없음
	// 
	// 양쪽에 다 const하면 다 못바꾸게 막을 수 있음
	// 
	// info [ 주소값 ] --> 주소값 [ 데이터 ]
	//
}

void PrintInfo(const StatInfo& info) // 레버런스랑 const는 짝지어서 많이 사용할 것임
{
	cout << "-----------" << endl;
	cout << "hp " << info.hp << endl;
	cout << "atk " << info.attack << endl;
	cout << "def " << info.defence << endl;
	cout << "-----------" << endl;

	// 신입이 왔다
	// info.hp = 10000; , 원본 손상
}

void PrintInfoByPtr(StatInfo* info)
{
	if (info == nullptr) return; // null 체크

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

// 아무 의미가 없음
// #define OUT 123 하면 123으로 의미하지만
#define OUT
void ChangeInfo(OUT StatInfo& info) 
{
	info.hp = 1000;
}

// 섞어서 금지
void ChangeInfo(StatInfo& info, StatInfo* info2)
{
	info.hp = 1000;
}

int main()
{
	StatInfo info;
	CreateMonster(&info);

	// 포인터 vs 참조
	// 성능 : 똑같음!
	// 편의성 : 참조 승!
	// 하지만!
	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다.
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있는데,
	// 참조는 자연스럽게 모르고 지나칠 수도 있음!
	// ex) 마음대로 고친다면?
	// 수정할 수 없게 할 수 있긴함. const 사용!

	// 참고사항) 포인터도 const를 사용 가능
	// * 기준으로 앞에 붙이느냐, 뒤에 붙이느냐에 따라 의미가 달라진다!!

	// 2) 초기와 여부
	// 참조 타입은 바구니의 2번째 이름
	// -> 참조하는 대상이 없으면 안됨!!

	// 포인터에서 '없다'는 의미로 ?
	// StatInfo* ptr = NULL; // NULL == 0
	// NULL에서 발전해서 어떠한 주소도 가리키지 않는다는 것을 말함
	// nullptr활용하는 것에서 포인터가 더 좋음, findMonster!!
	StatInfo* ptr = nullptr; 
	ptr = &info;
	PrintInfo(ptr); // 주소값을 넘겨주는 구나! 원본이네!

	// 포인터할때는 nullptr 널체크 하는것이 중요함!! 아니면 크래시 자주 일어날 거여

	// 무조건 처음부터 참조해야함!, 참조하는 대상이 없으면 안된다
	//StatInfo& ref; 
	//ref = info;
	StatInfo& ref = info;
	PrintInfo(info); // 원본인지, 참조인지 잘 모를 수 있음


	// 결론
	// 정해진 결론은 없다. Team by Team
	// 구글 오픈소스를 보면 거의 무조건 포인터 사용
	// 언리얼 에서는 ref도 애용함

	// 선호 방향
	// - 없는 경우도 고려해야 한다면 pointer (null check 필수) ex) findMonster()
	// - 없는 경우가 없다, 바뀌지 않고 읽는 용도 (read only) --> const ref&
	// - 그 외 일반적인 경우 ref (명시적으로 호출할 때 OUT을 붙인다)
	ChangeInfo(OUT info); // 이러면 힌트를 줄 수 있음

	// -- 단, 다른 사람이 pointer를 만들어놓은걸 이어서만든다면,
	// 계속 pointer를 사용함 (섞어서 사용하지 않음)

	// 포인터로 사용하던걸 참조로 넘겨주려면?
	// ptr[ 주소(&info) ]  info [data]
	// StatInfo& ref = *ptr;
	PrintInfoByRef(*ptr); // *을 사용해서 뿅 이동해라 주소값으로

	// 참조로 사용하던걸 포인터로 넘겨주려면?
	// 주소값을 참조해라
	PrintInfoByPtr(&ref);

	return 0;
}