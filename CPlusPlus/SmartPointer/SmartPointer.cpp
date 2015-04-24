// SmartPointer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//Nokia
///**
// *  Base interface for smart pointers. Provides standard overloaded operators used commonly 
// *  in smart pointers.
// */
//template <class T> class YPointerBase {
//public:
//    explicit YPointerBase(T *obj)
//        : m_object(obj) {}
//
//    /**
//     *  This is a shortcut that enables you to use an YPointerBase
//     *  as a regular pointer--like this:
//     *
//     *  <pre>
//     *  void func(MyClass *ptr);
//     *  YReference<MyClass> refToMyClass(new MyClass());
//     *  func(refToMyClass);
//     *  </pre>
//     */
//    operator T*() const { 
//        return m_object; 
//    }
//
//    /**
//     *  This is a shortcut that enables you to use the -> operator on a
//     *  YPointerBase as you would on a regular pointer--like this:
//     *
//     *  <pre>
//     *  YReference<MyClass> refToMyClass(new MyClass());
//     *  ptrToMyClass->memberFunction();
//     *  </pre>
//     *
//     *  You should make sure it really *does* contain a valid
//     *  pointer, though. Otherwise, you will have yourself a crash.
//     */
//    T *operator->() const {
//        return m_object;
//    }
//
//    /**
//     *  Transfers ownership of the object pointed to to the caller. The 
//     *  YPointer will contain 0 after this. This is a common scenario:
//     *
//     *  <pre>
//     *  MyClass *createAMyClass(int aValue) {
//     *    YPointer<MyClass> ptrToMyClass(new MyClass());
//     *    ptrToMyClass->setAValue(aValue);
//     *    // (... do even more stuff...)
//     *    return ptrToMyClass.detach();
//     *  }
//     *  </pre>
//     *
//     *  \return
//     *      The pointer.
//     */
//    T *detach() {
//        T *object = m_object;
//        m_object = 0;
//        return object;
//    }
//
//protected:
//    T *m_object;
//};
//
///**
// *  This class exists to help releasing objects on the heap. It will destroy
// *  the pointer associated with it as it is also destroyed.
// *
// *  Example:
// *  \code
// *  YPointer<SomeClass> someobject(new SomeClass(somearg));
// *  someobject->someOperation();
// *  return someobject.detach();
// *  \endcode
// *
// *  The reason all the functions are defined inline is that some compilers
// *  have trouble understanding template classes with the functions in a
// *  different file.
// *
// *  No virtual functions should be contained in this class.
// */
//template <class T> class YPointer : public YPointerBase<T> {
//public:
//
//    /**
//     * Construct an YPointer with an object.
//     * \note Does not use default arguments since that will cause
//     *    problems on ADS 1.2.
//     */
//    explicit YPointer(T *object) :
//        YPointerBase<T>(object)
//    {
//    }
//
//    /**
//     * Construct empty YPointer.
//     */
//    explicit YPointer() :
//        YPointerBase<T>(0)
//    {
//    }
//
//    
//    ~YPointer() {
//        delete YPointerBase<T>::m_object;
//    }
//
//    /**
//     *  Set a pointer to hold. If the YPointer already contains a
//     *  pointer, it will be deleted.
//     *
//     *  \param object
//     *      A pointer to a suitable object. Passing 0 is like calling the
//     *      reset() function.
//     */
//    void set(T *object) {
//        if (YPointerBase<T>::m_object == object) return;
//        delete YPointerBase<T>::m_object;
//        YPointerBase<T>::m_object = object;
//    }
//
//    /**
//     *  The = operator does the same as the set() function.
//     */
//    YPointer &operator=(T *object) {
//        if (YPointerBase<T>::m_object == object) return *this;
//        delete YPointerBase<T>::m_object;
//        YPointerBase<T>::m_object = object;
//        return *this;
//    }
//
//    /**
//     *  \return 
//     *      The contained pointer. 0 if none has been set.
//     */
//    T *get() const {
//        return YPointerBase<T>::m_object;
//    }
//
//    /**
//     *  Deletes the object pointed to and sets the pointer to 0.
//     */
//    void release() {
//        delete YPointerBase<T>::m_object;
//        YPointerBase<T>::m_object = 0;
//    }
//
//private:
//    // This one is illegal.
//    YPointer &operator=(YPointer<T> &pointer);
//};


template <class T>  
class smartpointer  
{  
private:  
    T *_ptr;  
public:  
    smartpointer(T *p) : _ptr(p)  //构造函数  
    {  
    }  
    T& operator *()        //重载*操作符  
    {  
        return *_ptr;  
    }  
    T* operator ->()       //重载->操作符  
    {  
        return _ptr;  
    }  
    ~smartpointer()        //析构函数  
    {  
        delete _ptr;  
    }  
}; 

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

