// open closed principle

// open for extension, closed for modification

#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum class Color
{
    red,
    green,
    blue
};
enum class Size
{
    small,
    medium,
    large
};

struct Product
{
    string name;
    Size size;
    Color color;
};

struct ProductFilter
{
    typedef vector<Product *> Items;

    Items byColor(Items items, Color color)
    {
        Items result;
        for (auto item : items)
        {
            if (item->color == color)
            {
                result.push_back(item);
            }
        }
        return result;
    }

    Items bySize(Items items, Size size)
    {
        Items result;
        for (auto item : items)
        {
            if (item->size == size)
            {
                result.push_back(item);
            }
        }
        return result;
    }

    Items bySizeAndColor(Items items, Color color, Size size)
    {
        Items result;
        for (auto item : items)
        {
            if ((item->size == size) && (item->color == color))
            {
                result.push_back(item);
            }
        }
        return result;
    }
};

template <typename T>
struct Specification
{
    virtual ~Specification() = default;
    virtual bool isSatisfied(T *item) const = 0;
};

template <typename T>
struct Filter
{
    virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product *> filter(vector<Product *> items, Specification<Product> &spec) override
    {
        vector<Product *> result;
        for (auto i : items)
        {
            if (spec.isSatisfied(i))
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;

    ColorSpecification(Color color) : color(color){};

    bool isSatisfied(Product *item) const override
    {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size;
    SizeSpecification(Size size) : size(size){};

    bool isSatisfied(Product *item) const override
    {
        return item->size == size;
    }
};

template <typename T>
struct AndSpecification : Specification<T>
{
    const Specification<T> &first;
    const Specification<T> &second;

    AndSpecification(const Specification<T> &first, const Specification<T> &second)
        : first(first), second(second)
    {
        cout << "Constructor for AND specification!" << endl;
    }

    bool isSatisfied(T *item) const override
    {
        return first.isSatisfied(item) && second.isSatisfied(item);
    }
};

template <typename T>
AndSpecification<T> operator&&(const Specification<T> &first, const Specification<T> &second)
{
    return AndSpecification<T>(first, second);
}

int main()
{
    Product apple{"apple", Size::small, Color::green};
    Product tree{"tree", Size::medium, Color::green};
    Product house{"house", Size::large, Color::blue};

    const vector<Product *> all{&apple, &tree, &house};

    ProductFilter pf;
    BetterFilter bpf;

    ColorSpecification blueSpec(Color::blue);
    SizeSpecification largeSpec(Size::large);

    auto bluethings = pf.byColor(all, Color::blue);
    for (auto x : bluethings)
    {
        cout << x->name << " is blue" << endl;
    }

    auto betterBlueThings = bpf.filter(all, blueSpec);
    for (auto x : betterBlueThings)
    {
        cout << x->name << " is blue" << endl;
    }

    // AndSpecification<Product> colorAndSize(blueSpec, largeSpec);
    AndSpecification<Product> blueAndLargeSpec = blueSpec && largeSpec;
    auto blueAndLarge = bpf.filter(all, blueAndLargeSpec);
    for (auto x : blueAndLarge)
    {
        cout << x->name << " is blue and large" << endl;
    }

    return 0;
}