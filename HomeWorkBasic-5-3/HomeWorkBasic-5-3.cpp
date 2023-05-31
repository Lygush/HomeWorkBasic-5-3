#include <iostream>
#include <string>

class Figure;
void getInfo(Figure&);

class Figure {
protected:
    int sidesCount{};
    std::string figureName{};

    Figure(std::string figureName, int sidesCount) {
        this->figureName = figureName;
        this->sidesCount = sidesCount;
    }

public:
    Figure(int sidesCount) {
        this->figureName = "Фигура";
        this->sidesCount = sidesCount;
    }

    std::string getFigureName() {
        return figureName;
    }

    virtual std::string Info() {
        std::string temp{};
        temp = figureName + ":\n";
        if (RightFigure()) {
            temp += "Правильная\n";
        }
        else {
            temp += "Неправильная\n";
        }
        temp += "Количество сторон: " + std::to_string(sidesCount) + "\n\n";
        return temp;
    }

    virtual bool RightFigure() {
        if (sidesCount == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Triangle : public Figure {
protected:
    int a{}, b{}, c{}, A{}, B{}, C{};

public:
    Triangle(int a, int b, int c, int A, int B, int C, std::string name, int sidesCount) : Figure(name, sidesCount) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    Triangle(int a, int b, int c, int A, int B, int C) : Figure("Треугольник", 3) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    std::string Info() override {
        std::string temp{};
        temp = figureName + ":\n";
        if (RightFigure()) {
            temp += "Правильная\n";
        }
        else {
            temp += "Неправильная\n";
        }
        temp += "Количество сторон: " + std::to_string(sidesCount) + "\n";
        temp += "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + "\n"
            + "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + "\n\n";
        return temp;
    }

    bool RightFigure() override {
        if (sidesCount == 3 && A + B + C == 180) {
            return true;
        }
        else {
            return false;
        }
    }


};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C, "Прямоугольный треугольник", 3) {}

    bool RightFigure() override {
        if (C == 90) {
            if (Triangle::RightFigure()) {
                return true;
            }
            else return false;
        }
        else {
            return false;
        }
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C, "Равнобедренный треугольник", 3) {}

    bool RightFigure() override {
        if (a == c && A == C) {
            if (Triangle::RightFigure()) {
                return true;
            }
            else return false;
        }
        else {
            return false;
        }
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C, "Равносторонний треугольник", 3) {}

    bool RightFigure() override {
        if ((a == b && b == c) && (A == 60 && B == 60 && C == 60)) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Quadrangle : public Figure {
protected:
    int a{}, b{}, c{}, d{}, A{}, B{}, C{}, D{};
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure("Четырёхугольник", 4) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string name) : Figure(name, 4) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    std::string Info() override {
        std::string temp{};
        temp = figureName + ":\n";
        if (RightFigure()) {
            temp += "Правильная\n";
        }
        else {
            temp += "Неправильная\n";
        }
        temp += "Количество сторон: " + std::to_string(sidesCount) + "\n";
        temp += "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + " d=" + std::to_string(d) + "\n"
            + "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + " D=" + std::to_string(D) + "\n\n";
        return temp;
    }

    bool RightFigure() override {
        if (sidesCount == 4 && A + B + C + D == 360) {
            return true;
        }
        else {
            return false;
        }
    }

};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D, "Параллелограмм") {}
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D, std::string name) : Quadrangle(a, b, c, d, A, B, C, D, name) {}

    bool RightFigure() override {
        if ((a == c && b == d) && (A == C && B == D)) {
            if (Quadrangle::RightFigure()) {
                return true;
            }
            else return false;
        }
        else {
            return false;
        }
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Parallelogram(a, b, c, d, A, B, C, D, "Прямоугольник") {}
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string name) : Parallelogram(a, b, c, d, A, B, C, D, name) {}

    bool RightFigure() override {
        if (A == 90 && B == 90 && C == 90 && D == 90) {
            if (Parallelogram::RightFigure()) {
                return true;
            }
            else return false;
        }
        else {
            return false;
        }
    }
};

class Rhomb : public Parallelogram {
public:
    Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) : Parallelogram(a, b, c, d, A, B, C, D, "Ромб") {}

    bool RightFigure() override {
        if (a == b) {
            if (Parallelogram::RightFigure()) {
                return true;
            }
            else return false;
        }
        else {
            return false;
        }
    }
};

class Square : public Rectangle {
public:
    Square(int a, int b, int c, int d, int A, int B, int C, int D) : Rectangle(a, b, c, d, A, B, C, D, "Квадрат") {}

    bool RightFigure() override {
        if (a == b) {
            if (Rectangle::RightFigure()) {
                return true;
            }
            else return false;
        }
        else {
            return false;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Figure figureObj(0);
    getInfo(figureObj);

    Triangle triangleObj(10, 20, 30, 50, 60, 70);
    getInfo(triangleObj);

    RightTriangle right(10, 20, 30, 50, 60, 90);
    getInfo(right);

    RightTriangle right1(10, 20, 30, 70, 20, 90);
    getInfo(right1);

    IsoscelesTriangle isoscele(10, 20, 10, 40, 100, 40);
    getInfo(isoscele);

    EquilateralTriangle equilateral(50, 50, 50, 60, 60, 60);
    getInfo(equilateral);

    Quadrangle quadrangleObj(10, 20, 30, 40, 50, 60, 70, 80);
    getInfo(quadrangleObj);

    Parallelogram parallelogram(20, 30, 20, 30, 30, 40, 50, 80);
    getInfo(parallelogram);

    Rhomb rhomb(30, 30, 30, 30, 150, 30, 150, 30);
    getInfo(rhomb);

    Square square(10, 10, 10, 10, 90, 90, 90, 90);
    getInfo(square);

    Rectangle rectangle(10, 20, 10, 20, 90, 90, 90, 90);
    getInfo(rectangle);
}

void getInfo(Figure& info) {
    std::cout << info.Info();
}