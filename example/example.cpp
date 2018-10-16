#include "../src/copy-object.h"

/********** class Base start here **********/ 
class Base : public CopyableTemplate<Base>{
public:
	Base();
	virtual ~Base();
	void SetBaseValue(const int value);
	int GetBaseValue() const;
private:
	int* m_pointer;
	
protected:
	virtual void DoCopy(Base* copy) const override;
};//class Base

Base::Base()
	: m_pointer(new int (0))
{ }

Base::~Base()
{
	delete m_pointer;
}

void Base::SetBaseValue(const int value)
{
	*m_pointer = value;
}

int Base::GetBaseValue() const
{
	return *m_pointer;
}

void Base::DoCopy(Base* copy) const override
{
	copy->m_pointer = new int(*m_pointer);
};
/********** class Base end here **********/ 


/********** class Derived start here **********/
class Derived : public CopyableTemplate<Derived, Base> {
public:
	Derived();
	virtual ~Derived();
	void SetDerivedValue(const int value);
	int GetDerivedValue() const;
private:
	int* m_pointer;
	
protected:
	virtual void DoCopy(Derived* copy) const override;
};//class Derived

Derived::Derived()
	: m_pointer(new int (0))
{ }

Derived::~Derived()
{
	delete m_pointer;
}

void Derived::SetDerivedValue(const int value)
{
	*m_pointer = value;
}

int Derived::GetDerivedValue() const
{
	return *m_pointer;
}

void Derived::DoCopy(Derived* copy) const override
{
	copy->m_pointer = new int(*m_pointer);
};
/********** class Derived end here **********/ 

int main()
{
	Derived* pDerived = new Derived();
	pDerived->SetBaseValue(1);
	pDerived->SetDerivedValue(2);
	Base* pBase = dynamic_cast<Base*>(pDerived);
	Base* pCopyBase = pBase->CopyObject();
	Derived* pCopyDerived = dynamic_cast<Derived*>(pCopyBase);
	if(pCopyDerived == NULL)
	{
		std::cout << "copy failed" << std::endl;
		exit(1);
	}
	else
	{
		std::cout << "copy successed" << std::endl;
	}

	pDerived->SetBaseValue(3);
	pDerived->SetDerivedValue(4);
	std::cout << "Base Value in Copy is " << pCopyDerived->GetBaseValue() << std::endl;
	std::cout << "Derived Value in COpy is " << pCopyDerived->GetDerivedValue() << std::endl;

	delete pCopyDerived;
	delete pDerived;
	return 0;
}
