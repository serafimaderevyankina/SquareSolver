/**
    \brief программа решает квадратные уравненя

    программа решает квадратные уравнения в целых числах.

*/
#include "TXLib.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

struct test_data
{               /**структура для юнит тестирования с коэффициентами и правильными ответами (чтобы копипастинга было меньше)*/
    float a;
    float b;
    float c;
    double x1;
    double x2;
    int nroots;
};
    /**количество корней в данном квадратном уравнении
    */
enum nroots
{
    no_roots = 0,  //<нет корней
    one_root,      //<один корень
    two_roots,     //<два корня
    infinite_roots //<бесконечное количество корней
};

struct consoleflags
{
    bool test;
    bool file;
    const char *name;
};

#define MAGENTA(arg) ({txSetConsoleAttr(FOREGROUND_LIGHTMAGENTA); arg; txSetConsoleAttr(FOREGROUND_LIGHTMAGENTA);}); //<окрашивание текста в розовый цвет
#define RED(arg) ({txSetConsoleAttr(FOREGROUND_RED); arg; txSetConsoleAttr(FOREGROUND_RED);});                       //<окрашивание текста в красный цвет
#define BLUE(arg) ({txSetConsoleAttr(FOREGROUND_BLUE); arg; txSetConsoleAttr(FOREGROUND_BLUE);});                    //<окрашивание текста в голубой цвет
#define GREEN(arg) ({txSetConsoleAttr(FOREGROUND_GREEN); arg; txSetConsoleAttr(FOREGROUND_GREEN);});                 //<окрашивание текста в зеленый цвет

int quadsolver( float, float, float, double *, double *);
int linesolver(float, float, double *);
int input(float *, float *, float *);
int output(int, double , double );
int SolveEquation(float a, float b, float c, double* px, double* py);
int comparisondouble(double sol, double ans);
int onetest(test_data);
int runtest();
int file_input(FILE *, float* , float* , float* );
int console(int ,char **, consoleflags *);
int distributionflags(consoleflags, float *, float *, float *);

int main(int argc, char *argv[])
{
    consoleflags cons;
    double x = 0;
    double y = 0;
    float a = 0, b = 0, c =0;
    float *pa = &a;
    float *pb = &b;
    float *pc = &c;
    console(argc, argv, &cons);

    distributionflags(cons, pa, pb, pc);

    int n_roots = SolveEquation(a, b, c, &x, &y);
    output(n_roots, x, y);

    return 0;
}
/**\brief выбор варианта решения

    функция, которая решает, она будет решать введенное уравнение как квадратное или как линейное (в зависимости от значения а)
    \param[in] a коэффициент а
    \param[in] b коэффициент а
    \param[in] c коэффициент а
    \param[out] px указатель на первый корень в уравнении
    \param[out] py указатель на второй корень в уравнении
    \return количество корней уравнения
*/
int SolveEquation(float a, float b, float c, double* px, double* py)
{
    assert(px != NULL);
    assert(py != NULL);

        int n = 0;
        if (fabs(a) < 1E-6 ) {
            n = linesolver(b, c, px);
        }
        else {
            n = quadsolver(a, b, c, px, py);
        }
        return n;
}

/**\brief решение квадратного уравнения

    функция, которая просто решает квадратное уравнение
    \param[in] a коэффициент а
    \param[in] b коэффициент а
    \param[in] c коэффициент а
    \param[out] px указатель на первый корень в уравнении
    \param[out] py указатель на второй корень в уравнении
    \return количество корней уравнения
*/
int quadsolver(float a, float b, float c, double *px,double *py)
{
    assert(px != NULL);
    assert(py != NULL);
    float d = 0;  //< дискриминант
    d = b*b - 4.0f*(a*c);
    if (d < 0)
    {
       return no_roots;
    }
    else if ( d > 0)
    {
        *px = ((-b - sqrt(d))/2.0f)/a;  //<решение первое
        *py = ((-b + sqrt(d))/2.0f)/a;  //< решение второе

        return two_roots;

    }
    else if (fabs(d) < 1E-6)
    {
        *px  = -b/ (2.0f*a);

        return one_root;
    }
    else
    {
        return infinite_roots;
    }
}


/**\brief решение линейного уравнения

    функция, которая просто решает линейное уравнение
    \param[in] a коэффициент а
    \param[in] b коэффициент а
    \param[in] c коэффициент а
    \param[out] px указатель на корень в уравнении
    \return количество корней уравнения
*/
int linesolver(float b, float c, double *px)
{   assert(px != NULL);
    if (fabs(b) < 1E-6)
    {
        if (fabs(c) < 1E-6)
        {
            return infinite_roots;
        }
        else
        {
            return no_roots;
        }
    }
    else
    {
        *px = -c/b;
        return one_root;
    }
}

