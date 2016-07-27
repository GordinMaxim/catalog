#include "product_tree.h"
#include "visitor.h"

namespace catalog {
using std::string;

Product::Product (const string &name, int price, const string &barcode) :
	name_(name), price_(price), barcode_(barcode) {} 

string Product::getName () const {
	return name_;
}

int Product::getPrice() const {
	return price_;
}

string Product::getBarcode() const {
	return barcode_;
}

void Product::setName(const string &name) {
	name_ = name;
}

void Product::setPrice(int price) {
	price_ = price;
}

void Product::setBarcode(const string &barcode) {
	barcode_ = barcode;
}


Book::Book(const string &name, int price, const string &barcode, int pageNum) :
	Product(name, price, barcode), pageNum_(pageNum) {}

int Book::getPageNumber() const {
	return pageNum_;
}

void Book::setPageNumber(int pageNum) {
	pageNum_ = pageNum;
}

ProgrammingBook::ProgrammingBook(const string &name, int price, const string &barcode, int pageNum, const string &lang) :
	Book(name, price, barcode, pageNum), lang_(lang) {}

string ProgrammingBook::getProgrammingLanguage() const {
	return lang_;
}

void ProgrammingBook::setProgrammingLanguage(const string &lang) {
	lang_ = lang;
} 

void ProgrammingBook::accept(Visitor &v, int state) {
	v.visit(this, state);
}

CookBook::CookBook(const string &name, int price, const string &barcode, int pageNum, const string &ingredient) :
	Book(name, price, barcode, pageNum), ingredient_(ingredient) {}

string CookBook::getIngredient() const {
	return ingredient_;
}

void CookBook::setIngredient(const string &ingredient) {
	ingredient_ = ingredient;
} 

void CookBook::accept(Visitor &v, int state) {
	v.visit(this, state);
}

EsotericBook::EsotericBook(const string &name, int price, const string &barcode, int pageNum, int age) :
	Book(name, price, barcode, pageNum), age_(age) {}

int EsotericBook::getAge() const {
	return age_;
}

void EsotericBook::setAge(int age) {
	age_ = age;
} 

void EsotericBook::accept(Visitor &v, int state) {
	v.visit(this, state);
}

string Disk::ToString(Disk::DiskType diskType) {
	switch (diskType) {
		case Disk::CD : {
			return "CD";
			break;
		}
		case Disk::DVD : {
			return "DVD";
			break;
		}
	}
	return "";
}

string Disk::ToString(Disk::ContentType contentType) {
	switch (contentType) {
		case Disk::MUSIC : {
			return "MUSIC";
			break;
		}
		case Disk::VIDEO : {
			return "VIDEO";
			break;
		}
		case Disk::SOFTWARE : {
			return "SOFTWARE";
			break;
		}
	}
	return "";
}

Disk::Disk(const string &name, int price, const string &barcode, DiskType diskType, ContentType contentType) :
	Product(name, price, barcode), diskType_(diskType), contentType_(contentType) {}

Disk::DiskType Disk::getDiskType() const {
	return diskType_;
}

Disk::ContentType Disk::getContentType() const {
	return contentType_;
}

void Disk::accept(Visitor &v, int state) {
	v.visit(this, state);
}

} /*end namespace catalog */