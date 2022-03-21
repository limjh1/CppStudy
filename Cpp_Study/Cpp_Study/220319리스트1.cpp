#include <iostream>
using namespace std;
#include <vector>
#include <list>

// LIST

// vector : 동적 배열
// [    ]
// [        ] 1.5배 증설 후 이전함

// [ data(4) next(4or8)  ] -> Node -> Node
class Node
{
public:
	Node*	_next;
	Node*	_prev;
	int		_data;
};

// list : 연결 리스트
// 단일/이중/원형

// [1]->[2]->[3]->[4]->[5]
// [1]<->[2]<->[3]<->[4]<->[5]
// [1]<->[2]<->[3]<->[4]<->[5]<->

int main()
{
	// list 연결 리스트
	// - 동작 원리
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근 (i 번재 데이터는 어디 있습니까? 벡터마냥 li[3]이 안됨.)

	list<int> li;

	for (int i = 0; i < 100; i++)
	{
		li.push_back(i);
	}

	// li.push_front(10);
	int size = li.size();
	// li.capacity는 없음

	int first = li.front();
	int last = li.back();

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);
	li.erase(li.begin()); // li.pop_front();
	li.remove(10); // list내에 있는 10 이라는 수를 다 지움

	vector<int> v;
	


	return 0;
}