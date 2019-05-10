#ifndef TEXTFUN_HEADER
#define TEXTFUN_HEADER

typedef struct listEle *listP;

typedef struct listEle {
    char *swort;
    char *ewort;
    listP next;
}ListEle;

struct Fundstelle {
    char *stelleImSuchstring;
    listP ersetzung;
};

extern listP wordlist;

static void addPair(const char *such, const char *ersatz);

void clearList(void);

struct Fundstelle find(const char *s);

int replaceAll(char *s);

#endif
