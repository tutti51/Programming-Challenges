import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static void main(String args[]) throws IOException {
        BigInteger tb, ans;
        int t, a, b;
        
        Scanner s = new Scanner(System.in);
        while (s.hasNextInt()) {
            t = s.nextInt();
            a = s.nextInt();
            b = s.nextInt();
            
            tb = new BigInteger(String.valueOf(t));
            ans = BigInteger.ZERO;
            boolean range = true;
            
            /* 
             除外するパターンを列挙する
             ・t = 1 の場合、分母が0になる
             ・a % b != 0 の場合、整数にならない
             ・(a - b) * log10(t) が99以上のとき、答えは100桁以上になる
             
             また、a = b のときは分母と分子が等しくなるので答えは 1
             
             上記のどれにも当てはまらない場合は普通に計算する
             */
            if (t == 1 || a % b != 0 || (int)((a - b) * Math.log10(t)) >= 99) {
                range = false;
            } else if (a == b) {
                ans = BigInteger.ONE;
            } else {
                ans = tb.pow(a).subtract(BigInteger.ONE).divide(tb.pow(b).subtract(BigInteger.ONE));
                if(ans.toString().length() >= 100)
                    range = false;
            }
            
            if (range) {
                System.out.printf("(%s^%d-1)/(%s^%d-1) %s\n" , t, a, t, b, ans);
            } else {
                System.out.printf("(%s^%d-1)/(%s^%d-1) is not an integer with less than 100 digits.\n"
                                  , t, a, t, b);
            }
        }
    }
}