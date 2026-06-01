#include "personExist.h"

//检测
int personExist(AddressBook* book, string name)
// 参数一：通讯录结构体    参数二：对比姓名
{
	// 检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1

	// 找到用户输入的姓名了
	for (int i = 0; i < book->size; i++)
	{
		if (book->personArray[i].name == name)
		{
			return i;	// 找到了，返回这个人的下标编号
		}
	}
	return -1;		// 遍历完都没有找到，那就返回-1代表没有这个人
}