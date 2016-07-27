#include "visitor.h"

namespace catalog {

void PrintVisitor::visit(ProgrammingBook *p) {
	os_ << "Programming Book (" << p->getProgrammingLanguage() << "): ";
	os_ << p->getName() << ", " << p->getPrice() << ", " << p->getBarcode() << std::endl;
}

void PrintVisitor::visit(CookBook *p) {
	os_ << "Cook Book (" << p->getIngredient() << "): ";
	os_ << p->getName() << ", " << p->getPrice() << ", " << p->getBarcode() << std::endl;
}

void PrintVisitor::visit(EsotericBook *p) {
	os_ << "Esoteric Book (Minimum age - " << p->getAge() << "): ";
	os_ << p->getName() << ", " << p->getPrice() << ", " << p->getBarcode() << std::endl;
}

void PrintVisitor::visit(Disk *p) {
	os_ << "Disk (" << p->getDiskType() << ", " << p->getContentType() << "): ";
	os_ << p->getName() << ", " << p->getPrice() << ", " << p->getBarcode() << std::endl;
}

void PrintVisitor::visit(Category<Component> *p) {
	os_ << p->getName() << std::endl;
	for (Category<Component>::ChildIterator it = p->begin(); it != p->end(); ++it) {
		os_ << "\t";
		(*it)->accept(*this);
	}
}

} /*end namespace catalog */