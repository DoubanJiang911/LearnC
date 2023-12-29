int buyChoco(int* prices, int pricesSize, int money){
    int first, second;
    if (prices[0] < prices[1]) {
      first = prices[0];
      second = prices[1];
    }
    else {
      first = prices[1];
      second = prices[0];
    }
    for (int i = 2; i < pricesSize; i++) {
        if (prices[i] < first) {
            second = first;
            first = prices[i];
        } else if (prices[i] < second && prices[i] >= first) {
            second = prices[i];
        }
    }
    //printf("The two smallest numbers are %d and %d.\n", first, second);
    int ans = money - first - second;
        if (ans < 0) {
            return money;
        }
        else {
            return ans;
        }
}
//else if处的判断条件如&& prices[i] >= first改为&& prices[i] != first后，则意味着找出不同的最小两个数字
