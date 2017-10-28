#include "CollectedTool.h"

#define DEBUG

const int needFixValue = 20;

CollectedTool::CollectedTool(string name)
	:Tool(name)
{
}

CollectedTool::CollectedTool(string name, vector<Tool*>* toolList)
	:Tool(name)
{
	toolList_ =  *toolList;
}

CollectedTool::CollectedTool(vector<Abstract*>* abs_list, int size, string name, int init_durability, MaterialType material)
	: Tool(abs_list, size, name, init_durability, material)
{
}


CollectedTool::~CollectedTool()
{
}

void CollectedTool::update(Abstract* abs, AbstractType type)
{

}

void CollectedTool::outputDurability() 
{
#ifdef DEBUG
	auto it = toolList_.begin();
	for (; it != toolList_.end(); it++) {
		cout << "���߳�Ա��" << (*it)->getName() << " ʣ���;ö�:" << (*it)->getDurability() << endl;
	}
#endif // DEBUG

}

//return worst Tool's durability
int CollectedTool::getDurability()
{
	int worstToolDurability = this->checkWorstTool()->getDurability();
	return worstToolDurability;
}

//reduce every member's
void CollectedTool::loss()
{
	auto it = toolList_.begin();
	for (; it != toolList_.end(); it++) {
		(*it)->loss();
	}
#ifdef DEBUG
	cout << "��(" << this->getName() << ")ĥ����!!��Ȼ���ǹ�����ϣ�" << endl;
#endif // DEBUG

}

void CollectedTool::fix(int n)
{
	durability_ += n;
#ifdef DEBUG
	cout << "��(" << this->getName() << ")�������� " << n << " ���;ö�����" << endl;
	outputDurability();
#endif // DEBUG
}

void CollectedTool::addTool(Tool* tool)
{
	toolList_.push_back(tool);
}

void CollectedTool::removeTool(Tool* tool)
{
	auto it = toolList_.begin();
	for (; it != toolList_.end(); it++) {
		if (*it == tool) {
			toolList_.erase(it);
			return;
		}
	}
	cout << "ERROR!û��������ߣ�" << endl;
}

vector<Tool*>* CollectedTool::getToolList()
{
	auto toolList = &toolList_;
	return toolList;
}

string CollectedTool::getUnitName(Tool* tool)
{
	auto it = toolList_.begin();
	for (; it != toolList_.end(); it++) {
		if (*it == tool) {
			cout << "���֣�" << endl;
			return (*it)->getName();
		}
	}
	cout << "ERROR!û��������ߣ�" << endl;
}

vector<Tool*>* CollectedTool::checkFixNeededTool()
{
	vector<Tool*>* newToolVector = new vector<Tool*>();
	auto it = toolList_.begin();
	for (; it != toolList_.end(); it++) {
		if (durability_ <= needFixValue) {	//��Ҫ�����ˣ�
			newToolVector->push_back(*it);
		}
	}
	return newToolVector;
}

Tool* CollectedTool::checkWorstTool()
{
	Tool* worstTool = nullptr;
	auto it = toolList_.begin();
	for (; it != toolList_.end(); it++) {
		if (worstTool == nullptr)
			worstTool = *it;
		else if ((*it)->getDurability() <= worstTool->getDurability())
			worstTool = *it;
	}
	return worstTool;
}