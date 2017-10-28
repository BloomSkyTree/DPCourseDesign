#include "Object.h"
#include "Time.h"
#include "Crop.h"
#include "InsectGroup.h"
#include "Insect.h"
#include "Time.h"
#include "InsectGroup.h"
#include "Bee.h"
#include "Weed.h"
#include "Stock.h"
#include "Chicken.h"
#include "BaseFarmland.h"

void test_time_h();

void stock_test();

void test_farmland();

int main(){
	Time* time = Time::instance();

	vector<Abstract*> abs_list;
	abs_list.push_back(time);
	Chicken* chicken = new Chicken(&abs_list);

	time->report();
	time = time->hour_pass(7);
	time->report();
	time = time->hour_pass(4);
	time->report();
	time = time->hour_pass(7);
	time->report();
	time = time->hour_pass(7);
	time->report();



	delete chicken;

	system("pause");
	return 0;
}

void test_farmland(){
	BaseFarmLand* base_farm_land = new BaseFarmLand(NULL, 100, 100, "base farmland", 0.3);
	FarmLand* farm_land = new FarmLand(base_farm_land);
	EffectFarmLand* effect_farm_land = new EffectFarmLand(farm_land);
	Crop* crop = new Crop(NULL, 10, 50);
	crop->plant_on(effect_farm_land);
	cout << "Because the crop is planted on an effect farmland, its output rate is set to " << crop->get_output_rate() << "." << endl;
}


void test_time_h(){
	Time* time = Time::instance();
	time->report();
	time = time->hour_pass(7);
	time->report();
	time = time->hour_pass(4);
	time->report();
	time = time->hour_pass(7);
	time->report();
	time = time->hour_pass(7);
	time->report();
}


void stock_test(){
	Stock* stock = new Stock(NULL, 100);
	Chicken* chicken = new Chicken();
	stock->put_in(chicken);
	StockList::Iterator* chicken_find = stock->find(chicken);
	if (chicken_find != NULL)cout << "FIND!" << endl;
	else cout << "not find" << endl;
	delete chicken_find;
	delete chicken;
	delete stock;
}