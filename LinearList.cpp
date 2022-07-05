#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/* Define the default size of the list */
const int defaultSize = 100;

/* Define the linear-list class using c++ */
class SequentialList {
public:
    SequentialList(int size = defaultSize); // the constructor
    SequentialList(SequentialList& Seq);    // the copy constructor
    ~SequentialList() { delete [] data; };  // the destructor
    int Size() const { return maxSize; };   // maximum size of the list
    int Length() const { return last + 1; }; // the length of the list
    int Search(int x) const;              // search the position of the element x in the list
    int Locate(int i) const;                 // locate the ith element in the list
    bool getData(int i, int & x) const;     // get the data of the ith element
    bool setData(int i, int x);             // set the data of the ith element
    bool Insert(int i, int x);           // insert the element after the ith element
    bool Remove(int i, int & x);             // remove the ith element
    bool IsEmpty() { return last == -1; }   // whether list is empty
    bool IsFull() { return last == maxSize - 1; } // whether list is full
    void Show() const;                      // show the list

private:
    int * data;  // pointer to the data
    int maxSize;    // maximum size of the list
    int last;   // last element in the list
    void Resize(const int newSize);
};


SequentialList::SequentialList(int size) {
    if (size > 0) {
        maxSize = size;  // maximum size of the list
        // last = maxSize - 1;
        last = -1;
        data = new int[maxSize];
        if (data == nullptr) {
            cerr << "Failed to allocate memory!" << endl;
            exit(EXIT_FAILURE);
        }
    } else {
        cerr << "The maxSize of the list must be a positive integer!" << endl;
        exit(EXIT_FAILURE);
    }
}

SequentialList::SequentialList(SequentialList& Seq) {
    /* To initialize a new list from an existing list */
    maxSize = Seq.Size();
    last = Seq.Length() - 1;
    int tempValue;
    data = new int[maxSize];
    if (data == nullptr) {
            cerr << "Failed to allocate memory for the list!" << endl;
            exit(EXIT_FAILURE);
    }
    // to copy the data from the existing list to the new list
    for (int i = 1; i <= last + 1; ++i) {  // start with index 1 when using the list
        Seq.getData(i, tempValue);
        data[i-1] = tempValue;
    }

}

void SequentialList::Resize(int newSize) {
    if (newSize <= 0) {
        cerr << "Invalid value for new size!" << endl;
        exit(EXIT_FAILURE);
    }
    if (newSize == maxSize) // unnecessary the apply a new space
        return;
    int * newArray = new int[newSize];
    if (newArray == nullptr) {
        cerr << "Failed to allocate memory!" << endl;
        exit(EXIT_FAILURE);
    }

    int n = last + 1;  // number of elements in the old list
    int * srcptr = data;
    int * destptr = newArray;

    // copy data to the new array
    while (n--)
        *destptr++ = *srcptr++;
    
    delete[] data;
    data = newArray;
    maxSize = newSize;
}

bool SequentialList::getData(int i, int & x) const {
    if (i <= 0 || i > last + 1)
        return false;
    x = data[i-1];
    return true;
}

bool SequentialList::setData(int i, int x) {
    if (i <= 0 || i > last + 1)
        return false;
    data[i-1] = x;
    return true;
}

int SequentialList::Search(int x) const {
    for (int i = 0; i < last + 1; ++i) {
        if (x == data[i])
            return i+1;
    }
    return 0;   // not found
}

int SequentialList::Locate(int i) const {
    if (i >= 1 && i <= last + 1) 
        return i;
    return 0;
}

bool SequentialList::Insert(int i, int x) {
    if (IsFull()) {
        cerr << "List is full!" << endl;
        return false;
    }
        
    if (i < 1 || i > maxSize + 1)
        return false;
    
    for (int j = last; j >= i; --j)  // when loop finishes, j = i - 1
        data[j+1] = data[j];   // move data backward
    data[i-1] = x;
    last++;
    return true;
}

bool SequentialList::Remove(int i, int & x) {
    if (IsEmpty())
        return false;
    if (i < 1 || i > last + 1)
        return false;
    x = data[i-1];

    for (int j = i; j < last + 1; ++j)  // move data forward
        data[j-1] = data[j];
    return true;
}

void SequentialList::Show() const {
    for (int i = 0; i < last + 1; ++i)
        cout << data[i] << " ";
    cout << endl;
}

int main() {
    SequentialList list(defaultSize);
    for (int i = 1; i <= 10; ++i) {
        list.Insert(i, pow(i+1, 2));
    }
    list.setData(5, 10);
    list.Show();
    cout << list.Search(64) << endl;
    return 0;
}