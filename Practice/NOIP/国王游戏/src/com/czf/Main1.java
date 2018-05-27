import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

//class P implements Comparable <P> {
//    public BigInteger a, b;
//
//    @Override
//    public int compareTo(P o) {
//        return a.multiply(b).compareTo(o.a.multiply(o.b));
//    }
//}

//public class Main1 {
//    private static Scanner in = new Scanner(System.in);
//
//    public static BigInteger solve(BigInteger n) {
//        BigInteger ba = new BigInteger("8");
//        BigInteger wu = new BigInteger("5");
//        return n.multiply(n).add(n.multiply(wu)).add(ba);
//    }
//
//    public static void main(String[] args) {
//        int T; T = in.nextInt();
//        while (T-- != 0) {
//            BigInteger x = in.nextBigInteger();
//            BigInteger l = BigInteger.ONE;
//            BigInteger r = x;
//            BigInteger er = new BigInteger("2");
//            BigInteger mid = BigInteger.ZERO;
//            while (l.compareTo(r) == -1) {
//                mid = (l.add(r)).multiply(er);
//                if (solve(mid).compareTo(x) == -1) { //n小了
//                    l = mid.add(BigInteger.ONE);
//                } else  { //n*n + 5n + 8 >= x
//                    r = mid;
//                }
//            }
//            System.out.println(mid);
//        }
//    }
//}


//    private static P king = new P();
//    private static P[] a = new P[1111];
//    private static Scanner in = new Scanner(System.in);
//    public static void main(String[] args) {
//        int n; n = in.nextInt();
//        king.a = in.nextBigInteger();
//        king.b = in.nextBigInteger();
//        for (int i = 0; i < n; i ++) {
//            a[i] = new P();
//            a[i].a = in.nextBigInteger();
//            a[i].b = in.nextBigInteger();
//        }
//        Arrays.sort(a, 0, n);
//        BigInteger res = BigInteger.ZERO, sum = king.a, temp;
//        for (int i = 0; i < n; i ++) {
//            res = res.max(sum.divide(a[i].b));
//            sum = sum.multiply(a[i].a);
//        }
//        System.out.println(res);
//    }