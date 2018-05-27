package com.czf;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    private static Scanner in = new Scanner(System.in);
    static int N = 110000;
    static int K = 26;
    static BigInteger f[][] = new BigInteger[2][26];
    static int a[] = new int[N];
    static int w[] = new int[N];
    public static void main(String[] args) {
        int T; T = in.nextInt();
        while (T-- != 0) {
            int n; n = in.nextInt();
            for (int i = 1; i <= n; i ++) {
                a[i] = in.nextInt();
                w[a[i]] = i;
            }
            w[n+1] = 0;
            int now = 0;
            for (int k = 0; k < K; k ++) {
                f[now][k] = BigInteger.ONE;
            }
            for (int i = 2; i <= n; i ++) {
                int pre = now;
                now = 1 - now;
                for (int k = 0; k < K; k ++) {
                    f[now][k] = BigInteger.ZERO;
                }
                if (w[a[i]+1] > w[a[i-1]+1]) {
                    for (int k = 0; k < K; k ++) {
                        f[now][k] = f[now][k].add(f[pre][k]);
                    }
                } else {
                    for (int k = 1; k < K; k ++) f[now][k] = f[now][k].add(f[pre][k-1]);
                }
                for (int k = 1; k < K; k ++) {
                    f[now][k] = f[now][k].add(f[now][k-1]);
                }
            }
            BigInteger res = BigInteger.ZERO;
            for (int i = 0; i < K; i ++) {
                res = res.add(f[now][i]);
            }
            System.out.println(res);
        }


    }
}