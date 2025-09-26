void __swap(int *a, int *b)
{
    int buf = *a;
    *a = *b;
    *b = buf;
}