/**\brief ввод чисел с клавиатуры

    функция, которая принимает значения параметров а, b и c c клавиатуры
    \param[out] pa указатель на коэффициент a в уравнении
    \param[out] pb указатель на коэффициент b в уравнении
    \param[out] pc указатель на коэффициент c в уравнении
    \return ничего
*/
int input(float *pa, float *pb, float *pc)
{
    assert(pa != NULL);
    assert(pb != NULL);
    assert(pc != NULL);
    float a = 0, b = 0, c = 0;
    int sca = 0, scb = 0, scc = 0;
    sca = GREEN(scanf("%f", &a));
    scb = GREEN(scanf("%f", &b));
    scc = GREEN(scanf("%f", &c));
    /** если одно из введенных значений не соответствует формату, то мы просим снова ввести коэффициенты*/
    while (sca == 0 || scb == 0 || scc == 0)
    {
        while ( getchar() != '\n' );
        printf("Invalid input");
        sca = GREEN(scanf("%f", &a));
        scb = GREEN(scanf("%f", &b));
        scc = GREEN(scanf("%f", &c));
    }

    *pa = a;
    *pb = b;
    *pc = c;

    return 0;
}
/**\brief вывод решений на экан

    функция, которая выводит значения получившихся корней на экран
    \param[in] n_roots количество корней в уравнении
    \param[in] x корень
    \param[in] y второй корень (при наличии)
    \return ничего
*/
int output(int n_roots,double x, double y)
{
    switch((nroots)n_roots)
    {
        case infinite_roots: BLUE(printf("an infinite number of roots"));
                             break;

        case two_roots: BLUE(printf("the roots is: %g,%g", x, y));
                        break;

        case one_root: BLUE(printf("the root is %g", x));
                       break;

        case no_roots: BLUE(printf("I've got no roots"));
                       break;
        default:
                       break;
    }

    return 0;
}

/**\brief сравнение даблов

    функция, которая сравнивает даблы между собой, потому что приравнивать даблы некорректно
    \param sol первое значение дабла
    \param ans второе значение дабла
    \return ничего, если даблы не равны, и 1, если они равны
*/
int comparisondouble(double sol, double ans)
{
    if (fabs(sol - ans) < 1e-16)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/**\brief тестирование

    функция, которая проверяет правильность решения уравнения при различных решениях
    \param[in] test_data структура со всеми коэффициентами и эталонными решениями
    \return ничего, если тест прошел проверку, и 1, если не прошел
*/
int onetest(test_data test)
{
    double x1 = 0, x2 = 0;
    int nroots = SolveEquation(test.a, test.b, test.c, &x1, &x2);
    if (!(comparisondouble(x1, test.x1) == 1 && comparisondouble(x2, test.x2) == 1 && nroots == test.nroots))
    {
        printf("a = %f, b = %f, c = %f, x1 = %f, x2 = %f, refx1 = %f, refx2 = %f\n", test.a, test.b, test.c, x1, x2, test.x1, test.x2);
        return 1;
    }
    else
    {
        return 0;
    }
}
/**\brief проверка тестов

    функция, которая прогоняет тесты и подсчитывает количество неправильных решений
    \return ничего, если тест прошел проверку, и 1, если не прошел
*/
int runtest()
{
    int failed = 0;
    test_data tests[] = {
        {.a = 2, .b =  5, .c =  3, .x1 = -1.5, .x2 = -1, .nroots = 2},
        {.a = 1, .b =  2, .c =  1, .x1 =   -1, .x2 =  0, .nroots = 1},
        {.a = 2, .b =  5, .c =  3, .x1 = -1.5, .x2 = -1, .nroots = 2},
        {.a = 0, .b =  0, .c =  0, .x1 =    0, .x2 =  0, .nroots = 3},
        {.a = 0, .b =  0, .c =  3, .x1 =    0, .x2 =  0, .nroots = 0},
        {.a = 0, .b =  2, .c =  1, .x1 = -0.5, .x2 =  0, .nroots = 1},
        {.a = 1, .b = -5, .c =  6, .x1 =    2, .x2 =  3, .nroots = 2}
    };
    const size_t len = sizeof(tests)/sizeof(test_data);
    for (size_t i = 0; i < len; i++)
    {
        failed += onetest(tests[i]);
    }
    return failed;
}
/**\brief ввод чисел из файла

    функция, которая принимает значения параметров а, b и c из файла
    \param[in] file указатель на файл, из которого вынимаются значения
    \param[out] pa указатель на коэфф а в уравнении
    \param[out] pb указатель на коэфф а в уравнении
    \param[out] pc указатель на коэфф а в уравнении
    \return ничего
*/
int file_input(FILE *file, float *pa, float *pb, float *pc)
{
    assert(pa != NULL);
    assert(pb != NULL);
    assert(pc != NULL);
    float a = 0, b = 0, c = 0;
    int sca = 0, scb = 0, scc = 0;
    sca = GREEN(fscanf(file, "%f", &a));
    scb = GREEN(fscanf(file, "%f", &b));
    scc = GREEN(fscanf(file, "%f", &c));
    if (sca==0 || scb == 0 || scc == 0)
    {
      printf("empty file");
    }
    *pa = a;
    *pb = b;
    *pc = c;
    return 0;
}
    /** \brief проверка флагов с консоли

        *если напечатано слово "--test", то проводится юнит тестирование,
        *а если "--file name_of_file", то принимает значение из того файла, имя которого указано в консоли*/
int console(int argc, char *argv[], consoleflags *cons)
{
    if (argc >= 2)
    {
        for(int i = 1; i < argc; i ++)
        {
            if (strcmp(argv[i], "--test") == 0)
            {
                (*cons).test = true;
            }
            if (strcmp(argv[i], "--file") == 0)
            {
                (*cons).file = true;
                (*cons).name = argv[i + 1];
            }
        }
    }

    return 0;
}

int distributionflags( consoleflags cons, float *pa, float *pb, float *pc)
{
    assert(pa != NULL);
    assert(pb != NULL);
    assert(pc != NULL);
    if (cons.test == true)
    {
        int if_tests_passed = runtest();
        if (if_tests_passed  != 0)
        {
            RED(printf("tests failed"));

            return 0;
        }
        else if (if_tests_passed  == 0)
        {
            RED(printf("tests passed\n"));
        }
    }
    if (cons.file == true)
    {
        FILE *file = fopen(cons.name, "r");
        file_input(file, pa, pb, pc);
    }
    else
    {
        printf("enter the coefficients of the quadratic equation\n");
        input(pa, pb, pc);
    }
    return 0;
}
