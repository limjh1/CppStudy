#include <iostream>
using namespace std;

// 배열 


struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defence = 0xDDDDDDDD;
};


int main()
{
	// TYPE 이름[개수];


	//배열의 크기는 상수여야 함 (VC 컴파일러 기준)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// 변수 = 바구니
	int a = 10;
	a = 3;

	// 배열은 [이름] 조금 다르게 동작
	// StatInfo players[10];
	// players = monsters;

	// 배열의 이름은 ?
	// 배열의 이름은 곧 배열의 시작 주소
	// 정확히는 시작 위치를 가리키는 TYPE* 포인터
	auto WhoAmI = monsters;

	StatInfo* monster_0 = monsters; // 배열의 첫 주소를 포인터로 받아감
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// 포인터의 덧셈 --> StatInfo 타입 바구니 한개씩 이동하라는 의미

	StatInfo* monster_1 = monsters + 1; // 다음 주소를 가리킴
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// 포인터와 참조는 자유자재로 변환가능
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// 완전히 다른 의미
	StatInfo temp = *(monsters + 2); // 배열의 3번째 주소의 데이터를 temp로 복사함
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4; // temp만 바뀌고 원본은 안바뀜


	// 이를 좀 더 자동화
	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = 1 * (i + 1);
	}

	// *(monsters+i) 불편, 가독성 떨어짐
	// 인덱스 사용
	// 배열 인덱스 0번부터 시작 배열이름[N]
	// *(monsters+i) = monsters[N]

	monsters[0].hp = 100;
	monsters[0].attack = 100;
	monsters[0].defence = 100;

	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = monsters[i];
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = 1 * (i + 1);
	}

	// 배열 초기화 문법
	int numbers[5] = {}; // 0으로 초기화
	int numbers1[10] = { 1,2,3,4,5 }; // 설정 값 이외에 값은 0으로 초기화
	int numbers2[] = { 1,2,3,4,5,6,7,8,9 }; // 데이터 크기에 해당하는 배열로 만들어줌

	char helloStr[] = { 'H','e','l','l','o','\0' };
	cout << helloStr << endl;


	return 0;
}