#include <cstdio>
using namespace std;

int n, q;
int bit[1000006];
int LOGN;

void add(int i, int v) { for (; i <= n; i += i & -i) bit[i] += v; }

int kth(int k) {
    int pos = 0;
    for (int pw = LOGN; pw >= 0; pw--) {
        int nxt = pos + (1 << pw);
        if (nxt <= n && bit[nxt] < k) { pos = nxt; k -= bit[nxt]; }
    }
    return pos + 1;
}

static char buf[1 << 16];
int bufLen = 0, bufPos = 0;
inline int getChar() {
    if (bufPos == bufLen) {
        bufLen = (int)fread(buf, 1, sizeof(buf), stdin);
        bufPos = 0;
        if (bufLen == 0) return -1;
    }
    return buf[bufPos++];
}
inline int readInt() {
    int c = getChar();
    while (c != '-' && (c < '0' || c > '9')) {
        if (c == -1) return 0;
        c = getChar();
    }
    bool neg = false;
    if (c == '-') { neg = true; c = getChar(); }
    int x = 0;
    while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = getChar(); }
    return neg ? -x : x;
}

int main() {
    n = readInt();
    q = readInt();
    LOGN = 0;
    while ((1 << (LOGN + 1)) <= n) LOGN++;

    for (int i = 0; i < n; i++) {
        int a = readInt();
        add(a, 1);
    }
    for (int i = 0; i < q; i++) {
        int k = readInt();
        if (k > 0) add(k, 1);
        else {
            int pos = kth(-k);
            add(pos, -1);
        }
    }

    long long total = 0;
    for (int i = n; i > 0; i -= i & -i) total += bit[i];
    if (total == 0) printf("0\n");
    else printf("%d\n", kth(1));
    return 0;
}
