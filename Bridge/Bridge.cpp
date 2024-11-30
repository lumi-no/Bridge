#include <iostream>
#include <string>


class Implementation {
public:
    virtual std::string OperationImplementation() const = 0;
    virtual ~Implementation() = default;
};


class ConcreteImplementationA : public Implementation {
public:
    std::string OperationImplementation() const override {
        return "ConcreteImplementationA: ��������� A.";
    }
};

class ConcreteImplementationB : public Implementation {
public:
    std::string OperationImplementation() const override {
        return "ConcreteImplementationB: ��������� B.";
    }
};


class Abstraction {
protected:
    Implementation* implementation_; 

public:
    Abstraction(Implementation* implementation) : implementation_(implementation) {}
    virtual ~Abstraction() = default;

    virtual std::string Operation() const {
        return "Abstraction: ������ �������� � �������������:\n" +
            implementation_->OperationImplementation();
    }
};


class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) {}

    std::string Operation() const override {
        return "ExtendedAbstraction: ��������� �������� � �������������:\n" +
            implementation_->OperationImplementation();
    }
};


void ClientCode(const Abstraction& abstraction) {
    std::cout << abstraction.Operation() << std::endl;
}

int main() {
    Implementation* implementationA = new ConcreteImplementationA;
    Abstraction* abstraction = new Abstraction(implementationA);
    std::cout << "�볺��: ���������� � ���������� ���������� A:\n";
    ClientCode(*abstraction);

    Implementation* implementationB = new ConcreteImplementationB;
    Abstraction* extendedAbstraction = new ExtendedAbstraction(implementationB);
    std::cout << "\n�볺��: ���������� � ���������� ����������� �� ���������� B:\n";
    ClientCode(*extendedAbstraction);

    
    delete implementationA;
    delete abstraction;
    delete implementationB;
    delete extendedAbstraction;

    return 0;
}
