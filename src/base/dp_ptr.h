#ifndef DP_PTR_H
#define DP_PTR_H

template <typename T> static inline T *GetPtrHelper(T *ptr) { return ptr; }

#define DECLARE_PRIVATE(Class) \
    inline Class##Private* d_func() { return reinterpret_cast<Class##Private*>(GetPtrHelper(d_ptr)); } \
    inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private*>(GetPtrHelper(d_ptr)); }\
    friend class Class##Private;

#define DECLARE_PUBLIC(Class) \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;
 
#define DPTR(Class) Class##Private * const d  = d_func()
#define QPTR(Class) Class * const q = q_func()


#endif //DP_PTR_H