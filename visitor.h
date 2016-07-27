#ifndef _VISITOR_H_
#define _VISITOR_H_

#include <ostream>
// #include "product_tree.h"
#include "category.h"

namespace catalog {
using std::ostream;

class Component;
class ProgrammingBook;
class CookBook;
class EsotericBook;
class Disk;
// class Category<Component>;

class Visitor {
public:
	virtual void visit(ProgrammingBook *p) = 0;
	virtual void visit(CookBook *p) = 0;
	virtual void visit(EsotericBook *p) = 0;
	virtual void visit(Disk *p) = 0;
	virtual void visit(Category<Component> *p) = 0;
};

class PrintVisitor : public Visitor {
	PrintVisitor(const ostream &os);
	void visit(ProgrammingBook *p);
	void visit(CookBook *p);
	void visit(EsotericBook *p);
	void visit(Disk *p);
	void visit(Category<Component> *p);
	virtual ~PrintVisitor() {}

private:
	ostream os_;
};

} 

#endif  /* _VISITOR_H_ */