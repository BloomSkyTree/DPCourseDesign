#pragma once
#include "Facility.h"
#include "List.h"
#include "Collection.h"

class Shelf;
class Warehouse;

class Shelf :public Collection
{
public:
	friend class Warehouse;
	class Iterator :public FarmIterator
	{
	public:
		friend class Shelf;
		Iterator();
		Iterator(Shelf* list);
		Iterator(Iterator* another);
		virtual ~Iterator() {}
		//*��ȡ�ýڵ��ֵ
		virtual Object* value();
		//*ָ����һ�ڵ�
		virtual void turn_next();
		//*ָ����һ�ڵ�
		virtual void turn_previous();
		//*ָ���׽ڵ�
		virtual void turn_first();
		//*ָ��β�ڵ�
		virtual void turn_last();
		//*�ж��Ƿ�����һ�ڵ�
		virtual bool has_next();
		//*�ж��Ƿ�����һ�ڵ�
		virtual bool has_previous();
		//*����д�Ļ�ȡ�����ĺ���������"Shelf::Iterator"
		virtual const char* get_class_name() { return "Shelf::Iterator"; }
	};
	//*��������
	~Shelf()
	{
		delete list_;
	}
	//*��ȡ��С
	virtual int size();
	//*�ж��Ƿ�Ϊ��
	virtual bool is_empty();
	//*��iteratorָ��ʼ��
	virtual void begin(FarmIterator& iterator);
	//*��iteratorָ�������
	virtual void end(FarmIterator& iterator);
	//*�����Ԫ��
	virtual void add(Object* new_element);
	//*�Ƴ�iteratorָ���Ԫ��
	virtual void remove(FarmIterator& iterator);
	//*��ʾ��Ʒ�б�
	void show_list();
	//*����ĳһ�������Ʒ����ʾ
	void find_kind(string kind_name);
	//*��ȡʣ������
	int usable_capacity();
	//*����
	void dilate(int extend_space);
	//*��ȡ����
	int capacity();
	//*����д�Ļ�ȡ�����ĺ���������"Living"
	virtual const char* get_class_name() { return "Shelf"; }
private:
	List* list_;
	int capacity_;
	int used_space_;
	Shelf();
};

class Warehouse :public Facility
{
public:
	static Warehouse* get_instance(vector<Abstract*>* abs_list)
	{
		if (warehouse_p_ != NULL)
		{
			return warehouse_p_;
		}
		else
		{
			warehouse_p_ = new Warehouse(abs_list, 100, 100);
			return warehouse_p_;
		}
	}
	//*��Ӧ��������ʱ������ʱ����update()���ô˺�����
	virtual void time_pass_by();
	//*��Ӧ�������������仯ʱ����update()���ô˺�����
	virtual void when_atmosphere_changed();
	//*�����ָ��;�
	virtual void fix(int n = 1);
	//*��������;�
	void set_max_durability(int value);
	//*����д�Ļ�ȡ�����ĺ���������"Living"
	virtual const char* get_class_name() { return "Warehouse"; }
	//*�жϴ�С
	int size();
	//*�ж��Ƿ�Ϊ��
	bool is_empty();
	//*��iteratorָ��ʼ��
	void begin(Collection::FarmIterator& iterator);
	//*��iteratorָ�������
	void end(Collection::FarmIterator& iterator);
	//*�����Ԫ��
	void add(Object* new_element);
	//*�Ƴ�iteratorָ���Ԫ��
	void remove(Collection::FarmIterator& iterator);
	//*��ʾ��Ʒ�б�
	void show_list();
	//*����ĳһ�������Ʒ����ʾ
	void find_kind(string kind_name);
	//*��ȡʣ������
	int usable_capacity();
	//*����
	void dilate(int extend_space);
	//*��ȡ����
	int capacity();
private:
	static Warehouse* warehouse_p_;

	Shelf* shelf_;

	Warehouse(vector<Abstract*>* abs_list, int size, int max_durability) :Facility(abs_list, size)
	{
		max_durability_ = max_durability;
	}

	int max_durability_;

	virtual ~Warehouse()
	{
		delete shelf_;
	}
};