#pragma once
#include <vector>
#include <iostream>

using namespace std;

namespace ariel
{

    class MagicalContainer {                // The class
    private:                                // private Access specifier

    /* part A - still not sure about the dynamic container to use so for now i prefer Vectors for all */
    bool sideCrossFlag;
    vector<int> elements;                   // dynamic array Container
    vector<int> ascContainer;               // ascending array Container
    vector<int> PrimeContainer;             // Prime array Container
    vector<int> sideCrossContainer;         // sideCross array Container

    public:                                 // Access specifier
	 bool isPrime(int number);
        MagicalContainer();                 // Constructor

        ~MagicalContainer();                // destructor

        void addElement(int element);       // add Element method

        void removeElement(int element);    // remove Element method

        int size() const ;                  // get Container size

        /* used these methods to link the containers by reference with there iterators */
        vector<int>& getascContainer(){
            return this->ascContainer;
        }
        vector<int>& getPrimeContainer(){
            return this->PrimeContainer;
        }
        vector<int>& getsideCrossContainer(){
            return this->sideCrossContainer;
        }
        /* Define Nested Classes */
            class AscendingIterator;
            class SideCrossIterator;
            class PrimeIterator;

    };

    class MagicalContainer::AscendingIterator   // The class
    {               
        private:                                // private Access specifier

        MagicalContainer& container;            // each iterator should have thier container
        vector<int>::iterator itr;              // built in iterator
        int index=0;                            // index to compare between two iterators value

        public:                                 // Access specifier

            AscendingIterator(MagicalContainer& container); // constructor

            AscendingIterator(AscendingIterator& other); // copy constructor

            ~AscendingIterator();                // destructor

            /* const after a method name like that : int getX() const -> means that this method is not going to modify any of the class variables */

            AscendingIterator& operator=(const AscendingIterator& other);

            bool operator==(const AscendingIterator& other) const ;

            bool operator!=(const AscendingIterator& other) const ;

            bool operator>(const AscendingIterator& other) const ;

            bool operator<(const AscendingIterator& other) const ;

            int operator*() const ;

            AscendingIterator& operator++() ;

            AscendingIterator &begin();

            AscendingIterator& end();
        
    };

    class MagicalContainer::PrimeIterator {                   // The class
        private:                                // private Access specifier

        MagicalContainer& container;            // each iterator should have thier container
        vector<int>::iterator itr;              // built in iterator
        int index=0;                            // index to compare between two iterators value

        public:                                 // Access specifier

            PrimeIterator(MagicalContainer& container); // constructor

            PrimeIterator(PrimeIterator& other);        // copy constructor
            
            ~PrimeIterator();                // destructor

            PrimeIterator& operator=(const PrimeIterator& other);

            bool operator==(const PrimeIterator& other) const;

            bool operator!=(const PrimeIterator& other) const ;

            bool operator>(const PrimeIterator& other) const ;

            bool operator<(const PrimeIterator& other) const ;

            int operator*() const ;

            PrimeIterator& operator++() ;

            bool isPrime(int num);

            PrimeIterator& begin();

            PrimeIterator& end();


    };

    class MagicalContainer::SideCrossIterator {               // The class
        private:                                // private Access specifier
            MagicalContainer& container;            // each iterator should have thier container
            vector<int>::iterator itr;    
             vector<int>::iterator itr_start;
       vector<int>::iterator itr_end;
             // built in iterator
            int index=0;                            // index to compare between two iterators value
	 bool fromStart=true;    
	  bool isEnd=false; 
        public:                                 // Access specifier
		
            SideCrossIterator(MagicalContainer& container); // constructor 

            SideCrossIterator(SideCrossIterator& other);    // copy constructor
	    bool fromstart(){
	    return fromStart;}
            ~SideCrossIterator();                // destructor

            SideCrossIterator& operator=(const SideCrossIterator& other) ;
		
            bool operator==(const SideCrossIterator& other) const ;

            bool operator!=(const SideCrossIterator& other) const ;

            bool operator>(const SideCrossIterator& other) const ;

            bool operator<(const SideCrossIterator& other) const ;

            int operator*() const ;

            SideCrossIterator& operator++() ;

            SideCrossIterator& begin();

            SideCrossIterator& end();


    };

}
