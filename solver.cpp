/**
    \brief ��������� ������ ���������� ��������

    ��������� ������ ���������� ��������� � ����� ������.

*/
#include "TXLib.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

struct test_data
{               /**��������� ��� ���� ������������ � �������������� � ����������� �������� (����� ������������ ���� ������)*/
    float a;
    float b;
    float c;
    double x1;
    double x2;
    int nroots;
};
    /**���������� ������ � ������ ���������� ���������
    */
enum nroots
{
    no_roots = 0,  //<��� ������
    one_root,      //<���� ������
    two_roots,     //<��� �����
    infinite_roots //<����������� ���������� ������
};

struct consoleflags
{
    bool test;
    bool file;
    const char *name;
};

#define MAGENTA(arg) ({txSetConsoleAttr(FOREGROUND_LIGHTMAGENTA); arg; txSetConsoleAttr(FOREGROUND_LIGHTMAGENTA);}); //<����������� ������ � ������� ����
#define RED(arg) ({txSetConsoleAttr(FOREGROUND_RED); arg; txSetConsoleAttr(FOREGROUND_RED);});                       //<����������� ������ � ������� ����
#define BLUE(arg) ({txSetConsoleAttr(FOREGROUND_BLUE); arg; txSetConsoleAttr(FOREGROUND_BLUE);});                    //<����������� ������ � ������� ����
#define GREEN(arg) ({txSetConsoleAttr(FOREGROUND_GREEN); arg; txSetConsoleAttr(FOREGROUND_GREEN);});                 //<����������� ������ � ������� ����

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
/**\brief ����� �������� �������

    �������, ������� ������, ��� ����� ������ ��������� ��������� ��� ���������� ��� ��� �������� (� ����������� �� �������� �)
    \param[in] a ����������� �
    \param[in] b ����������� �
    \param[in] c ����������� �
    \param[out] px ��������� �� ������ ������ � ���������
    \param[out] py ��������� �� ������ ������ � ���������
    \return ���������� ������ ���������
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

/**\brief ������� ����������� ���������

    �������, ������� ������ ������ ���������� ���������
    \param[in] a ����������� �
    \param[in] b ����������� �
    \param[in] c ����������� �
    \param[out] px ��������� �� ������ ������ � ���������
    \param[out] py ��������� �� ������ ������ � ���������
    \return ���������� ������ ���������
*/
int quadsolver(float a, float b, float c, double *px,double *py)
{
    assert(px != NULL);
    assert(py != NULL);
    float d = 0;  //< ������������
    d = b*b - 4.0f*(a*c);
    if (d < 0)
    {
       return no_roots;
    }
    else if ( d > 0)
    {
        *px = ((-b - sqrt(d))/2.0f)/a;  //<������� ������
        *py = ((-b + sqrt(d))/2.0f)/a;  //< ������� ������

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


/**\brief ������� ��������� ���������

    �������, ������� ������ ������ �������� ���������
    \param[in] a ����������� �
    \param[in] b ����������� �
    \param[in] c ����������� �
    \param[out] px ��������� �� ������ � ���������
    \return ���������� ������ ���������
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

/**\brief ���� ����� � ����������

    �������, ������� ��������� �������� ���������� �, b � c c ����������
    \param[out] pa ��������� �� ����������� a � ���������
    \param[out] pb ��������� �� ����������� b � ���������
    \param[out] pc ��������� �� ����������� c � ���������
    \return ������
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
    /** ���� ���� �� ��������� �������� �� ������������� �������, �� �� ������ ����� ������ ������������*/
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
/**\brief ����� ������� �� ����

    �������, ������� ������� �������� ������������ ������ �� �����
    \param[in] n_roots ���������� ������ � ���������
    \param[in] x ������
    \param[in] y ������ ������ (��� �������)
    \return ������
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

/**\brief ��������� ������

    �������, ������� ���������� ����� ����� �����, ������ ��� ������������ ����� �����������
    \param sol ������ �������� �����
    \param ans ������ �������� �����
    \return ������, ���� ����� �� �����, � 1, ���� ��� �����
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
/**\brief ������������

    �������, ������� ��������� ������������ ������� ��������� ��� ��������� ��������
    \param[in] test_data ��������� �� ����� �������������� � ���������� ���������
    \return ������, ���� ���� ������ ��������, � 1, ���� �� ������
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
/**\brief �������� ������

    �������, ������� ��������� ����� � ������������ ���������� ������������ �������
    \return ������, ���� ���� ������ ��������, � 1, ���� �� ������
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
/**\brief ���� ����� �� �����

    �������, ������� ��������� �������� ���������� �, b � c �� �����
    \param[in] file ��������� �� ����, �� �������� ���������� ��������
    \param[out] pa ��������� �� ����� � � ���������
    \param[out] pb ��������� �� ����� � � ���������
    \param[out] pc ��������� �� ����� � � ���������
    \return ������
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
    /** \brief �������� ������ � �������

        *���� ���������� ����� "--test", �� ���������� ���� ������������,
        *� ���� "--file name_of_file", �� ��������� �������� �� ���� �����, ��� �������� ������� � �������*/
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
