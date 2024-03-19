import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(br.readLine().trim());

        for (int i = 0; i < testCases; i++) {
            int numberOfPhoneNumbers = Integer.parseInt(br.readLine().trim());
            String[] phoneNumbers = new String[numberOfPhoneNumbers];

            for (int j = 0; j < numberOfPhoneNumbers; j++) {
                phoneNumbers[j] = br.readLine().trim();
            }

            Arrays.sort(phoneNumbers);

            if (isConsistent(phoneNumbers)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

    public static boolean isConsistent(String[] phoneNumbers) {
        for (int i = 0; i < phoneNumbers.length - 1; i++) {
            if (phoneNumbers[i + 1].startsWith(phoneNumbers[i])) {
                return false;
            }
        }
        return true;
    }
}
