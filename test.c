#include <stdio.h>
#include <stdlib.h>

int triangle(float a, float b, float c);

float randf()
{
    return (float)rand()/(float)(RAND_MAX) * 1.0;
}

struct triangle
{
    float a;
    float b;
    float c;
};

struct triangle make_345(float i)
{
    return (struct triangle){i * 3., i * 4., i * 5.};
}

struct tri_test
{
    int expected;
    float a;
    float b;
    float c;
};

struct tri_test tests[] = {
    {1, 0.1, 0.1, 0.1},
    {2, 0.5, 0.5, 0.1},
    {3, 0.3, 0.4, 0.5},
    {4, 13., 9., 14.},
    {-1, .7, .1, .1},
};

int main()
{
    // verify an example of each type of triangle
    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
    {
        printf(
            "%d %d: %g %g %g\n",
            tests[i].expected,
            triangle(tests[i].a, tests[i].b, tests[i].c),
            tests[i].a,
            tests[i].b,
            tests[i].c);
    }

    for (int i = 0; i < 1000; ++i)
    {
        struct triangle t = make_345(randf());
        if (3 != triangle(t.a, t.b, t.c))
        {
            printf("345 failure: %g %g %g\n", t.a, t.b, t.c);
        }
    }

    // attempt to randomly find a case of each triangle
    // doesn't work - too slow, triangles are rare
    int cases[] = {-1, 1, 2, 3, 4};
    for (size_t i = 0; i < 5; ++i)
    {
        int res;
        float a;
        float b;
        float c;
        do
        {
            a = randf();
            b = randf();
            c = randf();
            res = triangle(a,b,c);
            // fprintf(stderr, "%d: %g %g %g\n", res, a, b, c);
        } while (res != cases[i]);

        printf("%d: %g %g %g\n", cases[i], a, b, c);
    }
    return 0;
}
