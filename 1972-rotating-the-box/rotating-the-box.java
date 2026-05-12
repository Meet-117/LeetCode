class Solution {
    public char[][] rotateTheBox(char[][] boxGrid) {
        int n = boxGrid.length;
        int m = boxGrid[0].length;

        for (int i = 0; i < n; i++) {
            int empty = m - 1;

            for (int j = m - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    empty = j - 1;
                }

                if (boxGrid[i][j] == '#') {
                    char temp = boxGrid[i][j];
                    boxGrid[i][j] = boxGrid[i][empty];
                    boxGrid[i][empty] = temp;
                    empty--;
                }
            }
        }

        char[][] ans = new char[m][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][n - 1 - i] = boxGrid[i][j];
            }
        }

        return ans;
    }
}