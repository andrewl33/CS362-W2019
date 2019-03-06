

import junit.framework.TestCase;
import org.junit.Test;
import java.util.Random;
import java.util.ArrayList;
import java.util.List;
import javafx.util.Pair;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


    public UrlValidatorTest(String testName) {
        super(testName);
    }


    @Test
    public void testManualTest()
    {
//You can use this function to implement your manual testing	   

    }

    @Test
    public void testYourFirstPartition()
    {
        //You can use this function to implement your First Partition testing

    }
    @Test
    public void testYourSecondPartition(){
        //You can use this function to implement your Second Partition testing

    }
    //You need to create more test cases for your Partitions if you need to
    @Test
    public void testIsValid()
    {
        //You can use this function for programming based testing

    }



    // random testings
    // all i need to do is give valid regexes
    // To reach them all, generating each part of a url is best
    // then add them together, with one false to catch

    // and then have straight random tests, with a mix of false and true
    // this will give a much more uneven set, however, random testing generally
    // has a ton of false urls

    private static class UrlGenerator {
        private Random rand = new Random(System.currentTimeMillis());
        private final int nullChance = 100; // 1% chance
        private final ArrayList<String> validSchemes = new ArrayList<String>() {{
            add("http://");
            add("ftp://");
            add("h3t://");
            add("");
        }};
        private final int maxPort = 65536;
        private final int minPort = 0;
        // private final char[] testAlphabet = "#$%&-_=+qQwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlL:zZxXcCvBnNmM./?1234567890".toCharArray();
        private final char[] pathAlphabet = "#qQwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlLzZxXcCvBnNmM.1234567890".toCharArray();
        private final char[] queryAlphabet = "qwertyuiopasdfghjklzxcvbnm".toCharArray();
        private final char[] authAlphabet = "qwertyuiopasdfghjklzxcvbnm1234567890".toCharArray();

        //  random regexes, where falses could be 0 to list size
        public Pair<String, Boolean> generateUrls() {
            boolean isValid = true;
            StringBuilder sb = new StringBuilder();
            ArrayList<Pair<String, Boolean>> url = new ArrayList<Pair<String, Boolean>>();
            url.add(generateScheme());
            url.add(generateAuthority());
            url.add(generatePort());
            url.add(generatePath());
            url.add(generateQuery());

            for (int i = 0; i < 5; i++) {
                sb.append(url.get(i).getKey());
                if (!url.get(i).getValue()) {
                    isValid = false;
                }
            }

            return new Pair<>(sb.toString(), isValid);
        }

        private Pair<String, Boolean> generateScheme() {
            // has to be a part of valid schemes
            if (rand.nextBoolean()) {
                return new Pair<>(validSchemes.get(rand.nextInt(validSchemes.size())), true);
            } else {
                StringBuilder sb = new StringBuilder(validSchemes.get(rand.nextInt(validSchemes.size()));

                for (int i = 0; i < rand.nextInt(4); i++)  {
                    switch(rand.nextInt(4)) {
                        case 0:
                            //  prepend
                            sb.insert(0, nextChar(authAlphabet));
                        case 1:
                            // append
                            sb.append(nextChar(authAlphabet));
                        case 2:
                            // replace
                            int location = rand.nextInt(sb.length());
                            sb.replace(location, location, Character.toString(nextChar(authAlphabet)));
                        case 3:
                            // delete
                            sb.deleteCharAt(rand.nextInt(sb.length()));
                    }
                }

                // check if empty
                if (sb.length() == 0) {
                    return new Pair<>("", true);
                }

                // check if unchanged
                boolean isValid = false;
                for (int i = 0; i < validSchemes.size(); i++) {
                    if (validSchemes.get(i).equals(sb.toString())) {
                        isValid = true;
                        break;
                    }
                }

                return new Pair<>(sb.toString(), isValid);

            }
        }

        private Pair<String, Boolean> generateAuthority() {
            if (setToNull()) {
                return new Pair<String, Boolean>("", false);
            }

            if (rand.nextBoolean()) {
                // numbers
                int numbersCount = 0;
                boolean isValid = true;
                int i = 0;
                StringBuilder sb = new StringBuilder();
                if (rand.nextBoolean()) {
                    sb.append('.');
                    isValid = false;
                }

                for (i = 0; i < rand.nextInt(8); i++) {
                    int nextInt = rand.nextInt(500);

                    if (nextInt > 255) {
                        isValid = false;
                    }

                    sb.append(nextInt);
                    sb.append('.');

                }

                if (rand.nextBoolean()) {
                    sb.append('.');
                    isValid = false;
                } else {
                    int nextInt = rand.nextInt(500);

                    if (nextInt > 255) {
                        isValid = false;
                    }

                    sb.append(nextInt);
                    i++;
                }

                if (i != 4) {
                    isValid = false;
                }

                return new Pair<String, Boolean>(sb.toString(), isValid);

            } else {
                // create string
                boolean isValid = true;
                StringBuilder sb = new StringBuilder();

                // insert first
                if (rand.nextBoolean()) {
                    sb.append("www.");
                }

                if (rand.nextBoolean()) {
                    sb.append('.');
                    isValid = false;
                }

                // insert body
                for (int i = 1; i < rand.nextInt(5) + 1; i++) {
                    for (int j = 1; j < rand.nextInt(10) + 1; j++) {
                        sb.append(nextChar(authAlphabet));
                    }
                    sb.append(".");
                }

                // insert tail
                if (rand.nextBoolean()) {
                    if (rand.nextBoolean()) {
                        sb.append(nextChar(authAlphabet));
                    }
                    isValid = false;
                } else {
                    for (int i = 2; i < rand.nextInt(8) +2; i++) {
                        char nc = nextChar(authAlphabet);

                        if (Character.isDigit(nc)) {
                            isValid = false;
                        }
                        sb.append(nc);
                    }
                }

                return new Pair<String, Boolean>(sb.toString(), isValid);
            }
        }

        private Pair<String, Boolean> generatePort() {
            if (setToNull()) {
                return new Pair<String, Boolean>("", true);
            }

            boolean isValid = false;
            int portNumber = rand.nextInt(100000);
            if (rand.nextBoolean()) {
                portNumber*=-1;
            }
            StringBuilder portBuilder = new StringBuilder();
            portBuilder.append(":");

            // check if number
            if (maxPort > portNumber && minPort < portNumber) {
                isValid = true;
            }

            // build it
            portBuilder.append(portNumber);

            // TODO: maybe add alpha characters into the code

            return new Pair<String, Boolean>(portBuilder.toString(), isValid);
        }

        private Pair<String, Boolean> generatePath() {
            if (setToNull()) {
                return new Pair<String, Boolean>("", true);
            }

            StringBuilder pathSB = new StringBuilder();
            boolean isValid = true;
            pathSB.append("/");

            for (int i = 0; i < rand.nextInt(50); i++) {
                // 2% chance for items
                if (rand.nextInt(5) == 0) {
                    // test truthness
                    if (pathSB.charAt(pathSB.length()-1) == '/') {
                        isValid = false;
                    }
                    pathSB.append("/");
                }
                else {
                    char nc = nextChar(pathAlphabet);

                    if (nc == '.' || nc == '#') {
                        isValid = false;
                    }

                    pathSB.append(nc);
                }
            }

            return new Pair<String, Boolean>(pathSB.toString(), isValid);
        }


        private Pair<String,Boolean> generateQuery() {
            if (setToNull()) {
                return new Pair<String, Boolean>("", true);
            }

            boolean isValid = true;
            StringBuilder querySB = new StringBuilder();

            querySB.append('?');

            int equalCount = 0;

            for (int i = 0; i < rand.nextInt(50); i++) {

                if (rand.nextInt(10) == 0) {
                    if (i == 0 || equalCount != 1 || querySB.charAt(querySB.length() - 1) == '=') {
                        isValid = false;
                    }
                    equalCount = 0;

                    querySB.append('&');
                }
                else if (rand.nextInt(5) == 0) {
                    querySB.append('=');
                    equalCount++;
                } else {
                    char nc = nextChar(queryAlphabet);
                    querySB.append(nc);
                }
            }

            if (querySB.charAt(querySB.length() - 1) == '=') {
                isValid = false;
            }

            return new Pair<String, Boolean>(querySB.toString(), isValid);

        }

        private char nextChar(char[] alphabet) {
            return alphabet[rand.nextInt(alphabet.length)];
        }

        private boolean setToNull() {
            return rand.nextInt(nullChance) == 0;
        }

    }

}
