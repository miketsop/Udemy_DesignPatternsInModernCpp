#include <iostream>

struct Document;

// struct IMachine
// {
//     virtual void print(Document &doc) = 0;
//     virtual void scan(Document &doc) = 0;
//     virtual void fax(Document &doc) = 0;
// };

// struct MFP : IMachine
// {
//     void print(Document &doc) override
//     {
//     }
//     void scan(Document &doc) override
//     {
//     }
//     void fax(Document &doc) override
//     {
//     }
// };

// struct Scanner : IMachine
// {
//     void print(Document &doc) override
//     {
//         //* A scanner cannot print...
//     }
//     void scan(Document &doc) override
//     {
//         //* Ok to implement here
//     }
//     void fax(Document &doc) override
//     {
//         //* A scanner cannot print...
//     }
// };

//! Better segregate the interface

struct IPrinter
{
    virtual void print(Document &doc) = 0;
};

struct IScanner
{
    virtual void scan(Document &doc) = 0;
}

struct IFax
{
    virtual void fax(Document &doc) = 0;
}

struct Printer : IPrinter
{
    void print(Document &doc) override
    {
    }
}

struct Scanner : IScanner
{
    void scan(Document &doc) override
    {
    }
}

struct IMachine : IPrinter,
                  IScanner
{
    //* Keep it abstract
};

//* Can then decide what machine to implement
struct Machine : IMachine
{
    IPrinter &printer;
    IScanner &scanner;
    Machine(Iprint &printer, Iscanner &scanner) : printer(printer), scanner(scanner){};

    void print(Document &doc) override
    {
        printer.print(doc);
    }

    void scan(Document &doc) override
    {
        scanner.scan(doc);
    }
};

int main()
{
    return 0;
}