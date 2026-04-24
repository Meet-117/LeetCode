class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countLeft = 0;
        int countRight = 0;
        int result = 0;
        for (int i = 0; i < moves.length(); i++) {
            if (moves[i] == 'L')
                countLeft++;
            else if (moves[i] == 'R')
                countRight++;
        }
        if (countLeft > countRight) {
            for (int i = 0; i < moves.length(); i++) {
                if (moves[i] == 'L')
                    result++;
                else if (moves[i] == 'R')
                    result--;
                else
                    result++;
            }
        } else {
            for (int i = 0; i < moves.length(); i++) {
                if (moves[i] == 'R')
                    result++;
                else if (moves[i] == 'L')
                    result--;
                else
                    result++;
            }
        }
        return abs(result);
    }
};