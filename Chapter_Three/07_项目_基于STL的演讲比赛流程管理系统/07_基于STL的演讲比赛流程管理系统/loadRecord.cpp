#include "speechManager.h"

// 加载数据
void SpeechManager::loadRecord()
{
	// 防止重复加载往届数据
	m_Record.clear();


	ifstream ifs(FILENAME, ios::in);	// 打开方式：读文件


	// 1. 文件不存在
	if (!ifs.is_open())		// 返回false，那么表示文件不存在
	{
		this->m_FileIsEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;		// 直接退出函数
	}



	/*
		// 判断文件是否为空：
		// 方法一：
		// 逻辑：先读一个字符试试看文件有没有内容，如果有，再把这个字符放回去puback()，让后面的代码正常读取整个文件。

		char ch;
		ifs >> ch;	// 从文件中读取第一个字符，存入 ch 里
		// 必须得读一次才知道读取成功与否
		if (ifs.eof())	// 如果读取失败了，那么eof()会返回true

	*/



	// 方法二： ————> peek()	只看（复制）下一个字符，不取走。
	// peek() 返回的是一个值，而 eof() 是一个函数。
	// 所以不应该写 if (ifs.eof())，而是 if (ifs.peek() == EOF) （EOF:文件结束标志）




	// 2. 文件存在无数据
	if (ifs.peek() == EOF)
	{
		//cout << "文件为空！" << endl;

		m_FileIsEmpty = true;
		ifs.close();
		return;
	}




	// 3. 有文件有数据
	
	m_FileIsEmpty = false;

	//ifs.putback(ch);	// puback(ch) 把刚才读取的单个字符放回来

	string data;

	int index = 0;	// 行数（届数）

	while (ifs >> data)		// 现在是读出一行数据，因为不是用空格来分割
	{
		// 10011,85.03,10002,82.11,10008,78.79,

		// 先用string容器的find()找到","的位置，再 substr() 截取字符串

		int pos = -1;	// 默认没查到返回-1
		int start = 0;	// find从下标0开始找


		vector<string> v;	// 存放每一届人员信息

		while (true)
		{
			pos = data.find(",", start);	// 找“,”位置

			if (pos == -1)
			{
				// 直到最后一个逗号，找不到下一个会返回 -1，直接break掉
				break;
			}
			else
			{
				string temp = data.substr(start, pos - start);	// 从 start 位置截取到 pos-start 位置
				//cout << temp << endl;
				v.push_back(temp);

				start = pos + 1;	// 指向下一个单词第一个字母

			}
		}

		this->m_Record.insert(make_pair(index, v));
		index++;

	}


	ifs.close();
}