#ifndef LINEARLIST_H_
#define LINEARLIST_H_
/*
 * 模板类不支持分开文件实现 因为编译器无法在编译阶段确定分配的空间
 * 在编译阶段不会创建具体函数，在分文件编写代码时，可以直接包含.cpp文件
 * 但是更好的方法是将类模板的定义和实现一起写在.hpp文件中，约定俗成这是
 * 类模板文件，更推荐使用.hpp实现类模板的分文件编写
 */
const int defaultSize = 100;
template <typename T>
class LinearList
{
public:
    LinearList(int sz = defaultSize);
    ~LinearList();
    int Size();
    int Length();
    int Search(const T &x) const;
    int Locate(int i) const;
    bool getData(int i, T &x);
    bool setData(int i, T &x);
    bool Insert(int i, T x);
    bool Remove(int i, T &x);
    bool isEmpty() const;
    bool isFull() const;
    void Resize(int newSize);
    LinearList(const LinearList<T> &L);

protected:
    T * data;
    int maxSize;
    int last;

};
#endif