int detectCollisions(int oneX, int oneY, int twoX, int twoY, int oneSize, int twoSize){
    return
    (oneX >= twoX && oneX <= twoX + twoSize) &&
    (oneY >= twoY && oneY <= twoY + twoSize)
    ||
    (twoX >= oneX && twoX <= oneX + oneSize) &&
    (twoY >= oneY && twoY <= oneY + oneSize);
}