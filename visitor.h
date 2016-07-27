#ifndef _VISITOR_H_
#define _VISITOR_H_

#include <ostream>
#include "product_tree.h"

namespace catalog {
using std::ostream;

class Visitor {
public:
	virtual void visit(ProgrammingBook *p) = 0;
	virtual void visit(CookBook *p) = 0;
	virtual void visit(EsotericBook *p) = 0;
	virtual void visit(Disk *p) = 0;
	virtual void visit(Category<Component> *p) = 0;
};

class PrintVisitor : public Visitor;

} // end namespace Catalog

#endif /* _VISITOR_H_ */