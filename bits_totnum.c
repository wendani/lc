int hammingWeight(uint32_t n) {

    int i;
    int num = 0;

    for (i = 0; i < 32; i++) {
        if (n & 1)
            num++;

        n >>= 1;
    }

    return num;
}
