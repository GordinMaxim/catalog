#include <iostream>
#include "product_tree.h"
#include "category.h"
#include "visitor.h"

using namespace catalog;

int main(int argc, char **argv) {
	Category<Component> rootCategory("Products");
	Category<Component> bookCategory("Books");
	Category<Component> diskCategory("Disks");
	rootCategory.addChild(&bookCategory);
	rootCategory.addChild(&diskCategory);

	Category<Component> programmingBooks("Programming books");
	Category<Component> cookBooks("Cook books");
	Category<Component> esotericBooks("Esoteric books");
	bookCategory.addChild(&programmingBooks);
	bookCategory.addChild(&cookBooks);
	bookCategory.addChild(&esotericBooks);

	Category<Component> CDDisks("CD disks");
	Category<Component> DVDDisks("DVD disks");
	diskCategory.addChild(&CDDisks);
	diskCategory.addChild(&DVDDisks);

	ProgrammingBook progbook1("A Tour of C++", 500, "36000 29145", 663, "C++");
	ProgrammingBook progbook2("Effective Java, Second Edition", 730, "36000 291233", 433, "Java");
	ProgrammingBook progbook3("The C Programming Language", 480, "323400 22145", 1022, "C");
	programmingBooks.addChild(&progbook1);
	programmingBooks.addChild(&progbook2);
	programmingBooks.addChild(&progbook3);
	
	CookBook cookbook1("The joy of cooking", 120, "23445 55321", 321, "Carrot");
	CookBook cookbook2("Moosewood CookBook", 454, "23355 67653", 672, "Eggs");
	cookBooks.addChild(&cookbook1);
	cookBooks.addChild(&cookbook2);
	
	EsotericBook esotericbook1("Grimoire", 522, "32421 5687568", 763, 18);
	EsotericBook esotericbook2("The Secret Doctrine", 642, "213112 345322", 764, 21);
	esotericBooks.addChild(&esotericbook1);
	esotericBooks.addChild(&esotericbook2);

	Disk cd1("90's hits", 400, "324523 32665547", Disk::CD, Disk::MUSIC);
	Disk cd2("Twin Peaks", 466, "324324   676575", Disk::CD, Disk::VIDEO);
	Disk cd3("Microsoft Office", 740, "12311 12245676", Disk::CD, Disk::SOFTWARE);
	CDDisks.addChild(&cd1);
	CDDisks.addChild(&cd2);
	CDDisks.addChild(&cd3);

	Disk dvd1("Atmosphere discography", 1000, "657454 3221223", Disk::DVD, Disk::MUSIC);
	Disk dvd2("The Big Lebowski", 900, "324234232 353451", Disk::DVD, Disk::VIDEO);
	DVDDisks.addChild(&dvd1);
	DVDDisks.addChild(&dvd2);

	PrintVisitor v(std::cout);
	v.visit(&rootCategory);

	return 0;
}
