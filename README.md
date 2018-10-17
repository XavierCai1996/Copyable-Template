# Copyable-Template

A framework using object-oriented programming to provide interfaces for copy the object.

### Features
* Light-weight framework to achieve deep copy.
* Automatic copy interface. You just need to allocte memory for pointer members.

    An example object without any pointer member:
    ```
    class ClassWithoutPointerMember : public CopyableTemplate<ClassWithoutPointerMember> {
    private:
        int i, j;
    //...
    //you don not need to override any interface, because there is no pointer member inside this class
    };
    ```
    
    An example object with a pointer member :
    ```
    class ClassWithPointerMember : public CopyableTemplate<ClassWithPointerMember> {
    private:
        int* i;
        int j;
    public:
        ClassWithPointerMember() : i(new int(0)), j(0) { }
        //virtual is required here
        virtual ~ClassWithPointerMember() {
            delete i;
        }
    protected:
        //virtual, const, override are required here
        virtual DoCopy(ClassWithPointerMember* copy) const override {
           //just care about pointer member
           copy->i = new int(*i);
        }
    };
    ```
    
* User-friendly interfaces.
    
    Get a base type copy:
    
    `ClassWithPointerMember original;`
   
   `CopyableObject* copyBase = original.Copy();`
    
    Get a original type copy:
    
    `ClassWithPointerMember* copy = original.CopyObject();`

## How to run the example

1.Enter to the folder ./example/.

2.Run the script ./run.ls.

## How to use this template in projects

1.Copy the folder ./src/ to your projects.

2.Include the header file ./src/copy-object.h in your codes.

## Contact me

Contact me on my mail address cxw39@foxmail.com

and sorry about my poor English XD.
