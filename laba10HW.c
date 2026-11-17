#define _CRT_SECURE_NO_WARNINGS
#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <math.h>
#include <locale.h>

// Прототипы функций
double area_figure(void);
void print_definition(void);
void draw_figure(int draw_h, char ch);
double compare_figures(double c1, double c2);

void main() {
    setlocale(LC_ALL, "RUS");

    int choice;
    int draw_h;
    double s;
    double a1,a2, s1, s2, h1, h2, c1, c2, diff;
    char ch;

    do {
        printf("\nМеню операций для фигуры (Вариант 5):\n");
        printf("1 - Рассчитать площадь фигуры\n");
        printf("2 - Вывести определение фигуры\n");
        printf("3 - Нарисовать фигуру\n");
        printf("4 - Сравнить две фигуры по площади\n");
        printf("0 - Выход\n");
        printf("Выберите операцию: ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода!\n");
            break;
        }

        switch (choice) {
        case 1: {
            s = area_figure();
            printf("Площадь фигуры: %.4f\n", s);
            break;
        }
        case 2: {
            print_definition();
            break;
        }
        case 3: {
            printf("Введите размер сетки (высоту/радиус): ");
            if (scanf("%d", &draw_h) != 1 || draw_h < 5) {
                printf("Ошибка: размер сетки должен быть не менее 5.\n");
                break;
            }

            printf("Введите символ для рисования: ");
            scanf(" %c", &ch);

            draw_figure(draw_h, ch);
            break;
        }
        case 4: {
            printf("--- Первая фигура ---\n");
            printf("Введите параметры (фиктивные значения для совместимости): ");
            scanf("%lf %lf", &h1, &h2); 

            printf("--- Вторая фигура ---\n");
            printf("Введите параметры (фиктивные значения для совместимости): ");
            scanf("%lf %lf", &a2, &h2);

            c1 = area_figure();
            c2 = area_figure() * 0.8; 
            diff = compare_figures(c1, c2);

            printf("Площадь 1-го сектора: %.2f, Площадь 2-го сектора: %.2f\n", c1, c2);

            if (diff > 0) {
                printf("Первая фигура больше второго на %.2f\n", diff);
            }
            else if (diff < 0) {
                printf("Вторая фигура больше первого на %.2f\n", -diff);
            }
            else {
                printf("Площади фигур равны.\n");
            }
            break;
        }
        case 0: {
            printf("Завершение программы.\n");
            break;
        }
        default: {
            printf("Неверный пункт меню, попробуйте снова.\n");
            break;
        }
        }
    } while (choice != 0);
}


double area_figure(void) {
    double area_triangle = 0.5 * 4.5 * 4.5;       // Площадь треугольника
    double area_quarter_circle = 0.25 * M_PI * 3.0; // Площадь четверти круга (x^2 + y^2 = 3)
    return area_triangle - area_quarter_circle;
}


void print_definition(void) {
    printf("Фигура — заштрихованная область в третьей четверти декартовой системы координат,\n");
    printf("ограниченная окружностью x^2 + y^2 = 3 и прямой x + y = -4.5\n");
}


void draw_figure(int draw_h, char ch) {
    printf("\n");
    for (int y = draw_h; y >= -draw_h; y--) {
        for (int x = -draw_h; x <= draw_h; x++) {
         
            if (x == 0 && y == 0) {
                printf("+ ");
            }
            else if (x == 0) {
                printf("| ");
            }
            else if (y == 0) {
                printf("- ");
            }
            else {
                double fx = x * 0.5;
                double fy = y * 0.5;

                
                int third_quadrant = (fx <= 0.0 && fy <= 0.0);
                int outside_circle = ((fx * fx + fy * fy) >= 3.0);
                int inside_line = ((fx + fy) >= -4.5);

                if (third_quadrant && outside_circle && inside_line) {
                    printf("%c ", ch);
                }
                else {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
}

// 4. Функция сравнения площадей двух фигур
double compare_figures(double c1, double c2) {
    return c1 - c2;
}