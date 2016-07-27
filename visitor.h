#ifndef _VISITOR_H_
#define _VISITOR_H_

#include <ostream>
#include "product_tree.h"
#include "category.h"

namespace catalog {

class Visitor {
public:
	virtual void visit(ProgrammingBook *, int) = 0;
	virtual void visit(CookBook *, int) = 0;
	virtual void visit(EsotericBook *, int) = 0;
	virtual void visit(Disk *, int) = 0;
	virtual void visit(Category<Component> *, int) = 0;
};

class PrintVisitor : public Visitor {
public:
	PrintVisitor(const std::ostream &, char = '-', int = 3);
	std::streambuf* reset(std::ostream &);
	void visit(ProgrammingBook *, int = 0);
	void visit(CookBook *, int = 0);
	void visit(EsotericBook *, int = 0);
	void visit(Disk *, int = 0);
	void visit(Category<Component> *, int = 0);
	virtual ~PrintVisitor() {}

private:
	std::ostream os_;
	char indentChar_;
	int indentWidth_;
};

} /*end namespace catalog */

#endif  /* _VISITOR_H_ */