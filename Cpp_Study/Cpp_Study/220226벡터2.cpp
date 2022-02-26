#include <iostream>
#include <vector>
using namespace std;

// ����

int main()
{
	// ���״Ͼ�(Container) : �����͸� �����ϴ� ��ü (�ڷᱸ�� Data Structure)

	// vector (���� �迭)
	// - vector�� ���� ���� (size/capacity)
	// - �߰� ����/����
	// - ó��/�� ����/����
	// - ���� ����

	// �ݺ���(Iterator) : �����Ϳ� ������ ����, �����̳��� ����(������)�� ����Ű��,
	// ����/���� ���ҷ� �̵� ����
	vector<int> v(10); // 10���� v �迭

	v.reserve(1000); // 1000ĭ�� ����


	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		v[i] = i;
	}

	//// �ݺ���
	//vector<int>::iterator it;
	//int* ptr;

	//it = v.begin();
	//ptr = &v[0];

	//cout << (*it) << endl;
	//cout << (*ptr) << endl;

	//// ������ ������ ����, ������ ���� ����
	//it++;
	//++it;
	//ptr++;
	//++ptr;

	//it += 2;
	//ptr += 2;
	//
	//int a = 1;
	//int b = a++; // b=1 -> a=2
	//int c = ++a; // c <- (a=2)

	//vector<int>::iterator itBegin = v.begin();
	//vector<int>::iterator itEnd = v.end();

	// �� �����غ������� ���̴� ����
	// iterator �� vector�� �ƴ϶� , �ٸ� �����̳ʿ��� ���������� �ִ� ���� -> ���ϼ�
	// �ٸ� �����̳ʴ� v[i]�� ���� �ε��� ������ �� �� ���� ����
	for (vector<int>::iterator it = v.begin(); it < v.end(); ++it)
	{
		cout << (*it) << endl;	
	}

	int* ptrBegin = &v[0]; // v.begin()._ptr;
	int* ptrEnd = ptrBegin + 10; // v.end()._ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << (*ptr) << endl;
	}

	// const int*
	// vector<int>::const_iterator cit1 = v.cbegin();
	// *cit1 = 100; ���� �Ұ���
	
	// ������
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << (*it) << endl;
	}

	// - �߰� ����/���� (��ȿ������, �ϳ� �Ϸ��� �� �ű���� �־����)
	// -- õ������� õ���� ���������
	// - ó��/�� ����/����
	// -- ó���� �߰��̶� �Ȱ��� ��ȿ������
	// -- ���� �ѹ��� �����ϸ� �ȴ�, ȿ����
	// -- v.push_back(), v.pop_back()
	// - ���� ���� (random access)	
	// -- n��° �����͸� �ٷ� ����, v[i] = 3;

	// vector = ���� �迭 = �������� Ŀ���� �迭 = �迭
	// ���Ұ� �ϳ��� �޸� ��Ͽ� �����ϰ� ����ȴ�
	

	// 2��°ĭ�� 5�� ä���ְ� �� ��ĭ�� �и� ��
	// ä���� ���� return
	// vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);

	// 3��°ĭ�� ����� �� ��ĭ�� ���� ��
	// erase�� ���� return
	// vector<int>::iterator eraseIt1 = v.erase(v.begin() + 3); 

	// 2~3��°ĭ�� ����� �� ��ĭ�� ���� ��, 4�� ���Ե��� ����
	// return ���� 4��°
	// vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4); 
	
	// ��ĵ �ϸ鼭, 3�̶�� �����Ͱ� ������ �ϰ� �����ϰ� �ʹ�

	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		int data = *it;
		if (data == 3)
		{
			// erase�ϸ� �ٷ� ��ȿ���� �ʱ� ������ �� ��ġ�� return�ؾ� ��ġ�� ã�� �� ����
			// �׳� �ϳ��� ����Ÿ� �ϳ� ����� break;�ؾ� for������ ++it�� �� ũ���� �ȳ�
			it = v.erase(it);
		}
		else
		{
			++it;
		}

		// v.clear();
		// break; // break ���ϸ� �ٷ� �浹. �� ? ��ȿ���� �ʱ� ������
	}


	return 0;

}