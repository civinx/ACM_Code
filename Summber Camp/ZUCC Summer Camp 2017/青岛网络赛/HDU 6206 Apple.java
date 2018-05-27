import java.math.BigInteger;
import java.util.Scanner;

class Fraction {
    BigInteger num;
    BigInteger den;

    Fraction(BigInteger num, BigInteger den) {
        if (den.compareTo(BigInteger.ZERO) == -1) {
            num = num.multiply(new BigInteger("-1"));
            den = den.multiply(new BigInteger("-1"));

        }
        BigInteger g = num.abs().gcd(den);
        this.num = num.divide(g);
        this.den = den.divide(g);
    }

    public Fraction add(Fraction o) {
        return new Fraction(num.multiply(o.den).add(den.multiply(o.num)), den.multiply(o.den));
    }

    public Fraction sub(Fraction o) {
        return new Fraction(num.multiply(o.den).subtract(den.multiply(o.num)), den.multiply(o.den));
    }

    public Fraction mul(Fraction o) {
        return new Fraction(num.multiply(o.num), den.multiply(o.den));
    }
    public Fraction div(Fraction o) {
        return new Fraction(num.multiply(o.den), den.multiply(o.num));
    }

    int compareTo(Fraction o) {
        return num.multiply(o.den).compareTo(den.multiply(o.num));
    }
}
public class Main {
    private static Scanner in = new Scanner(System.in);

//    static public BigInteger sqr(BigInteger x) {
//        BigInteger L = new BigInteger("1");
//        BigInteger R = x;
//        while (L.compareTo(R) == -1) {
//            BigInteger mid = (L.add(R)).divide(new BigInteger("2"));
//            int op = mid.multiply(mid).compareTo(x);
//            if (op == -1) {
//                L = mid;
//            } else if (op == 1) {
//                R = mid;
//            } else {
//                return mid;
//            }
//        }
//        return L;
//    }

    static public Fraction dist(Fraction x1, Fraction y1, Fraction x2, Fraction y2) {
        Fraction t1 = x1.sub(x2);
        Fraction t2 = y1.sub(y2);
        return t1.mul(t1).add(t2.mul(t2));
    }
    public static void main(String[] args) {

        int T; T = in.nextInt();
        while (T--!=0) {
            BigInteger x1, y1, x2, y2, x3, y3, x, y;
            x1 = in.nextBigInteger();
            y1 = in.nextBigInteger();
            x2 = in.nextBigInteger();
            y2 = in.nextBigInteger();
            x3 = in.nextBigInteger();
            y3 = in.nextBigInteger();
            x = in.nextBigInteger();
            y = in.nextBigInteger();
            Fraction rx, ry;
            BigInteger num, den;
            BigInteger t1 = y3.subtract(y1);
            BigInteger t2 = y2.multiply(y2).subtract(y1.multiply(y1)).add(x2.multiply(x2)).subtract(x1.multiply(x1));
            BigInteger t3 = y2.subtract(y1);
            BigInteger t4 = y1.multiply(y1).subtract(y3.multiply(y3)).add(x1.multiply(x1)).subtract(x3.multiply(x3));
            num = t1.multiply(t2).add(t3.multiply(t4));

            BigInteger t5 = new BigInteger("2").multiply(x2.subtract(x1)).multiply(y3.subtract(y1));
            BigInteger t6 = new BigInteger("2").multiply(x3.subtract(x1)).multiply(y2.subtract(y1));
            den = t5.subtract(t6);
            rx = new Fraction(num, den);

            t1 = x3.subtract(x1);
            t2 = x2.multiply(x2).subtract(x1.multiply(x1)).add(y2.multiply(y2)).subtract(y1.multiply(y1));
            t3 = x2.subtract(x1);
            t4 = x1.multiply(x1).subtract(x3.multiply(x3)).add(y1.multiply(y1)).subtract(y3.multiply(y3));
            num = t1.multiply(t2).add(t3.multiply(t4));

            t5 = new BigInteger("2").multiply(y2.subtract(y1)).multiply(x3.subtract(x1));
            t6 = new BigInteger("2").multiply(y3.subtract(y1)).multiply(x2.subtract(x1));
            den = t5.subtract(t6);
            ry = new Fraction(num, den);

            Fraction R = dist(rx, ry, new Fraction(x1, BigInteger.ONE), new Fraction(y1, BigInteger.ONE));
            Fraction dist = dist(rx, ry, new Fraction(x, BigInteger.ONE), new Fraction(y, BigInteger.ONE));
            if (R.compareTo(dist) == -1) {
                System.out.println("Accepted");
            } else {
                System.out.println("Rejected");
            }
        }
    }
}