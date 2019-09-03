static int triangle_equality(float a, float b, float c)
{
    return a * a + b * b == c * c;
}

static int triangle_inequality(float a, float b, float c)
{
    return
        a * a + b * b >= c * c
        && b * b + c * c >= a * a
        && c * c + a * a >= b * b;
}

int triangle(float a, float b, float c)
{
    // equilateral
    if (a == b && b == c)
    {
        return 1;
    }

    // iso
    if ((a == b || b == c || c == a)
        && triangle_inequality(a,b,c)
    )
    {
        return 2;
    }

    // right
    if (
        triangle_equality(a, b, c)
        || triangle_equality(b, c, a)
        || triangle_equality(c, a, b)
    )
    {
        return 3;
    }

    // scalene
    if (triangle_inequality(a,b,c))
    {
        return 4;
    }

    // not a triangle
    return -1;
}
