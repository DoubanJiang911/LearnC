int minOperationsMaxProfit(int* customers, int customersSize, int boardingCost, int runningCost) {
	int max_profit = 0;
	int min_cnt = -1;
	int cnt = 0, wait = 0, onboard = 0;
	int arrived, temp, current_profit;
	for (int i = 0; i < customersSize; i++) {
		cnt += 1;
		arrived = customers[i];
		if (arrived + wait <= 4) {
			temp = arrived + wait;
			wait = 0;
		}
		else {
			temp = 4;
			wait += arrived - 4;
		}
		onboard += temp;
		current_profit = onboard * boardingCost - cnt * runningCost;
		//printf("%d位游客抵达,%d位登舱,%d位等待.摩天轮第%d次轮转,当前利润:%d\n", arrived, temp, wait, cnt, current_profit);
		if (current_profit > max_profit) {
			max_profit = current_profit;
			min_cnt = cnt;
		}
	}
	while (wait > 0) {
		cnt += 1;
		if (wait > 4) {
			temp = 4;
			wait -= 4;
		}
		else {
			temp = wait;
			wait = 0;
		}
		onboard += temp;
		current_profit = onboard * boardingCost - cnt * runningCost;
		//printf("已不再有游客抵达,%d位登舱,%d位等待.摩天轮第%d次轮转,当前利润:%d\n", temp, wait, cnt, current_profit);
		if (current_profit > max_profit) {
			max_profit = current_profit;
			min_cnt = cnt;
		}
	}
	return min_cnt;
}
