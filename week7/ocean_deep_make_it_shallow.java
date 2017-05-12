public class ocean_deep_make_it_shallow {
    public static void main(String args[]) {
        final int MAX_DIGITS = 10000;
        final int GIVEN_NUMBER = 131071;
        
        int[] mods = new int[MAX_DIGITS + 1];
        
        mods[0] = 1;
        for (int i = 1; i <= MAX_DIGITS; i++) {
            mods[i] = mods[i - 1] * 2 % GIVEN_NUMBER;
        }
        
        
    }
}

