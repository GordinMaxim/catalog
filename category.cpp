#include "category.h"
#include "visitor.h"
#include "product_tree.h"

namespace catalog {
    
    Category::Category(const string &name) : name_(name) {}

    string Category::getName() const {
        return name_;
    }

    void Category::setName(const string &name) {
        name_ = name;
    }

    void Category::addChild(Component *child) {
        ChildIterator it = std::find(children_.begin(), children_.end(), child);
        if (children_.end() == it) {
            children_.push_back(child);
        }
    }

    Category::ChildIterator Category::begin() {
        return children_.begin();
    }

    Category::ChildIterator Category::end() {
        return children_.end();
    }

    void Category::removeChild(Component *child) {
        ChildIterator it = std::find(children_.begin(), children_.end(), child);
        if (children_.end() != it) {
            children_.erase(it);
        }
    }

    void Category::clear() {
        children_.clear();
    }

    void Category::accept(Visitor &v, int state) {
        v.visit(this, state);
    }
}