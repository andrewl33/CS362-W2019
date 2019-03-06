

import junit.framework.TestCase;
import org.junit.Test;

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
        private final List<String> validSchemes = new ArrayList<String>("http://", "ftp://", "h3t://", "");
        private final int maxPort = 65536;
        private final int minPort = 0;
        private final char[] testAlphabet = "#$%&-_=+qQwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlL:zZxXcCvBnNmM./?1234567890".toCharArray();
        private final char[] pathAlphabet = "#qQwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlLzZxXcCvBnNmM.1234567890".toCharArray();
        private final char[] queryAlphabet = "qwertyuiopasdfghjklzxcvbnm".toCharArray();

        //  random regexes, where falses could be 0 to list size
        public List<Pair<String, Boolean>> generateUrls(int number) {

        }

        // should pass through all tests
        // maximum one false
        public List<Pair<String, Boolean>> generateDistributedUrls() {

        }

        private Pair<String, Boolean> generateScheme() {
            // has to be a part of valid schemes

        }

        private Pair<String, Boolean> generateAuthority() {

            int switchSize = 0;
            int authType = rand.nextInt(switchSize);

            // generate numeric url

            // generate named url
        }

        private Pair<String, Boolean> generatePort() {
            if (setToNull()) {
                return new Pair<String, Boolean>("", true);
            }

            boolean isValid = false;
            int portNumber = rand.nextInt(-10000, 100000);
            StringBuilder portBuilder = new StringBuilder();
            portBuilder.append(":");

            // check if number
            if (maxPort > portNumber && minPort < portNumber)
            {
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

            boolean isValid = True;
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
            return testAlphabet[rand.nextInt(alphabet.length)];
        }

        private boolean setToNull() {
            return rand.nextInt(nullChance) == 0;
        }

    }

}
