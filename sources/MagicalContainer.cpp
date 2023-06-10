#include "MagicalContainer.hpp"

using namespace ariel;

   MagicalContainer::MagicalContainer() : sideCrossFlag(false) {}


    MagicalContainer::~MagicalContainer(){}
    bool MagicalContainer::isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i*i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
void MagicalContainer::addElement(int element){
    this->elements.push_back(element);

    // For AscendingIterator
    ascContainer.push_back(element);
    std::sort(ascContainer.begin(), ascContainer.end());

    // For PrimeIterator
    if (isPrime(element)) {
        PrimeContainer.push_back(element);
        std::sort(PrimeContainer.begin(), PrimeContainer.end());
    }

    // For SideCrossIterator
   if (sideCrossContainer.empty() || !sideCrossFlag) {
        sideCrossContainer.push_back(element);
    } else {
        
        sideCrossContainer.insert(sideCrossContainer.begin(), element);
    }
    
std::sort(sideCrossContainer.begin(), sideCrossContainer.end());

    // Flip the flag for the next addition
    sideCrossFlag = !sideCrossFlag;
}




    void MagicalContainer::removeElement(int element){
     auto it = std::find(elements.begin(), elements.end(), element);
    if (it != elements.end()) {
        elements.erase(it);
    } else {
        throw std::runtime_error("Element not found");
    }

    it = std::find(ascContainer.begin(), ascContainer.end(), element);
    if (it != ascContainer.end()) {
        ascContainer.erase(it);
    }

    it = std::find(PrimeContainer.begin(), PrimeContainer.end(), element);
    if (it != PrimeContainer.end()) {
        PrimeContainer.erase(it);
    }

    it = std::find(sideCrossContainer.begin(), sideCrossContainer.end(), element);
    if (it != sideCrossContainer.end()) {
        sideCrossContainer.erase(it);
    }
    }

    int MagicalContainer::size() const{return this->elements.size();}





/*   -----------------    AscendingIterator      -----------------    */


    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
            : container(container){
                this->itr = container.getascContainer().begin();
            }

   MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator& other)
    : container(other.container), itr(other.itr), index(other.index) {}

    MagicalContainer::AscendingIterator::~AscendingIterator(){}

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
    if (&this->container != &other.container) {
        throw std::runtime_error("Iterators point to different containers");
    }
    this->itr = other.itr;
    this->index = other.index;
    return *this;
}

   bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return (this->index == other.index) && (&this->container == &other.container);
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return (this->index != other.index) || (&this->container != &other.container);
}

   bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    if (&this->container != &other.container) {
        throw std::runtime_error("Iterators point to different containers");
    }
    return this->index < other.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    if (&this->container != &other.container) {
        throw std::runtime_error("Iterators point to different containers");
    }
    return this->index > other.index;
}
    int MagicalContainer::AscendingIterator::operator*() const {
        return *itr;
    }

   MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++(){
    if (itr == container.getascContainer().end()) {
        throw std::runtime_error("Iterator cannot be incremented past the end");
    }
    ++itr;
    ++index;
    return *this;
}

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin(){
        // cout <<"inside begin: " <<  *container.getascContainer().begin() << endl;
        itr = container.getascContainer().begin();
        index = 0;
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end(){
        // cout <<"inside end: " <<  *container.getascContainer().end() << endl;
        itr = container.getascContainer().end();
        index = container.getascContainer().size();
        return *this;
    }




/*   -----------------    PrimeIterator      -----------------    */

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
            : container(container){
                this->itr = container.getPrimeContainer().begin();
            }
MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator& other)
    : container(other.container), itr(other.itr), index(other.index) {}

    MagicalContainer::PrimeIterator::~PrimeIterator(){}

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    if (&this->container != &other.container) {
        throw std::runtime_error("Iterators point to different containers");
    }
    this->itr = other.itr;
    this->index = other.index;
    return *this;
}

   bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return (this->index == other.index) && (&this->container == &other.container);
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return (this->index != other.index) || (&this->container != &other.container);
}

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    if (&this->container != &other.container) {
        throw std::runtime_error("Iterators point to different containers");
    }
    return this->index < other.index;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    if (&this->container != &other.container) {
        throw std::runtime_error("Iterators point to different containers");
    }
    return this->index > other.index;
}

    int MagicalContainer::PrimeIterator::operator*() const {
        return *itr;
    }

   MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++(){
    if (itr == container.getPrimeContainer().end()) {
        throw std::runtime_error("Iterator cannot be incremented past the end");
    }
    ++itr;
    ++index;
    return *this;
}

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::begin(){
        // cout <<"inside begin: " <<  *container.getPrimeContainer().begin() << endl;
        itr = container.getPrimeContainer().begin();
        index = 0;
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::end(){
        // cout <<"inside end: " <<  *container.getPrimeContainer().end() << endl;
        itr = container.getPrimeContainer().end();
        index = container.getPrimeContainer().size();
        return *this;
    }


    /*   -----------------    SideCrossIterator      -----------------    */

   MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
        : container(container) {
    this->itr = container.getsideCrossContainer().begin();
}
MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator& other)
    : container(other.container), itr(other.itr), index(other.index) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

   MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
    if (&this->container != &other.container) {
        throw std::runtime_error("Iterators point to different containers");
    }
    this->itr = other.itr;
    this->index = other.index;
    return *this;
}

   bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return (this->index == other.index) && (&this->container == &other.container);
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return (this->index != other.index) || (&this->container != &other.container);
}

  bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    if (&this->container != &other.container) {
        throw std::runtime_error("Iterators point to different containers");
    }
    return this->index < other.index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    if (&this->container != &other.container) {
        throw std::runtime_error("Iterators point to different containers");
    }
    return this->index > other.index;
}

    int MagicalContainer::SideCrossIterator::operator*() const {
        return *itr;
    }

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++(){
    if (itr == container.getsideCrossContainer().end()) {
        throw std::runtime_error("Iterator cannot be incremented past the end");
    }
   index++;
    if (index % 2 == 0) {
        itr = container.getsideCrossContainer().begin() + index / 2;
    } else {
        itr = container.getsideCrossContainer().end() - 1 - index / 2;
    }
    return *this;
}


 MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::begin() {
    
    itr=container.getsideCrossContainer().begin();
    index=0;
    return *this;
}

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::end(){
        // cout <<"inside end: " <<  *container.getsideCrossContainer().end() << endl;
        itr = container.getsideCrossContainer().end();
        index = container.getsideCrossContainer().size();
        return *this;
    }