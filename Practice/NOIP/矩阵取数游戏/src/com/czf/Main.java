package com.czf;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    private static final int MAXN = 100;
    private static BigInteger[] a;
    private static BigInteger[][] dp;
    private static int n;
    private static int m;
    private static Scanner in = new Scanner(System.in);
    public static void init() {
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < m; j ++) {
                dp[i][j] = new BigInteger("0");
            }
        }
    }

    public static void main(String[] args) {
        n = in.nextInt(); m = in.nextInt();
        a = new BigInteger[MAXN];
        dp = new BigInteger[MAXN][MAXN];
        init();
        BigInteger res = new BigInteger("0");
        for (int cnt = 0; cnt < n; cnt ++) {
            init();
            for (int pos = 0; pos < m; pos ++) {
                a[pos] = in.nextBigInteger();
                dp[pos][pos] = a[pos].multiply(new BigInteger("2"));
            }

            for (int d = 1; d < m; d ++) {
                for (int i = 0; i + d < m; i ++) {
                    BigInteger temp;
                    temp = dp[i+1][i+d].multiply(new BigInteger("2")).add(a[i].multiply(new BigInteger("2")
                    ));
                    if (temp.compareTo(dp[i][i+d]) == 1) {
                        dp[i][i+d] = temp;
                    }
                    temp = dp[i][i+d-1].multiply(new BigInteger("2")).add(a[i+d].multiply(new BigInteger("2")));
                    if (temp.compareTo(dp[i][i+d]) == 1) {
                        dp[i][i+d] = temp;
                    }
                }
            }
            res = res.add(dp[0][m-1]);
        }
        System.out.println(res);
    }
}
