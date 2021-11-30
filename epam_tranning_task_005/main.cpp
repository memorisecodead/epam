#include <iostream>
#include "myHuman.h"
#include "myShop.h"
#include "myInstit.h"
#include "myTransp.h"
#include "myCarrier.h"

int main()
{
	Human man;

	man.setName("John");
	man.setSurName("Mazur");
	man.setAge(15);
	man.printInfo();
	man.printUnicPhraze();

	std::cout << std::endl;

	Shop shop;
	shop.setNameShop("SlowDown");
	shop.setCharacter("Very cool shop!");
	shop.setId(124);
	shop.printInfo();
	shop.printPhraze();
	
	EducInstit instit;
	instit.setPeople(200);
	instit.setScore(2000);
	instit.generalCountOfPeople();
	instit.averageScore();

	Transoprt tr;
	tr.setPriceOfWay(5024);
	tr.setBenzo(1000);
	tr.setPlace(20);
	tr.setPriceOfWay(15);
	tr.averageBezno();
	tr.generalPriceOfWay();

	Carrier cr;
	cr.setHuman(10);
	cr.setPlace(2000);
	cr.setPrice(16);
	cr.setWay(1000);
	cr.averageCountOfHuman();
	cr.generalPriceOfCarrier();

}