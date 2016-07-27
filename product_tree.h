#ifndef _PRODUCT_TREE_H_
#define _PRODUCT_TREE_H_
#include <string>

namespace catalog {
using std::string;

class Visitor;

class Component {
public:
	virtual void accept(Visitor &v, int state) = 0; 
};

class Product {
public:
	Product (const string &name, int price, const string &barcode);
	string getName () const;
	int getPrice() const;
	string getBarcode() const; 
	void setName(const string &name);
	void setBarcode(const string &barcode);
	void setPrice(int price);

private:			
	string name_;
	int price_;
	string barcode_;
};

class Book : public Product {
public:
	Book(const string &name, int price, const string &barcode, int pageNum);
		int getPageNumber() const;
		void setPageNumber(int pageNum);

private:
	int pageNum_;
};

class ProgrammingBook : public Book, public Component {
public:
	ProgrammingBook(const string &name, int price, const string &barcode, int pageNum, const string &lang);
	string getProgrammingLanguage() const;
	void setProgrammingLanguage(const string &lang);
	void accept(Visitor &v, int state);

private:
	string lang_;
};

class CookBook : public Book, public Component {
public:
	CookBook(const string &name, int price, const string &barcode, int pageNum, const string &ingredient);
	string getIngredient() const;
	void setIngredient(const string &ingredient);
	void accept(Visitor &v, int state);

private:
	string ingredient_;
};

class EsotericBook : public Book, public Component {
public:
	EsotericBook(const string &name, int price, const string &barcode, int pageNum, int age);
	int getAge() const;
	void setAge(int age);
	void accept(Visitor &v, int state);

private:
	int age_;
};

class Disk : public Product, public Component {
public:
	enum DiskType {CD, DVD};
	enum ContentType {MUSIC, VIDEO, SOFTWARE};

	static string ToString(DiskType diskType);
	static string ToString(ContentType contentType);

	Disk(const string &name, int price, const string &barcode, DiskType diskType, ContentType contentType);
	DiskType getDiskType() const;
	ContentType getContentType() const;
	void accept(Visitor &v, int state);

private:
	DiskType diskType_;
	ContentType contentType_;
};

} // end namespace Catalog

#endif /* _PRODUCT_TREE_H_ */