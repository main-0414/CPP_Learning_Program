#include "orderFile.h"

// 构造函数
OrderFile::OrderFile()
{
	ifstream ifs(ORDER_FILE, ios::in);

	string date;
	string interval;	// 时段
	string stuID;
	string stuName;
	string roomID;
	string status;		// 审批状态

	this->m_Num = 0;	// 条数

	// 当前读到的信息还是 data:1 interval:1 这样一大串，还需要分割字符串
	while (ifs >> date >> interval >> stuID >> stuName >> roomID >> status)
	{
		// 搞个小容器，记录一行的数据
		map<string, string> m;

		string key;		// 标题
		string value;	// 值

		vector<string> v = { date,interval,stuID,stuName,roomID,status };

		// 范围 for 循环：一次把容器v里的数据放进data
		for (string data : v)
		{
			int pos = data.find(":");	// 返回下标，pos = 4
			if (pos != -1)
			{
				key = data.substr(0, pos);	// 从下标0开始，截取pos个字符
				value = data.substr(pos + 1, data.size() - pos - 1);

				m.insert(make_pair(key, value));
			}
		}


		// 将小map容器放入到大的map容器中
		this->m_orderData.insert(make_pair(this->m_Num, m));
		this->m_Num++;
	}

	ifs.close();

}


// 更新预约记录
void OrderFile::updataOrder()
{
	if (m_Num == 0)	// 一条预约记录都没有就不做更新
	{
		return;
	}
	else
	{
		ofstream ofs(ORDER_FILE, ios::out | ios::trunc);	// 重新写入

		for (int i = 0; i < m_Num; i++)
		{
			ofs << "date:" << m_orderData[i]["date"] << " "
				<< "interval:" << m_orderData[i]["interval"] << " "
				<< "stuID:" << m_orderData[i]["stuID"] << " "
				<< "stuName:" << m_orderData[i]["stuName"] << " "
				<< "roomID:" << m_orderData[i]["roomID"] << " "
				<< "status:" << m_orderData[i]["status"] << " " << endl;
		}
	}

}

