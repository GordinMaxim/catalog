#include "visitor.h"

namespace catalog {

class PrintVisitor : public Visitor {
public:
	PrintVisitor(const ostream &os) {
		os_ = os;
	}

	void visit(ProgrammingBook *p) {
		os_ << "Programming Book (" << p->getProgrammingLanguage() << "): ";
		os_ << p->getName() << ", " << p->getPrice() << ", " << p->getBarcode() << std::endl;
	}
	
	void visit(CookBook *p) {
		os_ << "Cook Book (" << p->getIngredient() << "): ";
		os_ << p->getName() << ", " << p->getPrice() << ", " << p->getBarcode() << std::endl;
	}
	
	void visit(EsotericBook *p) {
		os_ << "Esoteric Book (Minimum age - " << p->getAge() << "): ";
		os_ << p->getName() << ", " << p->getPrice() << ", " << p->getBarcode() << std::endl;
	}
	
	void visit(Disk *p) {
		os_ << "Disk (" << p->getDiskType() << ", " << p->getContentType() << "): ";
		os_ << p->getName() << ", " << p->getPrice() << ", " << p->getBarcode() << std::endl;
	}

	void visit(Category<Component> *p) {
		os_ << p->getName() << std::endl;
		for (Category<Component>::ChildIterator it = p->begin(); it != p->end(); ++it) {
			os_ << "\t";
			(*it)->accept(*this);
		}
	}

	virtual ~PrintVisitor() {}

private:
	ostream os_;
};

}