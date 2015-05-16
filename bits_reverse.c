uint32_t reverseBits(uint32_t n) {

    int i;
    uint32_t res;

    for (i = 0; i < 32; i++) {
        res <<= 1;

        if (n & 1)
            res |= 1;

        n >>= 1;
    }

    return res;
}
