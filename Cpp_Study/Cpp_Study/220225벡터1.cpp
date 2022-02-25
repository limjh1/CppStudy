#include <iostream>
#include <vector>
using namespace std;

// 벡터

int main()
{
	// STL (Standard Template Library)
	// 프로그래밍할 때 필요한 자료구조/알고리즘들을
	// 템플릿으로 제공하는 라이브러리

	// 컨테니어(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	// 배열 ,, 단점 : 사이즈를 넘어서 사용하기에 불편함
	const int MAX_SIZE = 10;
	int arr[MAX_SIZE] = { };

	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] << endl;
	}

	// 동적 배열
	// 매우 매우 중요한 개념 -> 어떤 원리로 배열을 유동적으로 사용한 것인가?

	// 1) (여유분을 두고) 메모리를 할당한다
	// 2) 여유분까지 꽉 찼으면, 메모리를 증설한다

	// Q1) 여유분은 얼만큼이 적달할까?
	// Q2) 증설을 얼만큼 해야하는가?
	// Q3) 기존의 데이터는 어떻게 처리할까?
	
	//// 증설
	//int* arr2 = new int[100]; // 꽉 찼으면
	//delete arr2; // 삭제하고
	//arr2 = new int[1000]; // 메모리 증설

	
	vector<int> v;
	// vector<int> v(1000, 0); v(size, init) size로 resize하는것, init으로 모든 값 초기화
	// vector<int> v2 = v 하면 복사 댐

	// size (실제 사용 데이터 개수)
	// 1 2 3 4 5 6 7 ...
		
	// size가 처음부터 1000
	v.resize(1000);

	// capacity (여유분을 포함한 용량 개수), 늘어나긴하는데 줄어들진 않음
	// 1 2 3 4 5 6 7 ... 
	// 1 2 3 4 6 9 13 19 28 42 63 ... 1000 2000 4000 8000 ...

	// capacity가 처음부터 1000
	// v.reserve(1000);

	// 증설할때 여유 공간이 없을 때는 이사를 해야함 새로운 배열 생성 -> 복사 -> 원래 배열 삭제
	// 비용이 많이 들어. 하지만 여유 공간이 생길수록 이사하는 비용이 없어도 돼
	// 그래서 capacity는 1.5배로 늘리는거임 후에는 엄청나게 여유로워질거

	for (int i = 0; i < 1001; i++)
	{
		v[i] = 100; // 이전ㅌ에 할당되어진 배열에 할당
		v.push_back(100); // 그 뒤로 새로 만들어서 배열에 할당
		cout << v.size() << " " << v.capacity() << endl;
	}


	v.clear(); // capacity는 안없어짐
	vector<int>().swap(v); // 깡통정보랑 스왑하여 없앰
	cout << v.size() << " " << v.capacity() << endl;

	return 0;
}