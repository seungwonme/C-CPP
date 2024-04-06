# Orthodox Canonical Class Form

```c++
class Foo
{
private:
    int mDataMember;
public:
    Foo(int dataMember) : mDataMember(dataMember) {}
    ~Foo() {}
    Foo(const Foo &rhs) : mDataMember(rhs.mDataMember) {}
    const Foo& operator=(const Foo &rhs)
    {
        if (this == &rhs)
            return *this;
        mDataMember = rhs.mDataMember;
        return *this;
    }
};
```
