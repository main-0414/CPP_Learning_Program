#include <iostream>
using namespace std;

// 各种硬件的抽象类
class CPU
{
public:
	virtual void calculate() = 0;
	virtual ~CPU() {};
};


class GPU
{
public:
	virtual void display() = 0;
	virtual ~GPU() {};
};

class Storage
{
public:
	virtual void Memory() = 0;
	virtual ~Storage() {};
};


// Intel厂商
class IntelCPU :public CPU
{
	void calculate()
	{
		cout << "Intel的CPU开始计算了！" << endl;
	}
};
class IntelGPU :public GPU
{
	void display()
	{
		cout << "Intel的GPU开始计算了！" << endl;
	}
};
class IntelStorage :public Storage
{
	void Memory()
	{
		cout << "Intel的内存开始计算了！" << endl;
	}
};


// Nvdia厂商
class NvdiaCPU :public CPU
{
	void calculate()
	{
		cout << "Nvdia的CPU开始计算了！" << endl;
	}
};
class NvdiaGPU :public GPU
{
	void display()
	{
		cout << "Nvdia的GPU开始计算了！" << endl;
	}
};
class NvdiaStorage :public Storage
{
	void Memory()
	{
		cout << "Nvdia的内存开始计算了！" << endl;
	}
};




// 电脑类
class Computer
{
public:
	// 构造函数中传入三个硬件指针
	Computer(const string& cpu_Brand, const string& GPU_Brand, const string& Storage_Brand)
	{
		// 创建CPU
		if (cpu_Brand == "Intel")
		{
			m_CPU = new IntelCPU;
		}
		else if (cpu_Brand == "Nvdia")
		{
			m_CPU = new NvdiaCPU;
		}
		else { m_CPU = nullptr; }


		// 创建GPU
		if (GPU_Brand == "Intel")
		{
			m_GPU = new IntelGPU;
		}
		else if (GPU_Brand == "Nvdia")
		{
			m_GPU = new NvdiaGPU;
		}
		else { m_GPU = nullptr; }


		// 创建Storage
		if (Storage_Brand == "Intel")
		{
			m_Storage = new IntelStorage;
		}
		else if (Storage_Brand == "Nvdia")
		{
			m_Storage = new NvdiaStorage;
		}
		else { m_Storage = nullptr; }

	}



	// 提供工作函数，调用每个硬件的接口
	void doWork()
	{
		if (m_CPU) m_CPU->calculate();
		if (m_GPU) m_GPU->display();
		if (m_Storage) m_Storage->Memory();
	}


	// 析构函数
	~Computer()
	{
		delete m_CPU;
		m_CPU = nullptr;
		delete m_GPU;
		m_GPU = nullptr;
		delete m_Storage;
		m_Storage = nullptr;
	}


	// 维护硬件指针
	CPU* m_CPU;
	GPU* m_GPU;
	Storage* m_Storage;
};





int main()
{
	Computer pc("Intel", "Intel", "Nvdia");
	pc.doWork();


	system("pause");
}