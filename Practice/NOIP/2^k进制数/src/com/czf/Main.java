package com.czf;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    private static final int MAXN = 512 + 10;

    public static void main(String[] args) {
        int k, n; Scanner in = new Scanner(System.in);
        k = in.nextInt(); n = in.nextInt();

        BigInteger c[][] = new BigInteger[MAXN][MAXN];

        int m_max = 1 << k, h_max = 1 << (n % k);
        for (int i = 0; i < m_max; i ++) {
            for (int j = 0; j < m_max; j ++) {
                if (j > i) c[i][j] = new BigInteger("0");
                else if (i == 0 || j == 0) c[i][j] = new BigInteger("1");
                else c[i][j] = c[i-1][j].add(c[i-1][j-1]);
//                System.out.printf("c[%d][%d] = ",i, j);
//                System.out.println(c[i][j]);
            }
        }

        BigInteger res = new BigInteger("0");

        for (int i = 2; i <= n/k && i < m_max; i ++) res = res.add(c[m_max-1][i]);
        for (int i = 1; i < h_max && m_max-1-i >= n / k; i ++) res = res.add(c[m_max-1-i][n/k]);

        System.out.println(res);
    }
}
