#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <ctime>
#include <numeric>
#include "Circle.hpp"
#include "Ellipse.hpp"
#include "Helix.hpp"

int main()
{
    std::srand(std::time(0));

    // Колличество объектов
    constexpr size_t nCount = 10ULL;
    // Вектор со всеми объектами
    std::vector<std::unique_ptr<Curve>> vecCurves(nCount);

    // Заполние вектора объектами, созданными случайным образом, со случайными параметрами
    std::generate(
        vecCurves.begin(), vecCurves.end(),
        []() -> std::unique_ptr<Curve>
        {
            const int nR = rand() % 3;
            const double R = rand() % 100 * 0.5;
            const double R1 = rand() % 100 * 0.5;
            const double R2 = rand() % 100 * 0.5;
            const double H = rand() % 100 * 0.5;

            switch (nR)
            {
            case 0:
                return std::make_unique<Circle>(Circle(R));
            case 1:
                return std::make_unique<Ellipse>(Ellipse(R1, R2));
            case 2:
                return std::make_unique<Helix>(Helix(R, H));
            }

            return nullptr;
        });
    // ============================================================================================

    // Вывод информации о всех объектах при t = PI / 4.
    for (const std::unique_ptr<Curve> &itCurve : vecCurves)
        itCurve->printInfo(M_PI_4);
    // ============================================================================================

    // Заполнение второго вектора, содержутся указательи только на окружности из первого вектора
    std::vector<Circle *> vecCirclesPtr;
    std::for_each(
        vecCurves.begin(), vecCurves.end(),
        [&vecCirclesPtr](const std::unique_ptr<Curve> &it)
        {
            // Так как данный объект наследуется от окружности,
            // то необходимо добавить данную проверку, чтобы во второй вектор попали только окружности
            if (dynamic_cast<Helix *>(it.get()))
                return;

            Circle *ptr = dynamic_cast<Circle *>(it.get());
            if (ptr)
                vecCirclesPtr.push_back(ptr);
        });
    // ============================================================================================

    // Сортировка вектора с окружностями в порядке возрастания их радиусов
    std::sort(
        vecCirclesPtr.begin(), vecCirclesPtr.end(),
        [](Circle *p1, Circle *p2)
        {
            return (p1->getRadius() < p2->getRadius());
        });
    // ============================================================================================

    // Нахождение суммы радиусов всех окружностей из второго вектора
    const double sum = std::accumulate(
        vecCirclesPtr.begin(), vecCirclesPtr.end(), 0.0,
        [](const double &temp, Circle *ptr) -> double
        {
            return temp + ptr->getRadius();
        });
    std::cout << "Sum: " << sum << std::endl;
    // ============================================================================================

    return 0;
}