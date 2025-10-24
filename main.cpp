#include "array.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "rhomb.h"
#include <iostream>

int main() {
    Array figures;
    int choice;

    while (true) {
        std::cout << "\nВыберите действие:\n"
                  << "1. Добавить прямоугольник\n"
                  << "2. Добавить ромб\n"
                  << "3. Добавить трапецию\n"
                  << "4. Вывод всех фигур\n"
                  << "5. Вывод общей площади фигур\n"
                  << "6. Удалить фигуру по индексу\n"
                  << "0. Выход\n"
                  << "Ваш выбор: ";
        
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Rectangle* rect = new Rectangle();
                std::cout << "Введите параметры прямоугольника (x y левая нижняя вершина и w h ширина высота): ";
                std::cin >> *rect;
                figures.add(rect);
                std::cout << "Прямоугольник добавлен.\n";
                break;
            }
            case 2: {
                Rhomb* rhomb = new Rhomb();  
                std::cout << "Введите параметры ромба (x y левая нижняя вершина и d1 d2 диагональ1 диагональ2): ";
                std::cin >> *rhomb;
                figures.add(rhomb);
                std::cout << "Ромб добавлен.\n";
                break;
            }
            case 3: {
                Trapezoid* trap = new Trapezoid();
                std::cout << "Введите параметры трапеции (x y левая нижняя вершина a b основания и h высота): ";
                std::cin >> *trap;
                figures.add(trap);
                std::cout << "Трапеция добавлена.\n";
                break;
            }
            case 4: {
                if (figures.size() == 0) {
                    std::cout << "Нет фигур.\n";
                } else {
                    std::cout << "\nВсе фигуры:\n";
                    figures.printAllCentersAndAreas();
                }
                break;
            }
            case 5: {
                std::cout << "Общая площадь всех фигур: " << figures.totalArea() << "\n";
                break;
            }
            case 6: {
                if (figures.size() == 0) {
                    std::cout << "Массив пуст.\n";
                    break;
                }
                std::cout << "Введите индекс фигуры для удаления (0–" 
                          << figures.size() - 1 << "): ";
                size_t idx;
                std::cin >> idx;
                figures.remove(idx);
                std::cout << "Фигура удалена.\n";
                break;
            }
            case 0: {
                std::cout << "Выход из программы.\n";
                return 0;
            }
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}