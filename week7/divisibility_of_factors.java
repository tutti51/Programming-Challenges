import java.util.*;
import java.math.*;

class Main {
    BigInteger fac(BigInteger n) {
        if (n.equals(BigInteger.ZERO)) return BigInteger.ONE;
        else return n.multiply(fac(n.subtract(BigInteger.ONE)));
    }
    
    public static void main(String args[]) {
        int num_of_prime_factors[101]; // num_of_prime_factors[N]に N を素因数分解した際の素因数の数を格納
        int num_of_prime_factors_sum[101]; // num_of_prime_factors_sum[N]に 1〜Nのnum_of_prime_factorsの合計を格納する。
        num_of_prime_factors[0] = num_of_prime_factors[1] = 0;
        num_of_prime_factors_sum[0] = num_of_prime_factors_sum[1] = 0;
        for (int i = 2; i <= 100; i++) {
            num_of_prime_factors[i] = 0;
            int tmp = i;
            for (int j = i / 2; j > 1; j--) {
                while (tmp % j == 0) {
                    num_of_prime_factors[i] += num_of_prime_factors[j];
                    tmp /= j;
                }
            }
            if (num_of_prime_factors[i] == 0) {
                num_of_prime_factors[i] = 1;
            }
            num_of_prime_factors_sum[i] = num_of_prime_factors_sum[i - 1] + num_of_prime_factors[i];
        }
        
        
        int n, d;
        Scanner s = new Scanner(System.in);
        while ((n = s.nextInt()) != 0 && (d = s.nextInt()) != 0) {
            if (d < 0) {
                System.out.println(0);
                continue;
            }
            
            BigInteger nfac = fac(new BigInteger(String.valueOf(n)));
            BigInteger db = new BigInteger(String.valueOf(d));
            int count = 0;
            while(nfac.remainder(db).equals(BigInteger.ZERO)) {
                count++;
                nfac = nfac.divide(db);
            }
                
        }
        return 0;
    }
}

