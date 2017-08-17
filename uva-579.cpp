int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int h, m;
    double hD, mD, diff;

    while (scanf("%d:%d", &h, &m)) {
        if (!h && !m) {
            break;
        }

        hD = h * 30 + m * 0.5;
        mD = m * 6;

        diff = fabs(hD - mD);
        if (diff > 180.0) {
            diff = 360.0 - diff;
        }
        printf("%.3lf\n", diff);
    }
    return 0;
}
