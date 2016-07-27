#include <string>
#include "visitor.h"

namespace catalog {

PrintVisitor::PrintVisitor(const std::ostream &os, char indentChar, int indentWidth) : 
	os_(os.rdbuf()), indentChar_(indentChar), indentWidth_(indentWidth) {
}

std::streambuf* PrintVisitor::reset(std::ostream &os) {
	return os_.rdbuf(os.rdbuf());
}

void PrintVisitor::visit(ProgrammingBook *p, int state) {
	os_ << std::string(indentWidth_ * state, indentChar_);
	os_ << p->getName() << ", " << p->getPrice() << ", " << p->getBarcode();
	os_ << " (" << p->getProgrammingLanguage() << ")" << std::endl;
}

void PrintVisitor::visit(CookBook *p, int state) {
	os_ << std::string(indentWidth_ * state, indentChar_);
	os_ << p->getName() << ", " << p->getPrice() << ", " << p->getBarcode();
	os_ << " (" << p->getIngredient() << ")" << std::endl;
}

void PrintVisitor::visit(EsotericBook *p, int state) {
	os_ << std::string(indentWidth_ * state, indentChar_);
	os_ << p->getName() << ", " << p->getPrice() << ", " << p->getBarcode();
	os_ << " (Minimum age - " << p->getAge() << ")" << std::endl;
}

void PrintVisitor::visit(Disk *p, int state) {
	std::string diskType = Disk::ToString(p->getDiskType());
	std::string contentType = Disk::ToString(p->getContentType());

	os_ << std::string(indentWidth_ * state, indentChar_);
	os_ << p->getName() << ", " << p->getPrice() << ", " << p->getBarcode();
	os_ << " (" << diskType << ", " << contentType << ")" << std::endl;
}

void PrintVisitor::visit(Category *p, int state) {
	os_ << std::string(indentWidth_ * state, indentChar_);
	os_ << p->getName() << std::endl;
	for (Category::ChildIterator it = p->begin(); it != p->end(); ++it) {
		(*it)->accept(*this, state + 1);
	}
}

} /*end namespace catalog */