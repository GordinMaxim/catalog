#ifndef _PRODUCT_TREE_H_
#define _PRODUCT_TREE_H_

#include <vector>
#include <string>
#include <algorithm>
#include "visitor.h"


namespace catalog {
using std::vector;
using std::string;

class Visitor;

class Component {
public:
	virtual void accept(Visitor &v) = 0; 
};

class Product {
public:
	Product (const string &name, int price, const string &barcode) :
		name_(name), price_(price), barcode_(barcode) {} 

	string getName () const {
		return name_;
	}

	int getPrice() const {
		return price_;
	}

	string getBarcode() const {
		return barcode_;
	}

	void setName(const string &name) {
		name_ = name;
	}

	void setPrice(int price) {
		price_ = price;
	}

	void setBarcode(const string &barcode) {
		barcode_ = barcode;
	}

private:
	string name_;
	int price_;
	string barcode_;
};

class Book : public Product {
public:
	Book(const string &name, int price, const string &barcode, int pageNum) :
		Product(name, price, barcode), pageNum_(pageNum) {}

		int getPageNumber() const {
			return pageNum_;
		}

		void setPageNumber(int pageNum) {
			pageNum_ = pageNum;
		}

private:
	int pageNum_;
};

class ProgrammingBook : public Book, public Component {
public:
	ProgrammingBook(const string &name, int price, const string &barcode, int pageNum, const string &lang) :
		Book(name, price, barcode, pageNum), lang_(lang) {}

	string getProgrammingLanguage() const {
		return lang_;
	}

	void setProgrammingLanguage(const string &lang) {
		lang_ = lang;
	} 

	void accept(Visitor &v) {
		v.visit(this);
	}

private:
	string lang_;
};

class CookBook : public Book, public Component {
public:
	CookBook(const string &name, int price, const string &barcode, int pageNum, const string &ingredient) :
		Book(name, price, barcode, pageNum), ingredient_(ingredient) {}

	string getIngredient() const {
		return ingredient_;
	}

	void setIngredient(const string &ingredient) {
		ingredient_ = ingredient;
	} 
	
	void accept(Visitor &v) {
		v.visit(this);
	}

private:
	string ingredient_;
};

class EsotericBook : public Book, public Component {
public:
	EsotericBook(const string &name, int price, const string &barcode, int pageNum, int age) :
		Book(name, price, barcode, pageNum), age_(age) {}

	int getAge() const {
		return age_;
	}

	void setAge(int age) {
		age_ = age;
	} 

	void accept(Visitor &v) {
		v.visit(this);
	}

private:
	int age_;
};

enum DiskType {CD, DVD};
enum ContentType {MUSIC, VIDEO, SOFTWARE};

class Disk : public Product, public Component {
public:
	Disk(const string &name, int price, const string &barcode, DiskType diskType, ContentType contentType) :
		Product(name, price, barcode), diskType_(diskType), contentType_(contentType) {}

	DiskType getDiskType() const {
		return diskType_;
	}

	ContentType getContentType() const {
		return contentType_;
	}

	void accept(Visitor &v) {
		v.visit(this);
	}

private:
	DiskType diskType_;
	ContentType contentType_;
};

template<typename TComponent>
class Category : public TComponent {
public:
	typedef typename vector<TComponent*>::iterator ChildIterator;

	Category(const string &name) : name_(name) {}

	string getName() const {
		return name_;
	}

	void setName(const string &name) {
		name_ = name;
	}

	void accept(Visitor &v) {
		v.visit(this);
	}

	void addChild(TComponent *child) {
		ChildIterator it = std::find(children_.begin(), children_.end(), child);
		if (children_.end() == it) {
			children_.push_back(child);
		}
	}

	ChildIterator begin() {
		return children_.begin();
	}

	ChildIterator end() {
		return children_.end();
	}

	void removeChild(TComponent *child) {
		ChildIterator it = std::find(children_.begin(), children_.end(), child);
		if (children_.end() != it) {
			children_.erase(child);
		}	
	}

	void clear() {
		children_.clear();
	}

	virtual ~Category() {}

protected:
	vector<TComponent*> children_;
	string name_;
};

} // end namespace Catalog

#endif /* _PRODUCT_TREE_H_ */