#include <iostream>
#include <list>
using namespace std;

// list 容器的赋值和交换
void printList02(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}




// 赋值
void test02()
{
	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	printList02(L1);


	

	// 1. operator=赋值
	list<int>L2;

	L2 = L1;
	printList02(L2);


	// 2. assign(区间)  赋值
	list<int> L3;

	L3.assign(L2.begin(), L2.end());
	printList02(L3);



	// 3. assign(n个elem)  赋值
	list<int> L4;
	L4.assign(10, 100);
	printList02(L4);

}


void test03()
{
	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int> L2;
	L2.assign(10, 100);

	cout << "交换前：" << endl;
	printList02(L1);
	printList02(L2);


	L1.swap(L2);
	cout << "交换后：" << endl;
	printList02(L1);
	printList02(L2);



}





int main2()
{
	test02();
	test03();



	system("pause");
	return 0;
}