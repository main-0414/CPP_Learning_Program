#include <iostream>
using namespace std;

// 抽象不同零件类


// 抽象CPU类
class CPU
{
public:
	// 抽象计算函数
	virtual void calculater() = 0;

	virtual ~CPU() {}	// 如果要用纯虚析构还要在类外写实现
};


// 抽象显卡类
class GPU
{
public:
	// 抽象的显卡函数
	virtual void display() = 0;

	virtual ~GPU() {}
};


// 抽象内存条类
class Memory
{
public:
	// 抽象的存储函数
	virtual void storage() = 0;

	virtual ~Memory() {}
};



// 电脑类
class Computer
{
public:

	// 构造函数
	Computer(CPU* cpu, GPU* gpu, Memory* mem) :m_cpu(cpu), m_gpu(gpu), m_memory(mem) {}

	// 提供工作函数
	void doWork()
	{
		// 让零件工作，调用接口
		m_cpu->calculater();
		m_gpu->display();
		m_memory->storage();
	}

	// 释放零件资源
	~Computer()
	{
		// 基类指针删除派生类对象，得要虚析构
		delete m_cpu;
		m_cpu = nullptr;
		delete m_gpu;
		m_gpu = nullptr;
		delete m_memory;
		m_memory = nullptr;
	}



private:
	CPU* m_cpu;		// CPU的零件指针
	GPU* m_gpu;		// GPU的零件指针
	Memory* m_memory;	// 内存的零件指针

};


// 具体厂商

// Intel厂商
class IntelCPU :public CPU
{
public:
	virtual void calculater()
	{
		cout << "Intel的CPU开始计算了" << endl;
	}
};
class IntelGPU :public GPU
{
public:
	virtual void display()
	{
		cout << "Intel的GPU开始显示了" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel的Memory开始存储了" << endl;
	}
};


// AMD厂商
class AMDCPU :public CPU
{
public:
	virtual void calculater()
	{
		cout << "AMD的CPU开始计算了" << endl;
	}
};
class AMDGPU :public GPU
{
public:
	virtual void display()
	{
		cout << "AMD的GPU开始显示了" << endl;
	}
};
class AMDMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "AMD的Memory开始存储了" << endl;
	}
};


void test01()
{
	cout << "第一台电脑开始工作了:" << endl;

	// 第一台电脑零件
	CPU* intelcpu = new IntelCPU;	// 零件也是new出来的，结束也应该释放
	GPU* intelgpu = new IntelGPU;
	Memory* intelmem = new IntelMemory;

	// 创建第一台电脑
	Computer* computer1 = new Computer(intelcpu, intelgpu, intelmem);
	computer1->doWork();
	delete computer1;

	cout << "--------------------------------" << endl;

	cout << "第二台电脑开始工作了:" << endl;
	// 第二台电脑组装
	Computer* computer2 = new Computer(new AMDCPU, new AMDGPU, new AMDMemory);
	computer2->doWork();
	delete computer2;

	cout << "--------------------------------" << endl;

	cout << "第三台电脑开始工作了:" << endl;
	// 第三台电脑组装
	Computer* computer3 = new Computer(new IntelCPU, new AMDGPU, new AMDMemory);
	computer3->doWork();
	delete computer3;

	cout << "--------------------------------" << endl;

	cout << "第四台电脑开始工作了:" << endl;
	// 第四台电脑组装
	Computer computer4(new AMDCPU, new IntelGPU, new IntelMemory);
	computer4.doWork();
	// 能创建在栈区就创建栈区，代码简单，不会忘记delete引发内存泄漏

}





int main()
{
	test01();

	system("pause");
}