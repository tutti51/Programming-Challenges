import java.util.*;
import java.math.*;

class Main {
    public static void main(String args[]) {
        final int MAX_N = 1000000;
        
        long[] sum = new long[MAX_N + 1];
        long[] num_of_tri = new long[MAX_N + 1];
        
        sum[0] = 0;
        for (int i = 1; i <= MAX_N; i++)
            sum[i] = sum[i - 1] + i;
        
        num_of_tri[3] = 0;
        for (int i = 4; i <= MAX_N; i++) {
            if (i % 2 == 0)
                num_of_tri[i] = sum[i / 2 - 1] + sum[i / 2 - 2];
            else
                num_of_tri[i] = sum[i / 2 - 1] * 2;
        }
        
        for (int i = 4; i <= MAX_N; i++) {
            num_of_tri[i] = num_of_tri[i - 1] + num_of_tri[i];
        }
        
        int n;
        Scanner s = new Scanner(System.in);
        while (s.hasNextInt()) {
            n = s.nextInt();
            if (n < 3) break;
            System.out.printf("%s\n", num_of_tri[n]);
        }
    }
}