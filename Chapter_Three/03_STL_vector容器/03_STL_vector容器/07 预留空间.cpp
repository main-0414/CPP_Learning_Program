#include <iostream>
#include <vector>
using namespace std;

void test08()
{
	vector<int> v;

	// 预留空间（可减少重新分配次数）
	v.reserve(100000);	


	int num = 0;	// 定义统计重新分配地址次数
	int* p = nullptr;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		// 统计重新分配地址的次数（vector扩容不是在原空间后面继续追加空间，而是申请一整块新的更大的连续空间，然后把旧数据复制过去，再释放旧空间。）
		if (p != &v[0])		// 如果 指针p 不在 数组首地址 那么就令 num++ 且 p=首地址
		{
			p = &v[0];
			num++;
		}
	}

	cout << "num = " << num << endl;	// 不reserve，num = 30

}






int main()
{
	test08();


	system("pause");
	return 0;
}