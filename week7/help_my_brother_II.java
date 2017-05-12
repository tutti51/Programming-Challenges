// 11161 Help My Brother (II)
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2102

import java.util.*;
import java.math.*;

class Main {
    public static void main(String args[]) {
        final int MAX_N = 1500;
        BigInteger zero = BigInteger.ZERO;
        BigInteger one = BigInteger.ONE;
        BigInteger two = one.add(one);
        
        BigInteger[] fib = new BigInteger[MAX_N + 1];
        BigInteger[] fib_sum = new BigInteger[MAX_N + 1];
        
        fib[0] = BigInteger.ZERO;
        fib[1] = BigInteger.ONE;
        for (int i = 2; i <= MAX_N; i++)
            fib[i] = fib[i - 2].add(fib[i - 1]);
        
        fib_sum[0] = BigInteger.ZERO;
        for (int i = 1; i <= MAX_N; i++)
            fib_sum[i] = fib_sum[i - 1].add(fib[i]);
        
        int n;
        int count = 0;
        Scanner s = new Scanner(System.in);
        while(s.hasNextInt()) {
            n = s.nextInt();
            if (n == 0)
                break;
            
            System.out.printf("Set %d:\n", ++count);
            
            if (fib[n].mod(two).equals(zero))
                System.out.println(fib_sum[n - 1].subtract(one).add(fib[n].divide(two)));
            else
                System.out.println(fib_sum[n - 1].subtract(one).add((fib[n].add(one)).divide(two)));
        }
    }

}

