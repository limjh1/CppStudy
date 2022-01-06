#include <iostream>
using namespace std;

// 참조

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

// 값을 수정하지 않는다면, 양쪽 다 일단 문제 없음

// 1) 값 전달 방식

void PrintInfoByCopy(StatInfo info)
{
	cout << "----------------------" << endl;
	cout << "HP"<< info.hp << endl;
	cout << "----------------------" << endl;
}

// 2) 주소 전달 방식
StatInfo globalInfo;
void PrintInfoByPtr(StatInfo* info)
{
	if (info == nullptr)
		return;

	cout << "----------------------" << endl;
	cout << "HP" << info->hp << endl;
	cout << "----------------------" << endl;

	// 별 뒤에 붙인다면?
	// StatInfo* const info
	// info라는 바구니의 내용물(주소)를 바꿀 수 없음
	// info는 주소값을 갖는 바구니 -> 이 주소값이 고정이됨.

	// 별 앞에 붙인다면?
	// const StatInfo* info
	// info '가리키고 있는' 바구니의 내용물을 바꿀 수 없음
	// 원격 바구니의 내용물을 바꿀 수 없음

	// --> 둘 다 하고싶으면 양 쪽에 넣으셈 const StatInfo* const info

	// info[ 주소값 ]
	info = &globalInfo; // -> 별 뒤

	info->hp = 10000; // -> 별 앞

}

// StatInfo 구조체가 1000바이트짜리 대형이라면
// - (값 전달) 1000바이트 복사해야함
// - (주소 전달) 8바이트 고정
// - (참조 전달) 8바이트 고정

// 값 전달처럼 편리하게 사용하면서 주소 전달처럼 주소값을 이용해 일석이조

// 3) 참조 전달 방식

void PrintInfoByRef(const StatInfo& info)
{
	cout << "----------------------" << endl;
	cout << "HP" << info.hp << endl;
	cout << "----------------------" << endl;

	// info.hp = 1000; --> 원본 수정 불가능
}

#define OUT
void ChangeInfo(OUT StatInfo& info)
{

}

int main()
{
	// 4바이트 정수형 바구니 사용	
	int number = 1;

	// * 주소를 담는 바구니
	int* ptr = &number;
	*ptr = 2; // 주소를 타고 이동해서 멀리 있는 주소에 2를 넣는다
	
	// 로우레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같음
	// 실행해보면 포인터링 100% 똑같음
	int& reference = number;

	// C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
	// number라는 바구니에 referecne라는 다른 이름을 지어준 것
	// 앞으로 reference에 뭘 꺼내거나 넣으면 실제 number에 꺼내거나 넣으면 됨
	reference = 3; // number에 3들어간 것

	// 참조 방식을 사용하는 이유는?
	// 참조 전달 때문인디

	StatInfo info;
	CreateMonster(&info);

	//PrintInfoByCopy(info);
	/*PrintInfoByPtr(&info);
	PrintInfoByRef(info);*/

	// 포인터 vs 참조
	// 성능 : 똑같음
	// 편의성 : 참조 > 포인터

	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점은 아님
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있음
	// 참조는 자연스럽게 모르고 지나칠 수도 있음
	// ex) 원본 훼손? --> const를 사용하여 개선

	// 참고 포인터도 const 사용 가능
	// * 기준으로 앞에 붙이느냐, 뒤에 붙이느냐에 따라 의미가 달라짐

	// 2) 초기화 여부
	// 참조하는 대상이 없으면 안됨
	// 반면 포인터는 그냥 어떤 주소라는 의미 --> 대상이 실존 안할수도있음
	// 포인터에서 '없다'는 의미?
	StatInfo* pointer2 = nullptr; // 어떠한 주소도 가르키지 않음
	// 참조 타입은 이런 nullptr

	StatInfo* pointer = &info;
	PrintInfoByPtr(pointer);

	StatInfo& reference1 = info;
	//reference1 = info;
	PrintInfoByRef(reference1);


	// 결론
	// Team by team
	// 그러나 거의 무조건 포인터
	// 언리얼 엔진 --> reference 애용

	// - 없는 경우 고려해야한다면 포인터 ! --> nullptr활용 (특정 조건을 만족한느 몬스터 찾기)
	// - 없는 경우 없이 읽는 용도(readonly) --> const reference&
	// - 그 외 일반적인 경우 ref (명시적으로 호출할 때 out을 붙임)
	// 단, 섞어서 사용 x 포인터면 포인터 참조면 참조
	ChangeInfo(OUT info);

	// 포인터로 사용하던걸 참조로 넘기려면?
	// pointer[ 주소(&info) ]
	PrintInfoByRef(*pointer); // 주소에 들어가서 그 데이터를 참조해라

	// 참조로 사용하던걸 포인터로 넘기려면?
	PrintInfoByPtr(&reference1); // 데이터의 주소값을 참조해라

	// * 포인터 선언 및 주소를 타고 들어가서 데이터 참조
	// & 주소값 참조 및 포인터의 주소값을 넘김

	return 0;
}