int isprime(int n) {
    // returns 1 if prime 0 else
    int i;
    if (n == 1 || n == 0) return 0; 
    for (i=2; i<=n/2; i++) {
        if (n%i!=0) continue;
        else return 0;
    } return 1;
}