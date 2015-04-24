//自己的实现
#pragma once

#include <memory>

using namespace std;

class Singleton
{
public:
    static Singleton* Instance();
    virtual ~Singleton(void);
protected:
    Singleton(void);
protected:
    static auto_ptr<Singleton> instance;
};

//NOKIA的实现
/**
 * Base class for singletons.
 *
 * This construction relies on the fact that function-static objects
 * are only initialized when the function is first being called upon;
 * thus, we maintain the benefit of dynamic initialization.
 *
 * To use this, inherit from YSingleton<YourClass> and add
 * \code
 *  friend class YSingleton<YourClass>;
 * \endcode
 * in the private part of your class.
 *
 * To call a method on the singleton class...
 * \code
 *  YourClass::GetInstance()->method();
 * \endcode
 */
//template <class T>
//class YSingleton {
//public:
//    /**
//     * \return The singleton instance for this class.
//     */
//    static T *GetInstance() {
//        static T _instance;
//        return &_instance;
//    }
//    
//protected:
//    YSingleton() {}
//    virtual ~YSingleton() {}
//};


//#pragma once
//
//#include <memory>
//#include <windows.h> 
//
//using namespace std;
//
//using namespace C2217::Win32;
//
//class CResGuard;
//
//namespace C2217
//
//{
//
//namespace Pattern
//
//{
//
//template <class T>
//
//class Singleton
//
//{
//
//public:
//
//       static inline T* instance();
//
//      
//
//private:
//
//       Singleton(void){}
//
//       ~Singleton(void){}
//
//       Singleton(const Singleton&){}
//
//       Singleton & operator= (const Singleton &){}
//
// 
//
//       static auto_ptr<T> _instance;
//
//       static CResGuard _rs;
//
//};
//
//template <class T>
//
//auto_ptr<T> Singleton<T>::_instance;
//
// 
//
//template <class T>
//
//CResGuard Singleton<T>::_rs;
//
// 
//
//template <class T>
//
// inline T* Singleton<T>::instance()
//
//{
//
//       if( 0 == _instance.get() )
//
//       {
//
//              CResGuard::CGuard gd(_rs);
//
//              if( 0== _instance.get())
//
//              {
//
//                     _instance.reset ( new T);
//
//              }
//
//       }
//
//       return _instance.get();
//
//}
//
// 
//
////Class that will implement the singleton mode,
//
////must use the macro in it's delare file
//
//#define DECLARE_SINGLETON_CLASS( type ) /
//       friend class auto_ptr< type >;/
//       friend class Singleton< type >;
//
//}
//
//}
//
/////////////////////////////////////////////////////////////////////////////////
//
// 
//
//// Instances of this class will be accessed by multiple threads. So,
//
//// all members of this class (except the constructor and destructor)
//
//// must be thread-safe.
//
//class CResGuard {
//
//public:
//
//   CResGuard()  { m_lGrdCnt = 0; InitializeCriticalSection(&m_cs); }
//
//   ~CResGuard() { DeleteCriticalSection(&m_cs); }
//
// 
//
//   // IsGuarded is used for debugging
//
//   bool IsGuarded() const { return(m_lGrdCnt > 0); }
//
// 
//
//public:
//
//   class CGuard {
//
//   public:
//
//      CGuard(CResGuard& rg) : m_rg(rg) { m_rg.Guard(); };
//
//      ~CGuard() { m_rg.Unguard(); }
//
// 
//
//   private:
//
//      CResGuard& m_rg;
//
//   };
//
// 
//
//private:
//
//   void Guard()   { EnterCriticalSection(&m_cs); m_lGrdCnt++; }
//
//   void Unguard() { m_lGrdCnt--; LeaveCriticalSection(&m_cs); }
//
// 
//
//   // Guard/Unguard can only be accessed by the nested CGuard class.
//
//   friend class CResGuard::CGuard;
//
// 
//
//private:
//
//   CRITICAL_SECTION m_cs;
//
//   long m_lGrdCnt;   // # of EnterCriticalSection calls
//
//};