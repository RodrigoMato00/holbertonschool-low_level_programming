#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static volatile unsigned int g_state = 0xA5A5F00Du;

static unsigned int rotl32(unsigned int x, unsigned int r)
{
    r &= 31u;
    return (x << r) | (x >> (32u - r));
}

static unsigned int mix32(unsigned int x)
{
    x ^= rotl32(x, 7);
    x += 0x9E3779B9u;
    x ^= (x >> 16);
    x *= 0x85EBCA6Bu;
    x ^= (x >> 13);
    x *= 0xC2B2AE35u;
    x ^= (x >> 16);
    return x;
}

static void decode_tag(char *out, size_t out_sz)
{
    static const unsigned char enc[] = {
        0x3C, 0x22, 0x2F, 0x2E, 0x38, 0x29, 0x2A, 0x23,
        0x3A, 0x2C, 0x2C, 0x3D, 0x00
    };
    unsigned int k = 0x6D2B79F5u ^ (unsigned int)(sizeof(enc) * 17u);

    size_t i = 0;
    if (out_sz == 0)
        return;

    while (enc[i] != 0x00 && i + 1 < out_sz) {
        unsigned char b = enc[i];
        b ^= (unsigned char)((k >> ((i % 4u) * 8u)) & 0xFFu);
        b ^= (unsigned char)(0x11u + (unsigned char)(i * 3u));
        out[i] = (char)b;
        i++;
    }
    out[i] = '\0';
}

static unsigned int parse_u32(const char *s, int *ok)
{
    char *end = NULL;
    unsigned long v;

    *ok = 0;
    if (s == NULL || *s == '\0')
        return 0;

    v = strtoul(s, &end, 10);
    if (end == s || *end != '\0')
        return 0;

    *ok = 1;
    return (unsigned int)v;
}

static unsigned int derive_key(unsigned int user_pin)
{
    char tag[32];
    unsigned int x;

    decode_tag(tag, sizeof(tag));

    x = 0x13579BDFu;
    {
        size_t i;
        for (i = 0; tag[i] != '\0'; i++) {
            unsigned int b = (unsigned int)(unsigned char)tag[i];
            x ^= rotl32(b + (unsigned int)i, (unsigned int)(i % 17u));
            x = mix32(x);
        }
    }

    x ^= mix32(user_pin ^ 0x2468ACE0u);
    x ^= mix32((unsigned int)g_state);

    g_state = (volatile unsigned int)mix32(x ^ 0xDEADC0DEu);

    return x;
}

static unsigned int compute_target(unsigned int k)
{
    static const unsigned int tbl[8] = {
        0x1B873593u, 0x85EBCA6Bu, 0xC2B2AE35u, 0x27D4EB2Fu,
        0x165667B1u, 0xD3A2646Cu, 0x9E3779B9u, 0x94D049BBu
    };

    unsigned int acc = 0x31415926u;
    unsigned int i;

    for (i = 0; i < 8u; i++) {
        unsigned int t = tbl[i] ^ rotl32(k, (unsigned int)(i + 3u));
        acc ^= mix32(t + (i * 0x1234u));
        acc = rotl32(acc, (unsigned int)((acc ^ t) & 15u));
        acc += 0x7F4A7C15u;
    }

    acc ^= mix32((unsigned int)g_state);
    return acc;
}

static int validate(unsigned int user_pin)
{
    unsigned int k = derive_key(user_pin);
    unsigned int tgt = compute_target(k);

    if ((tgt & 1u) == 0u) {
        tgt ^= rotl32(k, 11);
    } else {
        tgt += (k ^ 0x00C0FFEEu);
    }

    {
        unsigned int mask = mix32(k ^ 0x0BADF00Du) & 0x0000FFFFu;
        unsigned int sig  = (tgt ^ mix32(tgt + 0xABCDEF01u)) & 0x0000FFFFu;

        return (sig == mask);
    }
}

int main(void)
{
    char buf[128];
    int ok;
    unsigned int pin;

    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        puts("NO");
        return 1;
    }

    {
        size_t n = strlen(buf);
        if (n > 0 && buf[n - 1] == '\n')
            buf[n - 1] = '\0';
    }

    pin = parse_u32(buf, &ok);
    if (!ok) {
        puts("NO");
        return 1;
    }

    if (validate(pin)) {
        puts("OK");
        return 0;
    }

    puts("NO");
    return 1;
}
