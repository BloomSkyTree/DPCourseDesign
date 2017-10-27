#include "Time.h"
#include "InsectGroup.h"
#include "Bee.h"

int main(){
	Time* time = Time::instance();
	int test[] = { 2017, 15, 12, 15 };
	time->set_time(test);
	time->report();

	InsectGroup* beeGroup = new InsectGroup(new string("bee"));
	for (int i = 0; i < 99; i++)
	{
		SEX sex;
		if (i % 2 == 0)
		{
			sex = FEMALE;
		}
		else
		{
			sex = MALE;
		}
		Bee* bee = (Bee*)Insect::find_and_clone(NULL, sex, new string("bee"));
		beeGroup->add(bee);
	}

	beeGroup->hatch(NULL);
	cout << beeGroup->size() << endl;

	InsectGroup::Iterator* it = new InsectGroup::Iterator();

	beeGroup->begin(it);

	for (int i = 0; i < 50; i++)
	{
		it->turn_next();

		Bee* temp = (Bee*)it->value();

		cout << temp->get_sex() << endl;
	}
	/*
	Farmland *f1 = new Redland();
	f1 = new Kcl(f1);
	f1 = new Kcl(f1);
	f1 = new Nh4(f1);
	cout << "description: " << f1->get_discription() << endl;;
	cout << "size: " << f1->size() << endl;

	cout << "-----------------------" << endl;

	Farmland *f2 = new Blackland();
	f2 = new Nh4(f2);
	f2 = new Kcl(f2);
	cout << "description: " << f2->get_discription() << endl;;
	cout << "size: " << f2->size() << endl;

	cout << "-----------------------" << endl;

	Control *remote = new Control();
	Farmland *f3 = new Farmland();
	Plow *plow = new Plow(f3);
	Smell *smell = new Smell(f3);
	Ftime *time = new Ftime(f3);
	remote->set_command(0, plow);
	remote->set_command(1, smell);
	remote->set_command(2, time);
	remote->button_is_pressed(0);
	remote->button_is_pressed(1);
	remote->button_is_pressed(2);
	remote->button_is_pressed(2);
	*/
	system("pause");
	return 0;
}