float f()
{

    float x[7] = {1.0f, 2.0f, 3.f, 4.0f, 5.0f, 6.0f, 7.0f};

    float *p = &x[0];

    p = p + 1;

    return *p;
}