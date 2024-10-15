/*
FrogJmp: Count minimal number of jumps from position X to Y.
-----------------------------------------------------------------------------------------------------
A small frog wants to get to the other side of the road. The frog is currently
located at position X and wants to get to a position greater than or equal to Y.
The small frog always jumps a fixed distance, D.

Count the minimal number of jumps that the small frog must perform to reach its target.

Write a function:
  int solution(int X, int Y, int D);

that, given three integers X, Y and D, returns the minimal number of jumps from
position X to a position equal to or greater than Y.

For example, given:
  X = 10
  Y = 85
  D = 30
the function should return 3, because the frog will be positioned as follows:
 * after the first jump, at position 10 + 30 = 40
 * after the second jump, at position 10 + 30 + 30 = 70
 * after the third jump, at position 10 + 30 + 30 + 30 = 100

Write an efficient algorithm for the following assumptions:
 * X, Y and D are integers within the range [1..1,000,000,000];
 * X ≤ Y.
*/



// We solve this problem by finding the total distance 
// the frog must jump by the difference of the X and Y 
// ​​and then dividing it by the length of the jump.
int solution(int X, int Y, int D) {
    // By calculating the difference of X and Y,
    // we get the total distance the frog has to jump
    int distance{Y - X};

    // if the distance is exactly divisible by the length of the jump,
    // then it is enough to divide the distance by the length of the jump and if it is not,
    // we must add one.
    return distance % D ? (distance / D)  + 1 : (distance / D);
}
