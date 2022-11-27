#include <iostream>
#include <vector>

class ISpeed
{
protected:
    double speed;
public:
    virtual void SetSpeed(double) = 0;
    virtual double GetSpeed() = 0;
    void Method()
    {
        std::cout << "method work\n";
    }
};

class Bird : public ISpeed
{
    void SetSpeed(double) override
    {
        this->speed = speed;
    }
    double GetSpeed()
    {
        return this->speed;
    }
    void BirdMethod()
    {
        std::cout << "method work\n";
    }
};

class Figure
{
protected:
    int x, y;
public:
    Figure(int x = 0, int y = 0) : x{ x }, y{ y } {}
    virtual double Perimetr() = 0;
    virtual double Square() = 0;
    void Method()
    {
        std::cout << "method work\n";
    }
};

class Rectangle : public Figure
{
protected:
    int w, h;
public:
    Rectangle(int x = 0, int y = 0, int w = 0, int h = 0) : Figure(x, y), w{ w }, h{ h } {}
    double Perimetr() override
    {
        return 2 * (w + h);
    }
    double Square() override
    {
        return w * h;
    }
};

class Circle : public Figure
{
protected:
    const double PI = 3.14156;
    int radius;
public:
    Circle(int x, int y, int radius) : Figure(x, y), radius{ radius } {}
    double Perimetr() override
    {
        return 2 * PI * radius;
    }
    double Square() override
    {
        return radius * radius * PI;
    }
};

class CompositeFigure : public Figure
{
protected:
    std::vector<Figure*> fs;
public:
    void Add(Figure* f)
    {
        fs.push_back(f);
    }
    double Perimetr() override
    {
        double result{ 0.0 };
        for (int i = 0; i < fs.size(); i++)
            result += fs[i]->Perimetr();
        return result;
    }
    double Square() override
    {
        double result{ 0.0 };
        for (int i = 0; i < fs.size(); i++)
            result += fs[i]->Square();
        return result;
    }
};

int main()
{
    std::vector<Figure*> figures;
    figures.push_back(new Rectangle(0, 0, 10, 20));
    figures.push_back(new Circle(0, 0, 10));

    for (int i = 0; i < figures.size(); i++)
    {
        std::cout << figures[i]->Perimetr() << "\n";
        std::cout << figures[i]->Square() << "\n";
    }

    CompositeFigure* cf1 = new CompositeFigure();
    cf1->Add(new Rectangle(0, 0, 10, 20));
    cf1->Add(new Circle(0, 0, 10));

    CompositeFigure* cf2 = new CompositeFigure();
    cf2->Add(new Rectangle(0, 0, 30, 50));
    cf2->Add(new Circle(0, 0, 20));
    cf2->Add(cf1);

    ISpeed* bird = new Bird();
    bird->Method();
}
